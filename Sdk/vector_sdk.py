# sdk/vector_sdk.py

from __future__ import annotations

from ctypes import *
from pathlib import Path

from app.constants import DLL_PATH

XL_SUCCESS = 0

XL_BUS_TYPE_CAN = 0x00000001

XL_ACTIVATE_RESET_CLOCK = 8

XL_INTERFACE_VERSION_V4 = 4

XL_CAN_EXT_MSG_ID = 0x80000000

XL_CAN_TXMSG_FLAG_EDL = 0x0001
XL_CAN_TXMSG_FLAG_BRS = 0x0002
XL_CAN_TXMSG_FLAG_RTR = 0x0010

DLL = WinDLL(str(DLL_PATH / "vxlapi64.dll"))


XLaccess = c_uint64
XLportHandle = c_long


class XLdriverConfig(Structure):
    _fields_ = [
        ("dummy", c_uint8 * 4096)
    ]


class XLcanTxMsg(Structure):

    _fields_ = [

        ("canId", c_uint32),

        ("msgFlags", c_uint32),

        ("dlc", c_uint8),

        ("reserved", c_uint8 * 7),

        ("data", c_uint8 * 64)

    ]


class XLcanRxMsg(Structure):

    _fields_ = [

        ("canId", c_uint32),

        ("msgFlags", c_uint32),

        ("dlc", c_uint8),

        ("reserved", c_uint8 * 7),

        ("data", c_uint8 * 64)

    ]


class XLcanRxEvent(Structure):

    _fields_ = [

        ("tag", c_uint32),

        ("channelIndex", c_uint32),

        ("userHandle", c_uint32),

        ("flagsChip", c_uint32),

        ("reserved", c_uint32),

        ("timeStamp", c_uint64),

        ("tagData", XLcanRxMsg)

    ]


class VectorSDK:

    def __init__(self):

        self.port = XLportHandle()

        self.mask = XLaccess()

        self.driver = XLdriverConfig()

    def open_driver(self):

        return DLL.xlOpenDriver() == XL_SUCCESS

    def close_driver(self):

        DLL.xlCloseDriver()

    def get_driver_config(self):

        return DLL.xlGetDriverConfig(
            byref(self.driver)
        ) == XL_SUCCESS

    def open_port(
        self,
        app_name: str,
        queue_size: int = 4096
    ):

        return DLL.xlOpenPort(

            byref(self.port),

            app_name.encode(),

            byref(self.mask),

            byref(self.mask),

            queue_size,

            XL_INTERFACE_VERSION_V4,

            XL_BUS_TYPE_CAN

        ) == XL_SUCCESS

    def activate_channel(self):

        return DLL.xlActivateChannel(

            self.port,

            self.mask,

            XL_BUS_TYPE_CAN,

            XL_ACTIVATE_RESET_CLOCK

        ) == XL_SUCCESS

    def deactivate_channel(self):

        DLL.xlDeactivateChannel(
            self.port,
            self.mask
        )

    def close_port(self):

        DLL.xlClosePort(
            self.port
        )

    def transmit(self, msg: XLcanTxMsg):

        count = c_uint(1)

        return DLL.xlCanTransmitEx(

            self.port,

            self.mask,

            count,

            byref(count),

            byref(msg)

        ) == XL_SUCCESS

    def receive(self):

        event = XLcanRxEvent()

        size = c_uint(sizeof(event))

        ret = DLL.xlCanReceive(

            self.port,

            byref(event),

            byref(size)

        )

        if ret != XL_SUCCESS:

            return None

        return event
    