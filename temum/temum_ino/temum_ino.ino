#include<dht11.h>

dht11 sensor;

void setup() {
Serial.begin(9600);
}

void loop() {
Serial.print("Lendo sensor: ");
int chk = sensor.read(2);
Serial.print("Umidade (%): ");
Serial.println((float)sensor.humidity, 2);
Serial.print("Temperatura (graus Celsius): ");
Serial.println((float)sensor.temperature, 2);
delay(2000);
}

