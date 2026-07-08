# ui/widgets/settings/device_group.py

from PySide6.QtWidgets import *


class DeviceGroup(QGroupBox):

    def __init__(self,title):

        super().__init__(title)

        form = QFormLayout(self)

        self.dllPath = QLineEdit()

        self.channel = QSpinBox()

        self.channel.setMaximum(7)

        self.arb = QComboBox()

        self.data = QComboBox()

        self.arb.addItems(

            [

                "125K",

                "250K",

                "500K",

                "1M"

            ]

        )

        self.data.addItems(

            [

                "2M",

                "4M",

                "5M",

                "8M"

            ]

        )

        self.autoConnect = QCheckBox()

        self.deviceIndex = QSpinBox()

        form.addRow("DLL",self.dllPath)

        form.addRow("Device",self.deviceIndex)

        form.addRow("Channel",self.channel)

        form.addRow("Arbitration",self.arb)

        form.addRow("Data",self.data)

        form.addRow("Auto Connect",self.autoConnect)

    def value(self):

        return {

            "dll":self.dllPath.text(),

            "device":self.deviceIndex.value(),

            "channel":self.channel.value(),

            "arb":self.arb.currentText(),

            "data":self.data.currentText(),

            "auto":self.autoConnect.isChecked()

        }

    def restore(self):

        self.channel.setValue(0)

        self.deviceIndex.setValue(0)

        self.arb.setCurrentIndex(2)

        self.data.setCurrentIndex(1)

        self.autoConnect.setChecked(True)
        