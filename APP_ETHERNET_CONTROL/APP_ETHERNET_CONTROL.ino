 #include <SPI.h>
#include "EthernetSupW5100.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0, 105);
EthernetServer server(80);

int portaLampada = 5;
int portaPC = 7;
int portaTV = 8;
void setup()
{
  EthernetSupW5100.begin(mac, ip);
  server.begin();
  
  // Configurando portas dos botoes
  pinMode(portaLampada, OUTPUT);
  pinMode(portaTV, OUTPUT);
  pinMode(portaPC, OUTPUT);

 
  
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
}
