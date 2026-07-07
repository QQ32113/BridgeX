# sdk/zlg_sdk.py

from __future__ import annotations

from ctypes import *

from app.constants import DLL_PATH


DLL = WinDLL(str(DLL_PATH / "zlgcan.dll"))


class ZCAN_DEVICE_INFO(Structure):

    _fields_ = [

        ("hw_Version", c_ushort),

        ("fw_Version", c_ushort),

        ("dr_Version", c_ushort),

        ("in_Version", c_ushort),

        ("irq_Num", c_ushort),

        ("can_Num", c_ubyte),

        ("serial", c_ubyte * 20),

        ("hw_Type", c_ubyte * 40),

        ("reserved", c_ushort * 4),
    ]


class ZlgSDK:

    def __init__(self):

        self.device = c_uint(0)

    def openDevice(
        self,
        device_type: int,
        device_index: int = 0,
    ) -> bool:

        self.device = DLL.ZCAN_OpenDevice(
            device_type,
            device_index,
            0,
        )

        return self.device != 0

    def closeDevice(self):

        if self.device:

            DLL.ZCAN_CloseDevice(
                self.device
            )

            self.device = 0

    def getDeviceInfo(self):

        info = ZCAN_DEVICE_INFO()

        DLL.ZCAN_GetDeviceInf(
            self.device,
            byref(info)
        )

        return info
