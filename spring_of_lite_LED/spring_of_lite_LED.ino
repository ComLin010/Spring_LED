#include <Adafruit_NeoPixel.h>
#define PIN 6
uint32_t c;
uint32_t d;
uint32_t f;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
}

void loop() {

  d = strip.Color(0, 0, 0);
  c = strip.Color(255, 255, 255);
  f = strip.Color(100, 100, 100);
//  light(1, 4);
//  Jruo(1, 4);
  delay(2000);
  Jquo(1, 1);  
  Jquo(2, 2);
  Jruo(1, 1);
  Jquo(3, 3);  
  Jruo(2, 2);  
  Jquo(4, 4);
  Jruo(3, 3);
  Jquo(5, 5);
  Jruo(4, 4);
  Jquo(6, 6);
  Jruo(5, 5);
  Jruo(6, 6);
  
  
  
  delay(1000);
  Jquo(3, 3);  
  Jquo(4, 4);
  Jruo(3, 3);
  Jquo(2, 2);
  Jruo(4, 4);  
  Jquo(5, 5);
  Jruo(2, 2);
  Jquo(1, 1);  
  Jruo(5, 5);  
  Jquo(6, 6);
  Jruo(1, 1);
  Jruo(6, 6);
    
  // put your main code here, to run repeatedly:
}
//亮灯效果
void light(int st, int le) {
  st = st - 1;
  c = strip.Color(255, 255, 255);
  for (int i = st; i < le; i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(5);

}
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


