# adapter/base_adapter.py

from __future__ import annotations

from abc import ABC
from abc import abstractmethod

from core.frame import CANFrame


class BaseAdapter(ABC):

    def __init__(self):

        self._opened = False

        self._started = False

    @abstractmethod
    def open(self):

        ...

    @abstractmethod
    def close(self):

        ...

    @abstractmethod
    def start(self):

        ...

    @abstractmethod
    def stop(self):

        ...

    @abstractmethod
    def send(self, frame: CANFrame):

        ...

    @abstractmethod
    def receive(self):

        ...

    @property
    def opened(self):

        return self._opened

    @property
    def started(self):

        return self._started
