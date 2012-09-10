#include "ParallaxLiquidCrystal.h"
#include <Arduino.h>

#define SCROLL_LEFT 8
#define SCROLL_RIGHT 9
#define CLEAR 12
#define BACKLITE_ON 17
#define BACKLITE_OFF 18
#define LCD_OFF 21
#define CURSOR_OFF 22
#define CURSOR_BLOCK 23
#define CURSOR_UNDERLINE 24
#define LCD_ON 24
#define SET_CURSOR 128
#define ROW 20
#define QUARTER_NOTE 212
#define A_TONE 220
#define CUSTOM_CHARACTER_0 248
#define CUSTOM_CHARACTER_7 255

#define DELAY 5

ParallaxLiquidCrystal::ParallaxLiquidCrystal(int pin, int baud) : serial(SoftwareSerial(255, pin)), baud(baud) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

ParallaxLiquidCrystal::~ParallaxLiquidCrystal() {
  serial.end();
  delay(DELAY);
}

void ParallaxLiquidCrystal::begin(uint8_t numCols, uint8_t numRows, uint8_t) {
  serial.begin(baud);
  this->numCols = constrain(numCols, 2, 4);
  this->numRows = this->numCols == 2 ? constrain(numRows, 1, 16) : constrain(numRows, 1, 20);
  delay(DELAY);
  display();
}

void ParallaxLiquidCrystal::clear() {
  serial.write(CLEAR);
  delay(DELAY);
}

void ParallaxLiquidCrystal::display() {
  serial.write(LCD_ON);
  delay(DELAY);
}

void ParallaxLiquidCrystal::noDisplay() {
  noBacklight();
  serial.write(LCD_OFF);
  delay(DELAY);
}

void ParallaxLiquidCrystal::noBacklight() {
  serial.write(BACKLITE_OFF);
  delay(DELAY);
}

void ParallaxLiquidCrystal::backlight() {
  serial.write(BACKLITE_ON);
  delay(DELAY);
}

void ParallaxLiquidCrystal::noCursor() {
  serial.write(CURSOR_OFF);
  delay(DELAY);
}

void ParallaxLiquidCrystal::cursor() {
  serial.write(CURSOR_UNDERLINE);
  delay(DELAY);
}

void ParallaxLiquidCrystal::scrollDisplayLeft() {
  serial.write(SCROLL_LEFT);
  delay(DELAY);
}

void ParallaxLiquidCrystal::scrollDisplayRight() {
  serial.write(SCROLL_RIGHT);
  delay(DELAY);
}


size_t ParallaxLiquidCrystal::write(uint8_t b) {
  if (b == '\n')
    return 0;
  return serial.write(b);
}

void ParallaxLiquidCrystal::beep() {
  serial.write(QUARTER_NOTE);
  serial.write(A_TONE);
}

void ParallaxLiquidCrystal::setCursor(uint8_t col, uint8_t row) {
  int r = constrain(row, 0, numRows - 1);
  int c = constrain(col, 0, numCols - 1);  
  write(SET_CURSOR + ROW * r + col);
  delay(DELAY);
}

void ParallaxLiquidCrystal::createChar(uint8_t num, uint8_t* data) {
  int index = constrain(num, 0, 7);
  index = map(num, 0, 7, CUSTOM_CHARACTER_0, CUSTOM_CHARACTER_7);
  write(index);
  for (int i=0; i < 8; ++i) {
    write(data[i]);
  }
  delay(DELAY);
}
