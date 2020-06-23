#include "Arduino.h"
#include "Rover.h"
#define MOTOR_1_SPEED_PIN 9
#define MOTOR_1_FORWARD_PIN 8
#define MOTOR_1_BACKWARD_PIN 7
#define MOTOR_2_SPEED_PIN 6
#define MOTOR_2_FORWARD_PIN 4
#define MOTOR_2_BACKWARD_PIN 5

void setupRover() {
  pinMode(MOTOR_1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_1_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_1_BACKWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_2_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_BACKWARD_PIN, OUTPUT);
}

void pivotLeft() {
  digitalWrite(MOTOR_1_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_1_BACKWARD_PIN, HIGH);
  analogWrite(MOTOR_1_SPEED_PIN, 200);
  digitalWrite(MOTOR_2_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_2_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_2_SPEED_PIN, 0);
}

void pivotRight() {
  digitalWrite(MOTOR_1_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_1_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_1_SPEED_PIN, 0);
  digitalWrite(MOTOR_2_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_2_BACKWARD_PIN, HIGH);
  analogWrite(MOTOR_2_SPEED_PIN, 240);
}

void moveForward() {
  digitalWrite(MOTOR_1_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_1_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_1_SPEED_PIN, 200);
  digitalWrite(MOTOR_2_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_2_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_2_SPEED_PIN, 240);
}

void moveBackward() {
  digitalWrite(MOTOR_1_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_1_BACKWARD_PIN, HIGH);
  analogWrite(MOTOR_1_SPEED_PIN, 200);
  digitalWrite(MOTOR_2_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_2_BACKWARD_PIN, HIGH);
  analogWrite(MOTOR_2_SPEED_PIN, 240);
}

void stopMoving() {
  analogWrite(MOTOR_1_SPEED_PIN, 0);
  analogWrite(MOTOR_2_SPEED_PIN, 0);
}
