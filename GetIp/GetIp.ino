#include <SPI.h> //Inclui a Biblioteca SPI
#include <Ethernet.h> //Inclui a Biblioteca Ethernet

int IP[4], getway[4], submask[4];
int i;
EthernetClient client;


  
 void GetParams(){
  i = 0;
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    i = i + 1;
    IP[i] = (Ethernet.localIP()[thisByte]);
  }
  i = 0;
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    i = i + 1;
    getway[i] = (Ethernet.gatewayIP()[thisByte]);
  }
  i = 0;
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    i = i + 1;
    submask[i] = (Ethernet.subnetMask()[thisByte]);
  } 
    Serial.print("My IP address: "); 
  for (int i = 1; i <= 4; i++){
    Serial.print(IP[i]);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("My IP getway: "); 
  for (int i = 1; i <= 4; i++){
    Serial.print(getway[i]);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("My Submask: ");
    for (int i = 1; i <= 4; i++){
    Serial.print(submask[i]);
    Serial.print(".");
  }
  Serial.println();
 }


void setup(){
 Serial.begin(9600);
 Serial.println("Iniciando...");
 uint8_t mac[]     = { 0x90, 0xA2, 0xDA, 0x00, 0x51, 0x06 }; 
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Falha em configurar conexao Ethernet");
    for (;;);
  }
   GetParams();
   Serial.println("FIM setup");
}

void loop(){
  
}
