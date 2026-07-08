# core/ringbuffer.py

from collections import deque


class RingBuffer:

    def __init__(self,size=50000):

        self.buffer=deque(maxlen=size)

    def put(self,obj):

        self.buffer.append(obj)

    def get(self):

        if len(self.buffer):

            return self.buffer.popleft()

        return None

    def clear(self):

        self.buffer.clear()

    def empty(self):

        return len(self.buffer)==0

    def __len__(self):

        return len(self.buffer)

