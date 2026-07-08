# ui/pages/settings_page.py
# Part 1

from __future__ import annotations

from PySide6.QtCore import *
from PySide6.QtWidgets import *
from PySide6.QtGui import *

from ui.widgets.settings.device_group import DeviceGroup
from ui.widgets.settings.bridge_group import BridgeGroup
from ui.widgets.settings.theme_group import ThemeGroup
from ui.widgets.settings.system_group import SystemGroup


class SettingsPage(QWidget):

    configChanged = Signal(dict)

    def __init__(self):

        super().__init__()

        self.initUI()

    def initUI(self):

        root = QVBoxLayout(self)

        root.setContentsMargins(20,20,20,20)

        root.setSpacing(18)

        scroll = QScrollArea()

        scroll.setWidgetResizable(True)

        container = QWidget()

        layout = QVBoxLayout(container)

        layout.setSpacing(18)

        self.vectorGroup = DeviceGroup("Vector XL Driver")

        self.zlgGroup = DeviceGroup("ZLG CANFD")

        self.bridgeGroup = BridgeGroup()

        self.themeGroup = ThemeGroup()

        self.systemGroup = SystemGroup()

        layout.addWidget(self.vectorGroup)

        layout.addWidget(self.zlgGroup)

        layout.addWidget(self.bridgeGroup)

        layout.addWidget(self.themeGroup)

        layout.addWidget(self.systemGroup)

        layout.addStretch()

        scroll.setWidget(container)

        root.addWidget(scroll)

        self.systemGroup.saveButton.clicked.connect(self.save)

        self.systemGroup.restoreButton.clicked.connect(self.restore)

    def configuration(self):

        return {

            "vector":self.vectorGroup.value(),

            "zlg":self.zlgGroup.value(),

            "bridge":self.bridgeGroup.value(),

            "theme":self.themeGroup.value(),

        }

    def save(self):

        self.configChanged.emit(

            self.configuration()

        )

    def restore(self):

        self.vectorGroup.restore()

        self.zlgGroup.restore()

        self.bridgeGroup.restore()

        self.themeGroup.restore()
