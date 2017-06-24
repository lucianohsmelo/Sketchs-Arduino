int out = 6;
int aux;
int pwm = 0;

void setup(){
  Serial.begin(9600);
  pinMode(out, OUTPUT);
  
  
}


void loop(){    
   aux = analogRead(1);
   pwm = map(aux,0,1023,0,255);
   digitalWrite(out,pwm);
   Serial.print("Analogico = ");
   Serial.print(aux);
   Serial.print(" - ");
   Serial.print("PWM = ");
   Serial.println(pwm);
   delay(1000);
   
   
}
