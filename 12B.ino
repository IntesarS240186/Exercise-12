// 12b: Print out the number of the lit LED to the LCD when the button is pushed
#include <LiquidCrystal.h>                //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 8, 11, 12, 13);  //Create Liquid Crystal Object called LCD
const int ledPins[] = { 2, 3, 4, 5, 6 };
const int numLeds = 5;
const int delayTime = 200;  // 200ms delay between LEDs
const int buttonPin = 7;


void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  LCD.begin(16, 2);
  LCD.setCursor(0, 0);            //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("LED Button Game:");  //Print Message on First Row
  // Initialize LED pins
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    if (digitalRead(buttonPin) == HIGH) {
      LCD.setCursor(0, 0);
      LCD.clear();
      LCD.print("LED: ");
      LCD.print(i + 1);
    }
    digitalWrite(ledPins[i], LOW);
  }
}