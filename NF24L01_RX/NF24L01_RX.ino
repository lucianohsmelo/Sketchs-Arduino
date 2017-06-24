#include <SPI.h>  
#include "RF24.h" 

RF24 myRadio (4, 15); 
struct package
{
  int id=0;
  int Status = 0;
  int ping = 0;
  float value = 0.0;
  char  text[100] ="empty";
};

byte addresses[][6] = {"0"}; 
typedef struct package Package;
Package data;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Iniciando NF24L01 RX");
  pinMode(4,OUTPUT);
  delay(1000);

  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
}


void loop(){
    if ( myRadio.available()) 
    {
      digitalWrite(4,HIGH);
      while (myRadio.available())
      {
        myRadio.read( &data, sizeof(data) );
      }
      Serial.print("\ID:");
      Serial.println(data.id);
      Serial.print("Status: ");
      Serial.println(data.Status);
      Serial.print("PING: ");
      Serial.println(data.ping);
      Serial.println(data.value);
      Serial.println(data.text);    
    }
}
