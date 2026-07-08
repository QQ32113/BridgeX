# ui/widgets/bridge_card.py

from PySide6.QtWidgets import *
from PySide6.QtCore import *


class BridgeCard(QFrame):

    def __init__(self):

        super().__init__()

        self.setMinimumHeight(180)

        layout=QVBoxLayout(self)

        self.title=QLabel("Bridge")

        self.state=QLabel("STOP")

        self.state.setAlignment(Qt.AlignCenter)

        self.progress=QProgressBar()

        self.progress.setRange(0,0)

        self.progress.hide()

        layout.addWidget(self.title)

        layout.addStretch()

        layout.addWidget(self.state)

        layout.addWidget(self.progress)

        layout.addStretch()

    def setRunning(self,running):

        if running:

            self.state.setText("RUNNING")

            self.progress.show()

        else:

            self.state.setText("STOP")

            self.progress.hide()
            