﻿# Spring_LED
 * 想做生命之风的衣服效果
 
 * 第一版代码实现了渐变变换
 
 * 下一步是wifi和多项控制的接入
## 1.1
 * Wifi使用了esp8266方案

 * 还在尝试代码

 * 问题出现在TXD，RXD线接反（ESP8266与USB-TTL需要RX,TX交叉连接。）

 * GPIO0这个引脚在烧程序的时候必须接GND（接低电平），烧完程序后想要进行应用的话，必须将这个引脚拉高或者悬空。
## 1.2
 * Wifi模块成功接入Adruino mega 2560

 * 串口监视器有部分乱码，尚未明确对以后数据判断是否有影响

 * 编写监听串口代码
## 1.3
 * 程序成功获取手机发来的信息，并截取最后内容段进行判断

 * 下一步将手机控制代码和灯带结合