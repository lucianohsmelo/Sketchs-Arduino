#include <SPI.h> //Inclui a Biblioteca SPI
#include <Ethernet.h> //Inclui a Biblioteca Ethernet
int i;
int IP[4], getway[4], submask[4];
bool noEthernet;

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  Serial.println("Inciando, aguarde...");
  uint8_t mac[]     = { 0x90, 0xA2, 0xDA, 0x00, 0x51, 0x06 };
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for (;;)
      ;
  noEthernet = true;
  }else{
    GetParams();
  }
  Serial.println(millis());
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
  delay(1000);
  for (i = 1; i <= 4; i++){
    Serial.print(IP[i]);
    if (i < 4){
    Serial.print(".");
      }
    }
    Serial.println();
}
