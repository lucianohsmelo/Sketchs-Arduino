#include<dht11.h>

dht11 sensor;
int rele1 = 7;
int rele2 = 8;
int rele3 = 10;
int rele4 = 12;
int Left = 3;
int Right = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12,OUTPUT);
  


  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
  digitalWrite(rele4, HIGH);
}

void loop()
{
  if (Serial.available())
  {
    
    int c = Serial.read();

    if (c == 'U')
    {
      delay(500);
     
      digitalWrite(rele3, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(rele4, LOW);
      digitalWrite(5, HIGH);
      Serial.println("  U  ");

    }
     if (c == 'D')
    {
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(rele4, HIGH);
      digitalWrite(rele3, LOW);
      digitalWrite(3, HIGH);
      
      Serial.println("  D  ");

     if (c == 'P')
    {
      digitalWrite(rele1, HIGH);
      digitalWrite(rele2, HIGH);
      digitalWrite(rele3, HIGH);
      digitalWrite(rele4, HIGH); 
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
  }
    }}}
