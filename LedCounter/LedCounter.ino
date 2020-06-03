#define SWITCH 8
#define LED_0 4
#define LED_1 5
#define LED_2 6
#define LED_3 7

byte num = 0;

int cState = 0;
int pState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cState = digitalRead(SWITCH);
  if (pState == LOW && cState == HIGH) {
    if(num++ == 0xF) {
      num = 0;
    }
  } 
  pState = cState;
  digitalWrite(LED_0, ((num & 0b0001) != 0) ? HIGH : LOW);
  digitalWrite(LED_1, ((num & 0b0010) != 0) ? HIGH : LOW);
  digitalWrite(LED_2, ((num & 0b0100) != 0) ? HIGH : LOW);
  digitalWrite(LED_3, ((num & 0b1000) != 0) ? HIGH : LOW);
}
