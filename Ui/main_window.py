# ui/main_window.py

from __future__ import annotations

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QWidget
from PySide6.QtWidgets import QHBoxLayout

from qfluentwidgets import FluentWindow

from ui.dashboard_page import DashboardPage
from ui.bridge_page import BridgePage
from ui.trace_page import TracePage
from ui.statistics_page import StatisticsPage
from ui.settings_page import SettingsPage


class MainWindow(FluentWindow):

    def __init__(self):

        super().__init__()

        self.resize(1600, 960)

        self.setMinimumSize(1400, 900)

        self.setWindowTitle("BridgeX")

        self.dashboardPage = DashboardPage()

        self.bridgePage = BridgePage()

        self.tracePage = TracePage()

        self.statisticsPage = StatisticsPage()

        self.settingsPage = SettingsPage()

        self.initNavigation()

    def initNavigation(self):

        self.addSubInterface(
            self.dashboardPage,
            None,
            "Dashboard"
        )

        self.addSubInterface(
            self.bridgePage,
            None,
            "Bridge"
        )

        self.addSubInterface(
            self.tracePage,
            None,
            "Trace"
        )

        self.addSubInterface(
            self.statisticsPage,
            None,
            "Statistics"
        )

        self.addSubInterface(
            self.settingsPage,
            None,
            "Settings"
        )
        