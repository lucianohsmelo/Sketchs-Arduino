#include <IRremote.h> 
 
int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN); 
decode_results results; 

 
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(9, OUTPUT);
  irrecv.enableIRIn();  
} 
 
void loop() { 
  if (irrecv.decode(&results)) { 
    Serial.println(results.value, HEX); 
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    irrecv.resume();  
  } 
} 
