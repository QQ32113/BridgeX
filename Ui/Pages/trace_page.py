# ui/pages/trace_page.py
# Part 1

from __future__ import annotations

from PySide6.QtCore import *
from PySide6.QtWidgets import *
from PySide6.QtGui import *

from ui.widgets.trace_table import TraceTable
from ui.widgets.filter_bar import FilterBar
from ui.widgets.statistics_bar import StatisticsBar


class TracePage(QWidget):

    frameSelected = Signal(object)

    def __init__(self):

        super().__init__()

        self.model = []

        self.initUI()

    def initUI(self):

        self.mainLayout = QVBoxLayout(self)

        self.mainLayout.setContentsMargins(15, 15, 15, 15)

        self.mainLayout.setSpacing(12)

        self.filterBar = FilterBar()

        self.statisticsBar = StatisticsBar()

        self.table = TraceTable()

        self.mainLayout.addWidget(self.filterBar)

        self.mainLayout.addWidget(self.statisticsBar)

        self.mainLayout.addWidget(self.table)

        self.table.itemSelectionChanged.connect(

            self.onSelectionChanged

        )

    def appendFrame(

        self,

        frame,

    ):

        self.table.appendFrame(frame)

        self.statisticsBar.updateFrame(frame)

    def clear(self):

        self.table.clearFrames()

    def onSelectionChanged(self):

        frame = self.table.currentFrame()

        if frame:

            self.frameSelected.emit(frame)