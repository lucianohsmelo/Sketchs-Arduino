#include <ESP8266WiFi.h>
#include <PubSubClient.h>   // Read the rest of the article
#include <stdlib.h>
#include<dht.h>
#define D1 5
#define outDoor D1
const char *ssid =  "TIM WiFi Fon";   // cannot be longer than 32 characters!
const char *pass =  "estoucomfome";   //

const char *serverLocal = "192.168.1.10";//"m11.cloudmqtt.com";
const int portLocal = 1883;
const char *userLocal = "localBroker";
const char *passLocal = "1234";

const char *serverCloud = "m11.cloudmqtt.com";
const int portCloud = 14458;
const char *userCloud = "jgojknep";
const char *passCloud = "muJlxlc58d0v";


const char *mqtt_client_name = "arduinoClient1";

// Client connections cant have the same connection name
#define BUFFER_SIZE 100
#define DHT11_PIN D3
dht DHT;
long lastMsg = 0;
char msg[50];
unsigned long previousMillis = 0;
const long interval = 10000;
WiFiClient wclient;  //Declares a WifiClient Object using ESP8266WiFi
PubSubClient client(wclient, serverCloud,  portCloud);  //instanciates client object

//Function is called when, a message is recieved in the MQTT server.

String topics[] = {"keepAlive","outTopic","door","respDoor","tempInter","tempExter","clientMode"};
int numTopics;
String clientMode;

void callback(const MQTT::Publish& pub) {
  Serial.print(pub.topic());
  Serial.print(" => ");
  if (pub.has_stream()) {
    uint8_t buf[BUFFER_SIZE];
    int read;
    while (read = pub.payload_stream()->read(buf, BUFFER_SIZE)) {
      Serial.write(buf, read);     
    }
    pub.payload_stream()->stop();
    //Check if the buffer is -1
    if (buf[0] == '-' && buf[1] == '1') {
      //Code to blink the LED -- its strange that I can't blink the LED for more than 1sec.
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
    }
    Serial.println("");
  } else
    Serial.println(pub.payload_string());
    if (pub.topic() ==  "door" && pub.payload_string() == "open"){
      Serial.println("Requisição para abrir portão");
      client.publish("respDoor", "openSucess" );
      digitalWrite(outDoor,HIGH);
      delay(500);
      digitalWrite(outDoor,LOW);
    }else if (pub.topic() ==  "clientMode"){
      clientMode = pub.payload_string();
      if (clientMode == "local"){
        PubSubClient client(wclient, serverLocal,  portLocal);  //instanciates client object
        Serial.println("Change to Local Mode");
      }else if(clientMode == "cloud"){
        PubSubClient client(wclient, serverCloud,  portCloud);  //instanciates client object
        Serial.println("Change to Cloud Mode");
    }
  
    }
}

void setup() {
  // Setup console
  Serial.begin(115200);  //set the baud rate
  numTopics = (sizeof(topics)/sizeof(String)) - 1;
  int chk = DHT.read11(DHT11_PIN);
  pinMode(outDoor, OUTPUT);
  digitalWrite(outDoor,LOW);
  Serial.print(" Starting Humidity: " );
  Serial.print(DHT.humidity, 1);
  Serial.println('%');
  Serial.print(" Starting Temparature ");
  Serial.print(DHT.temperature, 1);
  Serial.println('C');
  delay(10);
  Serial.println();
  Serial.println();

  clientMode = "cloud";
  if (clientMode == "local"){
    PubSubClient client(wclient, serverLocal,  portLocal);  //instanciates client object
    Serial.println("Modo Local");
  }else if (clientMode == "cloud"){
    PubSubClient client(wclient, serverCloud,  portCloud);  //instanciates client object
    Serial.println("Modo Local");
  }
}


void loop() {
  if (WiFi.status() != WL_CONNECTED) {  //wifi not connected?
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println("...");
    WiFi.begin(ssid, pass);
    if (WiFi.waitForConnectResult() != WL_CONNECTED)
      return;
    Serial.println("WiFi connected");
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    //client object makes connection to server
    if (clientMode == "local"){
      if (!client.connected()) {
        Serial.println("Connecting to MQTT server");
        //Authenticating the client object
        if (client.connect(MQTT::Connect("mqtt_client_name")
                           .set_auth(userLocal, passLocal))) {
          Serial.println("Connected to MQTT server");
          //Subscribe code
          client.set_callback(callback);
        
          for (int i = 0; i <= numTopics; i++){
            client.subscribe(topics[i]);
          }
      
        } else {
        Serial.println("Could not connect to MQTT server");
        }
      }
    }

     if (clientMode == "cloud"){
      if (!client.connected()) {
        Serial.println("Connecting to MQTT server");
        //Authenticating the client object
        if (client.connect(MQTT::Connect("mqtt_client_name")
                           .set_auth(userCloud, passCloud))) {
          Serial.println("Connected to MQTT server");
          //Subscribe code
          client.set_callback(callback);
        
          for (int i = 0; i <= numTopics; i++){
            client.subscribe(topics[i]);
          }
      
        } else {
        Serial.println("Could not connect to MQTT server");
        }
      }
    }
    
    if (client.connected())
      client.loop();
  }
    long now = millis();
  // read DHT11 sensor every 6 seconds
  if (now - lastMsg > 10*1000) {
     lastMsg = now;
     int chk = DHT.read11(DHT11_PIN);
     String msg = String((int)(DHT.temperature));
     char message[58];
     msg.toCharArray(message,58);
     //client.publish("tempInter", message);
  } 
}

