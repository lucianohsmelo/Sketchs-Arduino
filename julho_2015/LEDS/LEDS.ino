#include <IRremote.h> 
int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN); 
decode_results results; 

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  irrecv.enableIRIn(); 

}

void loop() {
  
    if (irrecv.decode(&results)) { 
      Serial.println(results.value, HEX);
      if (results.value == 'DEFC4994' || results.value == '9F89EF33' || results.value == 'AE085647') {
        pinMode(2,HIGH);
      }
      else if (results.value == 'DEFC4994' || results.value == '9973226F' || results.value == '38573B7F'){
        pinMode(10,HIGH);
      }
      else{
        
        }
      }
      irrecv.resume();  
}
