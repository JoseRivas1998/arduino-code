#define MOTOR_1_SPEED_PIN 9
#define MOTOR_1_FORWARD_PIN 8
#define MOTOR_1_BACKWARD_PIN 7

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_1_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_1_BACKWARD_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MOTOR_1_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_1_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_1_SPEED_PIN, 100);
  delay(1000);
  //digitalWrite(MOTOR_1_FORWARD_PIN, LOW);
  //digitalWrite(MOTOR_1_BACKWARD_PIN, HIGH);
  //analogWrite(MOTOR_1_SPEED_PIN, 100);
  //delay(1000);
}
