from __future__ import annotations

from dataclasses import dataclass, field
from enum import IntEnum
import time


class BusType(IntEnum):
    VECTOR = 0
    ZLG = 1


class Direction(IntEnum):
    RX = 0
    TX = 1


class FrameFormat(IntEnum):
    STANDARD = 0
    EXTENDED = 1


class FrameType(IntEnum):
    CAN = 0
    CANFD = 1


@dataclass(slots=True)
class CANMessage:

    timestamp: float = field(default_factory=time.perf_counter)

    bus: BusType = BusType.VECTOR

    direction: Direction = Direction.RX

    channel: int = 0

    arbitration_id: int = 0

    frame_type: FrameType = FrameType.CANFD

    frame_format: FrameFormat = FrameFormat.STANDARD

    bitrate_switch: bool = False

    error_state_indicator: bool = False

    remote: bool = False

    error: bool = False

    dlc: int = 0

    length: int = 0

    data: bytearray = field(
        default_factory=lambda: bytearray(64)
    )

    user_data: object | None = None

    def clone(self):

        obj = CANMessage()

        obj.timestamp = self.timestamp
        obj.bus = self.bus
        obj.direction = self.direction
        obj.channel = self.channel
        obj.arbitration_id = self.arbitration_id

        obj.frame_type = self.frame_type
        obj.frame_format = self.frame_format

        obj.bitrate_switch = self.bitrate_switch
        obj.error_state_indicator = self.error_state_indicator
        obj.remote = self.remote
        obj.error = self.error

        obj.dlc = self.dlc
        obj.length = self.length

        obj.data[:] = self.data

        obj.user_data = self.user_data

        return obj

    @property
    def id_string(self):

        if self.frame_format == FrameFormat.EXTENDED:
            return f"{self.arbitration_id:08X}"

        return f"{self.arbitration_id:03X}"

    @property
    def data_string(self):

        return " ".join(
            f"{x:02X}"
            for x in self.data[: self.length]
        )

    @property
    def is_fd(self):

        return self.frame_type == FrameType.CANFD

