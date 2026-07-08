# ui/widgets/settings/system_group.py

from PySide6.QtWidgets import *


class SystemGroup(QGroupBox):

    def __init__(self):

        super().__init__("System")

        layout = QVBoxLayout(self)

        self.autoUpdate = QCheckBox("Check update on startup")

        self.enableLog = QCheckBox("Enable log")

        self.enableLog.setChecked(True)

        self.logLevel = QComboBox()

        self.logLevel.addItems(

            [

                "DEBUG",

                "INFO",

                "WARNING",

                "ERROR"

            ]

        )

        self.saveButton = QPushButton("Save")

        self.restoreButton = QPushButton("Restore Default")

        btn = QHBoxLayout()

        btn.addStretch()

        btn.addWidget(self.restoreButton)

        btn.addWidget(self.saveButton)

        layout.addWidget(self.autoUpdate)

        layout.addWidget(self.enableLog)

        layout.addWidget(QLabel("Log Level"))

        layout.addWidget(self.logLevel)

        layout.addSpacing(15)

        layout.addLayout(btn)
        