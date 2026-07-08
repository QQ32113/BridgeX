# ui/widgets/settings/theme_group.py

from PySide6.QtWidgets import *


class ThemeGroup(QGroupBox):

    def __init__(self):

        super().__init__("Appearance")

        form = QFormLayout(self)

        self.theme = QComboBox()

        self.theme.addItems(

            [

                "Light",

                "Dark",

                "System"

            ]

        )

        self.accent = QComboBox()

        self.accent.addItems(

            [

                "Blue",

                "Green",

                "Purple",

                "Orange"

            ]

        )

        self.mica = QCheckBox()

        self.animation = QCheckBox()

        self.animation.setChecked(True)

        form.addRow("Theme",self.theme)

        form.addRow("Accent",self.accent)

        form.addRow("Mica",self.mica)

        form.addRow("Animation",self.animation)

    def value(self):

        return {

            "theme":self.theme.currentText(),

            "accent":self.accent.currentText(),

            "mica":self.mica.isChecked(),

            "animation":self.animation.isChecked()

        }

    def restore(self):

        self.theme.setCurrentIndex(2)

        self.accent.setCurrentIndex(0)

        self.animation.setChecked(True)
        