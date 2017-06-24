#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();


int ledPin = 13; // escolha o pino para o LED
int inPin = 7;   // escolha o pino de entrada (para o interruptor)
int val = 0;     // variável para ler o estado do interruptor

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // declara-se o LED como saída
  pinMode(inPin, INPUT);    // declara-se o interruptor como entrada
  mySwitch.enableReceive(0); 
  mySwitch.enableTransmit(10);
  
  delay(500);
}

void loop(){
  val = digitalRead(inPin);  // ler o valor de entrada
  if (val == HIGH) {         // verificar se a entrada é HIGH (interruptor livre)
    digitalWrite(ledPin, LOW);  // desligar LED
    Serial.println("Desligado");
  } else {
    digitalWrite(ledPin, HIGH);  // ligar LED
    Serial.println("Ligado");
    //envia o comando desejado desejado
    mySwitch.send('2F6E4E', 24);
  }
}
