//Notas extraidas da biblioteca pitches
#define NOTE_C5  1047
#define NOTE_D5 1175
#define NOTE_E5  1319
#define NOTE_F5  1397
#define NOTE_G5  1568
#define NOTE_A5  1760
#define NOTE_AS5 1865
#define NOTE_B5 1976
#define NOTE_C6  2093
#define NOTE_D6  2349
#define NOTE_E6  2637
#define NOTE_F6  2794


//Pinos
#define buzzer 10
#define btn1 A0
#define btn2 A1
#define btn3 A3

#define verde1 2
#define amarelo1 3
#define azul1 4
#define vermelho1 5
#define verde2 6
#define amarelo2 7
#define azul2 9
#define vermelho2 11


//funções
void tocaMusica(int * vetorNotas, int * vetorDelays, int qtdeNotas);
void tocaSilentNight();
void tocaDeckTheHalls();
void tocaJingleBell();
void acendeLEDs(bool acendeVerde1, bool acendeAmarelo1, bool acendeAzul1, bool acendeVermelho1, bool acendeVerde2, bool acendeAmarelo2, bool acendeAzul2, bool acendeVermelho2);
void acendeNota(int nota);

void setup() {

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

  pinMode(verde1, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(azul1, OUTPUT);
  pinMode(vermelho1, OUTPUT);

  pinMode(verde2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(azul2, OUTPUT);
  pinMode(vermelho2, OUTPUT);

  pinMode(buzzer, OUTPUT);


  acendeLEDs(0,0,0,0,0,0,0,0);

}

void loop() {

  if (digitalRead(btn1)) {
    tocaJingleBell();
  } else if (digitalRead(btn2)) {
    tocaDeckTheHalls();
  } else if ( digitalRead(btn3)) {
    tocaSilentNight();
  }
  delay(200);

}

void tocaJingleBell() {
  //Notas B5,D6,G5,A5,C6,D5,E5,AS5
  int notas[] = {NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_A5, NOTE_C6, NOTE_B5, NOTE_D5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_A5, NOTE_AS5, NOTE_B5};
  int delays[] = {300, 300, 500, 300, 300, 600, 400, 300, 200, 300, 600, 300, 300, 400, 300, 300, 600, 400, 300, 300, 200, 400, 600, 300, 300, 500, 300, 300, 600, 400, 300, 200, 300, 600, 300, 300, 400, 300, 300, 300, 400, 400, 300, 300, 200, 600, 300, 300, 400, 300, 500, 700, 300, 300, 400, 300, 500, 700, 300, 300, 400, 300, 400, 400, 300, 300, 300, 400, 300, 800, 300, 300, 400, 300, 500, 700, 300, 300, 400, 300, 500, 700, 300, 300, 400, 300, 400, 400, 300, 300, 300, 400, 300, 800};
  tocaMusica(notas, delays, 94);

}

void tocaDeckTheHalls() {
  //Notas C6,AS5,A5,G5,F5,B5,D6,E6,F6
  int notas[] = {NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5};
  int delays[] = {400, 500, 400, 300, 300, 300, 300, 500, 300, 300, 300, 300, 500, 300, 300, 500, 500, 350, 450, 350, 250, 300, 300, 300, 500, 300, 300, 300, 300, 500, 300, 300, 500, 500, 300, 300, 400, 300, 400, 300, 300, 500, 300, 400, 400, 400, 500, 300, 300, 400, 500, 400, 500, 400, 300, 300, 300, 300, 500, 300, 300, 300, 300, 500, 300, 300, 500, 400};
  tocaMusica(notas, delays, 68);

}

void tocaSilentNight() {
  //Notas G5,A5,E5,D6,B5,C6,F6,E6,C5,F5,D5
  int notas[] = {NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D6, NOTE_D6, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_A5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D6, NOTE_D6, NOTE_F6, NOTE_D6, NOTE_B5, NOTE_C6, NOTE_E6, NOTE_C5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_C5};
  int delays[] = {800, 400, 400, 1300, 800, 400, 400, 1300, 800, 600, 1300, 800, 600, 1300, 800, 600, 800, 500, 500, 800, 500, 500, 800, 800, 600, 800, 500, 500, 800, 500, 500, 100, 600, 600, 800, 600, 500, 100, 100, 600, 600, 800, 600, 500, 800, 1000};
  tocaMusica(notas, delays, 46 );

}


void tocaMusica(int * vetorNotas, int * vetorDelays, int qtdeNotas) {
  for (int c = 0; c < qtdeNotas; c++) {
    vetorNotas[c] == 0 ? noTone(buzzer) :  tone (buzzer, vetorNotas[c], vetorDelays[c]);
    acendeNota(vetorNotas[c]);
    delay(vetorDelays[c]);
  }
         acendeLEDs(0,0,0,0,0,0,0,0);

}

void acendeNota(int nota) {
       acendeLEDs(0,0,0,0,0,0,0,0);

  switch (nota) {
    case NOTE_C5 :
acendeLEDs(1,0,0,1,1,0,0,1);
      break;
      
    case NOTE_D5 :
acendeLEDs(0,1,0,1,0,1,0,1);
      break;
      
    case NOTE_E5 :
acendeLEDs(1,1,1,1,0,0,0,0);
      break;
      
    case NOTE_F5 :
acendeLEDs(0,0,0,0,1,1,1,1);
      break;
      
    case NOTE_G5 :
acendeLEDs(0,1,1,0,0,1,1,0);
      break;
      
    case NOTE_A5 :
acendeLEDs(0,1,0,1,1,0,1,0);
      break;
      
    case NOTE_AS5 :
acendeLEDs(0,0,1,1,0,0,1,1);
      break;

    case NOTE_B5 :
acendeLEDs(1,1,0,0,1,1,0,0);
      break;

    case NOTE_C6 :
acendeLEDs(1,0,1,0,1,0,1,0);
      break;

    case NOTE_D6 :
acendeLEDs(1,1,0,0,0,0,1,1);
      break;
      
    case NOTE_E6 :
acendeLEDs(0,1,1,0,0,0,1,1);
      break;
      
    case NOTE_F6 :
      acendeLEDs(1,0,0,1,1,1,0,0);
      break;

    default:
     acendeLEDs(0,0,0,0,0,0,0,0);
  }
}

void acendeLEDs(bool acendeVerde1, bool acendeAmarelo1, bool acendeAzul1, bool acendeVermelho1, bool acendeVerde2, bool acendeAmarelo2, bool acendeAzul2, bool acendeVermelho2){

  digitalWrite(verde1, acendeVerde1);
  digitalWrite(amarelo1, acendeAmarelo1);
  digitalWrite(azul1, acendeAzul1);
  digitalWrite(vermelho1, acendeVermelho1);

  digitalWrite(verde2, acendeVerde2);
  digitalWrite(amarelo2, acendeAmarelo2);
  digitalWrite(azul2, acendeAzul2);
  digitalWrite(vermelho2, acendeVermelho2);

}
