# core/statistics.py

from __future__ import annotations

from dataclasses import dataclass


@dataclass(slots=True)
class Statistics:

    tx_frames: int = 0

    rx_frames: int = 0

    tx_bytes: int = 0

    rx_bytes: int = 0

    error_frames: int = 0

    dropped_frames: int = 0

    bridge_frames: int = 0

    def clear(self):

        self.tx_frames = 0
        self.rx_frames = 0

        self.tx_bytes = 0
        self.rx_bytes = 0

        self.error_frames = 0
        self.dropped_frames = 0

        self.bridge_frames = 0
