int matrizPinodosLEDS[] = {3, 4, 5};
float matrizCores[] = {0, 0, 0};
float matrizBranco[] = {0, 0, 0};
float matrizPreto[] = {0, 0, 0};

int mediaLeituras;


void Calibracao() {

  //Calibrando o branco!
  Serial.println("Calibrando o branco");
  delay(5000);
  for (int i = 0; i <= 2; i++) {
    digitalWrite(matrizPinodosLEDS[i], HIGH);
    delay(100);
    mediaSensor(5);
    matrizBranco[i] = mediaLeituras;
    digitalWrite(matrizPinodosLEDS[i], LOW);
    delay(100);
  }

  //Calibrando o preto!
  Serial.println("Calibrando o preto");
  delay(5000);
  for (int i = 0; i <= 2; i++) {
    digitalWrite(matrizPinodosLEDS[i], HIGH);
    delay(100);
    mediaSensor(5);
    matrizPreto[i] = mediaLeituras;
    digitalWrite(matrizPinodosLEDS[i], LOW);
    delay(100);
  }

  //Avisa que a calibragem foi feita
  Serial.println("Sensor Calibrado");
  delay(3000);
}

//Checa a cor
void checaCores() {
  for (int i = 0; i <= 2; i++) {
    digitalWrite(matrizPinodosLEDS[i], HIGH);
    delay(100);
    mediaSensor(5);
    matrizCores[i] = mediaLeituras;
    float cinzaDif = matrizBranco[i] - matrizPreto[i];
    matrizCores[i] = (matrizCores[i] - matrizPreto[i]) / (cinzaDif) * 255;
    digitalWrite(matrizPinodosLEDS[i], LOW);
    delay(100);
  }
}

void mediaSensor(int vezes) {
  int leituras;
  int somatorio = 0;
  for (int i = 0; i < vezes; i++) {
    leituras = analogRead(0);
    somatorio = leituras + somatorio;
    delay(10);
  }
  mediaLeituras = (somatorio) / vezes;
}

void mostraCores() {
  Serial.print("R = ");
  Serial.println(int(matrizCores[0]));
  Serial.print("G = ");
  Serial.println(int(matrizCores[1]));
  Serial.print("B = ");
  Serial.println(int(matrizCores[2]));

}

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT); //LED VERMELHO
  pinMode(4, OUTPUT); //LED AZUL
  pinMode(5, OUTPUT); //LED VERDE
  pinMode(6, INPUT_PULLUP); //PUSH BUTTON
  pinMode(2, INPUT_PULLUP); //PUSH BUTTON INTERRUPÇÃO
  attachInterrupt(digitalPinToInterrupt(2), Calibracao, FALLING);
}

void loop()
{
  if (digitalRead(6) == LOW)
  {
    checaCores();
    mostraCores();
  }
}
