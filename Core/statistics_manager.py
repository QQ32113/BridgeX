# core/statistics_manager.py
# Part 1

from __future__ import annotations

import time
import threading
import psutil
from dataclasses import dataclass, asdict
from collections import deque


@dataclass(slots=True)
class StatisticsSnapshot:

    timestamp: float = 0.0

    vector_rx: int = 0
    vector_tx: int = 0

    zlg_rx: int = 0
    zlg_tx: int = 0

    bridge: int = 0

    drop: int = 0

    error: int = 0

    fps_vector_rx: float = 0.0
    fps_vector_tx: float = 0.0
    fps_zlg_rx: float = 0.0
    fps_zlg_tx: float = 0.0

    cpu: float = 0.0

    memory: float = 0.0

    queue_vector: int = 0

    queue_zlg: int = 0

    delay_ms: float = 0.0

    busload_vector: float = 0.0

    busload_zlg: float = 0.0


class StatisticsManager:

    HISTORY = 300

    def __init__(self):

        self.lock = threading.Lock()

        self.callbacks = []

        self.running = False

        self.thread = None

        self.last = time.time()

        self.vector_rx = 0
        self.vector_tx = 0

        self.zlg_rx = 0
        self.zlg_tx = 0

        self.bridge = 0

        self.drop = 0

        self.error = 0

        self.vector_queue = 0

        self.zlg_queue = 0

        self.delay = 0

        self.vector_busload = 0

        self.zlg_busload = 0

        self.history = deque(maxlen=self.HISTORY)

        # core/statistics_manager.py
        # Part 2

        def addCallback(self, cb):
            self.callbacks.append(cb)

        def increaseVectorRx(self):
            with self.lock:
                self.vector_rx += 1

        def increaseVectorTx(self):
            with self.lock:
                self.vector_tx += 1

        def increaseZlgRx(self):
            with self.lock:
                self.zlg_rx += 1

        def increaseZlgTx(self):
            with self.lock:
                self.zlg_tx += 1

        def increaseBridge(self):
            with self.lock:
                self.bridge += 1

        def increaseDrop(self):
            with self.lock:
                self.drop += 1

        def increaseError(self):
            with self.lock:
                self.error += 1

        def updateQueues(

                self,

                vector,

                zlg,

        ):
            self.vector_queue = vector

            self.zlg_queue = zlg

        def updateDelay(

                self,

                delay,

        ):
            self.delay = delay

        def updateBusload(

                self,

                vector,

                zlg,

        ):
            self.vector_busload = vector

            self.zlg_busload = zlg

            # core/statistics_manager.py
            # Part 3

            def start(self):

                if self.running:
                    return

                self.running = True

                self.thread = threading.Thread(

                    target=self.__loop,

                    daemon=True,

                    name="Statistics",

                )

                self.thread.start()

            def stop(self):

                self.running = False

            def __loop(self):

                while self.running:

                    time.sleep(1)

                    now = time.time()

                    dt = now - self.last

                    if dt <= 0:
                        continue

                    snapshot = StatisticsSnapshot()

                    snapshot.timestamp = now

                    snapshot.vector_rx = self.vector_rx
                    snapshot.vector_tx = self.vector_tx

                    snapshot.zlg_rx = self.zlg_rx
                    snapshot.zlg_tx = self.zlg_tx

                    snapshot.bridge = self.bridge

                    snapshot.drop = self.drop

                    snapshot.error = self.error

                    snapshot.fps_vector_rx = self.vector_rx / dt
                    snapshot.fps_vector_tx = self.vector_tx / dt

                    snapshot.fps_zlg_rx = self.zlg_rx / dt
                    snapshot.fps_zlg_tx = self.zlg_tx / dt

                    snapshot.cpu = psutil.cpu_percent()

                    snapshot.memory = psutil.virtual_memory().percent

                    snapshot.queue_vector = self.vector_queue

                    snapshot.queue_zlg = self.zlg_queue

                    snapshot.delay_ms = self.delay

                    snapshot.busload_vector = self.vector_busload

                    snapshot.busload_zlg = self.zlg_busload

                    self.history.append(snapshot)

                    for cb in self.callbacks:

                        try:

                            cb(snapshot)

                        except Exception:

                            pass

                    self.vector_rx = 0
                    self.vector_tx = 0

                    self.zlg_rx = 0
                    self.zlg_tx = 0

                    self.bridge = 0

                    self.last = now

# core/statistics_manager.py
# Part 4

    def latest(self):

        if len(self.history):

            return self.history[-1]

        return StatisticsSnapshot()

    def export(self):

        return [

            asdict(i)

            for i in self.history

        ]

    def clear(self):

        self.history.clear()

    @property

    def cpu(self):

        return psutil.cpu_percent()

    @property

    def memory(self):

        return psutil.virtual_memory().percent