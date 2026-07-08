# sdk/vector_sdk.py
# Part 1

from __future__ import annotations

from ctypes import *
from enum import IntEnum
from pathlib import Path

DLL_PATH = Path(__file__).parent.parent / "dll"

_vxl = WinDLL(str(DLL_PATH / "vxlapi64.dll"))


XLstatus = c_short
XLportHandle = c_long
XLaccess = c_uint64
XLhandle = c_uint


XL_SUCCESS = 0

XL_BUS_TYPE_CAN = 0x00000001

XL_INTERFACE_VERSION_V4 = 4

XL_ACTIVATE_NONE = 0

XL_ACTIVATE_RESET_CLOCK = 8

XL_CAN_EXT_MSG_ID = 0x80000000

XL_CAN_TXMSG_FLAG_EDL = 0x0001
XL_CAN_TXMSG_FLAG_BRS = 0x0002
XL_CAN_TXMSG_FLAG_ESI = 0x0004
XL_CAN_TXMSG_FLAG_RTR = 0x0010

XL_CAN_RXMSG_FLAG_EDL = 0x0001
XL_CAN_RXMSG_FLAG_BRS = 0x0002
XL_CAN_RXMSG_FLAG_ESI = 0x0004
XL_CAN_RXMSG_FLAG_RTR = 0x0010


class XL_BusCapabilities(IntEnum):

    NONE = 0

    CAN = 1

    CANFD = 2

    LIN = 4

    FLEXRAY = 8

    MOST = 16

    ETHERNET = 32


class XLchipState(Structure):

    _fields_ = [

        ("busStatus", c_uint),

        ("txErrorCounter", c_ubyte),

        ("rxErrorCounter", c_ubyte),

        ("reserved", c_ushort)

    ]


class XLchannelConfig(Structure):

    _fields_ = [

        ("name", c_char * 32),

        ("hwType", c_uint),

        ("hwIndex", c_uint),

        ("hwChannel", c_uint),

        ("transceiverType", c_uint),

        ("transceiverState", c_uint),

        ("configError", c_uint),

        ("channelIndex", c_uint),

        ("channelMask", XLaccess),

        ("channelCapabilities", c_uint),

        ("channelBusCapabilities", c_uint),

        ("isOnBus", c_uint),

        ("connectedBusType", c_uint),

        ("busParams", c_uint8 * 64),

        ("driverVersion", c_uint),

        ("interfaceVersion", c_uint),

        ("raw_data", c_uint8 * 128)

    ]


class XLdriverConfig(Structure):

    _fields_ = [

        ("dllVersion", c_uint),

        ("channelCount", c_uint),

        ("reserved", c_uint),

        ("channels", XLchannelConfig * 64)

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

        ("crc", c_uint32),

        ("totalBitCnt", c_uint32),

        ("dlc", c_uint8),

        ("reserved", c_uint8 * 7),

        ("data", c_uint8 * 64)

    ]


class XLcanTxEvent(Structure):

    _fields_ = [

        ("tag", c_uint),

        ("channelIndex", c_uint),

        ("userHandle", c_uint),

        ("flagsChip", c_uint),

        ("reserved", c_uint),

        ("timeStamp", c_uint64),

        ("tagData", XLcanTxMsg)

    ]


class XLcanRxEvent(Structure):

    _fields_ = [

        ("tag", c_uint),

        ("channelIndex", c_uint),

        ("userHandle", c_uint),

        ("flagsChip", c_uint),

        ("reserved", c_uint),

        ("timeStamp", c_uint64),

        ("tagData", XLcanRxMsg)

    ]


class VectorException(RuntimeError):

    pass


class VectorSDK:

    def __init__(self):

        self.port = XLportHandle(-1)

        self.permissionMask = XLaccess()

        self.accessMask = XLaccess()

        self.driverConfig = XLdriverConfig()

    def check(self, status: int):

        if status != XL_SUCCESS:

            raise VectorException(
                f"Vector XL Error : {status}"
            )

    def openDriver(self):

        self.check(

            _vxl.xlOpenDriver()

        )

    def closeDriver(self):

        _vxl.xlCloseDriver()

    def getDriverConfig(self):

        self.check(

            _vxl.xlGetDriverConfig(

                byref(self.driverConfig)

            )

        )

        return self.driverConfig

    def openPort(

        self,

        appName: str,

        queueSize: int = 8192,

    ):

        self.check(

            _vxl.xlOpenPort(

                byref(self.port),

                appName.encode(),

                byref(self.accessMask),

                byref(self.permissionMask),

                queueSize,

                XL_INTERFACE_VERSION_V4,

                XL_BUS_TYPE_CAN

            )

        )

    def closePort(self):

        if self.port.value != -1:

            _vxl.xlClosePort(self.port)

            self.port = XLportHandle(-1)

# sdk/vector_sdk.py
# Part 2

from ctypes import *

XL_CANFD_RX_EVENT_SIZE = sizeof(XLcanRxEvent)
XL_CANFD_TX_EVENT_SIZE = sizeof(XLcanTxEvent)


class VectorSDK(VectorSDK):

    def activateChannel(
        self,
        busType: int = XL_BUS_TYPE_CAN,
    ):

        self.check(

            _vxl.xlActivateChannel(

                self.port,

                self.accessMask,

                busType,

                XL_ACTIVATE_RESET_CLOCK,

            )

        )

    def deactivateChannel(self):

        self.check(

            _vxl.xlDeactivateChannel(

                self.port,

                self.accessMask,

            )

        )

    def resetClock(self):

        self.check(

            _vxl.xlResetClock(

                self.port

            )

        )

    def flushReceiveQueue(self):

        self.check(

            _vxl.xlFlushReceiveQueue(

                self.port

            )

        )

    def getSyncTime(self):

        timestamp = c_uint64()

        self.check(

            _vxl.xlGetSyncTime(

                self.port,

                byref(timestamp),

            )

        )

        return timestamp.value

    def setNotification(self):

        handle = XLhandle()

        self.check(

            _vxl.xlSetNotification(

                self.port,

                byref(handle),

                1,

            )

        )

        return handle.value

    def popupHardwareConfig(self):

        _vxl.xlPopupHwConfig()

    def canTransmitFD(

        self,

        event: XLcanTxEvent,

    ) -> bool:

        count = c_uint(1)

        result = _vxl.xlCanTransmitEx(

            self.port,

            self.accessMask,

            count,

            byref(count),

            byref(event),

        )

        return result == XL_SUCCESS

    def canReceiveFD(self):

        event = XLcanRxEvent()

        size = c_uint(

            sizeof(event)

        )

        result = _vxl.xlCanReceive(

            self.port,

            byref(event),

            byref(size),

        )

        if result != XL_SUCCESS:

            return None

        return event

    def getErrorString(

        self,

        errorCode: int,

    ) -> str:

        ptr = _vxl.xlGetErrorString(

            errorCode

        )

        if not ptr:

            return "Unknown"

        return cast(

            ptr,

            c_char_p,

        ).value.decode(

            errors="ignore"

        )

    def setChannelBitrate(

        self,

        bitrate: int,

    ):

        self.check(

            _vxl.xlCanSetChannelBitrate(

                self.port,

                self.accessMask,

                bitrate,

            )

        )

    def setChannelParamsFD(

        self,

        arbitrationBitrate,

        dataBitrate,

        sjwAbr,

        tseg1Abr,

        tseg2Abr,

        sjwData,

        tseg1Data,

        tseg2Data,

    ):

        self.check(

            _vxl.xlCanFdSetConfiguration(

                self.port,

                self.accessMask,

                arbitrationBitrate,

                dataBitrate,

                sjwAbr,

                tseg1Abr,

                tseg2Abr,

                sjwData,

                tseg1Data,

                tseg2Data,

            )

        )

    def receiveLoop(

        self,

        callback,

    ):

        while True:

            event = self.canReceiveFD()

            if event is None:

                continue

            callback(event)

    def close(self):

        try:

            self.deactivateChannel()

        except Exception:

            pass

        try:

            self.closePort()

        except Exception:

            pass

        try:

            self.closeDriver()

        except Exception:

            pass


_vxl.xlOpenDriver.restype = XLstatus

_vxl.xlCloseDriver.restype = XLstatus

_vxl.xlOpenPort.restype = XLstatus

_vxl.xlClosePort.restype = XLstatus

_vxl.xlActivateChannel.restype = XLstatus

_vxl.xlDeactivateChannel.restype = XLstatus

_vxl.xlCanReceive.restype = XLstatus

_vxl.xlCanTransmitEx.restype = XLstatus

_vxl.xlGetDriverConfig.restype = XLstatus

_vxl.xlResetClock.restype = XLstatus

_vxl.xlGetSyncTime.restype = XLstatus

_vxl.xlCanSetChannelBitrate.restype = XLstatus

_vxl.xlCanFdSetConfiguration.restype = XLstatus

_vxl.xlFlushReceiveQueue.restype = XLstatus

_vxl.xlSetNotification.restype = XLstatus