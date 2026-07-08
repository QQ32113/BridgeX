# ui/pages/dashboard_page.py
# Part 1

from __future__ import annotations

from PySide6.QtCore import *
from PySide6.QtWidgets import *
from PySide6.QtGui import *

from ui.widgets.device_card import DeviceCard
from ui.widgets.bridge_card import BridgeCard
from ui.widgets.performance_card import PerformanceCard
from ui.widgets.flow_card import FlowCard


class DashboardPage(QWidget):

    def __init__(self):

        super().__init__()

        self.initUI()

    def initUI(self):

        self.mainLayout = QVBoxLayout(self)

        self.mainLayout.setContentsMargins(20,20,20,20)

        self.mainLayout.setSpacing(18)

        self.topLayout = QHBoxLayout()

        self.bottomLayout = QHBoxLayout()

        self.vectorCard = DeviceCard("Vector CANoe")

        self.bridgeCard = BridgeCard()

        self.zlgCard = DeviceCard("ZLG CANFD-200U")

        self.performanceCard = PerformanceCard()

        self.flowCard = FlowCard()

        self.topLayout.addWidget(self.vectorCard)

        self.topLayout.addWidget(self.bridgeCard)

        self.topLayout.addWidget(self.zlgCard)

        self.bottomLayout.addWidget(self.performanceCard,3)

        self.bottomLayout.addWidget(self.flowCard,2)

        self.mainLayout.addLayout(self.topLayout)

        self.mainLayout.addLayout(self.bottomLayout)

    def updateStatistics(self, stat):

        self.performanceCard.updateStatistics(stat)

        self.flowCard.updateStatistics(stat)

    def updateBridgeState(self,state):

        self.bridgeCard.setRunning(state)

    def updateVectorState(self,state):

        self.vectorCard.setConnected(state)

    def updateZlgState(self,state):

        self.zlgCard.setConnected(state)
        