#include "Arduino.h"
#include "Ultrasonic.h"

#define ULTRASONIC_TRIG_PIN 3
#define ULTRASONIC_ECHO_PIN 2

long duration;
long distance_cm;

void setupUltrasonic() {
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
}

long calculateDistanceInCentimeters()
{
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  distance_cm = (duration * 343) / 20000;
  return distance_cm;
}
