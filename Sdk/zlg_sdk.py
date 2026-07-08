# sdk/zlg_sdk.py
# Part 1

from __future__ import annotations

from ctypes import *
from pathlib import Path
from enum import IntEnum


DLL_PATH = Path(__file__).parent.parent / "dll"

_zlg = WinDLL(str(DLL_PATH / "zlgcan.dll"))


INVALID_DEVICE_HANDLE = 0

INVALID_CHANNEL_HANDLE = 0


class ZCANStatus(IntEnum):

    OK = 1

    ERROR = 0


class ZCANDeviceType(IntEnum):

    ZCAN_USBCANFD_200U = 41


class ZCAN_DEVICE_INFO(Structure):

    _fields_ = [

        ("hw_Version", c_ushort),

        ("fw_Version", c_ushort),

        ("dr_Version", c_ushort),

        ("in_Version", c_ushort),

        ("irq_Num", c_ushort),

        ("can_Num", c_ubyte),

        ("str_Serial_Num", c_ubyte * 20),

        ("str_hw_Type", c_ubyte * 40),

        ("reserved", c_ushort * 4)

    ]


class ZCAN_CHANNEL_CAN_INIT_CONFIG(Structure):

    _fields_ = [

        ("acc_code", c_uint),

        ("acc_mask", c_uint),

        ("reserved", c_uint),

        ("filter", c_ubyte),

        ("timing0", c_ubyte),

        ("timing1", c_ubyte),

        ("mode", c_ubyte)

    ]


class ZCAN_CHANNEL_CANFD_INIT_CONFIG(Structure):

    _fields_ = [

        ("acc_code", c_uint),

        ("acc_mask", c_uint),

        ("abit_timing", c_uint),

        ("dbit_timing", c_uint),

        ("brp", c_uint),

        ("filter", c_ubyte),

        ("mode", c_ubyte),

        ("pad", c_ushort),

        ("reserved", c_uint)

    ]


class _INIT_CONFIG_UNION(Union):

    _fields_ = [

        ("can", ZCAN_CHANNEL_CAN_INIT_CONFIG),

        ("canfd", ZCAN_CHANNEL_CANFD_INIT_CONFIG)

    ]


class ZCAN_CHANNEL_INIT_CONFIG(Structure):

    _fields_ = [

        ("can_type", c_uint),

        ("config", _INIT_CONFIG_UNION)

    ]


class ZCAN_CAN_FRAME(Structure):

    _fields_ = [

        ("can_id", c_uint),

        ("err", c_uint, 1),

        ("rtr", c_uint, 1),

        ("eff", c_uint, 1),

        ("reserved", c_uint, 29),

        ("can_dlc", c_ubyte),

        ("__pad", c_ubyte * 3),

        ("data", c_ubyte * 8)

    ]


class ZCAN_CANFD_FRAME(Structure):

    _fields_ = [

        ("can_id", c_uint),

        ("err", c_uint, 1),

        ("rtr", c_uint, 1),

        ("eff", c_uint, 1),

        ("brs", c_uint, 1),

        ("esi", c_uint, 1),

        ("reserved", c_uint, 27),

        ("len", c_ubyte),

        ("__pad", c_ubyte * 3),

        ("data", c_ubyte * 64)

    ]


class ZCAN_Transmit_Data(Structure):

    _fields_ = [

        ("frame", ZCAN_CAN_FRAME),

        ("transmit_type", c_uint)

    ]


class ZCAN_Receive_Data(Structure):

    _fields_ = [

        ("frame", ZCAN_CAN_FRAME),

        ("timestamp", c_ulonglong)

    ]


class ZCAN_TransmitFD_Data(Structure):

    _fields_ = [

        ("frame", ZCAN_CANFD_FRAME),

        ("transmit_type", c_uint)

    ]


class ZCAN_ReceiveFD_Data(Structure):

    _fields_ = [

        ("frame", ZCAN_CANFD_FRAME),

        ("timestamp", c_ulonglong)

    ]
# sdk/zlg_sdk.py
# Part 2

class ZlgException(RuntimeError):

    pass


class ZlgSDK:

    def __init__(self):

        self.device_handle = c_uint(0)

        self.channel_handle = c_uint(0)

    def check(self, value):

        if value == 0:

            raise ZlgException("ZLG API ERROR")

    def openDevice(

        self,

        device_type,

        device_index=0,

    ):

        self.device_handle = _zlg.ZCAN_OpenDevice(

            device_type,

            device_index,

            0,

        )

        self.check(self.device_handle)

        return self.device_handle

    def closeDevice(self):

        if self.device_handle:

            _zlg.ZCAN_CloseDevice(

                self.device_handle

            )

            self.device_handle = 0

    def getDeviceInfo(self):

        info = ZCAN_DEVICE_INFO()

        self.check(

            _zlg.ZCAN_GetDeviceInf(

                self.device_handle,

                byref(info)

            )

        )

        return info

    def initCANFD(

        self,

        channel,

        arbitrationTiming,

        dataTiming,

    ):

        cfg = ZCAN_CHANNEL_INIT_CONFIG()

        cfg.can_type = 1

        cfg.config.canfd.mode = 0

        cfg.config.canfd.acc_code = 0

        cfg.config.canfd.acc_mask = 0xFFFFFFFF

        cfg.config.canfd.abit_timing = arbitrationTiming

        cfg.config.canfd.dbit_timing = dataTiming

        cfg.config.canfd.brp = 0

        self.channel_handle = _zlg.ZCAN_InitCAN(

            self.device_handle,

            channel,

            byref(cfg),

        )

        self.check(

            self.channel_handle

        )

        return self.channel_handle

    def startCAN(self):

        self.check(

            _zlg.ZCAN_StartCAN(

                self.channel_handle

            )

        )

    def resetCAN(self):

        _zlg.ZCAN_ResetCAN(

            self.channel_handle

        )

    def clearBuffer(self):

        _zlg.ZCAN_ClearBuffer(

            self.channel_handle

        )

# sdk/zlg_sdk.py
# Part 3

    def transmitFD(

        self,

        packet,

    ):

        return _zlg.ZCAN_TransmitFD(

            self.channel_handle,

            byref(packet),

            1,

        )

    def receiveFD(self):

        packet = ZCAN_ReceiveFD_Data()

        count = _zlg.ZCAN_ReceiveFD(

            self.channel_handle,

            byref(packet),

            1,

            10,

        )

        if count <= 0:

            return None

        return packet

    def setValue(

        self,

        path,

        value,

    ):

        return _zlg.ZCAN_SetValue(

            self.device_handle,

            path.encode(),

            value.encode(),

        )

    def getValue(

        self,

        path,

    ):

        buf = create_string_buffer(

            256

        )

        _zlg.ZCAN_GetValue(

            self.device_handle,

            path.encode(),

            buf,

        )

        return buf.value.decode()

    def close(self):

        try:

            self.resetCAN()

        except Exception:

            pass

        self.closeDevice()


_zlg.ZCAN_OpenDevice.restype = c_uint

_zlg.ZCAN_CloseDevice.restype = c_uint

_zlg.ZCAN_InitCAN.restype = c_uint

_zlg.ZCAN_StartCAN.restype = c_uint

_zlg.ZCAN_ResetCAN.restype = c_uint

_zlg.ZCAN_ClearBuffer.restype = c_uint

_zlg.ZCAN_TransmitFD.restype = c_uint

_zlg.ZCAN_ReceiveFD.restype = c_uint

_zlg.ZCAN_SetValue.restype = c_uint

_zlg.ZCAN_GetValue.restype = c_uint

_zlg.ZCAN_GetDeviceInf.restype = c_uint
