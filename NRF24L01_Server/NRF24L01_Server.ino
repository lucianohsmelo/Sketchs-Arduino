#include <RF24.h>


//*************** Controle do RF ***********************
#define radioID 0   //Informar "0" para um dispositivo e "1" para o outro dispositivo

struct estruturaDadosRF
{
   boolean ligando = false;   //Esta variavel será usada para solicitar os dados do outro aparelho. Será útil quando o aparelho solicitante esta sendo ligado, para manter os valores do aparelho que já esta ligado.
   short id = 0;
   boolean botao1 = false;
   int An0 = 0;
};
typedef struct estruturaDadosRF tipoDadosRF;
tipoDadosRF dadosRF;
tipoDadosRF dadosRecebidos;

boolean transmitido = true;
boolean alterado = false;

RF24 radio(7,8);

byte enderecos[][6] = {"1node","2node"};



//*************** Controle do Projeto LOCAL ************
boolean botao1Ant = HIGH;
boolean botao1    = HIGH;
int pot1Ant = 0;
int pot1    = 0;
int angulo1 = 0;



void setup() {
  //*************** Controle do RF ***********************
  radio.begin();
  Serial.begin(115200);
  radio.openWritingPipe(enderecos[0]);
  radio.openReadingPipe(1, enderecos[1]);

  //Solicita os dados do outro aparelho, se ele estiver ligado. Tenta a comunicação por 2 segundos.
  dadosRF.ligando = true;
  radio.stopListening();                                   
  long tempoInicio = millis();
  while ( !radio.write( &dadosRF, sizeof(tipoDadosRF) ) ) {
     if ((millis() - tempoInicio) > 2000) {
        break;
     }   
  }
  dadosRF.ligando = false; 
  radio.startListening();  
}


void loop() {
  //*************** Controle do RF ***********************
  // se houve alteração dos dados, envia para o outro radio 
  if (alterado || !transmitido) {
     radio.stopListening();                                   
     transmitido = radio.write( &dadosRF, sizeof(tipoDadosRF) );
     radio.startListening();  
     alterado = false;
  }

  //verifica se esta recebendo mensagem       
  if (radio.available()) {                                   
     radio.read( &dadosRecebidos, sizeof(tipoDadosRF) ); 

     //verifica se houve solicitação de envio dos dados
     if (dadosRecebidos.ligando) {
        alterado = true;
     } else {
        dadosRF = dadosRecebidos;
     }
  }




    
  botao1 = digitalRead(2);
  if (botao1 && (botao1 != botao1Ant)) {
     dadosRF.botao1 = !dadosRF.botao1;
     alterado = true;  //esta variavel controla o envio dos dados sempre que houver uma alteração
  }
  botao1Ant = botao1;


  angulo1 = map(dadosRF.An0, 0, 1023, 0, 180);
  Serial.print(dadosRF.id);
  Serial.print(" - ");  
  Serial.println(angulo1);
  delay(10);
}
