#define RED_PIN 11
#define BLUE_PIN 10
#define GREEN_PIN 9

#define SERIAL_PORT 9600

long rgb = 0;
int r = 0;
int g = 0;
int b = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_PORT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*int r = (rgb >> 16) & 0xFF;
  int g = (rgb >> 8) & 0xFF;
  int b = rgb & 0xFF;*/

  if (r == 0 && g == 0 && b < 0xFF) {
    b++;
  } else if (r == 0 && g <= 0xFF && b > 0) {
    g++;
    b--;
  } else if (r <= 0xFF && g > 0 && b == 0) {
    r++;
    g--;
  } else if (r > 0 && g == 0 && b <= 0xFF) {
    b++;
    r--;
  }

  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);

  delay(5);

  /*if (rgb == 0xFFFFFF) {
    rgb = 0;
  } else {
    rgb++;
  }*/
}
