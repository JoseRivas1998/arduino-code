#include "Arduino.h"
#include "MovementIndicator.h"

#define GREEN_PIN 10
#define RED_PIN 12

void setupIndicator() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void setMovementStatus(MOVEMENT_STATUS movement_status) {
  switch (movement_status) {
    case MOVING:
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      break;
    case NOT_MOVING:
    case REVERSING:
    default: 
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      break;
  }
}
