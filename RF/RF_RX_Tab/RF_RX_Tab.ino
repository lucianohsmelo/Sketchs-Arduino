#include <RCSwitch.h>
 
//Instacia a Biblioteca 
RCSwitch mySwitch = RCSwitch();
int linha = 0;         // variavel que se refere as linhas do excel
int LABEL = 1; 
int amostra = 0;
int T_amostragem = 0.5; // período de amostragem = 1 segundo
 
void setup() {
  Serial.begin(9600);                      //  inicialização da comunicação serial
  Serial.println("CLEARDATA");             // Reset da comunicação serial
  Serial.println("LABEL,Hora,Leitura,Data, , ,Amostra");   // Nomeia as colunas
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
//    int value = mySwitch.getReceivedValue();
//    Serial.print("DATA,TIME,"); //inicia a impressão de dados, sempre iniciando
//    Serial.print(mySwitch.getReceivedValue());
//    Serial.print(",");
//    Serial.println("DATE");
    
    amostra++; // incrementa a linha do excel para que a leitura pule de linha em linha
    // Coluna 1
    Serial.print("DATA,TIME,"); //inicia a impressão de dados, sempre iniciando
    // Coluna 2
    Serial.print(mySwitch.getReceivedValue());
    Serial.print(",");
    // Coluna 3
    Serial.print("DATE");
    Serial.print(",");
    // Coluna 4
    Serial.print(",");
    // Coluna 5
    Serial.print(",");
    // Coluna 6
    Serial.print(amostra);
    Serial.print(",");
    // Coluna 7
  
    if (linha > 1000) //laço para limitar a quantidade de dados
      {
      linha = 0;
      Serial.println("ROW,SET,2"); // alimentação das linhas com os dados sempre iniciando
      }
   delay(T_amostragem);  // espera 200 milisegundos
    }
    //reseta “limpa” a instacia
    mySwitch.resetAvailable();
  }


