// 12a: Make the LEDs flash
const int ledPins[] = {2, 3, 4, 5, 6};
const int numLeds = 5;
const int delayTime = 200; // 200ms delay between LEDs

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}