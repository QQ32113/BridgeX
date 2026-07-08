# core/logger.py
# Part 1

from __future__ import annotations

import os
import sys
import zipfile
import traceback
from pathlib import Path

from loguru import logger


LOG_DIR = Path("logs")
LOG_DIR.mkdir(exist_ok=True)

TRACE_DIR = LOG_DIR / "trace"
TRACE_DIR.mkdir(exist_ok=True)

SDK_DIR = LOG_DIR / "sdk"
SDK_DIR.mkdir(exist_ok=True)

GUI_DIR = LOG_DIR / "gui"
GUI_DIR.mkdir(exist_ok=True)

BRIDGE_DIR = LOG_DIR / "bridge"
BRIDGE_DIR.mkdir(exist_ok=True)


class BridgeLogger:

    def __init__(self):

        self.initialized = False

    def initialize(self):

        if self.initialized:

            return

        logger.remove()

        logger.add(
            sys.stdout,
            level="INFO",
            colorize=True,
            enqueue=True,
            backtrace=False,
            diagnose=False,
            format="<green>{time:HH:mm:ss.SSS}</green> | "
                   "<level>{level:8}</level> | "
                   "{message}"
        )

        logger.add(
            LOG_DIR / "BridgeX.log",
            level="DEBUG",
            rotation="20 MB",
            retention="30 days",
            compression="zip",
            enqueue=True,
            encoding="utf-8"
        )

        logger.add(
            TRACE_DIR / "trace.log",
            filter=lambda r: r["extra"].get("module") == "trace",
            rotation="50 MB",
            retention=10,
            compression="zip",
            enqueue=True
        )

        logger.add(
            SDK_DIR / "sdk.log",
            filter=lambda r: r["extra"].get("module") == "sdk",
            rotation="20 MB",
            retention=15,
            compression="zip",
            enqueue=True
        )

        logger.add(
            BRIDGE_DIR / "bridge.log",
            filter=lambda r: r["extra"].get("module") == "bridge",
            rotation="20 MB",
            retention=15,
            compression="zip",
            enqueue=True
        )

        logger.add(
            GUI_DIR / "gui.log",
            filter=lambda r: r["extra"].get("module") == "gui",
            rotation="10 MB",
            retention=10,
            compression="zip",
            enqueue=True
        )

        sys.excepthook = self.exceptionHook

        self.initialized = True

        # core/logger.py
        # Part 2

    def exceptionHook(

            self,

            exc_type,

            exc,

            tb,

    ):
        logger.exception(

            "".join(

                traceback.format_exception(

                    exc_type,

                    exc,

                    tb,

                )

            )

        )

    def trace(

            self,

            message,

    ):
        logger.bind(

            module="trace"

        ).debug(message)

    def sdk(

            self,

            message,

    ):
        logger.bind(

            module="sdk"

        ).info(message)

    def bridge(

            self,

            message,

    ):
        logger.bind(

            module="bridge"

        ).info(message)

    def gui(

            self,

            message,

    ):
        logger.bind(

            module="gui"

        ).debug(message)

    def info(self, message):
        logger.info(message)

    def warning(self, message):
        logger.warning(message)

    def error(self, message):
        logger.error(message)

    def critical(self, message):
        logger.critical(message)

    def debug(self, message):
        logger.debug(message)

# core/logger.py
# Part 3

    def archiveLogs(self):

        zip_name = LOG_DIR / "Archive.zip"

        with zipfile.ZipFile(

            zip_name,

            "w",

            zipfile.ZIP_DEFLATED,

        ) as z:

            for root, _, files in os.walk(LOG_DIR):

                for file in files:

                    if file.endswith(".log"):

                        path = Path(root) / file

                        z.write(

                            path,

                            path.relative_to(LOG_DIR),

                        )

    def clearLogs(self):

        for root, _, files in os.walk(LOG_DIR):

            for file in files:

                if file.endswith(".log"):

                    try:

                        os.remove(

                            Path(root) / file

                        )

                    except Exception:

                        pass

    def currentLogDirectory(self):

        return LOG_DIR

    def traceDirectory(self):

        return TRACE_DIR

    def sdkDirectory(self):

        return SDK_DIR

    def bridgeDirectory(self):

        return BRIDGE_DIR

    def guiDirectory(self):

        return GUI_DIR


bridge_logger = BridgeLogger()

bridge_logger.initialize()

