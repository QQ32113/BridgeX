from pathlib import Path

APP_NAME = "BridgeX"

APP_VERSION = "1.0.0"

ROOT_PATH = Path(__file__).resolve().parent.parent

RESOURCE_PATH = ROOT_PATH / "resources"

ICON_PATH = RESOURCE_PATH / "icons"

IMAGE_PATH = RESOURCE_PATH / "images"

QSS_PATH = RESOURCE_PATH / "qss"

DLL_PATH = ROOT_PATH / "dll"

LOG_PATH = ROOT_PATH / "logs"

CONFIG_PATH = ROOT_PATH / "config.toml"

WINDOW_WIDTH = 1600

WINDOW_HEIGHT = 960

NAV_WIDTH = 280
