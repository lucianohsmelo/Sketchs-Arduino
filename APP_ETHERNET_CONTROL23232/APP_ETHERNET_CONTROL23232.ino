 #include <SPI.h>
#include "EthernetSupW5100.h"
#include<dht11.h>

dht11 sensor;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1, 10);
EthernetServer server(80);

int portaLampada = 5;
int portaPC = 7;
int portaTV = 8;
int portaAUX = 10;
void setup()
{
  EthernetSupW5100.begin(mac, ip);
  server.begin();
  
  // Configurando portas dos botoes
  pinMode(portaLampada, OUTPUT);
  pinMode(portaTV, OUTPUT);
  pinMode(portaPC, OUTPUT);
  pinMode(portaAUX, OUTPUT);
  Serial.begin(9600);

 
  
  // Registrando botoes
  //EthernetSupW5100.addButton(button pin, text on, text off, button type);
  EthernetSupW5100.addButton(portaLampada, "Lampada Ligada", "Lampada Desligada", FLIP_BUTTON);
  EthernetSupW5100.addButton(portaTV, "TV Ligada", "TV Desligada", FLIP_BUTTON);
  EthernetSupW5100.addButton(portaPC, "PC Ligado", "PC Desligado", FLIP_BUTTON);

}

void loop()
{
  // Carrega HTML
  EthernetSupW5100.loadHtml(server);
  
  // Verifica se algum botao foi pressionado
  int lastButton = EthernetSupW5100.getLastClickedButton();
  byte state = EthernetSupW5100.getButtonState(lastButton);
  
  // Executa o comando conforme o botao clicado
  if (lastButton == portaLampada)
  {
    digitalWrite(portaLampada, state);
  }
  else if (lastButton == portaTV)
  {
    digitalWrite(portaTV, state);
  } 
  else if (lastButton == portaPC)
  {
    digitalWrite(portaPC, state);
  } 
  
  
  // Delay
  delay(10);
     
  
  if (Serial.available())
  {
    int c = Serial.read();
    if (c == 'R')
    {
      digitalWrite(portaAUX, HIGH);
    }
     if (c == 'E')
    {
      digitalWrite(portaPC, HIGH);
    }
     if (c == 'W')
    {
      digitalWrite(portaTV, HIGH);
    }
     if (c == 'Q')
    {
      digitalWrite(portaLampada, HIGH);
    }
    else if (c == '4')
    {

      digitalWrite(portaAUX, LOW);
    }
    if (c == '3')
    {
      digitalWrite(portaPC, LOW);
    }
    if (c == '2')
    {
      digitalWrite(portaTV, LOW);
    }
     if (c == '1')
    {
      digitalWrite(portaLampada, LOW);
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
  }}
