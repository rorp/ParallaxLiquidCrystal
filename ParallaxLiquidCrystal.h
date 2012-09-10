#ifndef parallax_liquid_crystal_h
#define parallax_liquid_crystal_h

#include <SoftwareSerial.h>

class ParallaxLiquidCrystal : public Print {
  SoftwareSerial serial;
  int baud;
  uint8_t numCols, numRows;
public:
  ParallaxLiquidCrystal(int pin, int baud=9600);
  ~ParallaxLiquidCrystal();
  void begin(uint8_t cols=2, uint8_t rows=16, uint8_t charsize = 0x0);
  void clear();
  void home();

  void noDisplay();
  void display();
  
  void noBlink() {}
  void blink() {}
  
  void noCursor();
  void cursor();
  
  void noBacklight();
  void backlight();
  
  void beep();
  
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight() {}
  void rightToLeft() {}
  void autoscroll() {}
  void noAutoscroll() {}

  void createChar(uint8_t num, uint8_t* data);
  void setCursor(uint8_t, uint8_t);
  virtual size_t write(uint8_t);

  using Print::write;

};

#endif parallax_liquid_crystal_h
 
