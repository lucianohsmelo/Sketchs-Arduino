#include <SPI.h>
#include "RF24.h"

#define myID 10

RF24 myRadioTX  (9, 10);
RF24 myRadioRX  (7, 8);
byte addresses[][6] = {"0"};

struct package
{
  int id = myID;
  int activity = 1;
  float value = 18.3;
  char  text[100] = "Server10\n";
};
typedef struct package Package;
Package dataTX;
Package dataRX;

int activityData(int value) {
  if (value == 0) {
    value = 1;
  } else {
    value = 0;
  }
  return value;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando NRF24L01 Server");

  myRadioTX.begin();
  myRadioTX.setChannel(115);
  myRadioTX.setPALevel(RF24_PA_MAX);
  myRadioTX.setDataRate( RF24_250KBPS ) ;
  myRadioTX.openWritingPipe( addresses[0]);

  myRadioRX.begin();
  myRadioRX.setChannel(115);
  myRadioRX.setPALevel(RF24_PA_MAX);
  myRadioRX.setDataRate( RF24_250KBPS ) ;
  myRadioRX.openReadingPipe(1, addresses[0]);
  myRadioRX.startListening();
  delay(1000);
}

void loop() {
  myRadioTX.write(&dataTX, sizeof(dataTX));
  dataTX.activity = activityData(dataTX.activity);
  dataTX.value = analogRead(0);
  delay(10);
  if ( myRadioRX.available()) {
    while (myRadioRX.available())
    {
      myRadioRX.read( &dataRX, sizeof(dataRX) );
    }
    if (dataRX.id != myID) {
      Serial.print("\ID:");
      Serial.println(dataRX.id);
      Serial.print("Activity: ");
      Serial.println(dataRX.activity);
      Serial.println(dataRX.value);
      Serial.println(dataRX.text);
    }
  }
  delay(10);
}
