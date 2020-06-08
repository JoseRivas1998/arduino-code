#define MOTOR_1_SPEED_PIN 9
#define MOTOR_1_FORWARD_PIN 8
#define MOTOR_1_BACKWARD_PIN 7
#define MOTOR_2_SPEED_PIN 6
#define MOTOR_2_FORWARD_PIN 4
#define MOTOR_2_BACKWARD_PIN 5

#define ULTRASONIC_TRIG_PIN 3
#define ULTRASONIC_ECHO_PIN 2

#define DISTANCE_THRESHOLD 10

#define GREEN_PIN 10
#define RED_PIN 12

#define BUZZER_PIN 11

long duration;
long distance_cm;
long timeSinceLastBeep;
long timeToNextBeep;

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

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

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
  calculateDistance();
  if (distance_cm > DISTANCE_THRESHOLD) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    moveForward();
    if (timeSinceLastBeep >= timeToNextBeep) {
      tone(BUZZER_PIN, randomFrequency(), 250);
      timeSinceLastBeep = 0;
      timeToNextBeep = random(2000, 5000);
    }
  } else {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
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
