#include<dht11.h>

dht11 sensor;
int rele1 = 5;
int rele2 = 7;
int rele3 = 8;
int rele4 = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);

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

    if (c == 'R')
    {
      digitalWrite(rele4, HIGH);
    }
     if (c == 'E')
    {
      digitalWrite(rele3, HIGH);
    }
     if (c == 'W')
    {
      digitalWrite(rele2, HIGH);
    }
     if (c == 'Q')
    {
      digitalWrite(rele1, HIGH);
    }
    else if (c == '4')
    {

      digitalWrite(rele4, LOW);
    }
    if (c == '3')
    {
      digitalWrite(rele3, LOW);
    }
    if (c == '2')
    {
      digitalWrite(rele2, LOW);
    }
     if (c == '1')
    {
      digitalWrite(rele1, LOW);
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
