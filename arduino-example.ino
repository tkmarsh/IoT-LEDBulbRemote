//Connect IR LED to pin 3
#include <IRremote.h> //Get the library from here: github.com/z3t0/Arduino-IRremote
IRsend irsend;

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

void setup(){
  // put your setup code here, to run once:
}

void loop(){
  ledRemote("state",1); //ON
  delay(1000);
  ledRemote("white",1); //WHITE
  delay(1000);
  for(int i=0;i<5;i++){ //ALL SHADES OF RED
    delay(1000);
    ledRemote("red",i);
  }
   for(int i=0;i<5;i++){ //ALL SHADES OF GREEN
    delay(1000);
    ledRemote("green",i);
  }
   for(int i=0;i<5;i++){ //ALL SHADES OF BLUE
    delay(1000);
    ledRemote("blue",i);
  }
   for(int i=0;i<4;i++){ //FLASH,STROBE,FADE,SMOOTH
    delay(1000);
    ledRemote("misc",i);
  }
  delay(1000);
  ledRemote("state",0); //OFF
}
