byte displayDig[10][7] =
{
  { 0, 0, 0, 0, 0, 0, 1 }, //DIGITO 0
  { 1, 0, 0, 1, 1, 1, 1 }, //DIGITO 1
  { 0, 0, 1, 0, 0, 1, 0 }, //DIGITO 2
  { 0, 0, 0, 0, 1, 1, 0 }, //DIGITO 3
  { 1, 0, 0, 1, 1, 0, 0 }, //DIGITO 4
  { 0, 1, 0, 0, 1, 0, 0 }, //DIGITO 5
  { 0, 1, 0, 0, 0, 0, 0 }, //DIGITO 6
  { 0, 0, 0, 1, 1, 1, 1 }, //DIGITO 7
  { 0, 0, 0, 0, 0, 0, 0 }, //DIGITO 8
  { 0, 0, 0, 1, 1, 0, 0 }, //DIGITO 9
};

int auxC;
int auxD;
int contador = 0;

void atualizaDisplay(byte digit) { //FUNÇÃO QUE MODIFICA O DISPLAY
  byte pino = 1;
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos) { //PARA "contadorSegmentos"
    digitalWrite(pino, displayDig[digit][contadorSegmentos]);
    ++pino;
  }
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
}

void setup()
{
  pinMode(1, OUTPUT); //PINO 2 -> SEGMENTO A
  pinMode(2, OUTPUT); //PINO 3 -> SEGMENTO B
  pinMode(3, OUTPUT); //PINO 4 -> SEGMENTO C
  pinMode(4, OUTPUT); //PINO 5 -> SEGMENTO D
  pinMode(5, OUTPUT); //PINO 6 -> SEGMENTO E
  pinMode(6, OUTPUT); //PINO 7 -> SEGMENTO F
  pinMode(7, OUTPUT); //PINO 8 -> SEGMENTO G

  pinMode(8, INPUT); //PINO 8 -> PUSH CRESCENTE
  pinMode(9, INPUT); //PINO 8 -> PUSH DESCRECENTE

}

void loop()
{
  auxC = digitalRead(8);
  auxD = digitalRead(9);

  if (auxC == LOW) {
    if (contador == 9) {
      contador = contador;
    } else {
      contador++;
    }
  }

  if (auxD == LOW) {
    if (contador == 0) {
      contador = contador;
    } else {
      contador--;
    }
  }

  atualizaDisplay(contador); //ATUALIZA O VALOR DE CONTADOR NO DISPLAY
  delay(50);
}
