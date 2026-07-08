# core/busload.py

import time


class BusLoadCalculator:

    def __init__(self,bitrate=500000):

        self.bitrate=bitrate

        self.bits=0

        self.last=time.time()

        self.value=0

    def update(self,frame):

        self.bits+=frame.length*8+64

        now=time.time()

        if now-self.last>=1:

            self.value=self.bits/self.bitrate*100

            self.bits=0

            self.last=now

    @property

    def busload(self):

        return round(self.value,2)

