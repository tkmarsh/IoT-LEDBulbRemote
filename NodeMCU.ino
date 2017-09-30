/* NodeMCU IR LED WiFi Remote
   Open port 49000 on your router and format commands like this:
   "http://192.168.1.128:49000/?state=on" etc.
   Then use IFTT webhooks to use this from Google Assistant
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

IRsend irsend(4); //D2 pin
ESP8266WebServer server(49000);
const char* ssid = "[YOUR SSID]";
const char* password = "[YOUR PASSWORD]";
const int led = 13;

void ledRemote(String command,  int index){
  int state[] = {0xF740BF,0xF7C03F,0xF700FF,0xF7807F}; //OFF,ON,BRIGHTER,DIMMER
  int modes[] = {0xF7D02F,0xF7F00F,0xF7C837,0xF7E817}; //FLASH,STROBE,FADE,SMOOTH
  int red[] = {0xF720DF,0xF710EF,0xF730CF,0xF708F7,0xF728D7};
  int green[] = {0xF7A05F,0xF7906F,0xF7B04F,0xF78877,0xF7A857};
  int blue[] = {0xF7609F,0xF750AF,0xF7708F,0xF748B7,0xF76897};
  int white = 0xF7E01F;

  if(command=="state"){
     irsend.sendNEC(state[index], 32);
  }
  else if(command=="misc"){
    irsend.sendNEC(modes[index], 32);
  }
  else if(command=="red"){
    irsend.sendNEC(red[index], 32);
  }
  else if(command=="green"){
    irsend.sendNEC(green[index], 32);
  }
  else if(command=="blue"){
    irsend.sendNEC(blue[index], 32);
  }
  else if(command=="white"){
    irsend.sendNEC(white, 32);
  }
}

void handleRoot() {
  digitalWrite(led, 1);
  Serial.println(server.argName(0)+server.arg(0));
  String message;
  if (server.argName(0)=="state"){
    message += "Turning light " + server.arg(0) + "\n";
    if(server.arg(0)=="on"){
      ledRemote("state",1);
    }
    else if(server.arg(0)=="off"){
      ledRemote("state", 0);
    }
    else if(server.arg(0)=="bright"){
      ledRemote("state", 2);
    }
    else if(server.arg(0)=="dim"){
      ledRemote("state", 3);
    }
    else if(server.arg(0)=="red"){
      ledRemote("red", 0);
    }
    else if(server.arg(0)=="green"){
      ledRemote("green", 0);
    }
    else if(server.arg(0)=="blue"){
      ledRemote("blue", 0);
    }
    else if(server.arg(0)=="White"){
      ledRemote("white", 0);
    }
    else if(server.arg(0)=="rave"){
      ledRemote("state", 1);
      delay(100);
      ledRemote("misc", 0);
    }
  }
  server.send(200, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.begin();
  irsend.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
