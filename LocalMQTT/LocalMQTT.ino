#include <ESP8266WiFi.h>
#include <PubSubClient.h>   // Read the rest of the article
#include <stdlib.h>
const char *ssid =  "TIM WiFi Fon";   // cannot be longer than 32 characters!
const char *pass =  "estoucomfome";   //
const char *mqtt_server = "iot.eclipse.org";
const int mqtt_port = 1883;
const char *mqtt_user = "localBroker";
const char *mqtt_pass = "1234";
const char *mqtt_client_name = "arduinoClient1"; // Client connections cant have the same connection name
#define BUFFER_SIZE 100
unsigned long previousMillis = 0;
const long interval = 10000;
WiFiClient wclient;  //Declares a WifiClient Object using ESP8266WiFi
PubSubClient client(wclient, mqtt_server,  mqtt_port);  //instanciates client object
//Function is called when, a message is recieved in the MQTT server.

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
}

void setup() {
  // Setup console
  Serial.begin(115200);  //set the baud rate
  delay(10);
  Serial.println();
  Serial.println();
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
    if (!client.connected()) {
      Serial.println("Connecting to MQTT server");
      //Authenticating the client object
      if (client.connect(MQTT::Connect("mqtt_client_name")
                         .set_auth(mqtt_user, mqtt_pass))) {
        Serial.println("Connected to MQTT server");
        //Subscribe code
        client.set_callback(callback);
        client.subscribe("Temparture-sensor");
        Serial.println(client.subscribe("android0"));
      } else {
        Serial.println("Could not connect to MQTT server");
      }
    }
    if (client.connected())
      client.loop();
  }

  //SendTempHumid();  // this will send the dummy temparature reading
}

// Non-Blocking delay
void SendTempHumid() {
    int h = rand() % 100; // sets value between 0-99
    if (isnan(h)) {
      Serial.println("Failed to read from DHT sensor!");
      //return; This will ensure that data is always sent
    }
    Serial.print("Temparture-sensor: ");
    Serial.println(h);
    client.publish("Temparture-sensor", String(h) );
  
}
