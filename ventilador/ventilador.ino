#include <dht.h>

#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1
dht DHT; //Inicializa o sensor

int Vent = 7;
int tempo = 2000;
int controle;
int c;

void setup()
{
  Serial.begin(9600);//inicializa a serial
  pinMode(13,OUTPUT);//pino 13 como saída
  pinMode(Vent,OUTPUT);//pino de conexão do ventilador
  digitalWrite(Vent,LOW);//inicializa desligado
}

void loop()
{
      DHT.read11(dht_dpin); //Lê as informações do sensor
      int T = DHT.temperature;  //valor da temperatura
      Serial.println("  ");
      Serial.println("Temperatura: ");//Envia para o aplicativo
      Serial.print(T);Serial.println("°C");
      int valor,teste;
      valor = 0;
      Serial.println("   ");
      Serial.println("Aguardando Temperatura.");
      Serial.println("  ");
      delay(tempo);//tempo de leitura do sensor
  
      if(Serial.available()>0){//conversao da serial para um numero inteiro, de acordo com a tabela ASC
          valor=Serial.read()-48;
          while(Serial.peek()!=-1){
          teste=Serial.read()-48;
          valor=valor*10+teste;
          }
          Serial.flush();
     
        
      
              while (T > 20 & valor>1){
               int out = Serial.read();//leitura da porta serial
              
               DHT.read11(dht_dpin);
               int Temp = DHT.temperature; 
               if ( valor == 2 | out == 50){//Serial receve valor 2 fora do while
                     digitalWrite(Vent,HIGH);//Liga o ventilador
                     Serial.println("  ");
                     Serial.println("Ventilador Ligado"); //Envia ligago para o aplicativo
                     break;
               }
               else if (valor == 3 | out == 51){ //Serial recebe valor 3 fora do while ou 51 dentro no while de controle
                     digitalWrite(Vent,LOW);//ventilador desliga
                     Serial.println("  ");
                     Serial.println("Ventilador Desligado");//envia para o aplicativo
                     break;
               }
               else if (out == 49 ){   //Serial recebe valor 1
                     Serial.println("  ");
                     Serial.println("Atualizar");//envia para o aplicativo
                     break;
               }
               else if (valor < Temp){//se valor desejado for menor que a tempeatura ambiente
                    digitalWrite(Vent,HIGH);//ventilador liga
                    Serial.println(" Ligado(");//envia para o aplicativo
                    Serial.print(valor);
                    Serial.print("°C ) ");
                    Serial.println("  ");
                    Serial.print("Temperatura: ");
                    Serial.println("  ");
                    Serial.print(Temp);Serial.println("°C");
               }
               else if (valor >= Temp){//se o valor desejado for maior ou igual a temperatura ambiente
                   digitalWrite(Vent,LOW);//desliga o ventilador
                    Serial.println("  ");
                    Serial.println(" Desligado(");//envia para o aplicativo
                    Serial.print(valor);
                    Serial.print("°C ) ");
                    Serial.println("  ");
                    Serial.print("Temperatura: ");
                    Serial.print(Temp);Serial.println("°C");
               }
               delay(tempo);
             
          }
          }
}
