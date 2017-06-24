#include <Thermistor.h>

Thermistor temp(0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temperature = temp.getTemp();
  int analog = analogRead(0);
  Serial.print("Temperatura no Sensor: ");
  Serial.print(temperature);
  Serial.println("*C");
  Serial.print("Valor analogico: ");
  Serial.println(analog);
  delay(1000);
}
