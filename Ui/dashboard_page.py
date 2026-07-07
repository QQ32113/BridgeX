# ui/dashboard_page.py

from __future__ import annotations

from PySide6.QtCore import Qt

from PySide6.QtWidgets import QLabel
from PySide6.QtWidgets import QWidget
from PySide6.QtWidgets import QGridLayout
from PySide6.QtWidgets import QVBoxLayout

from qfluentwidgets import CardWidget


class DashboardCard(CardWidget):

    def __init__(self, title: str):

        super().__init__()

        self.title = QLabel(title)

        self.value = QLabel("0")

        self.title.setObjectName("cardTitle")

        self.value.setObjectName("cardValue")

        layout = QVBoxLayout(self)

        layout.addWidget(self.title)

        layout.addStretch()

        layout.addWidget(self.value)


class DashboardPage(QWidget):

    def __init__(self):

        super().__init__()

        layout = QGridLayout(self)

        self.txCard = DashboardCard("TX Frames")

        self.rxCard = DashboardCard("RX Frames")

        self.errorCard = DashboardCard("Errors")

        self.delayCard = DashboardCard("Latency")

        layout.addWidget(self.txCard, 0, 0)

        layout.addWidget(self.rxCard, 0, 1)

        layout.addWidget(self.errorCard, 0, 2)

        layout.addWidget(self.delayCard, 0, 3)

        layout.setContentsMargins(30, 30, 30, 30)

        layout.setHorizontalSpacing(20)

        layout.setVerticalSpacing(20)

    def updateStatistics(self, statistics):

        self.txCard.value.setText(str(statistics.tx_frames))

        self.rxCard.value.setText(str(statistics.rx_frames))

        self.errorCard.value.setText(str(statistics.error_frames))

        self.delayCard.value.setText("0.0 ms")
        