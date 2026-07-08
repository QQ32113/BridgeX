# ui/widgets/settings/bridge_group.py

from PySide6.QtWidgets import *


class BridgeGroup(QGroupBox):

    def __init__(self):

        super().__init__("Bridge")

        form = QFormLayout(self)

        self.autoBridge = QCheckBox()

        self.forwardSelf = QCheckBox()

        self.enableStatistics = QCheckBox()

        self.enableTrace = QCheckBox()

        self.queueSize = QSpinBox()

        self.queueSize.setMaximum(500000)

        self.queueSize.setValue(10000)

        form.addRow("Auto Start",self.autoBridge)

        form.addRow("Forward Self",self.forwardSelf)

        form.addRow("Statistics",self.enableStatistics)

        form.addRow("Trace",self.enableTrace)

        form.addRow("Queue Size",self.queueSize)

    def value(self):

        return {

            "auto":self.autoBridge.isChecked(),

            "self":self.forwardSelf.isChecked(),

            "statistics":self.enableStatistics.isChecked(),

            "trace":self.enableTrace.isChecked(),

            "queue":self.queueSize.value()

        }

    def restore(self):

        self.autoBridge.setChecked(True)

        self.enableStatistics.setChecked(True)

        self.enableTrace.setChecked(True)
        