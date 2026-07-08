# ui/widgets/performance_card.py

from PySide6.QtWidgets import *


class PerformanceCard(QFrame):

    def __init__(self):

        super().__init__()

        layout=QGridLayout(self)

        self.vectorRx=QLabel("0")

        self.vectorTx=QLabel("0")

        self.zlgRx=QLabel("0")

        self.zlgTx=QLabel("0")

        self.bridge=QLabel("0")

        self.error=QLabel("0")

        layout.addWidget(QLabel("Vector RX FPS"),0,0)
        layout.addWidget(self.vectorRx,0,1)

        layout.addWidget(QLabel("Vector TX FPS"),1,0)
        layout.addWidget(self.vectorTx,1,1)

        layout.addWidget(QLabel("ZLG RX FPS"),2,0)
        layout.addWidget(self.zlgRx,2,1)

        layout.addWidget(QLabel("ZLG TX FPS"),3,0)
        layout.addWidget(self.zlgTx,3,1)

        layout.addWidget(QLabel("Bridge"),4,0)
        layout.addWidget(self.bridge,4,1)

        layout.addWidget(QLabel("Errors"),5,0)
        layout.addWidget(self.error,5,1)

    def updateStatistics(self,s):

        self.vectorRx.setText(f"{s['fps_vector_rx']:.0f}")

        self.vectorTx.setText(f"{s['fps_vector_tx']:.0f}")

        self.zlgRx.setText(f"{s['fps_zlg_rx']:.0f}")

        self.zlgTx.setText(f"{s['fps_zlg_tx']:.0f}")

        self.bridge.setText(str(s["bridge"]))

        self.error.setText(str(s["error"]))
        