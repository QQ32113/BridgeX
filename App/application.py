from PySide6.QtGui import QColor
from PySide6.QtGui import QPalette

from PySide6.QtWidgets import QApplication


class BridgeApplication(QApplication):

    def __init__(self, argv):

        super().__init__(argv)

        self.setApplicationName("BridgeX")

        self.setOrganizationName("BridgeX")

        self.setStyle("Fusion")

        self.__init_palette()

    def __init_palette(self):

        palette = QPalette()

        palette.setColor(QPalette.ColorRole.Window, QColor("#202124"))
        palette.setColor(QPalette.ColorRole.Base, QColor("#2B2D31"))
        palette.setColor(QPalette.ColorRole.AlternateBase, QColor("#313338"))

        palette.setColor(QPalette.ColorRole.WindowText, QColor("#FFFFFF"))
        palette.setColor(QPalette.ColorRole.Text, QColor("#FFFFFF"))

        palette.setColor(QPalette.ColorRole.Button, QColor("#2B2D31"))
        palette.setColor(QPalette.ColorRole.ButtonText, QColor("#FFFFFF"))

        palette.setColor(QPalette.ColorRole.Highlight, QColor("#3B82F6"))

        self.setPalette(palette)
