#include <dht11.h>
dht11 sensor;
int pinSensor = 3;
void setup()
{
  Serial.begin(9600);
}
void loop()
{

    Serial.print("RH: ");//Imprime a sigla
    Serial.print(sensor.humidity);//Imprime a umidade
    Serial.println("%");//Imprime o simboloSerial.print("TEMP: ");//Imprime a sigla
    Serial.print(sensor.temperature);//Imprime a temperatura
    Serial.println("C");//Imprime o simbolo sem o "º"
    
  
  delay(1000);//Aguarda 1s, intervalo entre as leituras exigido pelo fabricante
}
  
