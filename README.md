# Spring_LED
 * 想做生命之风的衣服效果
 
 * 第一版代码实现了渐变变换
 
 * 下一步是wifi和多项控制的接入
 
## 1.1
 * Wifi使用了esp8266方案

 * 还在尝试代码

 * 问题出现在TXD，RXD线接反（ESP8266与USB-TTL需要RX,TX交叉连接。）

 * GPIO0这个引脚在烧程序的时候必须接GND（接低电平），烧完程序后想要进行应用的话，必须将这个引脚拉高或者悬空。

<<<<<<< HEAD

                                                                                          Spring of Life_LED
=======
   Spring of Life_LED
>>>>>>> 8e31e57af61fcf2afb1f5b68d48dd58393f6a069
