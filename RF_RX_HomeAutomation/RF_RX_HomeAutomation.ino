#include <RCSwitch.h>
 
RCSwitch mySwitch = RCSwitch();
int value;

void setup() {
  Serial.begin(9600);
  // delay para estabilizacao do Sinal
  delay(500);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);  
  //Seta como Receptor/ O “0″ é para não interromper, deixar continuo
  //O Pino padrão é o 2
  mySwitch.enableReceive(0);  

}
 
void loop() {
  digitalWrite(9, LOW); 
  //Quado estiver sinal disponivel
  if (mySwitch.available()) {
  digitalWrite(9, HIGH);
    value = mySwitch.getReceivedValue();
    if (value == 1){
      digitalWrite(10,HIGH);
      delay(300);
      digitalWrite(10,LOW);
      delay(2000);
      value = 0;  
  }
    //reseta “limpa” a instacia
    mySwitch.resetAvailable();
  }
}


