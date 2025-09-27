# STM32F429 u8g2 Oled

基于STM32F429的嵌入式菜单系统，使用U8G2图形库实现OLED显示界面和按键交互。

## 项目概述

本项目是用u8g2在OLED显示动态图标的方案。项目采用HAL库开发，代码结构清晰，易于扩展和维护。

## 硬件平台

- **MCU**: STM32F429ZGT6
- **显示**: OLED (SSD1306) 通过I2C接口
- **输入**: 按键输入系统
- **调试**: SWD接口

## 主要功能

- ✅ U8G2图形界面库集成
- ✅ 按键防抖和事件处理
- ✅ 任务调度器
- ✅ I2C通信接口

## 项目结构

```
├── Core/                  # STM32CubeMX生成的核心文件
│   ├── Inc/              # 头文件
│   └── Src/              # 源文件
├── Drivers/              # HAL驱动库
├── User/                 # 用户自定义代码
│   ├── App/              # 应用层代码
│   │   ├── btn_app.c     # 按键应用
│   │   ├── dynamic.c     # 动态菜单
│   │   ├── oled_app.c    # OLED应用
│   │   └── scheduler.c   # 任务调度
│   └── Components/       # 第三方组件
│       ├── ebtn/         # 按键库
│       └── u8g2-master/  # U8G2图形库
├── MDK-ARM/              # Keil MDK项目文件
└── menu.ioc              # STM32CubeMX配置文件
```

## 开发环境
- **STM32CubeMX**: 6.x 或更高版本
- **MDK-ARM**: Keil µVision 5.x
- **STM32 HAL库**: F4系列