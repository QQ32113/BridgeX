# ui/widgets/filter_bar.py

from PySide6.QtWidgets import *

from PySide6.QtCore import *


class FilterBar(QWidget):

    filterChanged = Signal()

    def __init__(self):

        super().__init__()

        layout = QHBoxLayout(self)

        self.idEdit = QLineEdit()

        self.idEdit.setPlaceholderText(

            "CAN ID"

        )

        self.channelBox = QComboBox()

        self.channelBox.addItems(

            [

                "ALL",

                "CH0",

                "CH1",

            ]

        )

        self.typeBox = QComboBox()

        self.typeBox.addItems(

            [

                "ALL",

                "CAN",

                "CANFD",

            ]

        )

        self.searchEdit = QLineEdit()

        self.searchEdit.setPlaceholderText(

            "Search..."

        )

        self.clearButton = QPushButton("Clear")

        self.exportButton = QPushButton("Export CSV")

        layout.addWidget(self.idEdit)

        layout.addWidget(self.channelBox)

        layout.addWidget(self.typeBox)

        layout.addWidget(self.searchEdit)

        layout.addStretch()

        layout.addWidget(self.exportButton)

        layout.addWidget(self.clearButton)
        