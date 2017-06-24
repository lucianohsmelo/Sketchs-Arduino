#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (7, 8);
byte addresses[][6] = {"0"};

int checkStatus(int value){ 
  if (value == 0){
    value = 1;
  }
  else {
    value = 0;
  }
  return value;
}


struct packageWrite
{
  int id=15;
  int Status = 1;
  int ping = 0;
  float value = 18.3;
  char  text[100] = "From ID.10\n";
};
typedef struct packageWrite Package;
Package dataWrite;



void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando NF24L01 TX");
  delay(1000);
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe( addresses[0]);
  delay(1000);
}

void loop(){
    myRadio.write(&dataWrite, sizeof(dataWrite)); 
    if (dataWrite.Status == 0){
      dataWrite.Status = 1;
    }else{
      dataWrite.Status = 0;
    }
    dataWrite.value = analogRead(0);
}
