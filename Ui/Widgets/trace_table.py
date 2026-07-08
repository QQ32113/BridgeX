# ui/widgets/trace_table.py
# Part 1

from __future__ import annotations

from PySide6.QtWidgets import *

from PySide6.QtCore import *

from PySide6.QtGui import *


class TraceTable(QTableWidget):

    HEADER = [

        "Time",

        "Dir",

        "Channel",

        "Type",

        "ID",

        "DLC",

        "Length",

        "Data",

    ]

    def __init__(self):

        super().__init__(0, len(self.HEADER))

        self.frames = []

        self.setHorizontalHeaderLabels(self.HEADER)

        self.horizontalHeader().setStretchLastSection(True)

        self.verticalHeader().hide()

        self.setAlternatingRowColors(True)

        self.setSelectionBehavior(

            QAbstractItemView.SelectRows

        )

        self.setEditTriggers(

            QAbstractItemView.NoEditTriggers

        )

        self.setShowGrid(False)

        self.setSortingEnabled(False)

        self.setWordWrap(False)

    def appendFrame(

        self,

        frame,

    ):

        row = self.rowCount()

        self.insertRow(row)

        self.frames.append(frame)

        self.setItem(

            row,

            0,

            QTableWidgetItem(

                f"{frame.timestamp:.6f}"

            ),

        )

        self.setItem(

            row,

            1,

            QTableWidgetItem(

                frame.direction.name

            ),

        )

        self.setItem(

            row,

            2,

            QTableWidgetItem(

                str(frame.channel)

            ),

        )

        self.setItem(

            row,

            3,

            QTableWidgetItem(

                frame.frame_type.name

            ),

        )

        self.setItem(

            row,

            4,

            QTableWidgetItem(

                hex(frame.arbitration_id)

            ),

        )

        self.setItem(

            row,

            5,

            QTableWidgetItem(

                str(frame.dlc)

            ),

        )

        self.setItem(

            row,

            6,

            QTableWidgetItem(

                str(frame.length)

            ),

        )

        self.setItem(

            row,

            7,

            QTableWidgetItem(

                " ".join(

                    f"{x:02X}"

                    for x in frame.data[:frame.length]

                )

            ),

        )

        if frame.direction.name == "RX":

            color = QColor("#D6F5D6")

        else:

            color = QColor("#D9ECFF")

        for c in range(self.columnCount()):

            self.item(row, c).setBackground(color)

        self.scrollToBottom()

    def clearFrames(self):

        self.frames.clear()

        self.setRowCount(0)

    def currentFrame(self):

        row = self.currentRow()

        if row < 0:

            return None

        return self.frames[row]
    