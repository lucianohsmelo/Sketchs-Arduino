#include <IRremote.h>
IRsend irsend;
int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN); 
decode_results results; 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop() {
 
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa90, 12);
      Serial.println(results.value, HEX); // Sony TV power code
      delay(100);
      Serial.println(results.value, HEX); 
      irrecv.resume();  
    }
  }
