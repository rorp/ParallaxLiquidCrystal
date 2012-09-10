#include <SoftwareSerial.h>
#include "ParallaxLiquidCrystal.h"

const int TxPin = 6;

ParallaxLiquidCrystal lcd(TxPin);

void setup() {
  Serial.begin(9600);  
  lcd.begin(2, 16);
  lcd.clear();
  lcd.backlight();
  lcd.println("Hello, world...");
  lcd.print("It's alive!!!");
  Serial.println("OK");
  lcd.beep();
  delay(100);
  lcd.beep();
  lcd.noCursor();
  delay(3000);
  lcd.noDisplay();
  delay(3000);
  lcd.display();
  lcd.cursor();
  lcd.print("x");
  lcd.print("y");
  lcd.print("z");
  lcd.scrollDisplayLeft();
  delay(1000);
  lcd.scrollDisplayRight();
  delay(1000);
  lcd.clear();

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

  lcd.setCursor(8, 1);
  lcd.createChar(1, smiley);
  lcd.write(1);

  lcd.setCursor(15, 0);
  lcd.createChar(1, smiley);
  lcd.write(1);

  Serial.println("OK");

}


void loop() {
  Serial.println("OK");
  delay(5000);
}
