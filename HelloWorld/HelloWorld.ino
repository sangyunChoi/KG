#include <Arduino.h>
#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);
void setup(void)
{
  u8x8.begin();
  u8x8.setPowerSave(0);
  Serial.begin(9600);
}
void loop(void)
{
  String sub_uga = "";
  if (Serial.available() > 0) {
    String uga = Serial.readStringUntil('\n');
    int start = uga.indexOf('a');
    int end = uga.indexOf('b');
    sub_uga = uga.substring(start+1, end);
    Serial.println(sub_uga);
    int uga_num = sub_uga.toInt();
    Serial.println(uga_num);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,1,sub_uga.c_str());
  u8x8.setInverseFont(1);
  u8x8.refreshDisplay();
  delay(2000);
  }
}