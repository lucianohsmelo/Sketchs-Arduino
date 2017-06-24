byte pinState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(6,1);
 digitalWrite(7,1);
 digitalWrite(8,1);
 digitalWrite(9,1);
 digitalWrite(10,1);
 digitalWrite(11,1);
 delay(1000);
 digitalWrite(6,0);
 digitalWrite(7,0);
 digitalWrite(8,0);
 digitalWrite(9,0);
 digitalWrite(10,0);
 digitalWrite(11,0);
 delay(1000);
 
}
