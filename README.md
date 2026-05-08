# Smart-Farm
基于STM32+FreeRTOS+MQTT的智能农场监控系统

项目简介--
本项目是基于STM32F103C8T6主控的多节点环境监测与自动灌溉预警控制系统，采用 FreeRTOS 多任务架构，通过 ESP8266 WiFi 模块以 MQTT 协议将环境数据上传至 EMQX 服务器，配合 uni-app 上位机实现远程数据监控、阈值告警与设备自动 / 手动控制，完成从感知→传输→计算→控制的完整物联网闭环。

技术栈--
主控：STM32F103C8T6
开发工具：STM32CubeMX、Keil5
操作系统：FreeRTOS（多任务调度、信号量、队列、互斥锁）
通信协议：UART、IIC、MQTT
通信模块：ESP8266（WiFi 透传 + MQTT 协议封装）
服务器：EMQX（MQTT 消息服务器，Docker 部署）
上位机：uni-app（移动端 / 网页端远程监控）
控制逻辑：自动阈值控制、远程手动控制与监控
传感器：温湿度、光照、土壤湿度、降雨量、水泵等环境传感器及硬件设备

功能清单--
多传感器数据实时采集
FreeRTOS 多任务并行处理（采集、上传、控制、按键）
ESP8266 WiFi 联网 + MQTT 协议数据上报
数据上传至 EMQX 消息服务器
上位机实时显示环境数据、日志记录
阈值触发自动灌溉 / 设备动作
支持远程手动控制继电器 / 水泵
系统状态指示、异常告警

项目结构--
SmartFarm_STM32/
├── Core/              # 内核、中断、主函数
├── Drivers/           # 芯片驱动、外设驱动
├── Middlewares/       # FreeRTOS、MQTT、ESP8266驱动
├── BSP/              # 传感器、控制逻辑
├── APP/               # 任务逻辑，全局函数
├── STM32CubeMX.ioc    # 工程配置文件
└── README.md          # 项目说明

硬件清单--
主控：STM32F103C8T6
WiFi 模块：ESP01S
传感器：AHT20、光照传感器、土壤湿度传感器、降雨量传感器
执行器：N-MOSFET模块、水泵
电源：5V/3.3V 稳压模块，12V电源
其他：OLED、按键、PCB双层板
