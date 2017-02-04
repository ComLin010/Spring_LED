#include <SoftwareSerial.h>
#include <String.h>


SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
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
  String data = "";
  if (mySerial.available() > 0) {

    unsigned long start;
    start = millis();

    while (millis() - start < 100)
    {
      if (mySerial.available() > 0)
      {
        char sjesh = mySerial.read();
        data += sjesh;
        //          Serial.print(data.indexOf("\nOK"));
      }
      if (data.indexOf("\nOK") != -1)
      {
        break;
      }

    }
    //      截取字符串
    if (data.indexOf(":") > 0)
    {
      //          Serial.print(data.indexOf(":")); 获取符号下标
      //          Serial.print(data.length()); 获取字符串长度
      //      Serial.print(data.substring(data.indexOf(":") + 1, data.length()));从符号下标加1位截取
      String sge = data.substring(data.indexOf(":") + 1, data.length());
      if (sge == "On") {
        Serial.print("\nOn");
      }
      else if (sge == "Off") {
        Serial.print("\nOff");
      }
      else {
        Serial.print("\nNot");
      }
    }
  }
}
