#include<Servo.h>
int pos = 1;
int servoPin = 9;
int servoDelay = 25;
int buton1 = 2;
int buton2 = 4;
int buzzer = 5;
int v[14] = {0};
///DE ADAUGAT LEDUL RGB
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);
  pinMode(servoPin, OUTPUT);

  pinMode(buton1, INPUT);
  digitalWrite(buton1, LOW);

  pinMode(buton2, INPUT);
  digitalWrite(buton2, LOW);

  pinMode(buzzer, OUTPUT);
  for (int i = 1; i <= 13; i++)
    v[i] = i * 10;
}

void loop() {
  if (digitalRead(buton1) == HIGH)
  { Serial.print("1 sus ");
    if (pos < 10)
    {
      pos++;
      delay(125);
    }
    else tone(buzzer, 500, 150);
  }

  if (digitalRead(buton2) == HIGH)
  { Serial.print("2 sus ");
    if (pos > 1)
    {
      pos--;
      delay(125);
    }
    else tone(buzzer, 500, 250);
  }

  servo.write(v[pos]);Serial.println(v[pos]);
  delay(25);
}
