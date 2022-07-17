/*Simon-Says (Gênio)

   O jogo pode ser rodado com opção de alocação dinâmica ou estática de memória. A alocação estática, consome 11% de storage e 4% de memória dinâmica, enquanto a alocação dinâmica consome 15% de storage e
   2% de memória dinâmica (Arduino Uno). As linhas de código referente a opção de memória estão marcadas com um comentáio, logo depois dos defines, (declaração do vetor que vai armazenar a sequência) e inicio da
   função adicionaNovo() (inserção de um novo item na sequência). O jogo está originalmente setado com alocação estática.

   Letícia Pegoraro Garcez 2019
*/
//entradas
#define led1 8
#define led2 9
#define led3 10
#define led4 11
#define btn1 7
#define btn2 6
#define btn3 5
#define btn4 4
#define sb 12
//sounds for each led and one for the wrong function.
#define SOUND1 1047
#define SOUND2 1175
#define SOUND3 1319
#define SOUND4 1397
#define SOUND_WRONG 2093

int posicoes;
//int *sequencia = (int*)malloc(sizeof(int));//ALOCAÇÃO DINÂMICA
int sequencia[30];//ALOCAÇÃO ESTÁTICA
void adicionaNovo (void);
void piscaLed(int n);
void playSequencia(void);
void confere(void);
void playWrong(void);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(sb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  adicionaNovo();//Insere a sequência
  delay(700);
  confere();//Confere a sequência.
  delay(800);

}

void adicionaNovo(void) {
  /*
    sequencia = (int*) realloc (sequencia,(posicoes+1)*sizeof(int));
    if(sequencia == NULL){//caso ocorra algum problema
    playWrong();
    }
  *///ALOCAÇÃO DINÂMICA

  if (posicoes != 0) { //Exibir o que tenho armazenado no vetor
    playSequencia();
  }
  randomSeed(millis());//A seed do random vira o tempo atual de execução, o que faz com que as sequencias possam ser diferentes
  sequencia[posicoes] = random(1, 5); //Gera um random entre 1 e 4
  piscaLed(sequencia[posicoes]);
  posicoes++;

}

void piscaLed (int n) { //Os valores 1,2,3,4 são associados ás saídas.
  switch (n) {
    case 1:
      digitalWrite(led1, HIGH);
      tone(sb, SOUND1);
      delay(500);
      noTone(sb);
      digitalWrite(led1, LOW);
      break;
    case 2:
      digitalWrite(led2, HIGH);
      tone(sb, SOUND2);
      delay(500);
      digitalWrite(led2, LOW);
      noTone(sb);
      break;
    case 3:
      digitalWrite(led3, HIGH);
      tone(sb, SOUND3);
      delay(500);
      digitalWrite(led3, LOW);
      noTone(sb);
      break;
    case 4:
      digitalWrite(led4, HIGH);
      tone(sb, SOUND4);
      delay(500);
      noTone(sb);
      digitalWrite(led4, LOW);
  }
}

void playSequencia(void) { //sem o que explicar aqui.
  for (int contador = 0; contador < posicoes; contador++) {
    piscaLed(sequencia[contador]);
    delay(500);
  }
}

void confere(void) {
  int contador = 0;
  while (contador < posicoes) { //Enquanto eu não tiver dado entrada para todos os elementos da sequência ele continua esperando.
    if ((digitalRead(btn1) && sequencia[contador] == 1) || (digitalRead(btn2) && sequencia[contador] == 2) || (digitalRead(btn3) && sequencia[contador] == 3) || (digitalRead(btn4) && sequencia[contador] == 4)) {
      //Se o botão apertado corresponder a cor certa, ele fica esperando a entrada da próxima posição.
      piscaLed(sequencia[contador]);//Acende o led correto
      contador++;
    }
    else if ((digitalRead(btn1) && sequencia[contador] != 1) || (digitalRead(btn2) && sequencia[contador] != 2) || (digitalRead(btn3) && sequencia[contador] != 3) || (digitalRead(btn4) && sequencia[contador] != 4)) {
      //Aqui precisa ser else if é pro programa esperar a entrada, do contrário simplesmente toca o wrong assim que o primeiro led correto é apertado.
      playWrong();//Se o botão  é diferente do que ele estava esperando ele roda a função de finalizar o jogo. Nessa função ele zera a quantidade de posições, o que sai do loop automaticamente.
    }
  }
}

void playWrong (void) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(sb, SOUND_WRONG);
  delay(1500);//Deixa os leds e o som ligados um pouco
  noTone(sb);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  posicoes = 0;//Zera o número de posições, então ele vai começar a preencher o vetor novamente do zero na próxima iteração do void loop
}
