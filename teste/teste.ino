//----------------------------------------------------------------------------------------------------------//

#include <SPI.h>

#include <String.h>

#include <Ethernet.h>



//-------------------------------------------------------------------

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };//MAC padrão;

IPAddress ip(192, 168, 1, 50);//Define o endereco IPv4(trocar final);

IPAddress gateway(192, 168, 1, 1);      //Define o gateway

IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

EthernetServer server(80); // Porta de serviço

//-------------------------------------------------------------------

int AA0 = A0;//Arduino analogica A0;

int AA1 = A1;//Arduino analogica A1;

int AA2 = A2;//Arduino analogica A2;

int AA3 = A3;//Arduino analogica A3;
int AA4 = A4;//Arduino analogica A4;
//-------------------------------------------------------------------
int D2 = 2;//Arduino digital D2;
int D3 = 3;//Arduino digital D3;
int D4 = 4;//Arduino digital D4;
int D5 = 5;//Arduino digital D5;
int D6 = 6;//Arduino digital D6;
//-------------------------------------------------------------------
String readString = String(30); // string para buscar dados de endereço
boolean statusA0 = false; // Variável para o status do led 
boolean statusA1 = false; // Variável para o status do led 
boolean statusA2 = false; // Variável para o status do led 
boolean statusA3 = false; // Variável para o status do led 
boolean statusA4 = false; // Variável para o status do led 
boolean statusD2 = false; // Variável para o status do led 
boolean statusD3 = false; // Variável para o status do led 
boolean statusD4 = false; // Variável para o status do led 
boolean statusD5 = false; // Variável para o status do led 
boolean statusD6 = false; // Variável para o status do led 
//--------------------------------------------------------------------
void setup(){
  // Inicia o Ethernet
  //Ethernet.begin(mac, ip);
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
//-----------------------Define pino como saída-----------------------
  pinMode(AA0, OUTPUT);
  pinMode(AA1, OUTPUT);
  pinMode(AA2, OUTPUT);
  pinMode(AA3, OUTPUT);
  pinMode(AA4, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
//---------------------------------------------------------------------
  // Inicia a comunicação Serial
  Serial.begin(9600); 
}

void loop(){
  // Criar uma conexão de cliente
  EthernetClient client = server.available();
  
  if (client) {
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        // ler caractere por caractere vindo do HTTP
        if (readString.length() < 30)
        {
          // armazena os caracteres para string
          readString += (c);
        }
       
        //se o pedido HTTP terminou
        if (c == '\n')
          {
//------------------------------------------------------------------
        if(readString.indexOf("a0high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(AA0, HIGH);//Arduino porta digital D2=5V;
            statusA0 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("a0low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(AA0, LOW);//Arduino porta digital D2=0V;
            statusA0 = false;
          }
//------------------------------------------------------------------
       if(readString.indexOf("a1high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(AA1, HIGH);//Arduino porta digital D2=5V;
            statusA1 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("a1low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(AA1, LOW);//Arduino porta digital D2=0V;
            statusA1 = false;
          }
//------------------------------------------------------------------
       if(readString.indexOf("a2high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(AA2, HIGH);//Arduino porta digital D2=5V;
            statusA2 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("a2low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(AA2, LOW);//Arduino porta digital D2=0V;
            statusA2 = false;
          }
//------------------------------------------------------------------
       if(readString.indexOf("a3high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(AA3, HIGH);//Arduino porta digital D2=5V;
            statusA3 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("a3low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(AA3, LOW);//Arduino porta digital D2=0V;
            statusA3 = false;
          }
//------------------------------------------------------------------
       if(readString.indexOf("a4high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(AA4, HIGH);//Arduino porta digital D2=5V;
            statusA4 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("a4low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(AA4, LOW);//Arduino porta digital D2=0V;
            statusA4 = false;
          }
//------------------------------------------------------------------        
          if(readString.indexOf("d2high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(D2, HIGH);//Arduino porta digital D2=5V;
            statusD2 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("d2low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(D2, LOW);//Arduino porta digital D2=0V;
            statusD2 = false;
          }
//------------------------------------------------------------------        
          if(readString.indexOf("d3high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(D3, HIGH);//Arduino porta digital D2=5V;
            statusD3 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("d3low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(D3, LOW);//Arduino porta digital D2=0V;
            statusD3 = false;
          }
//------------------------------------------------------------------        
          if(readString.indexOf("d4high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(D4, HIGH);//Arduino porta digital D2=5V;
            statusD4 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("d4low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(D4, LOW);//Arduino porta digital D2=0V;
            statusD4 = false;
          }
//------------------------------------------------------------------        
          if(readString.indexOf("d5high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(D5, HIGH);//Arduino porta digital D2=5V;
            statusD5 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("d5low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(D5, LOW);//Arduino porta digital D2=0V;
            statusD5 = false;
          }
//------------------------------------------------------------------        
          if(readString.indexOf("d6high")>=0)//Recebido do Android;
          {
            // O Led vai ser ligado
            digitalWrite(D6, HIGH);//Arduino porta digital D2=5V;
            statusD6 = true;
          }
          // Se a string possui o texto L=Desligar
          if(readString.indexOf("d6low")>=0)//Recebido do Android;
          {
            // O Led vai ser desligado
            digitalWrite(D6, LOW);//Arduino porta digital D2=0V;
            statusD6 = false;
          } 
//------------------------------------------------------------------         
        // dados HTML de saída começando com cabeçalho padrão
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();      
        client.print("<font size='20'>");
//------------------------------------------------------------------  
 if (statusA0) {
          client.print("azeroon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("azerooff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------  
if (statusA1) {
          client.print("aoneon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("aoneoff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
if (statusA2) {
          client.print("atwoon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("atwooff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------  
if (statusA3) {
          client.print("athreeon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("athreeoff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
if (statusA4) {
          client.print("afouron");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("afouroff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------        
        if (statusD2) {
          client.print("dtwoon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("dtwooff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
        if (statusD3) {
          client.print("dthreeon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("dthreeoff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
        if (statusD4) {
          client.print("dfouron");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("dfouroff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
        if (statusD5) {
          client.print("dfiveon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("dfiveoff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
        if (statusD6) {
          client.print("dsixon");//Ethernet envia para Android;
          //String apenas letras;
        } else {
          client.print("dsixoff");//Ethernet envia string para Android;
          //String apenas letras;
        }
//------------------------------------------------------------------ 
        //limpa string para a próxima leitura
        readString="";
        
        // parar cliente
        client.stop();
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------------
