#define X_AXIS A1
#define Y_AXIS A0
#define BUTTON 7
#define BUTTON_PRESSED LOW

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(X_AXIS, INPUT);
  pinMode(Y_AXIS, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

int x;
int y;
int button;

void loop() {
  // put your main code here, to run repeatedly:
  x = map(analogRead(X_AXIS), 0, 1023, -100, 100);
  y = map(analogRead(Y_AXIS), 0, 1023, 100, -100);
  button = digitalRead(BUTTON);
  Serial.print("\nX: ");
  Serial.print(x);
  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tButton: ");
  if (button == BUTTON_PRESSED) {
    Serial.print("Pressed");
  } else {
    Serial.print("Not Pressed");
  }
}
