//#include <SoftwareSerial.h>
//#include <string.h>

#define RX 2
#define TX 1

const int RED = 12;
const int GREEN = 11;
const int BLUE = 10;

String command = "";

void on(int pin){
  digitalWrite(pin, HIGH);
}

void off(int pin){
  digitalWrite(pin, LOW);
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
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);


  Serial.begin(9600);   
}

void loop() {
  while(Serial.available()){ 

//    char receivedChar = Serial.read();
//    Serial.println(receivedChar);
  
//    command = command + receivedChar;
    command = Serial.readString();
    Serial.println(command);

    if (command == "turn on red"){
      on(RED);
      flush();
    } else if (command == "turn off red"){
      off(RED);
      flush();

    } else if (command == "turn on blue"){
      on(BLUE);
      flush();
    } else if (command == "turn off blue"){
      off(BLUE);
      flush();

    } else if (command == "turn on green"){
      on(GREEN);
      flush();
    } else if (command == "turn off green"){
      off(GREEN);
      flush();
    } else if (command == "turn on all"){
      on(RED);
      on(BLUE);
      on(GREEN);
    } else if (command == "turn off all"){
      off(RED);
      off(BLUE);
      off(GREEN);
    } else {
        flush();
        serial_flush();
    }
  }
}