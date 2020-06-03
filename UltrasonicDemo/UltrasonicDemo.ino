#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
long distance_cm;

void setup()
{
  // put your setup code here, to run once:
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  calculateDistance();
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print("\tDistance: ");
  Serial.print(distance_cm);
  Serial.print("cm\n");
  delay(100);
}

void calculateDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance_cm = (duration * 343) / 20000;
}
