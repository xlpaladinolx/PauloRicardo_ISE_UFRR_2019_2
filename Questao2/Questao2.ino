
#include <Servo.h>

const int pinTerreo = 3;
const int pin1Andar = 4;
const int pin2Andar = 5;
int auxTerreo;
int aux1Andar;
int aux2Andar;
int  Terreo = 0;
int Andar1 = 90;
int Andar2 = 180;
Servo servo_9;

void setup()
{
  Serial.begin(9600);
  servo_9.attach(9);
  pinMode(pinTerreo, INPUT_PULLUP);
  pinMode(pin1Andar, INPUT_PULLUP);
  pinMode(pin2Andar, INPUT_PULLUP);
  servo_9.write(Terreo);
}

void loop()
{
  auxTerreo = digitalRead(pinTerreo);
  aux1Andar = digitalRead(pin1Andar);
  aux2Andar = digitalRead(pin2Andar);
  Serial.println(auxTerreo);
  if (auxTerreo == LOW) {
    Serial.println(auxTerreo);
    servo_9.write(Terreo);
  }
  if (aux1Andar == LOW) {
    Serial.println(aux1Andar);
    servo_9.write(Andar1);
  }
  if (aux2Andar == LOW) {
    Serial.println(aux2Andar);
    servo_9.write(Andar2);
  }
}
