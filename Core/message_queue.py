# core/message_queue.py

from __future__ import annotations

from queue import Empty
from queue import Queue


class MessageQueue:

    def __init__(self):

        self._queue = Queue()

    def put(self, frame):

        self._queue.put(frame)

    def get(self, timeout=None):

        return self._queue.get(timeout=timeout)

    def get_nowait(self):

        return self._queue.get_nowait()

    def try_get(self):

        try:

            return self._queue.get_nowait()

        except Empty:

            return None

    def clear(self):

        while not self._queue.empty():

            self._queue.get_nowait()

    @property
    def size(self):

        return self._queue.qsize()

    @property
    def empty(self):

        return self._queue.empty()
    