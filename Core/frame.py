
# core/frame.py

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum, IntEnum


class FrameType(Enum):
    CAN = 0
    CANFD = 1


class FrameFormat(Enum):
    STANDARD = 0
    EXTENDED = 1


class Direction(Enum):
    RX = 0
    TX = 1


class BusState(Enum):
    UNKNOWN = 0
    CONNECTED = 1
    DISCONNECTED = 2


class DLC(IntEnum):
    DLC0 = 0
    DLC1 = 1
    DLC2 = 2
    DLC3 = 3
    DLC4 = 4
    DLC5 = 5
    DLC6 = 6
    DLC7 = 7
    DLC8 = 8
    DLC12 = 9
    DLC16 = 10
    DLC20 = 11
    DLC24 = 12
    DLC32 = 13
    DLC48 = 14
    DLC64 = 15


_DLC_TO_LENGTH = {
    0: 0,
    1: 1,
    2: 2,
    3: 3,
    4: 4,
    5: 5,
    6: 6,
    7: 7,
    8: 8,
    9: 12,
    10: 16,
    11: 20,
    12: 24,
    13: 32,
    14: 48,
    15: 64,
}


@dataclass(slots=True)
class CANFrame:

    timestamp: int = 0

    channel: int = 0

    arbitration_id: int = 0

    dlc: int = 8

    length: int = 8

    frame_type: FrameType = FrameType.CAN

    frame_format: FrameFormat = FrameFormat.STANDARD

    direction: Direction = Direction.RX

    bitrate_switch: bool = False

    error_state_indicator: bool = False

    remote: bool = False

    error: bool = False

    data: bytearray = field(default_factory=lambda: bytearray(64))

    def update_length(self) -> None:

        self.length = _DLC_TO_LENGTH.get(self.dlc, 8)

    def clear(self) -> None:

        self.timestamp = 0

        self.channel = 0

        self.arbitration_id = 0

        self.dlc = 8

        self.length = 8

        self.frame_type = FrameType.CAN

        self.frame_format = FrameFormat.STANDARD

        self.direction = Direction.RX

        self.bitrate_switch = False

        self.error_state_indicator = False

        self.remote = False

        self.error = False

        self.data = bytearray(64)

    @property
    def is_fd(self) -> bool:

        return self.frame_type == FrameType.CANFD

    @property
    def is_extended(self) -> bool:

        return self.frame_format == FrameFormat.EXTENDED

    @property
    def hex_id(self) -> str:

        if self.is_extended:
            return f"{self.arbitration_id:08X}"

        return f"{self.arbitration_id:03X}"

    @property
    def hex_data(self) -> str:

        return " ".join(f"{b:02X}" for b in self.data[: self.length])
    