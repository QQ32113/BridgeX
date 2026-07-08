# core/bridge_manager.py
# Part 1

from __future__ import annotations

import time

from threading import Thread
from threading import Event
from threading import Lock

from core.frame import CANFrame


class BridgeManager:

    def __init__(

        self,

        vector_adapter,

        zlg_adapter,

    ):

        self.vector = vector_adapter

        self.zlg = zlg_adapter

        self.running = False

        self.stopEvent = Event()

        self.lock = Lock()

        self.v2zThread = None

        self.z2vThread = None

        self.watchdogThread = None

        self.statisticsThread = None

        self.traceCallbacks = []

        self.statisticsCallbacks = []

        self.stateCallbacks = []

        self.vectorTx = 0

        self.vectorRx = 0

        self.zlgTx = 0

        self.zlgRx = 0

        self.dropCount = 0

        self.errorCount = 0

        self.bridgeCount = 0

        self.lastVectorFrame = 0

        self.lastZlgFrame = 0

        self.lastStatisticsTime = time.time()

        self.fpsVectorRx = 0

        self.fpsVectorTx = 0

        self.fpsZlgRx = 0

        self.fpsZlgTx = 0

    def addTraceCallback(

        self,

        callback,

    ):

        self.traceCallbacks.append(callback)

    def addStatisticsCallback(

        self,

        callback,

    ):

        self.statisticsCallbacks.append(callback)

    def addStateCallback(

        self,

        callback,

    ):

        self.stateCallbacks.append(callback)

    def start(self):

        if self.running:

            return

        self.vector.start()

        self.zlg.start()

        self.running = True

        self.stopEvent.clear()

        self.v2zThread = Thread(

            target=self.__vector_to_zlg,

            daemon=True,

            name="Bridge Vector->ZLG",

        )

        self.z2vThread = Thread(

            target=self.__zlg_to_vector,

            daemon=True,

            name="Bridge ZLG->Vector",

        )

        self.watchdogThread = Thread(

            target=self.__watchdog,

            daemon=True,

            name="Bridge WatchDog",

        )

        self.statisticsThread = Thread(

            target=self.__statistics,

            daemon=True,

            name="Bridge Statistics",

        )

        self.v2zThread.start()

        self.z2vThread.start()

        self.watchdogThread.start()

        self.statisticsThread.start()

        self.__notifyState(True)

    def stop(self):

        self.running = False

        self.stopEvent.set()

        self.vector.stop()

        self.zlg.stop()

        self.__notifyState(False)
# core/bridge_manager.py
# Part 2

    def __vector_to_zlg(self):

        while not self.stopEvent.is_set():

            frame = self.vector.receive()

            if frame is None:

                time.sleep(0.0005)

                continue

            self.vectorRx += 1

            self.lastVectorFrame = time.time()

            self.zlg.send(frame)

            self.zlgTx += 1

            self.bridgeCount += 1

            self.__notifyTrace(frame)

    def __zlg_to_vector(self):

        while not self.stopEvent.is_set():

            frame = self.zlg.receive()

            if frame is None:

                time.sleep(0.0005)

                continue

            self.zlgRx += 1

            self.lastZlgFrame = time.time()

            self.vector.send(frame)

            self.vectorTx += 1

            self.bridgeCount += 1

            self.__notifyTrace(frame)

    def __notifyTrace(

        self,

        frame: CANFrame,

    ):

        for cb in self.traceCallbacks:

            try:

                cb(frame)

            except Exception:

                pass

    def __notifyState(

        self,

        connected,

    ):

        for cb in self.stateCallbacks:

            try:

                cb(connected)

            except Exception:

                pass

        # core/bridge_manager.py
        # Part 3

        def __statistics(self):

            while not self.stopEvent.is_set():

                time.sleep(1)

                now = time.time()

                dt = now - self.lastStatisticsTime

                if dt <= 0:
                    continue

                stat = {

                    "vector_rx": self.vectorRx,

                    "vector_tx": self.vectorTx,

                    "zlg_rx": self.zlgRx,

                    "zlg_tx": self.zlgTx,

                    "bridge": self.bridgeCount,

                    "drop": self.dropCount,

                    "error": self.errorCount,

                    "fps_vector_rx": self.vectorRx / dt,

                    "fps_vector_tx": self.vectorTx / dt,

                    "fps_zlg_rx": self.zlgRx / dt,

                    "fps_zlg_tx": self.zlgTx / dt,

                }

                for cb in self.statisticsCallbacks:

                    try:

                        cb(stat)

                    except Exception:

                        pass

                self.vectorRx = 0

                self.vectorTx = 0

                self.zlgRx = 0

                self.zlgTx = 0

                self.bridgeCount = 0

                self.lastStatisticsTime = now

        def __watchdog(self):

            while not self.stopEvent.is_set():

                time.sleep(1)

                try:

                    if not self.vector.is_connected:
                        self.vector.close()

                        self.vector.open()

                        self.vector.start()

                except Exception:

                    pass

                try:

                    if not self.zlg.is_connected:
                        self.zlg.close()

                        self.zlg.open()

                        self.zlg.start()

                except Exception:

                    pass

        @property
        def connected(self):

            return (

                    self.vector.is_connected

                    and

                    self.zlg.is_connected

            )

        @property
        def statistics(self):

            return {

                "connected": self.connected,

                "bridge": self.bridgeCount,

                "drop": self.dropCount,

                "error": self.errorCount,

            }

