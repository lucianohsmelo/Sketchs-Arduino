int poten = 0;
int LedVerm = 10;
int LedAma = 8;
int LedVerd = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(LedAma, OUTPUT);
  pinMode(LedVerd, OUTPUT);
  pinMode(LedVerm, OUTPUT); 
}

void loop()
{
  int val = analogRead(poten);
 if ( val == 0)
 {
   digitalWrite(LedVerd, LOW);
   digitalWrite(LedAma, LOW);
   digitalWrite(LedVerm, LOW);
   Serial.println(val);
 }
 if ( val > 0)
 {
   digitalWrite(LedVerd, HIGH);
   digitalWrite(LedAma, LOW);
   digitalWrite(LedVerm, LOW);
   Serial.println(val);

 }
 if (val >= 341)
 {
   digitalWrite(LedVerd, HIGH);
   digitalWrite(LedAma, HIGH);
   digitalWrite(LedVerm, LOW);
   Serial.println(val);

 }
 if (val >= 682)
 {
   digitalWrite(LedVerd, HIGH);
   digitalWrite(LedAma, HIGH);
   digitalWrite(LedVerm, HIGH);
   Serial.println(val);
 }
 
}
