# BridgeX

Modern CAN Bridge for CANoe

---

# 1. 项目介绍

## 1.1 项目背景

## 1.2 项目目标

## 1.3 软件特点

## 1.4 系统架构

---

# 2. 软件架构

整体架构图

GUI

↓

BridgeManager

↓

Adapter

↓

SDK

↓

DLL

↓

CAN Device

---

# 3. 项目目录

BridgeX/

说明每一个目录用途

---

# 4. 模块说明

## GUI

Dashboard

Bridge

Trace

Statistics

Settings

About

## Core

Logger

Queue

Frame

BridgeManager

Statistics

## Adapter

BaseAdapter

VectorAdapter

ZlgAdapter

## SDK

VectorSDK

ZlgSDK

---

# 5. 数据流

CANoe

↓

Vector Adapter

↓

CANFrame

↓

BridgeManager

↓

CANFrame

↓

ZLG Adapter

↓

ECU

---

# 6. 类图

MainWindow

↓

BridgeManager

↓

AdapterManager

↓

VectorAdapter

↓

VectorSDK

ZlgAdapter

↓

ZlgSDK

---

# 7. GUI设计

Dashboard

Bridge

Trace

Settings

产品设计原则

颜色

字体

图标

动画

---

# 8. CAN Frame

Frame结构

DLC

CAN FD

BRS

ESI

Timestamp

---

# 9. 多线程

GUI Thread

Vector RX

Vector TX

ZLG RX

ZLG TX

Statistics

Logger

线程关系图

---

# 10. SDK封装

Vector

ZLG

DLL加载

异常处理

错误码

---

# 11. Bridge流程

初始化

打开设备

启动

转发

关闭

自动恢复

BusOff处理

---

# 12. Trace

数据显示

过滤

导出CSV

颜色规则

搜索

---

# 13. Statistics

FPS

TX

RX

Delay

Dropped

Error

CPU

Memory

---

# 14. 配置文件

config.toml

说明全部配置项

---

# 15. 日志系统

Loguru

Rolling

Zip

等级

---

# 16. 打包

PyInstaller

生成EXE

DLL复制

发布目录

---

# 17. 后续规划

Peak

Kvaser

TSMaster

DBC

Signal

Graph

Plugin

OTA

Lua

MDF

CAN Log

---

# 18. RoadMap

V1.0

Bridge

V1.1

Trace

V1.2

Statistics

V2.0

DBC

Signal

Graph

Plugin

---

# 19. 开发规范

Python

命名规范

目录规范

注释规范

Git规范

Commit规范

Branch规范

---

# 20. 致谢
