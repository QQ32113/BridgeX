# ui/widgets/device_card.py

from PySide6.QtWidgets import *
from PySide6.QtGui import *
from PySide6.QtCore import *


class DeviceCard(QFrame):

    def __init__(self,title):

        super().__init__()

        self.setObjectName("DeviceCard")

        self.setMinimumHeight(180)

        layout=QVBoxLayout(self)

        self.title=QLabel(title)

        self.title.setObjectName("Title")

        self.state=QLabel("Disconnected")

        self.state.setObjectName("Offline")

        self.serial=QLabel("Serial : ---")

        self.channel=QLabel("Channel : ---")

        self.bitrate=QLabel("Bitrate : ---")

        layout.addWidget(self.title)

        layout.addSpacing(12)

        layout.addWidget(self.state)

        layout.addStretch()

        layout.addWidget(self.serial)

        layout.addWidget(self.channel)

        layout.addWidget(self.bitrate)

    def setConnected(self,connected):

        if connected:

            self.state.setText("● Connected")

            self.state.setObjectName("Online")

        else:

            self.state.setText("● Disconnected")

            self.state.setObjectName("Offline")

        self.state.style().unpolish(self.state)

        self.state.style().polish(self.state)
        