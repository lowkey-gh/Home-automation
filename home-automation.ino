//#include <SoftwareSerial.h>
//#include <string.h>

#include "mp3tf16p.h"

// MP3Player mp3(6,5); // rx,tx

int trig = 8;

#define RX 2
#define TX 1

const int RED = 9;
const int YELLOW = 10;
const int BLUE = 11;

String command = "";

void on(int pin){
  digitalWrite(pin, LOW);
}

void off(int pin){
  digitalWrite(pin, HIGH);
}

void flush(){
  int len = command.length();
  command.remove(0,len);
}

void serial_flush(void) {
  while (Serial.available()) Serial.read();
}

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(BLUE, HIGH);

  Serial.begin(9600);   

//  mp3.initialize();
//  mp3.playTrackNumber(1, 30);

  pinMode(trig, OUTPUT);
  digitalWrite(trig,HIGH);
}

void loop() {
  while(Serial.available()){ 

//    char receivedChar = Serial.read();
//    Serial.println(receivedChar);
  
//    command = command + receivedChar;
    command = Serial.readString();
    
    Serial.println(command);

    if (command == "Turn on red" or command == "turn on red"){
      on(RED);
      flush();
    } else if (command == "Turn off red" or command == "turn off red"){
      off(RED);
      flush();

    } else if (command == "Turn on blue" or command == "turn on blue"){
      on(BLUE);
      flush();
    } else if (command == "Turn off blue" or command == "turn off blue"){
      off(BLUE);
      flush();

    } else if (command == "Turn on yellow" or command == "turn on yellow"){
      on(YELLOW);
      flush();
    } else if (command == "Turn off yellow" or command == "turn off yellow"){
      off(YELLOW);
      flush();
    } else if (command == "Turn on all" or command == "turn on all"){
      on(RED);
      on(BLUE);
      on(YELLOW);
    } else if (command == "Turn off all" or command == "turn off all"){
      off(RED);
      off(BLUE);
      off(YELLOW);
    } else if (command == "Play my song" or command == "play my song"){
      on(trig);
      delay(100);
      off(trig);
    } else {
        flush();
        serial_flush();
    }
  }
}