#include <Servo.h>
#define X_AXIS A0
#define PULSE 8
#define BUTTON 7
#define BUTTON_PRESSED LOW
#define CENTER 90

int x;
Servo servo;

int buttonVal;
int pButtonVal;

int offset;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(X_AXIS, INPUT);

  pinMode(BUTTON, INPUT_PULLUP);
  
  servo.attach(PULSE);
  pButtonVal = HIGH;
  offset = 0;
}

void loop() {

  x = map(analogRead(X_AXIS), 0, 1023, 0, 179);
  
  buttonVal = digitalRead(BUTTON);
  if (buttonVal == BUTTON_PRESSED && pButtonVal != buttonVal) {
    offset = x - CENTER;
  }
  pButtonVal = buttonVal;
  
  x += offset;
  x = min(179, max(0, x));

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tOffset: ");
  Serial.print(offset);
  Serial.print("\n");
  
  servo.write(x);
  delay(15);
}

void buttonPress() {
  Serial.write("BUTTON PRESSED");
}
