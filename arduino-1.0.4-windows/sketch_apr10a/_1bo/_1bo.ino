#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,1,177);

EthernetServer server(80);

void setup() {
  Serial.begin(9600);
 
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
 
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
}


void loop() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
      
    boolean currentLineIsBlank = true;
    
    // Variaveis da aula 4
    String vars;
    int varled1_OnOff = 0;
    int varled2_OnOff = 0;
    //
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        vars.concat(c);     
       
        // Maniuplacao das variaveis da aula 4
        if (vars.endsWith("/led1_on")) varled1_OnOff = 1;
        if (vars.endsWith("/led1_off")) varled1_OnOff = 2;
        if (vars.endsWith("/led2_on")) varled2_OnOff = 1;
        if (vars.endsWith("/led2_off")) varled2_OnOff = 2;
        
        //
       
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connnection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
          // Condicoes de acionamento da aula 4
         
                 client.println("<input type=button value=Ligar ");
                 client.println(" onclick=\"document.location='/led1_on'\" />");
                 client.println("<input type=button value=Desligar ");
                 client.println(" onclick=\"document.location='/led1_off'\" />");
                 client.println("<br>");
                  
                 client.println("<input type=button value=Ligar ");
                 client.println(" onclick=\"document.location='/led2_on'\" />");
                 client.println("<input type=button value=Desligar ");
                 client.println(" onclick=\"document.location='/led2_off'\" />");
                 client.println("<br>");
                  
         
          if (varled1_OnOff == 1)
               {
                  digitalWrite(8, HIGH);
                  client.println("Led 1 Ligado");
                                 
 
                }
          if (varled1_OnOff == 2)
                {
                  digitalWrite(8, LOW);
                  client.println("Led 1 Desligado");
                  
               }
                
                
          if (varled2_OnOff == 1)
               {
                  digitalWrite(7, HIGH);
                  client.println("Led 2 Ligado");
                                 
 
                }
          if (varled2_OnOff == 2)
                {
                  digitalWrite(7, LOW);
                  client.println("Led 2 Desligado");
                  
               }
                
                           
                
          
          //
         
         
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
    Serial.println("client disonnected");
  }
}
