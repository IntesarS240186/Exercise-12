// 12c: Print out the number of the lit LED to the LCD when the button is pushed
#include <LiquidCrystal.h>                //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 8, 11, 12, 13);  //Create Liquid Crystal Object called LCD
const int ledPins[] = { 2, 3, 4, 5, 6 };
const int numLeds = 5;
const int delayTime = 200;  // 200ms delay between LEDs
const int buttonPin = 7;
int hits = 0, misses = 0;


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
    if (digitalRead(buttonPin) == HIGH && i == 2) {
      // Correct timing
      LCD.setCursor(0, 1);  //Go to 1st column(column 0) and 2nd row(row 1)
      LCD.print("Hit!!!!");
      hits++;
      LCD.setCursor(0, 1);  //Go to 1st column(column 0) and 2nd row(row 1)
      LCD.print("Hit: ");
      LCD.print(hits);

      for (int k = 0; k < 3; k++) {
        for (int j = 0; j < 5; j++) {
          digitalWrite(ledPins[j], HIGH);
        }
        delay(100);
        for (int j = 0; j < 5; j++) {
          digitalWrite(ledPins[j], LOW);
        }
      }
    } else if (digitalRead(buttonPin) == HIGH) {
      // Wrong timing
      LCD.setCursor(0, 1);  //Go to 1st column(column 0) and 2nd row(row 1)
      LCD.print("Miss XD");
      misses++;
      for (int j = 0; j < numLeds; j++) {
        digitalWrite(ledPins[j], LOW);
      }
      delay(1000);
    }
    digitalWrite(ledPins[i], LOW);
  }
}
