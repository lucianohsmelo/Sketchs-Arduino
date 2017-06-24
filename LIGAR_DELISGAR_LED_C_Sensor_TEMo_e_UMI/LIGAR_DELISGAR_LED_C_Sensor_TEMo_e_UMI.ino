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
  Serial.println("1/Q - ON/OFF LED 1");
  Serial.println("2/W - ON/OFF LED 2");
  Serial.println("3/E - ON/OFF LED 3");
  Serial.println("4/R - ON/OFF LED 4");
  Serial.println(" 0 - Ler instruções novamente"); 
}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();
if (c == '0')
    {
      Serial.println("1/Q - ON/OFF LED 1");
      Serial.println("2/W - ON/OFF LED 2");
      Serial.println("3/E - ON/OFF LED 3");
      Serial.println("4/R - ON/OFF LED 4");
    }
    if (c == 'R')
    {
      digitalWrite(led4, HIGH);
      Serial.println("LED 4 ligado!");
    }
     if (c == 'E')
    {
      digitalWrite(led3, HIGH);
      Serial.println("LED 3 ligado!");
    }
     if (c == 'W')
    {
      digitalWrite(led2, HIGH);
      Serial.println("LED 2 ligado!");
    }
     if (c == 'Q')
    {
      digitalWrite(led1, HIGH);
      Serial.println("LED 1 ligado!");
    }
    else if (c == '4')
    {

      digitalWrite(led4, LOW);
      Serial.println("LED 4 ligado!");
    }
    if (c == '3')
    {
      digitalWrite(led3, LOW);
      Serial.println("LED 3 ligado!");
    }
    if (c == '2')
    {
      digitalWrite(led2, LOW);
      Serial.println("LED 2 ligado!");
    }
     if (c == '1')
    {
      digitalWrite(led1, LOW);
      Serial.println("LED 1 ligado!");
    }
    if (c == 'T')
    {
      Serial.print("Lendo sensor: ");
      int chk = sensor.read(2);
      Serial.print("Umidade (%): ");
      Serial.println((float)sensor.humidity, 2);
      Serial.print("Temperatura (graus Celsius): ");
      Serial.println((float)sensor.temperature, 2);
    }
  }
}
