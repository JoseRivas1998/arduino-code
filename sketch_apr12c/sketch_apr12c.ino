#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char text[2][16] = {{'H', 'e', 'l', 'l', 'o', '\0'}, {'W', 'o', 'r', 'l', 'd', '!', '\0'}};

int i;
int j;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  i = 0;
  j = 0;
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  /*lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text[0]);
  delay(1000);*/
  if (i < 16) {
    if (text[0][i] == '\0') {
      i = 16;
    } else {
      lcd.setCursor(i, 0);
      lcd.print(text[0][i]);
      i++;
    }
  } else if (j < 16) {
    if (text[1][j] == '\0') {
      j = 16;
    } else {
      lcd.setCursor(j, 1);
      lcd.print(text[1][j]);
      j++;
    }
  }
  delay(50);
}
