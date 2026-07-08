# ui/widgets/flow_card.py

from PySide6.QtWidgets import *
from PySide6.QtCore import *
from PySide6.QtGui import *


class FlowCard(QFrame):

    def __init__(self):

        super().__init__()

        self.vectorValue=0

        self.zlgValue=0

        self.timer=QTimer()

        self.timer.timeout.connect(self.update)

        self.timer.start(30)

    def updateStatistics(self,s):

        self.vectorValue=s["fps_vector_rx"]

        self.zlgValue=s["fps_zlg_rx"]

    def paintEvent(self,event):

        p=QPainter(self)

        p.setRenderHint(QPainter.Antialiasing)

        r=self.rect()

        p.drawText(20,40,"CANoe")

        p.drawText(r.width()-90,40,"ZLG")

        p.drawLine(100,r.center().y(),r.width()-100,r.center().y())

        x=100+((self.vectorValue+self.zlgValue)%300)

        p.setBrush(QColor("#00C853"))

        p.setPen(Qt.NoPen)

        p.drawEllipse(QPointF(x,r.center().y()),6,6)
        