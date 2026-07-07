#ifndef ZLGCAN_H_
#define ZLGCAN_H_

#include <time.h>

#include "canframe.h"
#include "config.h"

#define ZCAN_PCI5121              1
#define ZCAN_PCI9810              2
#define ZCAN_USBCAN1              3
#define ZCAN_USBCAN2              4
#define ZCAN_PCI9820              5
#define ZCAN_CAN232               6
#define ZCAN_PCI5110              7
#define ZCAN_CANLITE              8
#define ZCAN_ISA9620              9
#define ZCAN_ISA5420              10
#define ZCAN_PC104CAN             11
#define ZCAN_CANETUDP             12
#define ZCAN_CANETE               12
#define ZCAN_DNP9810              13
#define ZCAN_PCI9840              14
#define ZCAN_PC104CAN2            15
#define ZCAN_PCI9820I             16
#define ZCAN_CANETTCP             17
#define ZCAN_PCIE_9220            18
#define ZCAN_PCI5010U             19
#define ZCAN_USBCAN_E_U           20
#define ZCAN_USBCAN_2E_U          21
#define ZCAN_PCI5020U             22
#define ZCAN_EG20T_CAN            23
#define ZCAN_PCIE9221             24
#define ZCAN_WIFICAN_TCP          25
#define ZCAN_WIFICAN_UDP          26
#define ZCAN_PCIe9120             27
#define ZCAN_PCIe9110             28
#define ZCAN_PCIe9140             29
#define ZCAN_USBCAN_4E_U          31
#define ZCAN_CANDTU_200UR         32
#define ZCAN_CANDTU_MINI          33
#define ZCAN_USBCAN_8E_U          34
#define ZCAN_CANREPLAY            35
#define ZCAN_CANDTU_NET           36
#define ZCAN_CANDTU_100UR         37
#define ZCAN_PCIE_CANFD_100U      38
#define ZCAN_PCIE_CANFD_200U      39
#define ZCAN_PCIE_CANFD_400U      40
#define ZCAN_USBCANFD_200U        41
#define ZCAN_USBCANFD_100U        42
#define ZCAN_USBCANFD_MINI        43
#define ZCAN_CANFDCOM_100IE       44
#define ZCAN_CANSCOPE             45
#define ZCAN_CLOUD                46
#define ZCAN_CANDTU_NET_400       47
#define ZCAN_CANFDNET_TCP         48
#define ZCAN_CANFDNET_200U_TCP    48
#define ZCAN_CANFDNET_UDP         49
#define ZCAN_CANFDNET_200U_UDP    49
#define ZCAN_CANFDWIFI_TCP        50
#define ZCAN_CANFDWIFI_100U_TCP   50
#define ZCAN_CANFDWIFI_UDP        51
#define ZCAN_CANFDWIFI_100U_UDP   51
#define ZCAN_CANFDNET_400U_TCP    52
#define ZCAN_CANFDNET_400U_UDP    53
#define ZCAN_CANFDBLUE_200U       54
#define ZCAN_CANFDNET_100U_TCP    55
#define ZCAN_CANFDNET_100U_UDP    56
#define ZCAN_CANFDNET_800U_TCP    57
#define ZCAN_CANFDNET_800U_UDP    58
#define ZCAN_USBCANFD_800U        59
#define ZCAN_PCIE_CANFD_100U_EX   60
#define ZCAN_PCIE_CANFD_400U_EX   61
#define ZCAN_PCIE_CANFD_200U_MINI 62
#define ZCAN_PCIE_CANFD_200U_M2   63
#define ZCAN_CANFDDTU_400_TCP     64
#define ZCAN_CANFDDTU_400_UDP     65
#define ZCAN_CANFDWIFI_200U_TCP   66
#define ZCAN_CANFDWIFI_200U_UDP   67
#define ZCAN_CANFDDTU_800ER_TCP   68
#define ZCAN_CANFDDTU_800ER_UDP   69
#define ZCAN_CANFDDTU_800EWGR_TCP 70
#define ZCAN_CANFDDTU_800EWGR_UDP 71
#define ZCAN_CANFDDTU_600EWGR_TCP 72
#define ZCAN_CANFDDTU_600EWGR_UDP 73
#define ZCAN_CANFDDTU_CASCADE_TCP 74
#define ZCAN_CANFDDTU_CASCADE_UDP 75
#define ZCAN_USBCANFD_400U        76
#define ZCAN_CANFDDTU_200U        77
#define ZCAN_ZPSCANFD_TCP         78
#define ZCAN_ZPSCANFD_USB         79
#define ZCAN_CANFDBRIDGE_PLUS     80

#define ZCAN_OFFLINE_DEVICE 98
#define ZCAN_VIRTUAL_DEVICE 99

#define ZCAN_ERROR_CAN_OVERFLOW        0x0001
#define ZCAN_ERROR_CAN_ERRALARM        0x0002
#define ZCAN_ERROR_CAN_PASSIVE         0x0004
#define ZCAN_ERROR_CAN_LOSE            0x0008
#define ZCAN_ERROR_CAN_BUSERR          0x0010
#define ZCAN_ERROR_CAN_BUSOFF          0x0020
#define ZCAN_ERROR_CAN_BUFFER_OVERFLOW 0x0040

#define ZCAN_ERROR_DEVICEOPENED   0x0100
#define ZCAN_ERROR_DEVICEOPEN     0x0200
#define ZCAN_ERROR_DEVICENOTOPEN  0x0400
#define ZCAN_ERROR_BUFFEROVERFLOW 0x0800
#define ZCAN_ERROR_DEVICENOTEXIST 0x1000
#define ZCAN_ERROR_LOADKERNELDLL  0x2000
#define ZCAN_ERROR_CMDFAILED      0x4000
#define ZCAN_ERROR_BUFFERCREATE   0x8000

#define ZCAN_ERROR_CANETE_PORTOPENED 0x00010000
#define ZCAN_ERROR_CANETE_INDEXUSED  0x00020000
#define ZCAN_ERROR_REF_TYPE_ID       0x00030001
#define ZCAN_ERROR_CREATE_SOCKET     0x00030002
#define ZCAN_ERROR_OPEN_CONNECT      0x00030003
#define ZCAN_ERROR_NO_STARTUP        0x00030004
#define ZCAN_ERROR_NO_CONNECTED      0x00030005
#define ZCAN_ERROR_SEND_PARTIAL      0x00030006
#define ZCAN_ERROR_SEND_TOO_FAST     0x00030007

typedef UINT ZCAN_RET_STATUS;
#define STATUS_ERR              0
#define STATUS_OK               1
#define STATUS_ONLINE           2
#define STATUS_OFFLINE          3
#define STATUS_UNSUPPORTED      4
#define STATUS_BUFFER_TOO_SMALL 5

typedef UINT ZCAN_LAST_ERROR_STATUS;
//#define STATUS_NO_ERR                       0
//#define STATUS_NO_ERR                       1

typedef UINT ZCAN_UDS_DATA_DEF;
#define DEF_CAN_UDS_DATA  1  // CAN/CANFD UDSï¿½ï¿½ï¿½ï¿½
#define DEF_LIN_UDS_DATA  2  // LIN UDSï¿½ï¿½ï¿½ï¿½
#define DEF_DOIP_UDS_DATA 3  // DOIP UDSï¿½ï¿½ï¿½ï¿½

#define CMD_DESIP           0
#define CMD_DESPORT         1
#define CMD_CHGDESIPANDPORT 2
#define CMD_SRCPORT         2
#define CMD_TCP_TYPE        4
#define TCP_CLIENT          0
#define TCP_SERVER          1

#define CMD_CLIENT_COUNT       5
#define CMD_CLIENT             6
#define CMD_DISCONN_CLINET     7
#define CMD_SET_RECONNECT_TIME 8

#define TYPE_CAN      0
#define TYPE_CANFD    1
#define TYPE_ALL_DATA 2

// ï¿½ï¿½Ì¬ï¿½ï¿½ï¿½ï¿½ ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½ï¿½ BEGIN
#define ZCAN_DYNAMIC_CONFIG_DEVNAME \
    "DYNAMIC_CONFIG_DEVNAME"  // ï¿½è±¸ï¿½ï¿½ï¿½ï¿½ï¿½î³¤Îª32ï¿½Ö½Ú£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½\0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½CANFDNET -
                              // 200UÄ¬ï¿½ï¿½ÖµÎªï¿½ï¿½CANFDNET - 200Uï¿½ï¿½ï¿½ï¿½CANFDNET -
                              // 100MINIÄ¬ï¿½ï¿½ÖµÎªï¿½ï¿½CANFDNET - 100MINIï¿½ï¿½
// CANï¿½ï¿½Í¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢(CAN%dï¿½ï¿½ï¿½ï¿½Ð¸ï¿½Ê½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½?ï¿½ï¿½ ï¿½ï¿½Î§ï¿½ï¿½0-7)
#define ZCAN_DYNAMIC_CONFIG_CAN_ENABLE \
    "DYNAMIC_CONFIG_CAN%d_ENABLE"  // Í¨ï¿½ï¿½Ê¹ï¿½Ü£ï¿½1ï¿½ï¿½Ê¹ï¿½Ü£ï¿½0ï¿½ï¿½Ê§ï¿½Ü£ï¿½CANFDNETÏµï¿½Ð²ï¿½Æ·Í¨ï¿½ï¿½Ä¬ï¿½ï¿½Ê¹ï¿½Ü¡ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_MODE "DYNAMIC_CONFIG_CAN%d_MODE"  // ï¿½ï¿½ï¿½ï¿½Ä£Ê½ï¿½ï¿½Ä¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£Ê½ï¿½ï¿½0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£Ê½ï¿½ï¿½1ï¿½ï¿½Ö»ï¿½ï¿½Ä£Ê½ï¿½ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_TXATTEMPTS \
    "DYNAMIC_CONFIG_CAN%d_TXATTEMPTS"  // ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½Ç·ï¿½ï¿½Ø´ï¿½ï¿½ï¿½0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê§ï¿½Ü²ï¿½ï¿½Ø´ï¿½1ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½Ø´ï¿½ï¿½ï¿½Ö±ï¿½ï¿½ï¿½ï¿½ï¿½ß¹Ø±Õ£ï¿½CANFDNET
                                       // - 100 / 200ï¿½Þ´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã£ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_NOMINALBAUD     "DYNAMIC_CONFIG_CAN%d_NOMINALBAUD"  // CANï¿½ï¿½ï¿½ï¿½ï¿½Ê»ï¿½CANFDï¿½Ù²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê£ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_DATABAUD        "DYNAMIC_CONFIG_CAN%d_DATABAUD"     // CANFDï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê£ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_USERES          "DYNAMIC_CONFIG_CAN%d_USERES"       // ï¿½Õ¶Ëµï¿½ï¿½è¿ªï¿½Ø£ï¿½0ï¿½ï¿½ï¿½Ø±Õ£ï¿½1ï¿½ï¿½ï¿½ò¿ª¡ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_SNDCFG_INTERVAL "DYNAMIC_CONFIG_CAN%d_SNDCFG_INTERVAL"  // ï¿½ï¿½ï¿½Ä·ï¿½ï¿½Í¼ï¿½ï¿½ï¿½ï¿„1¤7?0~255ms
#define ZCAN_DYNAMIC_CONFIG_CAN_BUSRATIO_ENABLE \
    "DYNAMIC_CONFIG_CAN%d_BUSRATIO_ENABLE"  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¹ï¿½Ü£ï¿½Ê¹ï¿½Üºó£¬½ï¿½ï¿½ï¿½ï¿½Ú·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Êµï¿½ï¿½è¶¨ï¿½ï¿½TCP/UDPï¿½ï¿½ï¿½Ó¡ï¿½1:Ê¹ï¿½Ü£ï¿½0ï¿½ï¿½Ê§ï¿½ï¿½
#define ZCAN_DYNAMIC_CONFIG_CAN_BUSRATIO_PERIOD \
    "DYNAMIC_CONFIG_CAN%d_BUSRATIO_PERIOD"  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê²É¼ï¿½ï¿½ï¿½ï¿½Ú£ï¿½È¡Öµ200~2000ms

typedef struct tagZCAN_DYNAMIC_CONFIG_DATA {
    char key[64];
    char value[64];
} ZCAN_DYNAMIC_CONFIG_DATA;

#define CANFD_FILTER_COUNT_MAX 16
#define CANFD_DATA_LEN_MAX     64

typedef UINT DynamicConfigDataType;
#define DYNAMIC_CONFIG_CAN    0  // CANÍ¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define DYNAMIC_CONFIG_FILTER 1  // ï¿½Ë²ï¿½ï¿½ï¿½ï¿½ï¿½

union unionCANFDFilterRulePresent {
    struct {
        unsigned int bChnl       : 1;   // Í¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bFD         : 1;   // CANFDï¿½ï¿½Ê¶ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bEXT        : 1;   // ï¿½ï¿½×¼Ö¡/ï¿½ï¿½Õ¹Ö¡ï¿½ï¿½Ê¶ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bRTR        : 1;   // ï¿½ï¿½ï¿½ï¿½Ö¡/Ô¶ï¿½ï¿½Ö¡ï¿½ï¿½Ê¶ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bLen        : 1;   // ï¿½ï¿½ï¿½ï¿½  ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bID         : 1;   // ï¿½ï¿½Ê¼ID/ï¿½ï¿½ï¿½ï¿½ID ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bTime       : 1;   // ï¿½ï¿½Ê¼Ê±ï¿½ï¿½/ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bFilterMask : 1;   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý¹ï¿½ï¿½ï¿½/ï¿½ï¿½ï¿½ï¿½ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int bErr        : 1;   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ CAN/CANFDï¿½ï¿½Ö¾ ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
        unsigned int nReserved   : 23;  // ï¿½ï¿½ï¿½ï¿½
    } unionValue;
    unsigned int rawValue;
};

// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë¹ï¿½ï¿½ï¿½
struct CANFD_FILTER_RULE {
    unionCANFDFilterRulePresent presentFlag;  // ï¿½ï¿½Ê¶ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½ï¿„1¤7?
    int                         nErr;  // ï¿½Ç·ï¿½ï¿½ï¿½ï¿½ï¿½Ä£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½Ú£ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö¡ï¿½ï¿½ï¿½Ç´ï¿½ï¿½ï¿½Ö¡ï¿½ï¿„1¤7?0:ï¿½ï¿½ï¿½ï¿½ï¿½Ë´ï¿½ï¿½ï¿½Ö¡
                                       // 1:ï¿½ï¿½ï¿½Ë´ï¿½ï¿½ï¿½Ö¡
    int  nChnl;                        // Í¨ï¿½ï¿½
    int  nFD;                          // CANFDï¿½ï¿½Ê¶ï¿½ï¿½0ï¿½ï¿½CAN; 1:CANFD
    int  nExt;                         // ï¿½ï¿½Õ¹Ö¡ï¿½ï¿½Ê¶ï¿½ï¿½0:ï¿½ï¿½×¼Ö¡ 1:ï¿½ï¿½Õ¹Ö¡
    int  nRtr;                         // Ô¶ï¿½ï¿½Ö¡ï¿½ï¿½Ê¶ï¿½ï¿½0:ï¿½ï¿½ï¿½ï¿½Ö¡ 1:Ô¶ï¿½ï¿½Ö¡
    int  nLen;                         // ï¿½ï¿½ï¿½Ä³ï¿½ï¿½È£ï¿½0-64
    int  nBeginID;                     // ï¿½ï¿½Ê¼ID
    int  nEndID;                       // ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½ï¿½ï¿½Ê¼IDÖµï¿½ï¿½ï¿½ï¿½<=ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¼IDï¿½É¶Ô´ï¿½ï¿½ï¿½
    int  nBeginTime;                   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¼Ê±ï¿½ä£¬ï¿½ï¿½Î»sï¿½ï¿½È¡Öµ0-(24*60*60-1)
    int  nEndTime;                     // ï¿½ï¿½ï¿½Ë½ï¿½ï¿½ï¿½Ê±ï¿½ä£¬ï¿½ï¿½Î»sï¿½ï¿½È¡Öµ0-(24*60*60-1)ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¼Ê±ï¿½ï¿½É¶Ô´ï¿½ï¿½ï¿„1¤7?
    int  nFilterDataLen;
    int  nMaskDataLen;
    BYTE nFilterData[CANFD_DATA_LEN_MAX];  // ï¿½ï¿½ï¿½Ä¹ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½uint8ï¿½ï¿½ï¿½é£¬ï¿½î³¤64
    BYTE nMaskData[CANFD_DATA_LEN_MAX];    // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½uint8ï¿½ï¿½ï¿½é£¬ï¿½î³¤64ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³É¶Ô´ï¿½ï¿½ï¿„1¤7?
};

typedef UINT enumCANFDFilterBlackWhiteList;
#define CANFD_FILTER_BLACK_LIST 0  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define CANFD_FILTER_WHITE_LIST 1  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

struct CANFD_FILTER_CFG {
    int                           bEnable;
    enumCANFDFilterBlackWhiteList enBlackWhiteList;
    CANFD_FILTER_RULE             vecFilters[CANFD_FILTER_COUNT_MAX];
};

// Ä¿Ç°Ö»ï¿½ï¿½ï¿½Ë²ï¿½Ê¹ï¿½Ã¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½É¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£ï¿½ï¿½
typedef struct tagZCAN_DYNAMIC_CONFIG {
    DynamicConfigDataType dynamicConfigDataType;
    UINT                  isPersist;  // ï¿½Ç·ï¿½ï¿½Ç³Ö¾ï¿½ï¿½ï¿½ï¿½Ã£ï¿½ï¿½ï¿½ï¿½è±¸ï¿½ï¿½ï¿½ç±£ï¿½ï¿½ï¿½ï¿½ï¿½Ã£ï¿½ï¿½ï¿½TRUE-ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½ï¿½
                                      // FALSE-ï¿½ï¿½Ì¬ï¿½ï¿½ï¿½ï¿½
    union {
        CANFD_FILTER_CFG
        filterCfg;                 // dynamicConfigDataType = DYNAMIC_CONFIG_FILTERÊ±ï¿½ï¿½Ð§
        BYTE reserved[10 * 1024];  // ï¿½ï¿½ï¿½ï¿½
    } data;
} ZCAN_DYNAMIC_CONFIG;
// ï¿½ï¿½Ì¬ï¿½ï¿½ï¿½ï¿½ ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½ï¿½ END

typedef void *DEVICE_HANDLE;
typedef void *CHANNEL_HANDLE;

typedef struct tagZCAN_DEVICE_INFO {
    USHORT hw_Version;  // Ó²ï¿½ï¿½ï¿½æ±¾
    USHORT fw_Version;  // ï¿½Ì¼ï¿½ï¿½æ±¾
    USHORT dr_Version;  // ï¿½ï¿½ï¿½ï¿½ï¿½æ±¾
    USHORT in_Version;  // ï¿½ï¿½Ì¬ï¿½ï¿½ï¿„1¤7?
    USHORT irq_Num;
    BYTE   can_Num;
    UCHAR  str_Serial_Num[20];
    UCHAR  str_hw_Type[40];
    USHORT reserved[4];
} ZCAN_DEVICE_INFO;

typedef struct {
    UINT acc_code;
    UINT acc_mask;
    UINT reserved;
    BYTE filter;
    BYTE timing0;
    BYTE timing1;
    BYTE mode;
} ZCAN_CHANNEL_INIT_CONFIG_INFO_CAN;

typedef struct {
    UINT   acc_code;
    UINT   acc_mask;
    UINT   abit_timing;
    UINT   dbit_timing;
    UINT   brp;
    BYTE   filter;
    BYTE   mode;
    USHORT pad;
    UINT   reserved;
} ZCAN_CHANNEL_INIT_CONFIG_INFO_CANFD;


typedef union {
   ZCAN_CHANNEL_INIT_CONFIG_INFO_CAN  can;
   ZCAN_CHANNEL_INIT_CONFIG_INFO_CANFD canfd;
}ZCAN_CHANNEL_INIT_CONFIG_INFO;

typedef struct tagZCAN_CHANNEL_INIT_CONFIG {
    UINT can_type;  // type:TYPE_CAN
                    // TYPE_CANFDï¿½ï¿½can_typeï¿½ï¿½ï¿½è±¸ï¿½ï¿½ï¿½ï¿½Ö»È¡ï¿½ï¿½ï¿½Ú²ï¿½Æ·Ó²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½CANFDÏµï¿½ÐµÄ²ï¿½Æ·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Îª1ï¿½ï¿½ï¿½ï¿½Ê¾CANFDï¿½è±¸ï¿½ï¿½
    ZCAN_CHANNEL_INIT_CONFIG_INFO info;
} ZCAN_CHANNEL_INIT_CONFIG;

typedef struct tagZCAN_CHANNEL_ERR_INFO {
    UINT error_code;
    BYTE passive_ErrData[3];
    BYTE arLost_ErrData;
} ZCAN_CHANNEL_ERR_INFO;

typedef struct tagZCAN_CHANNEL_STATUS {
    BYTE errInterrupt;
    BYTE regMode;
    BYTE regStatus;
    BYTE regALCapture;
    BYTE regECCapture;
    BYTE regEWLimit;
    BYTE regRECounter;
    BYTE regTECounter;
    UINT Reserved;
} ZCAN_CHANNEL_STATUS;

typedef struct tagZCAN_Transmit_Data {
    can_frame frame;
    UINT      transmit_type;
} ZCAN_Transmit_Data;

typedef struct tagZCAN_Receive_Data {
    can_frame frame;
    UINT64    timestamp;  // us
} ZCAN_Receive_Data;

typedef struct tagZCAN_TransmitFD_Data {
    canfd_frame frame;
    UINT        transmit_type;
} ZCAN_TransmitFD_Data;

typedef struct tagZCAN_ReceiveFD_Data {
    canfd_frame frame;
    UINT64      timestamp;  // us
} ZCAN_ReceiveFD_Data;

typedef struct tagZCAN_AUTO_TRANSMIT_OBJ {
    USHORT             enable;
    USHORT             index;     // 0...n
    UINT               interval;  // ms
    ZCAN_Transmit_Data obj;
} ZCAN_AUTO_TRANSMIT_OBJ, *PZCAN_AUTO_TRANSMIT_OBJ;

typedef struct tagZCANFD_AUTO_TRANSMIT_OBJ {
    USHORT               enable;
    USHORT               index;     // 0...n
    UINT                 interval;  // ms
    ZCAN_TransmitFD_Data obj;
} ZCANFD_AUTO_TRANSMIT_OBJ, *PZCANFD_AUTO_TRANSMIT_OBJ;

// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã¶ï¿½Ê±ï¿½ï¿½ï¿½Í¶ï¿½ï¿½ï¿½Ä²ï¿½ï¿½ï¿½ï¿½ï¿½Ä¿Ç°Ö»Ö§ï¿½ï¿½USBCANFD-X00UÏµï¿½ï¿½ï¿½è±¸
typedef struct tagZCAN_AUTO_TRANSMIT_OBJ_PARAM {
    USHORT index;  // ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½Ö¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    USHORT type;   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½Ä¿Ç°ï¿½ï¿½ï¿½ï¿½Ö»ï¿½ï¿½1ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±
    UINT   value;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ
} ZCAN_AUTO_TRANSMIT_OBJ_PARAM, *PZCAN_AUTO_TRANSMIT_OBJ_PARAM;

// for zlg cloud
#define ZCLOUD_MAX_DEVICES 100
#define ZCLOUD_MAX_CHANNEL 16

typedef struct tagZCLOUD_CHNINFO {
    BYTE enable;  // 0:disableï¿½ï¿½1:enable
    BYTE type;    // 0:CANï¿½ï¿½1:ISO CANFDï¿½ï¿½2:Non-ISO CANFD
    BYTE isUpload;
    BYTE isDownload;
} ZCLOUD_CHNINFO;

typedef struct tagZCLOUD_DEVINFO {
    int            devIndex;
    char           type[64];
    char           id[64];
    char           name[64];
    char           owner[64];
    char           model[64];
    char           fwVer[16];
    char           hwVer[16];
    char           serial[64];
    int            status;  // 0:onlineï¿½ï¿½1:offline
    BYTE           bGpsUpload;
    BYTE           channelCnt;
    ZCLOUD_CHNINFO channels[ZCLOUD_MAX_CHANNEL];
} ZCLOUD_DEVINFO;

typedef struct tagZCLOUD_USER_DATA {
    char           username[64];
    char           mobile[64];
    char           dllVer[16];  // cloud dll version
    size_t         devCnt;
    ZCLOUD_DEVINFO devices[ZCLOUD_MAX_DEVICES];
} ZCLOUD_USER_DATA;

// GPS
typedef struct tagZCLOUD_GPS_FRAME {
    float latitude;   // + north latitudeï¿½ï¿½- south latitude
    float longitude;  // + east longitudeï¿½ï¿½- west longitude
    float speed;      // km/h
    struct __gps_time {
        USHORT year;
        USHORT mon;
        USHORT day;
        USHORT hour;
        USHORT min;
        USHORT sec;
    } tm;
} ZCLOUD_GPS_FRAME;
// for zlg cloud

// TX timestamp
typedef struct tagUSBCANFDTxTimeStamp {
    UINT *pTxTimeStampBuffer;    // allocated by user, size:nBufferTimeStampCount *
                                 // 4,unit:100us
    UINT nBufferTimeStampCount;  // buffer size
} USBCANFDTxTimeStamp;

typedef struct tagTxTimeStamp {
    UINT64 *pTxTimeStampBuffer;  // allocated by user, size:nBufferTimeStampCount *
                                 // 8,unit:1us
    UINT nBufferTimeStampCount;  // buffer timestamp count
    int  nWaitTime;              // Wait Time ms, -1ï¿½ï¿½Ê¾ï¿½Èµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý²Å·ï¿½ï¿½ï¿½
} TxTimeStamp;

// Bus usage
typedef struct tagBusUsage {
    UINT64 nTimeStampBegin;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¼Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»us
    UINT64 nTimeStampEnd;    // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»us
    BYTE   nChnl;            // Í¨ï¿½ï¿½
    BYTE   nReserved;        // ï¿½ï¿½ï¿½ï¿½
    USHORT
    nBusUsage;         // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½(%)ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½*100Õ¹Ê¾ï¿½ï¿½È¡Öµ0~10000ï¿½ï¿½ï¿½ï¿½8050ï¿½ï¿½Ê¾80.50%
    UINT nFrameCount;  // Ö¡ï¿½ï¿½ï¿½ï¿½
} BusUsage;

enum eZCANErrorDEF {
    // ï¿½ï¿½ï¿½ß´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_ERR_TYPE_NO_ERR         = 0,  // ï¿½Þ´ï¿½ï¿½ï¿½
    ZCAN_ERR_TYPE_BUS_ERR        = 1,  // ï¿½ï¿½ï¿½ß´ï¿½ï¿½ï¿½
    ZCAN_ERR_TYPE_CONTROLLER_ERR = 2,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_ERR_TYPE_DEVICE_ERR     = 3,  // ï¿½Õ¶ï¿½ï¿½è±¸ï¿½ï¿½ï¿½ï¿½

    // ï¿½Úµï¿½×´Ì¬
    ZCAN_NODE_STATE_ACTIVE   = 1,  // ï¿½ï¿½ï¿½ß»ï¿½ï¿½ï¿½
    ZCAN_NODE_STATE_WARNNING = 2,  // ï¿½ï¿½ï¿½ß¸æ¾¯
    ZCAN_NODE_STATE_PASSIVE  = 3,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_NODE_STATE_BUSOFF   = 4,  // ï¿½ï¿½ï¿½ß¹Ø±ï¿½

    // ï¿½ï¿½ï¿½ß´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½, errType = ZCAN_ERR_TYPE_BUS_ERR
    ZCAN_BUS_ERR_NO_ERR           = 0,  // ï¿½Þ´ï¿½ï¿½ï¿½
    ZCAN_BUS_ERR_BIT_ERR          = 1,  // Î»ï¿½ï¿½ï¿½ï¿½
    ZCAN_BUS_ERR_ACK_ERR          = 2,  // Ó¦ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    ZCAN_BUS_ERR_CRC_ERR          = 3,  // CRCï¿½ï¿½ï¿½ï¿½
    ZCAN_BUS_ERR_FORM_ERR         = 4,  // ï¿½ï¿½Ê½ï¿½ï¿½ï¿½ï¿½
    ZCAN_BUS_ERR_STUFF_ERR        = 5,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_BUS_ERR_OVERLOAD_ERR     = 6,  // ï¿½ï¿½ï¿½Ø´ï¿½ï¿½ï¿½
    ZCAN_BUS_ERR_ARBITRATION_LOST = 7,  // ï¿½Ù²Ã¶ï¿½Ê§
    ZCAN_BUS_ERR_NODE_STATE_CHAGE = 8,  // ï¿½ï¿½ï¿½ß½Úµï¿½ï¿„1¤7?

    // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½, errType = ZCAN_ERR_TYPE_CONTROLLER_ERR
    ZCAN_CONTROLLER_RX_FIFO_OVERFLOW          = 1,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½FIFOï¿½ï¿½ï¿„1¤7?
    ZCAN_CONTROLLER_DRIVER_RX_BUFFER_OVERFLOW = 2,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Õ»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    ZCAN_CONTROLLER_DRIVER_TX_BUFFER_OVERFLOW = 3,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    ZCAN_CONTROLLER_INTERNAL_ERROR            = 4,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ú²ï¿½ï¿½ï¿½ï¿½ï¿½

    // ï¿½Õ¶ï¿½ï¿½è±¸ï¿½ï¿½ï¿½ï¿½, errType = ZCAN_ERR_TYPE_DEVICE_ERR
    ZCAN_DEVICE_APP_RX_BUFFER_OVERFLOW = 1,  // ï¿½Õ¶ï¿½Ó¦ï¿½Ã½ï¿½ï¿½Õ»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    ZCAN_DEVICE_APP_TX_BUFFER_OVERFLOW = 2,  // ï¿½Õ¶ï¿½Ó¦ï¿½Ã·ï¿½ï¿½Í»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    ZCAN_DEVICE_APP_AUTO_SEND_FAILED   = 3,  // ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½
    ZCAN_CONTROLLER_TX_FRAME_INVALID   = 4,  // ï¿½ï¿½ï¿½Í±ï¿½ï¿½ï¿½ï¿½ï¿½Ð§
};

enum eZCANDataDEF {
    // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_CAN_CANFD_DATA = 1,  // CAN/CANFDï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_ERROR_DATA     = 2,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_GPS_DATA       = 3,  // GPSï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_LIN_DATA       = 4,  // LINï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_BUSUSAGE_DATA  = 5,  // BusUsageï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_LIN_ERROR_DATA = 6,  // LINï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_LIN_EX_DATA    = 7,  // LINï¿½ï¿½Õ¹ï¿½ï¿½ï¿½ï¿½
    ZCAN_DT_ZCAN_LIN_EVENT_DATA = 8,  // LINï¿½Â¼ï¿½ï¿½ï¿½ï¿½ï¿½

    // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Î»
    ZCAN_TX_DELAY_NO_DELAY   = 0,  // ï¿½Þ·ï¿½ï¿½ï¿½ï¿½ï¿½Ê±
    ZCAN_TX_DELAY_UNIT_MS    = 1,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Î»ï¿½ï¿½ï¿½ï¿½
    ZCAN_TX_DELAY_UNIT_100US = 2,  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Î»100Î¢ï¿½ï¿½(0.1ï¿½ï¿½ï¿½ï¿½)
};

#pragma pack(push, 1)

// CAN/CANFDï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANCANFDData {
    UINT64
    timeStamp;  // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Î»ï¿½?ï¿½ï¿½(us)ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿½Ýµï¿½Î»È¡ï¿½ï¿½ï¿½ï¿½flag.unionVal.txDelay
    union {
        struct {
            UINT frameType : 2;     // Ö¡ï¿½ï¿½ï¿½Í£ï¿½0:CANÖ¡ï¿½ï¿½1:CANFDÖ¡
            UINT txDelay   : 2;     // ï¿½ï¿½ï¿½Ð·ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð§.
                                    // 0:ï¿½Þ·ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½1:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Î»msï¿½ï¿½2:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Î»100us.
                                    // ï¿½ï¿½ï¿½Ã¶ï¿½ï¿½Ð·ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½Ê±Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½timeStampï¿½Ö¶ï¿½
            UINT transmitType : 4;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð§.
                                    // 0:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½1:ï¿½ï¿½ï¿½Î·ï¿½ï¿½Í£ï¿½2:ï¿½Ô·ï¿½ï¿½ï¿½ï¿½Õ£ï¿½3:ï¿½ï¿½ï¿½ï¿½ï¿½Ô·ï¿½ï¿½ï¿½ï¿½ï¿½.
                                    // ï¿½ï¿½ï¿½ï¿½ï¿½è±¸Ö§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î¿ï¿½ï¿½ï¿½ï¿½ï¿½Ê¹ï¿½ï¿½ï¿½Ö²ï¿„1¤7?
            UINT
                txEchoRequest : 1;  // ï¿½ï¿½ï¿½Í»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ó£¬·ï¿½ï¿½ï¿½ï¿½ï¿½Ð§.
                                    // Ö§ï¿½Ö·ï¿½ï¿½Í»ï¿½ï¿½Ôµï¿½ï¿½è±¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½Î»ï¿½ï¿½1ï¿½ï¿½ï¿½è±¸ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½ï¿½ï¿½ï¿½Õ½Ó¿Ú½ï¿½ï¿½ï¿½ï¿½Í³ï¿½È¥ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö¡ï¿½ï¿½ï¿½Ø£ï¿½ï¿½ï¿½ï¿½Õµï¿½ï¿½Ä·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¹ï¿½ï¿½txEchoedÎ»ï¿½ï¿½ï¿„1¤7?
            UINT txEchoed : 1;      // ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½Ç»ï¿½ï¿½Ô±ï¿½ï¿½Ä£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð§.
                                    // 0:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ß½ï¿½ï¿½Õ±ï¿½ï¿½Ä£ï¿½1:ï¿½ï¿½ï¿½è±¸ï¿½ï¿½ï¿½Í»ï¿½ï¿½Ô±ï¿½ï¿½ï¿½.
            UINT reserved : 22;     // ï¿½ï¿½ï¿½ï¿½
        } unionVal;
        UINT rawVal;           // Ö¡ï¿½ï¿½Ö¾Î»rawï¿½ï¿½ï¿½ï¿½
    } flag;                    // CAN/CANFDÖ¡ï¿½ï¿½Ö¾Î»
    BYTE        extraData[4];  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½,ï¿½ï¿½Î´Ê¹ï¿½ï¿½
    canfd_frame frame;         // CAN/CANFDÖ¡ID+ï¿½ï¿½ï¿½ï¿½
} ZCANCANFDData;

// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANErrorData {
    UINT64 timeStamp;   // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»ï¿½?ï¿½ï¿½(us)
    BYTE   errType;     // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½ï¿½Î¿ï¿½eZCANErrorDEFï¿½ï¿½ ï¿½ï¿½ï¿½ß´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½Öµï¿½ï¿½ï¿½ï¿½
    BYTE   errSubType;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½ï¿½Î¿ï¿½eZCANErrorDEFï¿½ï¿½ ï¿½ï¿½ï¿½ß´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½Öµï¿½ï¿½ï¿½ï¿½
    BYTE   nodeState;   // ï¿½Úµï¿½×´Ì¬ï¿½ï¿½ï¿½Î¿ï¿½eZCANErrorDEFï¿½ï¿½ ï¿½Úµï¿½×´Ì¬ ï¿½ï¿½ï¿½ï¿½Öµï¿½ï¿½ï¿½ï¿½
    BYTE   rxErrCount;  // ï¿½ï¿½ï¿½Õ´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    BYTE   txErrCount;  // ï¿½ï¿½ï¿½Í´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    BYTE   errData;     // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½Íµï¿½Ç°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¶ï¿½ï¿½ï¿½Ä¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?,
                        // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î¿ï¿½Ê¹ï¿½ï¿½ï¿½Ö²ï¿„1¤7?
    BYTE reserved[2];   // ï¿½ï¿½ï¿½ï¿½
} ZCANErrorData;

// GPSï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANGPSData {
    struct {
        USHORT year;    // ï¿½ï¿½
        USHORT mon;     // ï¿½ï¿½
        USHORT day;     // ï¿½ï¿½
        USHORT hour;    // Ê±
        USHORT min;     // ï¿½ï¿½
        USHORT sec;     // ï¿½ï¿½
        USHORT milsec;  // ï¿½ï¿½ï¿½ï¿½
    } time;             // UTCÊ±ï¿½ï¿½
    union {
        struct {
            USHORT timeValid        : 1;   // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½Ð§
            USHORT latlongValid     : 1;   // ï¿½ï¿½Î³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½Ð§
            USHORT altitudeValid    : 1;   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½Ð§
            USHORT speedValid       : 1;   // ï¿½Ù¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½Ð§
            USHORT courseAngleValid : 1;   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½ï¿½?
            USHORT reserved         : 13;  // ï¿½ï¿½ï¿½ï¿½
        } unionVal;
        USHORT rawVal;
    } flag;              // ï¿½ï¿½Ö¾ï¿½ï¿½Ï¢
    double latitude;     // Î³ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Î³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Î³
    double longitude;    // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½
    double altitude;     // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½Î»: ï¿½ï¿½
    double speed;        // ï¿½Ù¶ï¿½ ï¿½ï¿½Î»: km/h
    double courseAngle;  // ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
} ZCANGPSData;

// LINï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANLINData {
    union {
        struct {
            BYTE ID     : 6;  // Ö¡ID
            BYTE Parity : 2;  // Ö¡IDÐ£ï¿½ï¿½
        } unionVal;
        BYTE rawVal;  // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½IDÔ­Ê¼Öµ
    } PID;            // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½ID
    struct {
        UINT64 timeStamp;     // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»ï¿½?ï¿½ï¿½(us)
        BYTE   dataLen;       // ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½
        BYTE   dir;           // ï¿½ï¿½ï¿½ä·½ï¿½ï¿½0-ï¿½ï¿½ï¿½ï¿½ 1-ï¿½ï¿½ï¿½ï¿½
        BYTE   chkSum;        // ï¿½ï¿½ï¿½ï¿½Ð£ï¿½é£¬ï¿½ï¿½ï¿½ï¿½ï¿½è±¸ï¿½ï¿½Ö§ï¿½ï¿½Ð£ï¿½ï¿½ï¿½ï¿½ï¿½ÝµÄ»ï¿½È¡
        BYTE   reserved[13];  // ï¿½ï¿½ï¿½ï¿½
        BYTE   data[8];       // ï¿½ï¿½ï¿½ï¿½
    } RxData;                 // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Ð§
    BYTE reserved[7];         // ï¿½ï¿½ï¿½ï¿½
} ZCANLINData;

// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANLINErrData {
    UINT64 timeStamp;  // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»ï¿½?ï¿½ï¿½(us)
    union {
        struct {
            BYTE ID     : 6;  // Ö¡ID
            BYTE Parity : 2;  // Ö¡IDÐ£ï¿½ï¿½
        } unionVal;
        BYTE rawVal;  // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½IDÔ­Ê¼Öµ
    } PID;            // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½ID
    BYTE dataLen;
    BYTE data[8];
    union {
        struct {
            USHORT errStage  : 4;  // ï¿½ï¿½ï¿½ï¿½×¶ï¿„1¤7?
            USHORT errReason : 4;  // ï¿½ï¿½ï¿½ï¿½Ô­ï¿½ï¿½
            USHORT reserved  : 8;  // ï¿½ï¿½ï¿½ï¿½
        };
        USHORT unionErrData;
    } errData;
    BYTE dir;           // ï¿½ï¿½ï¿½ä·½ï¿½ï¿½
    BYTE chkSum;        // ï¿½ï¿½ï¿½ï¿½Ð£ï¿½é£¬ï¿½ï¿½ï¿½ï¿½ï¿½è±¸ï¿½ï¿½Ö§ï¿½ï¿½Ð£ï¿½ï¿½ï¿½ï¿½ï¿½ÝµÄ»ï¿½È¡
    BYTE reserved[10];  // ï¿½ï¿½ï¿½ï¿½
} ZCANLINErrData;

typedef BYTE ZCAN_LIN_EVENT_TYPE;
#define ZCAN_LIN_WAKE_UP            1
#define ZCAN_LIN_ENTERED_SLEEP_MODE 2
#define ZCAN_LIN_EXITED_SLEEP_MODE  3

typedef struct tagZCANLINEventData {
    UINT64              timeStamp;  // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»ï¿½?ï¿½ï¿½(us)
    ZCAN_LIN_EVENT_TYPE type;
    BYTE                reserved[7];
} ZCANLINEventData;

// LINï¿½ï¿½Õ¹ï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANLINExData {
    union {
        struct {
            BYTE ID     : 6;  // Ö¡ID
            BYTE Parity : 2;  // Ö¡IDÐ£ï¿½ï¿½
        } unionVal;
        BYTE rawVal;   // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½IDÔ­Ê¼Öµ
    } PID;             // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½ID
    BYTE reserved[7];  // ï¿½ï¿½ï¿½ï¿½
    struct {
        UINT64 timeStamp;    // Ê±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»ï¿½?ï¿½ï¿½(us)
        BYTE   dataLen;      // ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½
        BYTE   dir;          // ï¿½ï¿½ï¿½ä·½ï¿½ï¿½0-ï¿½ï¿½ï¿½ï¿½ 1-ï¿½ï¿½ï¿½ï¿½
        BYTE   chkSum;       // ï¿½ï¿½ï¿½ï¿½Ð£ï¿½é£¬ï¿½ï¿½ï¿½ï¿½ï¿½è±¸ï¿½ï¿½Ö§ï¿½ï¿½Ð£ï¿½ï¿½ï¿½ï¿½ï¿½ÝµÄ»ï¿½È¡
        BYTE   reserved[5];  // ï¿½ï¿½ï¿½ï¿½
        BYTE   data[64];     // ï¿½ï¿½ï¿½ï¿½
    } RxData;                // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Ð§
} ZCANLINExData;

// ï¿½Ï²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý½á¹¹ï¿½ï¿½Ö§ï¿½ï¿½CAN/CANFD/LIN/GPS/ï¿½ï¿½ï¿½ï¿½È²ï¿½ï¿½?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANDataObj {
    BYTE dataType;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½ï¿½Î¿ï¿½eZCANDataDEFï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ö¶ï¿½ï¿½ï¿½
    BYTE chnl;      // ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½
    union {
        struct {
            USHORT reserved : 16;  // ï¿½ï¿½ï¿½ï¿½
        } unionVal;
        USHORT rawVal;
    } flag;             // ï¿½ï¿½Ö¾ï¿½ï¿½Ï¢ï¿½ï¿½ï¿½ï¿½Î´Ê¹ï¿½ï¿½
    BYTE extraData[4];  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î´Ê¹ï¿½ï¿½
    union {
        ZCANCANFDData    zcanCANFDData;     // CAN/CANFDï¿½ï¿½ï¿½ï¿½
        ZCANErrorData    zcanErrData;       // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        ZCANGPSData      zcanGPSData;       // GPSï¿½ï¿½ï¿½ï¿½
        ZCANLINData      zcanLINData;       // LINï¿½ï¿½ï¿½ï¿½
        ZCANLINErrData   zcanLINErrData;    // LINï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        ZCANLINExData    zcanLINExData;     // LINï¿½ï¿½Õ¹ï¿½ï¿½ï¿½ï¿½
        ZCANLINEventData zcanLINEventData;  // LINï¿½Â¼ï¿½ï¿½ï¿½ï¿½ï¿½
        BusUsage         busUsage;          // BusUsageï¿½ï¿½ï¿½ï¿½
        BYTE             raw[92];           // RAWï¿½ï¿½ï¿½ï¿½
    } data;                                 // Êµï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½å£¬ï¿½ï¿½Ð§ï¿½ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ dataType ï¿½Ö¶Î¶ï¿½ï¿½ï¿½
} ZCANDataObj;

// LIN
typedef struct _VCI_LIN_MSG {
    BYTE chnl;      // ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½
    BYTE dataType;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½0-LINï¿½ï¿½ï¿½ï¿½ 1-LINï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ 2-LINï¿½Â¼ï¿½ï¿½ï¿½ï¿½ï¿½
    union {
        ZCANLINData      zcanLINData;       // LINï¿½ï¿½ï¿½ï¿½
        ZCANLINErrData   zcanLINErrData;    // LINï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        ZCANLINEventData zcanLINEventData;  // LINï¿½Â¼ï¿½ï¿½ï¿½ï¿½ï¿½
        BYTE             raw[46];           // RAWï¿½ï¿½ï¿½ï¿½
    } data;                                 // Êµï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½å£¬ï¿½ï¿½Ð§ï¿½ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ dataType ï¿½Ö¶Î¶ï¿½ï¿½ï¿½
} ZCAN_LIN_MSG, *PZCAN_LIN_MSG;

enum eZLINChkSumMode {
    DEFAULT = 0,     // Ä¬ï¿½Ï£ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½
    CLASSIC_CHKSUM,  // ï¿½ï¿½ï¿½ï¿½Ð£ï¿½ï¿½
    ENHANCE_CHKSUM,  // ï¿½ï¿½Ç¿Ð£ï¿½ï¿½
    AUTOMATIC,       // ï¿½Ô¶ï¿½ï¿½ï¿½ï¿½è±¸ï¿½Ô¶ï¿½Ê¶ï¿½ï¿½Ð£ï¿½é·½Ê½ï¿½ï¿½ï¿½ï¿½ZCAN_SetLINSubscribeÊ±ï¿½ï¿½Ð§ï¿½ï¿½
};

typedef struct _VCI_LIN_INIT_CONFIG {
    BYTE linMode;     // ï¿½Ç·ï¿½ï¿½ï¿½Îªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0-ï¿½Ó»ï¿½ï¿½ï¿½1-ï¿½ï¿½ï¿½ï¿½
    BYTE chkSumMode;  // Ð£ï¿½é·½Ê½ï¿½ï¿½1-ï¿½ï¿½ï¿½ï¿½Ð£ï¿½ï¿½ 2-ï¿½ï¿½Ç¿Ð£ï¿½ï¿½ 3-ï¿½Ô¶ï¿½(ï¿½ï¿½Ó¦eZLINChkSumModeï¿½ï¿½Ä£Ê½)
    BYTE maxLength;   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿„1¤7?8~64
    BYTE reserved;    // ï¿½ï¿½ï¿½ï¿½
    UINT linBaud;     // ï¿½ï¿½ï¿½ï¿½ï¿½Ê£ï¿½È¡Öµ1000~20000
} ZCAN_LIN_INIT_CONFIG, *PZCAN_LIN_INIT_CONFIG;

typedef struct _VCI_LIN_PUBLISH_CFG {
    BYTE ID;       // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½IDÈ¡Öµï¿½ï¿½Î§Îª0-63ï¿½ï¿½
    BYTE dataLen;  // dataLenï¿½ï¿½Î§Îª1-8
    BYTE data[8];
    BYTE chkSumMode;   // Ð£ï¿½é·½Ê½ï¿½ï¿½0-Ä¬ï¿½Ï£ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ 1-ï¿½ï¿½ï¿½ï¿½Ð£ï¿½ï¿½
                       // 2-ï¿½ï¿½Ç¿Ð£ï¿½ï¿½(ï¿½ï¿½Ó¦eZLINChkSumModeï¿½ï¿½Ä£Ê½)
    BYTE reserved[5];  // ï¿½ï¿½ï¿½ï¿½
} ZCAN_LIN_PUBLISH_CFG, *PZCAN_LIN_PUBLISH_CFG;

typedef struct _VCI_LIN_PUBLISH_CFG_EX {
    BYTE ID;       // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½IDÈ¡Öµï¿½ï¿½Î§Îª0-63ï¿½ï¿½
    BYTE dataLen;  // dataLenï¿½ï¿½Î§Îª1-64
    BYTE data[64];
    BYTE chkSumMode;   // Ð£ï¿½é·½Ê½ï¿½ï¿½0-Ä¬ï¿½Ï£ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ 1-ï¿½ï¿½ï¿½ï¿½Ð£ï¿½ï¿½
                       // 2-ï¿½ï¿½Ç¿Ð£ï¿½ï¿½(ï¿½ï¿½Ó¦eZLINChkSumModeï¿½ï¿½Ä£Ê½)
    BYTE reserved[5];  // ï¿½ï¿½ï¿½ï¿½
} ZCAN_LIN_PUBLISH_CFG_EX, *PZCAN_LIN_PUBLISH_CFG_EX;

typedef struct _VCI_LIN_SUBSCIBE_CFG {
    BYTE ID;           // ï¿½Ü±ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½IDÈ¡Öµï¿½ï¿½Î§Îª0-63ï¿½ï¿½
    BYTE dataLen;      // dataLenï¿½ï¿½Î§Îª1-8 ï¿½ï¿½Îª255ï¿½ï¿½0xffï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½è±¸ï¿½Ô¶ï¿½Ê¶ï¿½ï¿½ï¿½Ä³ï¿½ï¿½ï¿„1¤7?
    BYTE chkSumMode;   // Ð£ï¿½é·½Ê½ï¿½ï¿½0-Ä¬ï¿½Ï£ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ 1-ï¿½ï¿½ï¿½ï¿½Ð£ï¿½ï¿½ 2-ï¿½ï¿½Ç¿Ð£ï¿½ï¿½
                       // 3-ï¿½Ô¶ï¿½(ï¿½ï¿½Ó¦eZLINChkSumModeï¿½ï¿½Ä£Ê½)
    BYTE reserved[5];  // ï¿½ï¿½ï¿½ï¿½
} ZCAN_LIN_SUBSCIBE_CFG, *PZCAN_LIN_SUBSCIBE_CFG;

// end LIN

// UDSï¿½ï¿½ï¿½ï¿½Ð­ï¿½ï¿½ï¿„1¤7?
typedef BYTE ZCAN_UDS_TRANS_VER;
#define ZCAN_UDS_TRANS_VER_0 0  // ISO15765-2(2004ï¿½æ±¾)
#define ZCAN_UDS_TRANS_VER_1 1  // ISO15765-2(2016ï¿½æ±¾)

// Ö¡ï¿½ï¿½ï¿½ï¿½
typedef BYTE ZCAN_UDS_FRAME_TYPE;
#define ZCAN_UDS_FRAME_CAN       0  // CANÖ¡
#define ZCAN_UDS_FRAME_CANFD     1  // CANFDÖ¡
#define ZCAN_UDS_FRAME_CANFD_BRS 2  // CANFDï¿½ï¿½ï¿½ï¿½Ö¡

// ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£ï¿½?
typedef BYTE ZCAN_UDS_FILL_MODE;
#define ZCAN_UDS_FILL_MODE_SHORT 0  // Ð¡ï¿½ï¿½8ï¿½Ö½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?8ï¿½Ö½Ú£ï¿½ï¿½ï¿½ï¿½ï¿½8ï¿½Ö½ï¿½Ê±ï¿½ï¿½DLCï¿½Í½ï¿½ï¿½ï¿½ï¿„1¤7?
#define ZCAN_UDS_FILL_MODE_NONE  1  // ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
#define ZCAN_UDS_FILL_MODE_MAX   2  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½)

// CAN UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct _ZCAN_UDS_REQUEST {
    UINT                req_id;             // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½ï¿½ï¿½Î§0~65535ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î¨Ò»ï¿½ï¿½ï¿½?
    BYTE                channel;            // ï¿½è±¸Í¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ 0~255
    ZCAN_UDS_FRAME_TYPE frame_type;         // Ö¡ï¿½ï¿½ï¿½ï¿½
    BYTE                reserved0[2];       // ï¿½ï¿½ï¿½ï¿½
    UINT                src_addr;           // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½?
    UINT                dst_addr;           // ï¿½ï¿½Ó¦ï¿½ï¿½Ö·
    BYTE                suppress_response;  // 1:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦
    BYTE                sid;                // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½id
    BYTE                reserved1[6];       // ï¿½ï¿½ï¿½ï¿½
    struct {
        UINT timeout;           // ï¿½ï¿½Ó¦ï¿½ï¿½Ê±Ê±ï¿½ï¿½(ms)ï¿½ï¿½ï¿½ï¿½PCï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã²ï¿½Ð¡ï¿½ï¿½200ms
        UINT enhanced_timeout;  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Îª0x78ï¿½ï¿½Ä³ï¿½Ê±Ê±ï¿½ï¿„1¤7?(ms)ï¿½ï¿½ï¿½ï¿½PCï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã²ï¿½Ð¡ï¿½ï¿½200ms
        BYTE check_any_negative_response : 1;  // ï¿½ï¿½ï¿½Õµï¿½ï¿½Ç±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦Ê±ï¿½Ç·ï¿½ï¿½ï¿½Òªï¿½Ð¶ï¿½Îªï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
        BYTE wait_if_suppress_response   : 1;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦Ê±ï¿½Ç·ï¿½ï¿½ï¿½Òªï¿½È´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½È´ï¿½Ê±ï¿½ï¿½Îªï¿½ï¿½Ó¦ï¿½ï¿½Ê±Ê±ï¿½ï¿½
        BYTE flag                        : 6;  // ï¿½ï¿½ï¿½ï¿½
        BYTE reserved0[7];                     // ï¿½ï¿½ï¿½ï¿½
    } session_param;                           // ï¿½á»°ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    struct {
        ZCAN_UDS_TRANS_VER version;       // ï¿½ï¿½ï¿½ï¿½Ð­ï¿½ï¿½æ±¾ï¿½ï¿½VERSION_0ï¿½ï¿½VERSION_1
        BYTE               max_data_len;  // ï¿½ï¿½Ö¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½can:8ï¿½ï¿½canfd:64
        BYTE local_st_min;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½Ã£ï¿½ï¿½ï¿½ï¿½ï¿½Ö¡Ö®ï¿½ï¿½ï¿½ï¿½ï¿½Ð¡ï¿½ï¿½ï¿½ï¿½ï¿½0x00-0x7F(0ms~127ms)ï¿½ï¿½0xF1-0xF9(100us~900us)
        BYTE block_size;    // ï¿½ï¿½ï¿½ï¿½Ö¡ï¿½Ä¿ï¿½ï¿½ï¿½?
        BYTE fill_byte;     // ï¿½ï¿½Ð§ï¿½Ö½Úµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
        BYTE ext_frame;     // 0:ï¿½ï¿½×¼Ö¡ 1:ï¿½ï¿½Õ¹Ö¡
        BYTE is_modify_ecu_st_min;        // ï¿½Ç·ï¿½ï¿½ï¿½ï¿½ECUï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Øµï¿½STminï¿½ï¿½Ç¿ï¿½ï¿½Ê¹ï¿½Ã±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ãµï¿½
                                          // remote_st_min
        BYTE remote_st_min;               // ï¿½ï¿½ï¿½Í¶ï¿½Ö¡Ê±ï¿½Ã£ï¿½is_ignore_ecu_st_min = 1
                                          // Ê±ï¿½ï¿½Ð§ï¿½ï¿½0x00-0x7F(0ms~127ms)ï¿½ï¿½0xF1-0xF9(100us~900us)
        UINT               fc_timeout;    // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ø³ï¿½Ê±Ê±ï¿½ï¿½(ms)ï¿½ï¿½ï¿½ç·¢ï¿½ï¿½ï¿½ï¿½Ö¡ï¿½ï¿½ï¿½ï¿½Òªï¿½È´ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½Ö¡
        ZCAN_UDS_FILL_MODE fill_mode;     // ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£ï¿½?
        BYTE               reserved0[3];  // ï¿½ï¿½ï¿½ï¿½
    } trans_param;                        // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    BYTE *data;                           // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SID)
    UINT  data_len;                       // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä³ï¿½ï¿½ï¿„1¤7?
    UINT  reserved2;                      // ï¿½ï¿½ï¿½ï¿½
} ZCAN_UDS_REQUEST;

// LIN UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct _ZLIN_UDS_REQUEST {
    UINT req_id;             // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½ï¿½ï¿½Î§0~65535ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î¨Ò»ï¿½ï¿½ï¿½?
    BYTE channel;            // ï¿½è±¸Í¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ 0~255
    BYTE suppress_response;  // 1:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ 0:ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    BYTE sid;                // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½id
    BYTE Nad;                // ï¿½Úµï¿½ï¿½ï¿½?
    BYTE reserved1[8];       // ï¿½ï¿½ï¿½ï¿½
    struct {
        UINT p2_timeout;        // ï¿½ï¿½Ó¦ï¿½ï¿½Ê±Ê±ï¿½ï¿½(ms)ï¿½ï¿½ï¿½ï¿½PCï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã²ï¿½Ð¡ï¿½ï¿½200ms
        UINT enhanced_timeout;  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Îª0x78ï¿½ï¿½Ä³ï¿½Ê±Ê±ï¿½ï¿„1¤7?(ms)ï¿½ï¿½ï¿½ï¿½PCï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã²ï¿½Ð¡ï¿½ï¿½200ms
        BYTE check_any_negative_response : 1;  // ï¿½ï¿½ï¿½Õµï¿½ï¿½Ç±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦Ê±ï¿½Ç·ï¿½ï¿½ï¿½Òªï¿½Ð¶ï¿½Îªï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
        BYTE wait_if_suppress_response   : 1;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦Ê±ï¿½Ç·ï¿½ï¿½ï¿½Òªï¿½È´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½È´ï¿½Ê±ï¿½ï¿½Îªï¿½ï¿½Ó¦ï¿½ï¿½Ê±Ê±ï¿½ï¿½
        BYTE flag                        : 6;  // ï¿½ï¿½ï¿½ï¿½
        BYTE reserved0[7];                     // ï¿½ï¿½ï¿½ï¿½
    } session_param;                           // ï¿½á»°ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    struct {
        BYTE fill_byte;     // ï¿½ï¿½Ð§ï¿½Ö½Úµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
        BYTE st_min;        // ï¿½Ó½Úµï¿½×¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»Ö¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½Ò»Ö¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð¡Ê±ï¿½ï¿½
        BYTE reserved0[6];  // ï¿½ï¿½ï¿½ï¿½
    } trans_param;          // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    BYTE *data;             // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SID)
    UINT  data_len;         // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä³ï¿½ï¿½ï¿„1¤7?
    UINT  reserved2;        // ï¿½ï¿½ï¿½ï¿½
} ZLIN_UDS_REQUEST;

typedef BYTE ZCAN_DOIP_ROUTING_ACT_TYPE;
#define ZCAN_DOIP_ACTIVATION_DEFAULT          0x00
#define ZCAN_DOIP_ACTIVATION_WWH_OBD          0x01
#define ZCAN_DOIP_ACTIVATION_CENTRAL_SECURITY 0xE0

typedef BYTE ZCAN_DOIP_VERSION;
#define ZCAN_DOIP_ISO_13400_2_2010      0x01
#define ZCAN_DOIP_ISO_13400_2_2012      0x02
#define ZCAN_DOIP_ISO_13400_2_2019      0x03
#define ZCAN_DOIP_AUTO_DETECTED_VERSION 0xFF

// DoIP ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct _ZDOIP_REQUEST {
    UINT req_id;        // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½ï¿½ï¿½Î§0~65535ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î¨Ò»ï¿½ï¿½ï¿½?
    BYTE reserved0[4];  // ï¿½ï¿½ï¿½ï¿½

    ZCAN_DOIP_VERSION          doipVersion;        // DoIPÐ­ï¿½ï¿½ï¿„1¤7?
    ZCAN_DOIP_ROUTING_ACT_TYPE rcType;             // Â·ï¿½É¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    BYTE                       sourceAddress[2];   // Ô´ï¿½ß¼ï¿½ï¿½ï¿½Ö·
    char                       serverAddress[32];  // DoIPÊµï¿½ï¿½ï¿½IPï¿½ï¿½Ö·
    USHORT                     connectTimeoutMs;   // ï¿½ï¿½ï¿½Ó³ï¿½Ê±
    USHORT                     routingTimeoutMs;   // Â·ï¿½É¼ï¿½ï¿½î³¬Ê±

    BYTE  targetAddress[2];  // Ä¿ï¿½ï¿½ï¿½ß¼ï¿½ï¿½ï¿½Ö·
    BYTE  sid;               // ï¿½ï¿½ï¿½ï¿½ï¿½SID
    BYTE  suppressPosResp;   // ï¿½Ç·ï¿½ï¿½ï¿½ï¿½Æ»ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦
    BYTE  waitForNegResp;    // ï¿½Ç·ï¿½È´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½suppressPosRespÎªï¿½ï¿½Ê±ï¿½ï¿½Ð§
    BYTE  reserved1[3];      // ï¿½ï¿½ï¿½ï¿½
    UINT  requestTimeoutMs;  // UDSï¿½ï¿½ï¿½ï¿½Ê±
    UINT  dataLength;        // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿„1¤7?
    BYTE *data;              // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
} ZDOIP_REQUEST;

// UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef BYTE ZCAN_UDS_ERROR;
#define ZCAN_UDS_ERROR_OK                                            0x00  // Ã»ï¿½ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_TIMEOUT                                       0x01  // ï¿½ï¿½Ó¦ï¿½ï¿½Ê±
#define ZCAN_UDS_ERROR_TRANSPORT                                     0x02  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½
#define ZCAN_UDS_ERROR_CANCEL                                        0x03  // È¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_SUPPRESS_RESPONSE                             0x04  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦
#define ZCAN_UDS_ERROR_BUSY                                          0x05  // Ã¦Âµï¿½ï¿½
#define ZCAN_UDS_ERROR_REQ_PARAM                                     0x06  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
#define ZCAN_UDS_ERROR_OTHTER                                        0x64  // ï¿½ï¿½ï¿½ï¿½Î´Öªï¿½ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_FAILED_TO_CREATE_SOCKET                  0x20  // ï¿½ï¿½ï¿½ï¿½socketÊ§ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_FAILED_TO_CONNECT                        0x21  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_TIMEOUT                                  0x22  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±
#define ZCAN_UDS_ERROR_DOIP_ROUTING_NOT_ACTIVE                       0x23  // Â·ï¿½ï¿½Î´ï¿½ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_BUFFER_TOO_SMALL                         0x24  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_ROUTING_ALREADY_ACTIVE                   0x25  // Â·ï¿½ï¿½ï¿½Ñ±ï¿½ï¿½ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_HEADER_NACK_INCORRECT_PATTERN_FORMAT     0x26  // ï¿½Õµï¿½DoIPÍ·ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_HEADER_NACK_UNKNOWN_PAYLOAD_TYPE         0x27  // ï¿½Õµï¿½DoIPÍ·ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_HEADER_NACK_MESSAGE_TOO_LARGE            0x28  // ï¿½Õµï¿½DoIPÍ·ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_HEADER_NACK_OUT_OF_MEMORY                0x29  // ï¿½Õµï¿½DoIPÍ·ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_HEADER_NACK_INVALID_PAYLOAD_LENGTH       0x2A  // ï¿½Õµï¿½DoIPÍ·ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_HEADER_NACK_UNKNOWN                      0x2B  // ï¿½Õµï¿½DoIPÍ·ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_INVALID_SOURCE_ADDRESS   0x2C  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_UNKNOWN_TARGET_ADDRESS   0x2D  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_MESSAGE_TOO_LARGE        0x2E  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_OUT_OF_MEMORY            0x2F  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_TARGET_UNREACHABLE       0x30  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_UNKNOWN_NETWORK          0x31  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_TRANSPORT_PROTOCOL_ERROR 0x32  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_DIAGNOSTIC_NACK_UNKNOWN                  0x33  // ï¿½Õµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NACK
#define ZCAN_UDS_ERROR_DOIP_INVALID_HANDLE                           0x34  // ï¿½ï¿½Ð§ï¿½Ä¾ï¿½ï¿„1¤7?
#define ZCAN_UDS_ERROR_DOIP_UNEXPECTED_NULL_POINTER                  0x35  // Î´Ô¤ï¿½ÚµÄ¿ï¿½Ö¸ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_UNKNOWN_HANDLE                           0x36  // Î´Öªï¿½Ä¾ï¿½ï¿„1¤7?
#define ZCAN_UDS_ERROR_DOIP_OUT_OF_MEMORY                            0x37  // ï¿½Ú´æ²»ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_UNKNOWN_ERROR                            0x38  // Î´Öªï¿½Ä´ï¿½ï¿½ï¿½
#define ZCAN_UDS_ERROR_DOIP_ROUTING_ACTIVE_FAIL                      0x39  // Â·ï¿½É¼ï¿½ï¿½ï¿½Ê§ï¿½ï¿½

typedef BYTE ZCAN_UDS_RESPONSE_TYPE;
#define ZCAN_UDS_RT_NEGATIVE 0  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦
#define ZCAN_UDS_RT_POSITIVE 1  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦
#define ZCAN_UDS_RT_NONE     2  // ï¿½ï¿½ï¿½ï¿½Ó¦

// UDSï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
typedef struct _ZCAN_UDS_RESPONSE {
    ZCAN_UDS_ERROR         status;       // ï¿½ï¿½Ó¦×´Ì¬
    BYTE                   reserved[6];  // ï¿½ï¿½ï¿½ï¿½
    ZCAN_UDS_RESPONSE_TYPE type;         // ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
    union {
        struct {
            BYTE sid;       // ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½id
            UINT data_len;  // ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SID), ï¿½ï¿½ï¿½Ý´ï¿½ï¿½ï¿½Ú½Ó¿Ú´ï¿½ï¿½ï¿½ï¿½dataBufï¿½ï¿½
        } positive;
        struct {
            BYTE neg_code;    // ï¿½Ì¶ï¿½Îª0x7F
            BYTE sid;         // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½id
            BYTE error_code;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        } negative;
        BYTE raw[8];
    };
} ZCAN_UDS_RESPONSE;

// UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef UINT ZCAN_UDS_CTRL_CODE;
#define ZCAN_UDS_CTRL_STOP_REQ 0  // Í£Ö¹UDSï¿½ï¿½ï¿½ï¿½

// UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct _ZCAN_UDS_CTRL_REQ {
    UINT               reqID;        // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½Ö¸ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    ZCAN_UDS_CTRL_CODE cmd;          // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    BYTE               reserved[8];  // ï¿½ï¿½ï¿½ï¿½
} ZCAN_UDS_CTRL_REQ;

// UDSï¿½ï¿½ï¿½Æ½ï¿½ï¿„1¤7?
typedef UINT ZCAN_UDS_CTRL_RESULT;
#define ZCAN_UDS_CTRL_RESULT_OK  0  // ï¿½É¹ï¿½
#define ZCAN_UDS_CTRL_RESULT_ERR 1  // Ê§ï¿½ï¿½

// UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
typedef struct _ZCAN_UDS_CTRL_RESP {
    ZCAN_UDS_CTRL_RESULT result;        // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?
    BYTE                 reserved[12];  // ï¿½ï¿½ï¿½ï¿½
} ZCAN_UDS_CTRL_RESP;

// CAN/CANFD UDSï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANCANFDUdsData {
    const ZCAN_UDS_REQUEST *req;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
    BYTE                    reserved[24];
} ZCANCANFDUdsData;

// LIN UDSï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANLINUdsData {
    const ZLIN_UDS_REQUEST *req;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
    BYTE                    reserved[24];
} ZCANLINUdsData;

// DoIP UDSï¿½ï¿½ï¿½ï¿½
typedef struct tagZDoIPUdsData {
    const ZDOIP_REQUEST *req;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
    BYTE                 reserved[24];
} ZDoIPUdsData;

// UDSï¿½ï¿½ï¿½Ý½á¹¹ï¿½ï¿½Ö§ï¿½ï¿½CAN/LINï¿½ï¿½UDSï¿½ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
typedef struct tagZCANUdsRequestDataObj {
    ZCAN_UDS_DATA_DEF dataType;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    union {
        ZCANCANFDUdsData zcanCANFDUdsData;  // CAN/CANFD UDSï¿½ï¿½ï¿½ï¿½
        ZCANLINUdsData   zcanLINUdsData;    // LIN UDSï¿½ï¿½ï¿½ï¿½
        ZDoIPUdsData     zcanDoIPUdsData;   // DoIP UDSï¿½ï¿½ï¿½ï¿½
        BYTE             raw[63];           // RAWï¿½ï¿½ï¿½ï¿½
    } data;                                 // Êµï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½å£¬ï¿½ï¿½Ð§ï¿½ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ dataType ï¿½Ö¶Î¶ï¿½ï¿½ï¿½
    BYTE reserved[32];                      // ï¿½ï¿½ï¿½ï¿½Î»
} ZCANUdsRequestDataObj;

#pragma pack(pop)

#ifdef __cplusplus
#define DEF(a) = a
#else
#define DEF(a)
#endif

#ifdef WIN32
#define FUNC_CALL __stdcall
#else
#define FUNC_CALL  // __attribute__((stdcall))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define INVALID_DEVICE_HANDLE 0
DEVICE_HANDLE FUNC_CALL ZCAN_OpenDevice(UINT device_type, UINT device_index, UINT reserved);
UINT FUNC_CALL          ZCAN_CloseDevice(DEVICE_HANDLE device_handle);
UINT FUNC_CALL          ZCAN_GetDeviceInf(DEVICE_HANDLE device_handle, ZCAN_DEVICE_INFO *pInfo);

UINT FUNC_CALL ZCAN_IsDeviceOnLine(DEVICE_HANDLE device_handle);

#define INVALID_CHANNEL_HANDLE 0
CHANNEL_HANDLE FUNC_CALL ZCAN_InitCAN(DEVICE_HANDLE device_handle, UINT can_index,
                                      ZCAN_CHANNEL_INIT_CONFIG *pInitConfig);
UINT FUNC_CALL           ZCAN_StartCAN(CHANNEL_HANDLE channel_handle);
UINT FUNC_CALL           ZCAN_ResetCAN(CHANNEL_HANDLE channel_handle);
UINT FUNC_CALL           ZCAN_ClearBuffer(CHANNEL_HANDLE channel_handle);
UINT FUNC_CALL           ZCAN_ReadChannelErrInfo(CHANNEL_HANDLE channel_handle, ZCAN_CHANNEL_ERR_INFO *pErrInfo);
UINT FUNC_CALL           ZCAN_ReadChannelStatus(CHANNEL_HANDLE channel_handle, ZCAN_CHANNEL_STATUS *pCANStatus);
UINT FUNC_CALL           ZCAN_GetReceiveNum(CHANNEL_HANDLE channel_handle,
                                            BYTE           type);  // type:TYPE_CAN, TYPE_CANFD, TYPE_ALL_DATA
UINT FUNC_CALL           ZCAN_Transmit(CHANNEL_HANDLE channel_handle, ZCAN_Transmit_Data *pTransmit, UINT len);
UINT FUNC_CALL           ZCAN_Receive(CHANNEL_HANDLE channel_handle, ZCAN_Receive_Data *pReceive, UINT len,
                                      int wait_time DEF(-1));
UINT FUNC_CALL           ZCAN_TransmitFD(CHANNEL_HANDLE channel_handle, ZCAN_TransmitFD_Data *pTransmit, UINT len);
UINT FUNC_CALL           ZCAN_ReceiveFD(CHANNEL_HANDLE channel_handle, ZCAN_ReceiveFD_Data *pReceive, UINT len,
                                        int wait_time DEF(-1));

UINT FUNC_CALL ZCAN_TransmitData(DEVICE_HANDLE device_handle, ZCANDataObj *pTransmit, UINT len);
UINT FUNC_CALL ZCAN_ReceiveData(DEVICE_HANDLE device_handle, ZCANDataObj *pReceive, UINT len, int wait_time DEF(-1));
UINT FUNC_CALL ZCAN_SetValue(DEVICE_HANDLE device_handle, const char *path, const char *value);
const void *FUNC_CALL ZCAN_GetValue(DEVICE_HANDLE device_handle, const char *path);

IProperty *FUNC_CALL GetIProperty(DEVICE_HANDLE device_handle);
UINT FUNC_CALL       ReleaseIProperty(IProperty *pIProperty);

void FUNC_CALL ZCLOUD_SetServerInfo(const char *httpSvr, unsigned short httpPort, const char *authSvr,
                                    unsigned short authPort);
// return 0:success, 1:failure, 2:https error, 3:user login info error, 4:mqtt
// connection error, 5:no device
UINT FUNC_CALL ZCLOUD_ConnectServer(const char *username, const char *password);
// return 0:not connected, 1:connected
UINT FUNC_CALL ZCLOUD_IsConnected();
// return 0:success, 1:failure
UINT FUNC_CALL                    ZCLOUD_DisconnectServer();
const ZCLOUD_USER_DATA *FUNC_CALL ZCLOUD_GetUserData(int update DEF(0));
UINT FUNC_CALL                    ZCLOUD_ReceiveGPS(DEVICE_HANDLE device_handle, ZCLOUD_GPS_FRAME *pReceive, UINT len,
                                                    int wait_time DEF(-1));

CHANNEL_HANDLE FUNC_CALL ZCAN_InitLIN(DEVICE_HANDLE device_handle, UINT lin_index,
                                      PZCAN_LIN_INIT_CONFIG pLINInitConfig);
UINT FUNC_CALL           ZCAN_StartLIN(CHANNEL_HANDLE channel_handle);
UINT FUNC_CALL           ZCAN_ResetLIN(CHANNEL_HANDLE channel_handle);
UINT FUNC_CALL           ZCAN_TransmitLIN(CHANNEL_HANDLE channel_handle, PZCAN_LIN_MSG pSend, UINT Len);
UINT FUNC_CALL           ZCAN_GetLINReceiveNum(CHANNEL_HANDLE channel_handle);
UINT FUNC_CALL           ZCAN_ReceiveLIN(CHANNEL_HANDLE channel_handle, PZCAN_LIN_MSG pReceive, UINT Len, int WaitTime);

UINT FUNC_CALL ZCAN_SetLINSubscribe(CHANNEL_HANDLE channel_handle, PZCAN_LIN_SUBSCIBE_CFG pSend, UINT nSubscribeCount);
UINT FUNC_CALL ZCAN_SetLINPublish(CHANNEL_HANDLE channel_handle, PZCAN_LIN_PUBLISH_CFG pSend, UINT nPublishCount);
UINT FUNC_CALL ZCAN_SetLINPublishEx(CHANNEL_HANDLE channel_handle, PZCAN_LIN_PUBLISH_CFG_EX pSend, UINT nPublishCount);

UINT FUNC_CALL ZCAN_WakeUpLIN(CHANNEL_HANDLE channel_handle);

/**
 * @brief UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7? (DoCAN)
 * @param[in] device_handle ï¿½è±¸ï¿½ï¿½ï¿„1¤7?
 * @param[in] req ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
 * @param[out] resp ï¿½ï¿½Ó¦ï¿½ï¿½Ï¢ï¿½ï¿½ï¿½ï¿½Îªnullptrï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
 * @param[out] dataBuf
 * ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½Ý»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Å»ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SID)ï¿½ï¿½Êµï¿½Ê³ï¿½ï¿½ï¿½Îªresp.positive.data_len
 * @param[in] dataBufSize ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½Ý»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ü´ï¿½Ð¡ï¿½ï¿½ï¿½ï¿½ï¿½Ð¡ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½ï¿½ï¿½ï¿½ï¿½
 * STATUS_BUFFER_TOO_SMALL
 * @return Ö´ï¿½Ð½ï¿½ï¿½×´ï¿½?
 */
ZCAN_RET_STATUS FUNC_CALL ZCAN_UDS_Request(DEVICE_HANDLE device_handle, const ZCAN_UDS_REQUEST *req,
                                           ZCAN_UDS_RESPONSE *resp, BYTE *dataBuf, UINT dataBufSize);

/**
 * @brief UDSï¿½ï¿½Ï¿ï¿½ï¿½ï¿„1¤7?, ï¿½ï¿½Í£Ö¹ï¿½ï¿½ï¿½ï¿½Ö´ï¿½Ðµï¿½UDSï¿½ï¿½ï¿½ï¿½ (DoCAN)
 * @param[in] device_handle ï¿½è±¸ï¿½ï¿½ï¿„1¤7?
 * @param[in] ctrl ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
 * @param[out] resp ï¿½ï¿½Ó¦ï¿½ï¿½Ï¢ï¿½ï¿½ï¿½ï¿½Îªnullptrï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
 * @return Ö´ï¿½Ð½ï¿½ï¿½×´ï¿½?
 */
ZCAN_RET_STATUS FUNC_CALL ZCAN_UDS_Control(DEVICE_HANDLE device_handle, const ZCAN_UDS_CTRL_REQ *ctrl,
                                           ZCAN_UDS_CTRL_RESP *resp);

/**
 * @brief UDSï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿„1¤7?(ï¿½ï¿½)
 * @param[in] device_handle ï¿½è±¸ï¿½ï¿½ï¿„1¤7?
 * @param[in] requestData ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
 * @param[out] resp ï¿½ï¿½Ó¦ï¿½ï¿½Ï¢ï¿½ï¿½ï¿½ï¿½Îªnullptrï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
 * @param[out] dataBuf
 * ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½Ý»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Å»ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SID)ï¿½ï¿½Êµï¿½Ê³ï¿½ï¿½ï¿½Îªresp.positive.data_len
 * @param[in] dataBufSize ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½Ý»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ü´ï¿½Ð¡ï¿½ï¿½ï¿½ï¿½ï¿½Ð¡ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½ï¿½ï¿½ï¿½ï¿½
 * STATUS_BUFFER_TOO_SMALL
 */
ZCAN_RET_STATUS FUNC_CALL ZCAN_UDS_RequestEX(DEVICE_HANDLE device_handle, const ZCANUdsRequestDataObj *requestData,
                                             ZCAN_UDS_RESPONSE *resp, BYTE *dataBuf, UINT dataBufSize);

/**
 * @brief UDSï¿½ï¿½Ï¿ï¿½ï¿½Æ£ï¿½ï¿½ï¿½Í£Ö¹ï¿½ï¿½ï¿½ï¿½Ö´ï¿½Ðµï¿½UDSï¿½ï¿½ï¿½ï¿½(ï¿½ï¿½)
 * @param[in] device_handle ï¿½è±¸ï¿½ï¿½ï¿„1¤7?
 * @param[in] dataType ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
 * @param[in] ctrl ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¢
 * @param[out] resp ï¿½ï¿½Ó¦ï¿½ï¿½Ï¢ï¿½ï¿½ï¿½ï¿½Îªnullptrï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½
 * @return Ö´ï¿½Ð½ï¿½ï¿½×´ï¿½?
 */
ZCAN_RET_STATUS FUNC_CALL ZCAN_UDS_ControlEX(DEVICE_HANDLE device_handle, ZCAN_UDS_DATA_DEF dataType,
                                             const ZCAN_UDS_CTRL_REQ *ctrl, ZCAN_UDS_CTRL_RESP *resp);

/*ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½*/
UINT FUNC_CALL ZCAN_SetLINSlaveMsg(CHANNEL_HANDLE channel_handle, PZCAN_LIN_MSG pSend, UINT nMsgCount);
UINT FUNC_CALL ZCAN_ClearLINSlaveMsg(CHANNEL_HANDLE channel_handle, BYTE *pLINID, UINT nIDCount);

#ifdef __cplusplus
}
#endif

#endif  // ZLGCAN_H_

