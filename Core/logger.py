# core/logger.py

from __future__ import annotations

import sys
from pathlib import Path

from loguru import logger

from app.constants import LOG_PATH


class Logger:

    _initialized = False

    @classmethod
    def initialize(cls):

        if cls._initialized:
            return

        Path(LOG_PATH).mkdir(
            parents=True,
            exist_ok=True,
        )

        logger.remove()

        logger.add(
            sys.stdout,
            level="INFO",
            colorize=True,
            enqueue=True,
            backtrace=False,
            diagnose=False,
        )

        logger.add(
            Path(LOG_PATH) / "BridgeX_{time:YYYY_MM_DD}.log",
            rotation="50 MB",
            retention="30 days",
            compression="zip",
            enqueue=True,
            encoding="utf-8",
            level="DEBUG",
        )

        cls._initialized = True

    @staticmethod
    def debug(message, *args, **kwargs):

        logger.debug(message, *args, **kwargs)

    @staticmethod
    def info(message, *args, **kwargs):

        logger.info(message, *args, **kwargs)

    @staticmethod
    def warning(message, *args, **kwargs):

        logger.warning(message, *args, **kwargs)

    @staticmethod
    def error(message, *args, **kwargs):

        logger.error(message, *args, **kwargs)

    @staticmethod
    def exception(message, *args, **kwargs):

        logger.exception(message, *args, **kwargs)
        