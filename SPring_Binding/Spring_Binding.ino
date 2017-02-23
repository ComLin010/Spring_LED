#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <String.h>
#define PINONE 6
#define PINTWO 5
uint32_t c;
uint32_t d;
uint32_t f;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PINONE, NEO_GRB + NEO_KHZ800);//灯带初始化
Adafruit_NeoPixel striptwo = Adafruit_NeoPixel(30, PINTWO, NEO_GRB + NEO_KHZ800);
SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  strip.begin();
  strip.show();
  striptwo.begin();
  striptwo.show();
  // 打开端口
  Serial.begin(9600);
  while (!Serial) {
    ; // 等待端口连接 wait for serial port to connect. Needed for Leonardo only
  }

  Serial.println("Goodnight moon!");

  // 为端口设置速率set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  //开启多连接模式命令
  mySerial.println("AT+CIPMUX=1");
  //开启服务器模式    8080为端口号，手机连接时会用到
  delay(2000);
  mySerial.println("AT+CIPSERVER=1,8080");
  delay(3000);
  Serial.print("setp");
}

void loop() // run over and over
{
  //Wifi模块
  String data = "";
  if (mySerial.available() > 0) {
    unsigned long start;
    start = millis();//  为程序运行时间
    while (millis() - start < 100)
    {
      if (mySerial.available() > 0) {
        char sjesh = mySerial.read();//读取串口信息
        data += sjesh;
      }
      if (data.indexOf("\nOK") != -1) {
        break;
      }
    }
    if (data.indexOf(":") > 0) { //      截取字符串
      //          Serial.print(data.indexOf(":")); 获取符号下标
      //          Serial.print(data.length()); 获取字符串长度
      //      Serial.print(data.substring(data.indexOf(":") + 1, data.length()));从符号下标加1位截取
      String sge = data.substring(data.indexOf(":") + 1, data.length());
      //      sge.substring(sge.indexOf(",") + 1,sge.length())
      if (sge == "On") {
        light(1, 4, 1);
        Serial.print("\nOn");
      }
      else if (sge == "Off") {
        Jruo(1, 4);
        Serial.print("\nOff");
      }
      else {
        Serial.print("\nNot");
      }
    }
  }
}
//LED模块
//亮灯效果
void light(int st, int le , int num) {
  st = st - 1;
  c = strip.Color(255, 255, 255);
  c = striptwo.Color(255, 255, 255);
  for (int i = st; i < le; i++) {
    if (num == 1) {
      strip.setPixelColor(i, c);
    }
    else if (num == 2) {
      striptwo.setPixelColor(i, c);
    }
  }
  strip.show();
  switch (num) {
    case 1: strip.show(); break;
    case 2: striptwo.show(); break;
  }
  delay(5);

}
//void lighttwo(int st, int le) {
//  st = st - 1;
//  c = striptwo.Color(255, 255, 255);
//  for (int i = st; i < le; i++) {
//    striptwo.setPixelColor(i, c);
//  }
//  striptwo.show();
//  delay(5);
//
//}
//熄灯效果
void black(int st, int le) {
  st = st - 1;
  c = strip.Color(100, 100, 100);
  for (int i = st; i < le; i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(5);

}
//  渐强模块
void Jquo(int st, int le) {
  st = st - 1;
  for (int s = 0; s < 255; s = s + 1) {
    c = strip.Color(s, s, s);
    for (int i = st; i < le; i++) {
      strip.setPixelColor(i, c);
    }
    strip.show();
    //    delay(1);
  }
}
//  渐弱模块
void Jruo(int st, int le) {
  st = st - 1;
  for (int s = 255; s >= 0; s = s - 1) {
    c = strip.Color(s, s, s);
    for (int i = st; i < le; i++) {
      strip.setPixelColor(i, c);
    }
    strip.show();
    //    delay(1);
  }
}
