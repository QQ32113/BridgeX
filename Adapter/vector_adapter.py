# adapter/vector_adapter.py

from __future__ import annotations

from core.frame import CANFrame
from core.frame import FrameFormat
from core.frame import FrameType

from adapter.base_adapter import BaseAdapter

from sdk.vector_sdk import VectorSDK
from sdk.vector_sdk import XLcanTxMsg
from sdk.vector_sdk import XL_CAN_EXT_MSG_ID
from sdk.vector_sdk import XL_CAN_TXMSG_FLAG_BRS
from sdk.vector_sdk import XL_CAN_TXMSG_FLAG_EDL


class VectorAdapter(BaseAdapter):

    def __init__(self):

        super().__init__()

        self.sdk = VectorSDK()

    def open(self):

        if not self.sdk.open_driver():

            return False

        if not self.sdk.get_driver_config():

            return False

        if not self.sdk.open_port("CANoe"):

            return False

        self._opened = True

        return True

    def close(self):

        self.sdk.close_port()

        self.sdk.close_driver()

        self._opened = False

    def start(self):

        self._started = self.sdk.activate_channel()

        return self._started

    def stop(self):

        self.sdk.deactivate_channel()

        self._started = False

    def send(self, frame: CANFrame):

        msg = XLcanTxMsg()

        msg.canId = frame.arbitration_id

        if frame.is_extended:

            msg.canId |= XL_CAN_EXT_MSG_ID

        msg.dlc = frame.dlc

        if frame.is_fd:

            msg.msgFlags |= XL_CAN_TXMSG_FLAG_EDL

        if frame.bitrate_switch:

            msg.msgFlags |= XL_CAN_TXMSG_FLAG_BRS

        for i in range(frame.length):

            msg.data[i] = frame.data[i]

        return self.sdk.transmit(msg)

    def receive(self):

        event = self.sdk.receive()

        if event is None:

            return None

        frame = CANFrame()

        frame.timestamp = event.timeStamp

        frame.channel = event.channelIndex

        frame.arbitration_id = event.tagData.canId & 0x1FFFFFFF

        frame.dlc = event.tagData.dlc

        frame.update_length()

        frame.frame_type = FrameType.CANFD if event.tagData.msgFlags & XL_CAN_TXMSG_FLAG_EDL else FrameType.CAN

        frame.frame_format = FrameFormat.EXTENDED if event.tagData.canId & XL_CAN_EXT_MSG_ID else FrameFormat.STANDARD

        frame.bitrate_switch = bool(event.tagData.msgFlags & XL_CAN_TXMSG_FLAG_BRS)

        for i in range(frame.length):

            frame.data[i] = event.tagData.data[i]

        return frame
    