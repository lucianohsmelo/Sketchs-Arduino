int poten = 0;
int OUT = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(OUT, OUTPUT);
 
}

void loop()
{
  int val = analogRead(poten);
  if (val == 0){
   Serial.println(val);
   digitalWrite(OUT, HIGH);
  }
  else if (val == 1023){
  Serial.println(val);
  digitalWrite(OUT, LOW);
  }
  else {
  Serial.println(val);
  digitalWrite(OUT, HIGH);
  delay(val/10);
  digitalWrite(OUT, LOW);
  delay(val/10);
  }
}
