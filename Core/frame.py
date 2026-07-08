# core/frame.py
# Part 1

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum, IntEnum
import time


class FrameType(Enum):

    CAN = 0

    CANFD = 1


class FrameFormat(Enum):

    STANDARD = 0

    EXTENDED = 1


class Direction(Enum):

    RX = 0

    TX = 1


class BusType(Enum):

    VECTOR = 0

    ZLG = 1


class ErrorType(IntEnum):

    NONE = 0

    BUSOFF = 1

    PASSIVE = 2

    WARNING = 3

    CRC = 4

    ACK = 5

    STUFF = 6

    FORM = 7

    BIT = 8


@dataclass(slots=True)
class CANFrame:

    timestamp: float = field(
        default_factory=time.time
    )

    arbitration_id: int = 0

    channel: int = 0

    dlc: int = 0

    length: int = 0

    data: bytearray = field(
        default_factory=lambda: bytearray(64)
    )

    frame_type: FrameType = FrameType.CAN

    frame_format: FrameFormat = FrameFormat.STANDARD

    direction: Direction = Direction.RX

    bus: BusType = BusType.ZLG

    bitrate_switch: bool = False

    error_state_indicator: bool = False

    remote: bool = False

    error: bool = False

    error_type: ErrorType = ErrorType.NONE

# core/frame.py
# Part 2

    def copy(self):

        obj = CANFrame()

        obj.timestamp = self.timestamp

        obj.arbitration_id = self.arbitration_id

        obj.channel = self.channel

        obj.dlc = self.dlc

        obj.length = self.length

        obj.data[:] = self.data

        obj.frame_type = self.frame_type

        obj.frame_format = self.frame_format

        obj.direction = self.direction

        obj.bus = self.bus

        obj.bitrate_switch = self.bitrate_switch

        obj.error_state_indicator = self.error_state_indicator

        obj.remote = self.remote

        obj.error = self.error

        obj.error_type = self.error_type

        return obj

    def clear(self):

        self.arbitration_id = 0

        self.channel = 0

        self.dlc = 0

        self.length = 0

        self.data[:] = bytes(64)

        self.error = False

        self.remote = False

        self.bitrate_switch = False

        self.error_state_indicator = False

        self.error_type = ErrorType.NONE

    @property
    def is_fd(self):

        return self.frame_type == FrameType.CANFD

    @property
    def is_extended(self):

        return self.frame_format == FrameFormat.EXTENDED

    @property
    def hex_id(self):

        if self.is_extended:

            return f"{self.arbitration_id:08X}"

        return f"{self.arbitration_id:03X}"

    @property
    def data_string(self):

        return " ".join(

            f"{x:02X}"

            for x in self.data[:self.length]

        )

