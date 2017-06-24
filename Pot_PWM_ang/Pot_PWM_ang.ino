void setup(){
  Serial.begin(9600);
  pinMode(6,OUTPUT);
}


void loop(){
  int val = analogRead(1);
  int pwm = map(val, 0.00, 1023.00, 0.00, 255.00);
  int ten = map(pwm, 0, 255.00, 0.00, 5.00);
  int sensorValue = analogRead(0);
  int out = map(sensorValue, 573,849,0,100);
  //Serial.print("Poten = ");
  //Serial.println(val);
  Serial.print("PWM = ");
  Serial.println(pwm);
  //Serial.print("Tensao = ");
  //Serial.println(ten);
  //Serial.print("sensorValue = ");
  //Serial.println(sensorValue);
  Serial.print("Output = ");
  Serial.println(out);
  analogWrite(6,pwm);
  
  delay(0);
  
    
  }
  
