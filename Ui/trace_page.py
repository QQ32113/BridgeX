# ui/trace_page.py

from __future__ import annotations

from PySide6.QtWidgets import QWidget
from PySide6.QtWidgets import QVBoxLayout

from qfluentwidgets import TableWidget


class TracePage(QWidget):

    def __init__(self):

        super().__init__()

        layout = QVBoxLayout(self)

        self.table = TableWidget()

        self.table.setColumnCount(7)

        self.table.setHorizontalHeaderLabels(
            [
                "Time",
                "Direction",
                "Channel",
                "ID",
                "Type",
                "Length",
                "Data",
            ]
        )

        layout.addWidget(self.table)

    def appendFrame(self, frame):

        row = self.table.rowCount()

        self.table.insertRow(row)

        self.table.setItem(row, 0, self.table.createItem(str(frame.timestamp)))

        self.table.setItem(row, 1, self.table.createItem(frame.direction.name))

        self.table.setItem(row, 2, self.table.createItem(str(frame.channel)))

        self.table.setItem(row, 3, self.table.createItem(frame.hex_id))

        self.table.setItem(row, 4, self.table.createItem(frame.frame_type.name))

        self.table.setItem(row, 5, self.table.createItem(str(frame.length)))

        self.table.setItem(row, 6, self.table.createItem(frame.hex_data))
        