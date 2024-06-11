#include <Arduino.h>
#include <WiFi.h>
#include "oled.h"

extern TwoWire i2c_oled ;
extern Adafruit_SSD1306 oled ;

//char* ssid     = "OPPO K11 5G";   /* 要连接网络名称 */
//char* password = "12345678";   /* 要连接网络密码 */
   uint16_t b = 0;
   
void setup() 
{
 
    oled_init();
    //WiFi.mode(WIFI_STA);
    //WiFi.begin(ssid, password);  /* 开始连接网络 */
    WiFi.softAP("esp32","12345678");   
}

void loop() 
{
  b = WiFi.softAPgetStationNum();
  oled.setCursor(0,40); 
  oled.printf("b:%d",b);
      oled.setCursor(0,0); 
    oled.printf("%s",WiFi.softAPSSID());
    oled.setCursor(0,10); 
    uint32_t d=WiFi.softAPIP();
    oled.printf("%d",d);
  //i++;
  oled.display();
  delay(10);
  oled.clearDisplay();
}
