# adapter/vector_adapter.py
# Part 1

from __future__ import annotations

from threading import Lock
from threading import Thread
from threading import Event
from queue import Queue
from queue import Empty

from adapter.base_adapter import BaseAdapter

from core.frame import CANFrame
from core.frame import FrameType
from core.frame import FrameFormat
from core.frame import Direction

from sdk.vector_sdk import (
    VectorSDK,
    XLcanTxEvent,
    XL_CAN_EXT_MSG_ID,
    XL_CAN_TXMSG_FLAG_EDL,
    XL_CAN_TXMSG_FLAG_BRS,
    XL_CAN_TXMSG_FLAG_ESI,
    XL_CAN_TXMSG_FLAG_RTR,
    XL_CAN_RXMSG_FLAG_EDL,
    XL_CAN_RXMSG_FLAG_BRS,
    XL_CAN_RXMSG_FLAG_ESI,
    XL_CAN_RXMSG_FLAG_RTR,
)


class VectorAdapter(BaseAdapter):

    def __init__(self):

        super().__init__()

        self.sdk = VectorSDK()

        self.txQueue = Queue()

        self.rxQueue = Queue()

        self.txThread = None

        self.rxThread = None

        self.stopEvent = Event()

        self.lock = Lock()

        self.connected = False

        self.channelMask = 0

    def open(self):

        self.sdk.openDriver()

        self.sdk.getDriverConfig()

        self.sdk.openPort("CANoe")

        self.connected = True

        self._opened = True

        return True

    def close(self):

        self.stop()

        self.sdk.close()

        self.connected = False

        self._opened = False

    def start(self):

        if self._started:

            return

        self.sdk.activateChannel()

        self.stopEvent.clear()

        self.txThread = Thread(

            target=self.__tx_loop,

            daemon=True,

            name="VectorTX"

        )

        self.rxThread = Thread(

            target=self.__rx_loop,

            daemon=True,

            name="VectorRX"

        )

        self.txThread.start()

        self.rxThread.start()

        self._started = True

    def stop(self):

        self.stopEvent.set()

        self.sdk.deactivateChannel()

        self._started = False

    def send(

        self,

        frame: CANFrame,

    ):

        self.txQueue.put(frame)

    def receive(self):

        try:

            return self.rxQueue.get_nowait()

        except Empty:

            return None

    def __build_tx_event(

        self,

        frame: CANFrame,

    ) -> XLcanTxEvent:

        event = XLcanTxEvent()

        event.tag = 0

        event.channelIndex = frame.channel

        event.timeStamp = frame.timestamp

        event.tagData.canId = frame.arbitration_id

        if frame.frame_format == FrameFormat.EXTENDED:

            event.tagData.canId |= XL_CAN_EXT_MSG_ID

        event.tagData.dlc = frame.dlc

        if frame.frame_type == FrameType.CANFD:

            event.tagData.msgFlags |= XL_CAN_TXMSG_FLAG_EDL

        if frame.bitrate_switch:

            event.tagData.msgFlags |= XL_CAN_TXMSG_FLAG_BRS

        if frame.error_state_indicator:

            event.tagData.msgFlags |= XL_CAN_TXMSG_FLAG_ESI

        if frame.remote:

            event.tagData.msgFlags |= XL_CAN_TXMSG_FLAG_RTR

        for i in range(frame.length):

            event.tagData.data[i] = frame.data[i]

        return event

        # adapter/vector_adapter.py
        # Part 2

        def __parse_rx_event(

                self,

                event,

        ) -> CANFrame:

            frame = CANFrame()

            frame.timestamp = event.timeStamp

            frame.channel = event.channelIndex

            frame.arbitration_id = (

                    event.tagData.canId & 0x1FFFFFFF

            )

            frame.dlc = event.tagData.dlc

            frame.update_length()

            if event.tagData.canId & XL_CAN_EXT_MSG_ID:

                frame.frame_format = FrameFormat.EXTENDED

            else:

                frame.frame_format = FrameFormat.STANDARD

            if event.tagData.msgFlags & XL_CAN_RXMSG_FLAG_EDL:

                frame.frame_type = FrameType.CANFD

            else:

                frame.frame_type = FrameType.CAN

            frame.bitrate_switch = bool(

                event.tagData.msgFlags &

                XL_CAN_RXMSG_FLAG_BRS

            )

            frame.error_state_indicator = bool(

                event.tagData.msgFlags &

                XL_CAN_RXMSG_FLAG_ESI

            )

            frame.remote = bool(

                event.tagData.msgFlags &

                XL_CAN_RXMSG_FLAG_RTR

            )

            frame.direction = Direction.RX

            for i in range(frame.length):
                frame.data[i] = event.tagData.data[i]

            return frame

        def __tx_loop(self):

            while not self.stopEvent.is_set():

                try:

                    frame = self.txQueue.get(

                        timeout=0.05

                    )

                except Empty:

                    continue

                packet = self.__build_tx_event(

                    frame

                )

                self.sdk.canTransmitFD(

                    packet

                )

        def __rx_loop(self):

            while not self.stopEvent.is_set():

                event = self.sdk.canReceiveFD()

                if event is None:
                    continue

                frame = self.__parse_rx_event(

                    event

                )

                self.rxQueue.put(

                    frame

                )

        @property
        def queue_size(self):

            return self.rxQueue.qsize()

        def clear(self):

            while not self.txQueue.empty():
                self.txQueue.get_nowait()

            while not self.rxQueue.empty():
                self.rxQueue.get_nowait()