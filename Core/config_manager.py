# core/config_manager.py
# Part 1

from __future__ import annotations

from pathlib import Path
from dataclasses import dataclass, asdict

import tomllib

try:
    import tomli_w
except ImportError:
    tomli_w = None


CONFIG_DIR = Path("config")
CONFIG_FILE = CONFIG_DIR / "BridgeX.toml"


@dataclass(slots=True)
class VectorConfig:

    dll: str = "dll/vxlapi64.dll"

    app_name: str = "BridgeX"

    channel: int = 0

    arbitration_bitrate: int = 500000

    data_bitrate: int = 2000000

    auto_connect: bool = True


@dataclass(slots=True)
class ZlgConfig:

    dll: str = "dll/zlgcan.dll"

    device_type: int = 41

    device_index: int = 0

    channel: int = 0

    arbitration_bitrate: int = 500000

    data_bitrate: int = 2000000

    auto_connect: bool = True


@dataclass(slots=True)
class BridgeConfig:

    auto_start: bool = True

    loopback: bool = False

    enable_trace: bool = True

    enable_statistics: bool = True

    queue_size: int = 10000

    reconnect: bool = True


@dataclass(slots=True)
class GuiConfig:

    theme: str = "System"

    accent: str = "Blue"

    mica: bool = True

    animation: bool = True

    language: str = "zh_CN"

    maximize: bool = False

    width: int = 1500

    height: int = 900


@dataclass(slots=True)
class LogConfig:

    enable: bool = True

    level: str = "INFO"

    retention: int = 30

    directory: str = "logs"


@dataclass(slots=True)
class ProjectConfig:

    vector: VectorConfig

    zlg: ZlgConfig

    bridge: BridgeConfig

    gui: GuiConfig

    log: LogConfig

    # core/config_manager.py
    # Part 2


class ConfigManager:

    def __init__(self):

        self.vector = VectorConfig()

        self.zlg = ZlgConfig()

        self.bridge = BridgeConfig()

        self.gui = GuiConfig()

        self.log = LogConfig()

    def default(self):

        self.vector = VectorConfig()

        self.zlg = ZlgConfig()

        self.bridge = BridgeConfig()

        self.gui = GuiConfig()

        self.log = LogConfig()

    def load(self):

        if not CONFIG_FILE.exists():
            self.save()

            return

        with open(CONFIG_FILE, "rb") as fp:
            data = tomllib.load(fp)

        self.vector = VectorConfig(**data["vector"])

        self.zlg = ZlgConfig(**data["zlg"])

        self.bridge = BridgeConfig(**data["bridge"])

        self.gui = GuiConfig(**data["gui"])

        self.log = LogConfig(**data["log"])

    def save(self):

        CONFIG_DIR.mkdir(
            parents=True,
            exist_ok=True,
        )

        obj = {

            "vector": asdict(self.vector),

            "zlg": asdict(self.zlg),

            "bridge": asdict(self.bridge),

            "gui": asdict(self.gui),

            "log": asdict(self.log),

        }

        if tomli_w is None:
            raise RuntimeError(
                "Please install tomli-w"
            )

        with open(CONFIG_FILE, "wb") as fp:
            tomli_w.dump(obj, fp)

        # core/config_manager.py
        # Part 3

    @property
    def project(self):

        return ProjectConfig(

            vector=self.vector,

            zlg=self.zlg,

            bridge=self.bridge,

            gui=self.gui,

            log=self.log,

        )

    def updateVector(self, **kwargs):

        for k, v in kwargs.items():
            setattr(self.vector, k, v)

    def updateZlg(self, **kwargs):

        for k, v in kwargs.items():
            setattr(self.zlg, k, v)

    def updateBridge(self, **kwargs):

        for k, v in kwargs.items():
            setattr(self.bridge, k, v)

    def updateGui(self, **kwargs):

        for k, v in kwargs.items():
            setattr(self.gui, k, v)

    def updateLog(self, **kwargs):

        for k, v in kwargs.items():
            setattr(self.log, k, v)

    def export(self):

        return {

            "vector": asdict(self.vector),

            "zlg": asdict(self.zlg),

            "bridge": asdict(self.bridge),

            "gui": asdict(self.gui),

            "log": asdict(self.log),

        }

