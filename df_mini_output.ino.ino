#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


#define RX_PIN 10
#define TX_PIN 11


DFRobotDFPlayerMini mp3;
SoftwareSerial *softwareSerialMP3;

void setup() {
  Serial.begin(9600);
  softwareSerialMP3 = new SoftwareSerial(RX_PIN,TX_PIN);
  softwareSerialMP3->begin(9600);
  Serial.println("Initialising MP3 Player...");

  if(!mp3.begin(*softwareSerialMP3,true,false)) {
    Serial.println("Unable to initialise the player");
    while(true);
  }
  Serial.println("MP3 player online");
  mp3.volume(30);
  mp3.play(1);
}

void loop() {

}
