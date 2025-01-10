// 12f: Print out the number of the lit LED to the LCD when the button is pushed
#include <stdlib.h>
#include <LiquidCrystal.h>                //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 8, 11, 12, 13);  //Create Liquid Crystal Object called LCD
const int ledPins[] = { 2, 3, 4, 5, 6 };
const int numLeds = 5;
int delayTime = 200;  // 200ms delay between LEDs
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
  if (hits < 8) {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(delayTime);
      
      if (digitalRead(buttonPin) == HIGH && i == 2) {
        // Correct timing
        LCD.setCursor(0, 1);
        LCD.print("Hit!!!!!!!!!!     ");
        hits++;
        LCD.setCursor(0, 1);
        LCD.print("Hit: ");
        LCD.print(hits);
        delayTime = delayTime - 15;
        delayTime = max(delayTime, 50);

        // Flash all LEDs 3 times for feedback
        for (int k = 0; k < 3; k++) {
          for (int j = 0; j < numLeds; j++) {
            digitalWrite(ledPins[j], HIGH);
          }
          delay(100);
          for (int j = 0; j < numLeds; j++) {
            digitalWrite(ledPins[j], LOW);
          }
        }
      } else if (digitalRead(buttonPin) == HIGH) {
        // Wrong timing
        LCD.setCursor(0, 1);
        LCD.print("Miss XD           ");
        misses++;

        // Print the number of misses every 5 misses
        if (misses % 5 == 0) {
          LCD.setCursor(0, 1);
          LCD.print("Misses: ");
          LCD.print(misses);
        }
        for (int j = 0; j < numLeds; j++) {
          digitalWrite(ledPins[j], LOW);
        }
        delay(1000);
      }
      digitalWrite(ledPins[i], LOW);
    }
  } else if (hits < 10) {
    int randLed = random(0, numLeds);
    digitalWrite(ledPins[randLed], HIGH);
    delay(delayTime);
    
    if (digitalRead(buttonPin) == HIGH && randLed == 2) {
      // Correct timing
      LCD.setCursor(0, 1);
      LCD.print("Hit!!!!!!!!!!     ");
      hits++;
      LCD.setCursor(0, 1);
      LCD.print("Hit: ");
      LCD.print(hits);
      delayTime = delayTime - 15;
      delayTime = max(delayTime, 50);

      // Flash all LEDs 3 times for feedback
      for (int k = 0; k < 3; k++) {
        for (int j = 0; j < numLeds; j++) {
          digitalWrite(ledPins[j], HIGH);
        }
        delay(100);
        for (int j = 0; j < numLeds; j++) {
          digitalWrite(ledPins[j], LOW);
        }
      }
    } else if (digitalRead(buttonPin) == HIGH) {
      // Wrong timing
      LCD.setCursor(0, 1);
      LCD.print("Miss XD           ");
      misses++;

      // Print the number of misses every 5 misses
      if (misses % 5 == 0) {
        LCD.setCursor(0, 1);
        LCD.print("Misses: ");
        LCD.print(misses);
      }
      for (int j = 0; j < numLeds; j++) {
        digitalWrite(ledPins[j], LOW);
      }
      delay(1000);
    }
    digitalWrite(ledPins[randLed], LOW);
  }

  // Check for game win condition
  if (hits >= 10) {
    LCD.clear();
    LCD.print("You Win!");
    while (true);  // Stop the program
  }
}
