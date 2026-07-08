# core/dlc.py

CANFD_DLC = {

    0:0,

    1:1,

    2:2,

    3:3,

    4:4,

    5:5,

    6:6,

    7:7,

    8:8,

    9:12,

    10:16,

    11:20,

    12:24,

    13:32,

    14:48,

    15:64,

}


def dlc_to_len(dlc:int)->int:

    return CANFD_DLC.get(dlc,0)


def len_to_dlc(length:int)->int:

    for k,v in CANFD_DLC.items():

        if v>=length:

            return k

    return 15

