#include "Rover.h"
#include "Ultrasonic.h"
#include "MovementIndicator.h"

#define DISTANCE_THRESHOLD 10

#define BUZZER_PIN 11

long timeSinceLastBeep;
long timeToNextBeep;

void setup() {
  // put your setup code here, to run once:
  setupRover();
  setupUltrasonic();
  setupIndicator();

  randomSeed(analogRead(0));

  tone(BUZZER_PIN, 261);
  delay(62);
  tone(BUZZER_PIN, 294);
  delay(62);
  tone(BUZZER_PIN, 330);
  delay(62);
  tone(BUZZER_PIN, 349);
  delay(62);
  tone(BUZZER_PIN, 392);
  delay(62);
  tone(BUZZER_PIN, 440);
  delay(62);
  tone(BUZZER_PIN, 493);
  delay(62);
  tone(BUZZER_PIN, 523);
  delay(62);

  noTone(BUZZER_PIN);
  timeSinceLastBeep = 0;
  timeToNextBeep = random(2000, 5000);

  Serial.begin(9600);
}

void loop() {
  long distance_cm = calculateDistanceInCentimeters();
  if (distance_cm > DISTANCE_THRESHOLD) {
    setMovementStatus(MOVING);
    moveForward();
    if (timeSinceLastBeep >= timeToNextBeep) {
      tone(BUZZER_PIN, randomFrequency(), 250);
      timeSinceLastBeep = 0;
      timeToNextBeep = random(2000, 5000);
    }
  } else {
    setMovementStatus(NOT_MOVING);
    stopMoving();
    timeSinceLastBeep = 0;
    for (int i = 0; i < 1000; i++) {
      tone(BUZZER_PIN, 1000 - i);
      delay(1);
    }
    noTone(BUZZER_PIN);
    moveBackward();
    int reverseTime = random(1000, 2001);
    int numSlides = 16;
    int slideTime = reverseTime / numSlides;
    for (int i = 0; i < numSlides; i++) {
      for (int j = 0; j < slideTime; j++) {
        tone(BUZZER_PIN, map((i % 2 == 0 ? j : slideTime - j), 0, slideTime, 500, 2000));
        delay(1);
      }
    }
    noTone(BUZZER_PIN);
    if (random(2) == 0) {
      pivotLeft();
    } else {
      pivotRight();
    }
    int delayTime = random(500, 2001);
    for (int i = 0; i < delayTime; i++) {
      tone(BUZZER_PIN, map(i, 0, delayTime, 261, 523));
      delay(1);
    }
    noTone(BUZZER_PIN);
  }
  timeSinceLastBeep += 100;
  delay(100);
}

int randomFrequency() {
  switch (random(0, 8)) {
    case 0:
      return 261;
    case 1:
      return 294;
    case 2:
      return 330;
    case 3:
      return 349;
    case 4:
      return 392;
    case 5:
      return 440;
    case 6:
      return 493;
    case 7:
      return 523;
  }
  return 0;
}
