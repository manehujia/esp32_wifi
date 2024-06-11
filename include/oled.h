#ifndef OLED_H
#define OLED_H
#include <Arduino.h>
#include <Wire.h>  //IIC的库
#include <Adafruit_GFX.h>  //OLED显示屏的库
#include <adafruit_ssd1306.h>



void oled_init(void);
void oled_show(void);

#endif