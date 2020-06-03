#include <Servo.h>
#define POTENTIOMETER A0
#define SERVO_PIN 9

Servo myServo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  myServo.attach(SERVO_PIN);

}

int p;
int angle = 0;
int dir = 1;

void loop() {
  // put your main code here, to run repeatedly:
  p = map(analogRead(POTENTIOMETER), 0, 1023, 0, 179);
  Serial.print(p);
  Serial.print("\n");

  myServo.write(p);
  angle += dir;
  if (angle == 180) {
    dir = -1;
  }
  if (angle == 0) {
    dir = 1;
  }
  
}
