# ui/bridge_page.py

from __future__ import annotations

from PySide6.QtWidgets import QWidget
from PySide6.QtWidgets import QGridLayout

from qfluentwidgets import ComboBox
from qfluentwidgets import PushButton
from qfluentwidgets import CardWidget
from qfluentwidgets import BodyLabel


class BridgePage(QWidget):

    def __init__(self):

        super().__init__()

        layout = QGridLayout(self)

        vectorCard = CardWidget()

        zlgCard = CardWidget()

        vectorLayout = QGridLayout(vectorCard)

        vectorLayout.addWidget(BodyLabel("Vector Channel"), 0, 0)

        self.vectorChannel = ComboBox()

        vectorLayout.addWidget(self.vectorChannel, 0, 1)

        vectorLayout.addWidget(BodyLabel("CANoe App"), 1, 0)

        self.vectorApp = ComboBox()

        vectorLayout.addWidget(self.vectorApp, 1, 1)

        zlgLayout = QGridLayout(zlgCard)

        zlgLayout.addWidget(BodyLabel("Device"), 0, 0)

        self.deviceBox = ComboBox()

        zlgLayout.addWidget(self.deviceBox, 0, 1)

        zlgLayout.addWidget(BodyLabel("Channel"), 1, 0)

        self.channelBox = ComboBox()

        zlgLayout.addWidget(self.channelBox, 1, 1)

        self.startButton = PushButton("Start Bridge")

        self.stopButton = PushButton("Stop")

        layout.addWidget(vectorCard, 0, 0)

        layout.addWidget(zlgCard, 0, 1)

        layout.addWidget(self.startButton, 1, 0)

        layout.addWidget(self.stopButton, 1, 1)

        layout.setContentsMargins(30, 30, 30, 30)

        layout.setHorizontalSpacing(20)

        layout.setVerticalSpacing(20)
        