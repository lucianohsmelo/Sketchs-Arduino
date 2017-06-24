int wait = 100;
int p1 = 4;
int p2 = 7;
int p3 = 8;
char inChar;

void setup() {
pinMode(p1, OUTPUT);
pinMode(p2, OUTPUT);
pinMode(p3, OUTPUT);
Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

if (Serial.available()){
inChar = (char)Serial.read();
if (inChar == '-'){
wait -=1;
}
else{
wait +=1;
}
Serial.println(wait);
}

digitalWrite(p1, 1);
digitalWrite(p2, 1);
digitalWrite(p3, 0);
delay(wait);
digitalWrite(p1, 1);
digitalWrite(p2, 0);
digitalWrite(p3, 0);
delay(wait);
digitalWrite(p1, 1);
digitalWrite(p2, 0);
digitalWrite(p3, 1);
delay(wait);
digitalWrite(p1, 0);
digitalWrite(p2, 0);
digitalWrite(p3, 1);
delay(wait);
digitalWrite(p1, 0);
digitalWrite(p2, 1);
digitalWrite(p3, 1);
delay(wait);
digitalWrite(p1, 0);
digitalWrite(p2, 1);
digitalWrite(p3, 0);
delay(wait);
}
