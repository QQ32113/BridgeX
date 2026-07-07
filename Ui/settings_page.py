# ui/settings_page.py

from __future__ import annotations

from PySide6.QtWidgets import QWidget
from PySide6.QtWidgets import QVBoxLayout

from qfluentwidgets import SettingCardGroup
from qfluentwidgets import ComboBoxSettingCard
from qfluentwidgets import SwitchSettingCard


class SettingsPage(QWidget):

    def __init__(self):

        super().__init__()

        layout = QVBoxLayout(self)

        appearanceGroup = SettingCardGroup("Appearance")

        self.themeCard = ComboBoxSettingCard(
            configItem=None,
            icon=None,
            title="Theme",
            content="Application theme"
        )

        self.animationCard = SwitchSettingCard(
            icon=None,
            title="Animation",
            content="Enable UI animation",
            configItem=None
        )

        appearanceGroup.addSettingCard(self.themeCard)
        appearanceGroup.addSettingCard(self.animationCard)

        layout.addWidget(appearanceGroup)

        layout.addStretch()
