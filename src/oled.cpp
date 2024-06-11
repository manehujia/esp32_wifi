
#include "oled.h"
TwoWire i2c_oled = TwoWire(0);
Adafruit_SSD1306 oled = Adafruit_SSD1306(128,64,&i2c_oled);

extern uint16_t g_ledpwmval;

void oled_init()
{
  i2c_oled.begin(4,5,400000);
  oled.begin(SSD1306_SWITCHCAPVCC,0x3c);

  oled.setTextSize(1);
  oled.setTextColor(INVERSE);

  oled.setCursor(0,0); 
  oled.println("text==========");
}

uint16_t i=0;

void oled_show()
{
  oled.setCursor(0,10);

  oled.println("hujia2_yyds");
  oled.setCursor(0,20); 
  oled.printf("text:%d",i);
  oled.setCursor(0,30); 
  oled.printf("g_ledpwmval:%d",g_ledpwmval);
  i++;
  oled.display();
  delay(10);
  oled.clearDisplay();

}
