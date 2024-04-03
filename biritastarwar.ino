// Definição dos pinos
const int buttonPin = 2; // Pino do botão
const int ledPin = 8;   // Pino do LED
const int buzzerPin = 3; // Pino do buzzer

// Variáveis para armazenar o estado do botão
int buttonState = 0;
int lastButtonState = 0;
bool buttonPressed = false;

// Variáveis para controlar o tempo do LED
unsigned long previousMillis = 0;
const long interval = 3000; // Intervalo de tempo em milissegundos (3 segundos)

// Função para emitir bips
void beep(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration + 50);
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Emitir 3 bips ao ligar
  for (int i = 0; i < 3; i++) {
    beep(1000, 200); // Bips de média duração
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
    beep(1000, 200); // Emitir um bip
    digitalWrite(ledPin, HIGH); // Acender o LED
    previousMillis = millis(); // Atualizar o tempo atual
    buttonPressed = false; // Reiniciar a variável de controle do botão
  }

  // Se o botão não está sendo pressionado
 // if (buttonState == LOW && lastButtonState == HIGH && !buttonPressed) {
 //   digitalWrite(ledPin, LOW); // Apagar o LED
 // }

  // Verificar se passaram 3 segundos desde que o botão foi pressionado
  if (digitalRead(ledPin) == HIGH && millis() - previousMillis >= interval) {
    digitalWrite(ledPin, LOW); // Apagar o LED após 3 segundos
  }

  // Atualizar o estado do botão
  lastButtonState = buttonState;
}
