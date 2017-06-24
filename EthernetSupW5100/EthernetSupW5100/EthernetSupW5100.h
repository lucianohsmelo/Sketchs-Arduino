#ifndef ethernetsup_h
#define ethernetsup_h

#include <inttypes.h>
//#include "w5100.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "EthernetServer.h"
#include "Dhcp.h"

#define MAX_SOCK_NUM    4
#define MAX_BUTTONS     10
#define MAX_TEXT_BUTTON 50

enum ButtonType
{
		UNKNOWN,
		FLIP_BUTTON,
		SWITCH_BUTTON
};

enum ButtonState
{
	STUNKNOWN,
	ACTIVATED,
	DEACTIVATED
};

typedef struct Button_t
{
	int         id;
	char        textOn[MAX_TEXT_BUTTON];
	char        textOff[MAX_TEXT_BUTTON];
	ButtonType  type;
	ButtonState state;
	byte        flag;
} Button;

class EthernetClass {
private:
  IPAddress   _dnsServerAddress;
  DhcpClass*  _dhcp;
  
  int getButtonId(char* requestText);
  void printP(EthernetClient client, const prog_uchar *str);
  Button getButton(int id);
  void setButtonId(int id);
  
  
public:
  EthernetClass();
  static uint8_t _state[MAX_SOCK_NUM];
  static uint16_t _server_port[MAX_SOCK_NUM];
  int begin(uint8_t *mac_address);
  void begin(uint8_t *mac_address, IPAddress local_ip);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
  int maintain();
  
  void addButton(int pin, char *texton, char *textoff, ButtonType type);
  void addButton(int pin, char *texton, char *textoff, ButtonType type, ButtonState state);
  void loadHtml(EthernetServer server);
  int getLastClickedButton();
  byte getButtonState(int id);

  IPAddress localIP();
  IPAddress subnetMask();
  IPAddress gatewayIP();
  IPAddress dnsServerIP();

  friend class EthernetClient;
  friend class EthernetServer;
};

extern EthernetClass EthernetSupW5100;

#endif
