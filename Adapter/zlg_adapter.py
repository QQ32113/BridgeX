# adapter/zlg_adapter.py
# Part 1

from __future__ import annotations

from threading import Thread
from threading import Event
from queue import Queue
from queue import Empty

from adapter.base_adapter import BaseAdapter

from core.frame import (
    CANFrame,
    FrameType,
    FrameFormat,
    Direction,
)

from sdk.zlg_sdk import (
    ZlgSDK,
    ZCAN_TransmitFD_Data,
)


class ZlgAdapter(BaseAdapter):

    def __init__(self):

        super().__init__()

        self.sdk = ZlgSDK()

        self.txQueue = Queue()

        self.rxQueue = Queue()

        self.stopEvent = Event()

        self.txThread = None

        self.rxThread = None

    def open(self):

        self.sdk.openDevice(41)

        self.sdk.initCANFD(
            channel=0,
            arbitrationTiming=0x060003,
            dataTiming=0x010001,
        )

        self._opened = True

        return True

    def close(self):

        self.stop()

        self.sdk.close()

        self._opened = False

    def start(self):

        self.sdk.startCAN()

        self.stopEvent.clear()

        self.txThread = Thread(
            target=self.__tx_loop,
            daemon=True,
            name="ZLG TX",
        )

        self.rxThread = Thread(
            target=self.__rx_loop,
            daemon=True,
            name="ZLG RX",
        )

        self.txThread.start()

        self.rxThread.start()

        self._started = True

    def stop(self):

        self.stopEvent.set()

        self._started = False

    def send(self, frame: CANFrame):

        self.txQueue.put(frame)

    def receive(self):

        try:

            return self.rxQueue.get_nowait()

        except Empty:

            return None
# adapter/zlg_adapter.py
# Part 2

    def __build_tx_packet(
        self,
        frame: CANFrame,
    ):

        packet = ZCAN_TransmitFD_Data()

        packet.transmit_type = 0

        packet.frame.can_id = frame.arbitration_id

        packet.frame.len = frame.length

        packet.frame.eff = (
            frame.frame_format ==
            FrameFormat.EXTENDED
        )

        packet.frame.rtr = frame.remote

        packet.frame.brs = frame.bitrate_switch

        packet.frame.esi = (
            frame.error_state_indicator
        )

        for i in range(frame.length):

            packet.frame.data[i] = frame.data[i]

        return packet

    def __parse_packet(
        self,
        packet,
    ):

        frame = CANFrame()

        frame.timestamp = packet.timestamp

        frame.channel = 0

        frame.arbitration_id = packet.frame.can_id

        frame.length = packet.frame.len

        frame.dlc = frame.length

        frame.direction = Direction.RX

        frame.frame_type = FrameType.CANFD

        frame.frame_format = (
            FrameFormat.EXTENDED
            if packet.frame.eff
            else FrameFormat.STANDARD
        )

        frame.remote = bool(packet.frame.rtr)

        frame.bitrate_switch = bool(packet.frame.brs)

        frame.error_state_indicator = bool(packet.frame.esi)

        for i in range(frame.length):

            frame.data[i] = packet.frame.data[i]

        return frame
# adapter/zlg_adapter.py
# Part 3

    def __tx_loop(self):

        while not self.stopEvent.is_set():

            try:

                frame = self.txQueue.get(
                    timeout=0.05
                )

            except Empty:

                continue

            packet = self.__build_tx_packet(
                frame
            )

            self.sdk.transmitFD(
                packet
            )

    def __rx_loop(self):

        while not self.stopEvent.is_set():

            packet = self.sdk.receiveFD()

            if packet is None:

                continue

            frame = self.__parse_packet(
                packet
            )

            self.rxQueue.put(frame)

    def clear(self):

        while not self.txQueue.empty():

            self.txQueue.get_nowait()

        while not self.rxQueue.empty():

            self.rxQueue.get_nowait()

    @property
    def queue_size(self):

        return self.rxQueue.qsize()

    @property
    def is_connected(self):

        return self._opened
