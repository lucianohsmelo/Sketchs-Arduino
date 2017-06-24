#include <RCSwitch.h>
 
//Instacia a Biblioteca 
RCSwitch mySwitch = RCSwitch();
 
void setup() {
  Serial.begin(9600);
  Serial.println("RX Mode");
  // delay para estabilizacao do Sinal
  delay(500);
  
  //Seta como Receptor/ O “0″ é para não interromper, deixar continuo
  //O Pino padrão é o 2
  mySwitch.enableReceive(0);  

}
 
void loop() {
  //Quado estiver sinal disponivel
  if (mySwitch.available()) {
 
    //recebe na variavel value o Status
    char value = mySwitch.getReceivedValue();
 
    //Se o value for Zero
    if (value == 0) {
      Serial.println("Codigo desconhecido");
  
    } else {
      //Valor Recebido
      Serial.println(mySwitch.getReceivedValue(),(BIN));
  
     
    }
    //reseta “limpa” a instacia
    mySwitch.resetAvailable();
  }
}


