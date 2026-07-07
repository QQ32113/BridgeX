import sys

from app.application import BridgeApplication

from ui.main_window import MainWindow


def main():

    app = BridgeApplication(sys.argv)

    window = MainWindow()

    window.show()

    sys.exit(app.exec())


if __name__ == "__main__":

    main()
