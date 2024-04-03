//feito por fabricio matos email: fbmjogador@gmail.com 



const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;



// Definição dos pinos
const int ledPin1 = 11;  // Digital Pin 11
const int ledPin2 = 8;  // Digital Pin 8 

int counter = 0;
const int buttonPin = 5; // Pino do botão
const int bomba = 7;   // Pino do LED
const int buzzerPin = 3; // Pino do buzzer

// Variáveis para armazenar o estado do botão
int buttonState = 0;
int lastButtonState = 0;
bool buttonPressed = false;

// Variáveis para controlar o tempo do LED
unsigned long previousMillis = 0;
const long interval = 3000; // Intervalo de tempo em milissegundos (3 segundos)

// Função para emitir bips
void beep1(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration + 50);
}

void setup() {
   //Setup pin modes
  pinMode(ledPin1, OUTPUT);  // Digital Pin 13
  pinMode(ledPin2, OUTPUT); // Digital Pin 8
 // pinMode(buttonPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(bomba, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Emitir 3 bips ao ligar
  for (int i = 0; i < 3; i++) {
    beep1(1000, 200); // Bips de média duração
  }
}

void loop() {
  // Verificar o estado do botão
  buttonState = digitalRead(buttonPin);
  //digitalWrite(ledPin, HIGH);
  // Se o botão foi pressionado
  if (buttonState == HIGH && lastButtonState == LOW) {
    buttonPressed = true;
  }

  // Se o botão foi solto após ter sido pressionado
  if (buttonState == LOW && lastButtonState == HIGH && buttonPressed) {
    beep1(1000, 200); // Emitir um bip
    digitalWrite(bomba, HIGH); // Acender o LED
    previousMillis = millis(); // Atualizar o tempo atual
    buttonPressed = false; // Reiniciar a variável de controle do botão
   /// codigo da musica 
  introducao();


  }





  // Verificar se passaram 3 segundos desde que o botão foi pressionado
  if (digitalRead(bomba) == HIGH && millis() - previousMillis >= interval) {
    digitalWrite(bomba, LOW); // desliga a bomba o LED após 3 segundos
  }

  // Atualizar o estado do botão
  lastButtonState = buttonState;








}
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);

  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }

  //Stop tone on buzzerPin
  noTone(buzzerPin);

  delay(50);

  //Increment counter
  counter++;
}


void introducao()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}


