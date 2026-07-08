# ui/widgets/statistics_bar.py

from PySide6.QtWidgets import *


class StatisticsBar(QWidget):

    def __init__(self):

        super().__init__()

        layout = QHBoxLayout(self)

        self.totalLabel = QLabel("Frames : 0")

        self.rxLabel = QLabel("RX : 0")

        self.txLabel = QLabel("TX : 0")

        self.fdLabel = QLabel("CANFD : 0")

        layout.addWidget(self.totalLabel)

        layout.addSpacing(20)

        layout.addWidget(self.rxLabel)

        layout.addSpacing(20)

        layout.addWidget(self.txLabel)

        layout.addSpacing(20)

        layout.addWidget(self.fdLabel)

        layout.addStretch()

        self.total = 0

        self.rx = 0

        self.tx = 0

        self.fd = 0

    def updateFrame(self, frame):

        self.total += 1

        if frame.direction.name == "RX":

            self.rx += 1

        else:

            self.tx += 1

        if frame.frame_type.name == "CANFD":

            self.fd += 1

        self.totalLabel.setText(f"Frames : {self.total}")

        self.rxLabel.setText(f"RX : {self.rx}")

        self.txLabel.setText(f"TX : {self.tx}")

        self.fdLabel.setText(f"CANFD : {self.fd}")
        