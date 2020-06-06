#define MOTOR_1_SPEED_PIN 9
#define MOTOR_1_FORWARD_PIN 8
#define MOTOR_1_BACKWARD_PIN 7
#define MOTOR_2_SPEED_PIN 6
#define MOTOR_2_FORWARD_PIN 4
#define MOTOR_2_BACKWARD_PIN 5

#define ULTRASONIC_TRIG_PIN 3
#define ULTRASONIC_ECHO_PIN 2

#define DISTANCE_THRESHOLD 10

long duration;
long distance_cm;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_1_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_1_BACKWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_2_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_BACKWARD_PIN, OUTPUT);
  
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);

  randomSeed(analogRead(0));
  
  Serial.begin(9600);
}

void loop() {
  calculateDistance();
  if (distance_cm > DISTANCE_THRESHOLD) {
    moveForward();
  } else {
    stopMoving();
    delay(1000);
    moveBackward();
    delay(random(1000, 2001));
    if(random(2) == 0) {
      pivotLeft();
    } else {
      pivotRight();
    }
    delay(random(1000, 2001));
  }
  delay(100);
}

void calculateDistance()
{
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  distance_cm = (duration * 343) / 20000;
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
