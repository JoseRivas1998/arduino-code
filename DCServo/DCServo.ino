#define MOTOR_1_SPEED_PIN 9
#define MOTOR_1_FORWARD_PIN 8
#define MOTOR_1_BACKWARD_PIN 7
#define MOTOR_2_SPEED_PIN 6
#define MOTOR_2_FORWARD_PIN 4
#define MOTOR_2_BACKWARD_PIN 5

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_1_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_1_BACKWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_2_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_BACKWARD_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MOTOR_1_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_1_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_1_SPEED_PIN, 200);
  digitalWrite(MOTOR_2_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_2_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_2_SPEED_PIN, 240);
  delay(1000);
}
