#include <RCSwitch.h>
int pot = 0;
int valor;
#define D2    4

RCSwitch mySwitch = RCSwitch();

void setup() {
  //Inicia a Serial
  Serial.begin(9600);
  
  // Seta como habititado para enviar o pino 10  
  mySwitch.enableTransmit(10);
  delay(500);
  
}
void loop() {
  valor = analogRead(0);
  //envia o comando desejado desejado
  mySwitch.send("00000111");
  
}

