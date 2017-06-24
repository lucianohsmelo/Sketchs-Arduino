#include <SPI.h>
#include "EthernetSupW5100.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1, 177);
EthernetServer server(80);

int portaLampada = 5;
int portaVentilador = 6;
int portaFechadura = 7;

void setup()
{
  EthernetSupW5100.begin(mac, ip);
  server.begin();
  
  // Configurando portas dos botoes
  pinMode(portaLampada, OUTPUT);
  pinMode(portaVentilador, OUTPUT);
  pinMode(portaFechadura, OUTPUT);
  
  // Estado incial das portas
  digitalWrite(portaLampada, LOW);
  digitalWrite(portaVentilador, LOW);
  digitalWrite(portaFechadura, LOW);
  
  // Registrando botoes
  //EthernetSupW5100.addButton(button pin, text on, text off, button type);
  EthernetSupW5100.addButton(portaLampada, "Liga Lampada", "Desliga Lampada", FLIP_BUTTON);
  EthernetSupW5100.addButton(portaVentilador, "Liga Ventilador", "Desliga Ventilador", FLIP_BUTTON);
  EthernetSupW5100.addButton(portaFechadura, "Abre Fechadura", "", SWITCH_BUTTON);
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
  else if (lastButton == portaVentilador)
  {
    digitalWrite(portaVentilador, state);
  } 
  else if (lastButton == portaFechadura)
  {
    digitalWrite(portaFechadura, HIGH);
    delay(1000);
    digitalWrite(portaFechadura, LOW);
  }
  
  // Delay
  delay(10);
}