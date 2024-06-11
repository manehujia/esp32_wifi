#include <Arduino.h>
#include <WiFi.h>
#include "oled.h"

extern TwoWire i2c_oled;
extern Adafruit_SSD1306 oled;

// char* ssid     = "OPPO K11 5G";   /* 要连接网络名称 */
// char* password = "12345678";   /* 要连接网络密码 */
uint16_t b = 0;

void setup()
{

  oled_init();
  WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid, password);  /* 开始连接网络 */
  WiFi.config(IPAddress(192, 168, 1, 123), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0), IPAddress(8, 8, 8, 8));
  // WiFi.softAP("esp32","12345678");
}

void loop()
{

  /*   WiFi.localIP();// 从 WiFi 对象获取本地 IP 地址
    WiFi.gatewayIP();// 从 WiFi 对象获取网关 IP 地址
    WiFi.subnetMask(); // 从 WiFi 对象获取子网掩码
    WiFi.dnsIP();// 从 WiFi 对象获取 DNS 服务器 IP 地址 */

  b = WiFi.softAPgetStationNum();
  oled.setCursor(0, 0);
  oled.printf("localIP:%s", WiFi.localIP().toString().c_str());
  oled.setCursor(0, 10);
  oled.printf("wayIP:%s", WiFi.gatewayIP().toString().c_str());
  oled.setCursor(0, 20);
  oled.printf("subnetMask:%s", WiFi.subnetMask().toString().c_str());
  oled.setCursor(0, 30);

  oled.printf("DNS IP: %s", WiFi.dnsIP().toString().c_str());
  oled.setCursor(0, 40);

  oled.display();
  delay(20);
  oled.clearDisplay();
}
