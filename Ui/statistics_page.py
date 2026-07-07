# ui/statistics_page.py

from __future__ import annotations

from PySide6.QtWidgets import QWidget
from PySide6.QtWidgets import QGridLayout

from qfluentwidgets import CardWidget
from qfluentwidgets import StrongBodyLabel
from qfluentwidgets import CaptionLabel


class StatisticsCard(CardWidget):

    def __init__(self, title: str):

        super().__init__()

        layout = QGridLayout(self)

        self.titleLabel = CaptionLabel(title)

        self.valueLabel = StrongBodyLabel("0")

        layout.addWidget(self.titleLabel, 0, 0)

        layout.addWidget(self.valueLabel, 1, 0)

    def setValue(self, value):

        self.valueLabel.setText(str(value))


class StatisticsPage(QWidget):

    def __init__(self):

        super().__init__()

        layout = QGridLayout(self)

        self.txFrame = StatisticsCard("TX Frames")
        self.rxFrame = StatisticsCard("RX Frames")

        self.txBytes = StatisticsCard("TX Bytes")
        self.rxBytes = StatisticsCard("RX Bytes")

        self.errorFrame = StatisticsCard("Errors")
        self.dropFrame = StatisticsCard("Dropped")

        layout.addWidget(self.txFrame, 0, 0)
        layout.addWidget(self.rxFrame, 0, 1)

        layout.addWidget(self.txBytes, 1, 0)
        layout.addWidget(self.rxBytes, 1, 1)

        layout.addWidget(self.errorFrame, 2, 0)
        layout.addWidget(self.dropFrame, 2, 1)

        layout.setContentsMargins(30,30,30,30)
        layout.setHorizontalSpacing(20)
        layout.setVerticalSpacing(20)

    def updateStatistics(self, stat):

        self.txFrame.setValue(stat.tx_frames)
        self.rxFrame.setValue(stat.rx_frames)

        self.txBytes.setValue(stat.tx_bytes)
        self.rxBytes.setValue(stat.rx_bytes)

        self.errorFrame.setValue(stat.error_frames)
        self.dropFrame.setValue(stat.dropped_frames)
        