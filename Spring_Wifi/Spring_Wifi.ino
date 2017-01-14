#include <SoftwareSerial.h>


SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  mySerial.println("Hello, world?");
  //开启多连接模式命令
  mySerial.println("AT+CIPMUX=1");
  //开启服务器模式    8080为端口号，手机连接时会用到
  delay(2000);
  mySerial.println("AT+CIPSERVER=1,8080");
  delay(3000);
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
