#include<dht11.h>

dht11 sensor;
int led1 = 5;
int led2 = 7;
int led3 = 8;
int led4 = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();
    if (c == 'R')
    {
      digitalWrite(led4, LOW);
    }
     if (c == 'E')
    {
      digitalWrite(led3, LOW);
    }
     if (c == 'W')
    {
      digitalWrite(led2, LOW);
    }
     if (c == 'Q')
    {
      digitalWrite(led1, LOW);
    }
    else if (c == '4')
    {

      digitalWrite(led4, HIGH);
    }
    if (c == '3')
    {
      digitalWrite(led3, HIGH);
    }
    if (c == '2')
    {
      digitalWrite(led2, HIGH);
    }
     if (c == '1')
    {
      digitalWrite(led1, HIGH);
    }
    if (c == 'T')
    {
      int chk = sensor.read(2);
      Serial.print("    ");
      Serial.print("Temperatura (C): ");
      Serial.println((float)sensor.temperature, 2);
      Serial.print("    ");
      Serial.print("Umidade (%): ");
      Serial.println((float)sensor.humidity, 2);
     
      
    }
  
  }
}
