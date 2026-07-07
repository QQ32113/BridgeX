# core/bridge_manager.py

from __future__ import annotations

from threading import Thread
from threading import Event

from adapter.vector_adapter import VectorAdapter
from adapter.zlg_adapter import ZlgAdapter

from core.statistics import Statistics


class BridgeManager:

    def __init__(self):

        self.vector = VectorAdapter()

        self.zlg = ZlgAdapter()

        self.statistics = Statistics()

        self.stopEvent = Event()

        self.v2zThread = None

        self.z2vThread = None

    def open(self):

        return self.vector.open() and self.zlg.open()

    def start(self):

        self.vector.start()

        self.zlg.start()

        self.stopEvent.clear()

        self.v2zThread = Thread(
            target=self.vector_to_zlg,
            daemon=True
        )

        self.z2vThread = Thread(
            target=self.zlg_to_vector,
            daemon=True
        )

        self.v2zThread.start()

        self.z2vThread.start()

    def stop(self):

        self.stopEvent.set()

        self.vector.stop()

        self.zlg.stop()

    def vector_to_zlg(self):

        while not self.stopEvent.is_set():

            frame = self.vector.receive()

            if frame is None:

                continue

            self.zlg.send(frame)

            self.statistics.bridge_frames += 1

            self.statistics.tx_frames += 1

    def zlg_to_vector(self):

        while not self.stopEvent.is_set():

            frame = self.zlg.receive()

            if frame is None:

                continue

            self.vector.send(frame)

            self.statistics.bridge_frames += 1

            self.statistics.rx_frames += 1
