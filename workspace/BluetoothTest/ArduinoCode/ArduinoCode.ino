#include <SoftwareSerial.h>

int enable1Pin = 11;
int in1Pin = 10;
int in2Pin = 9;


int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
const int ledPin = 13;

SoftwareSerial mySerial(0, 1); //RX TX

void setup() {
    // sets the pins as outputs:
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
   
    // sets enable1Pin and enable2Pin high so that motor can turn on:
    digitalWrite(enable1Pin, HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(mySerial.available() > 0){     
      state = mySerial.read();   
      flag=0;
    }
    // if the state is '1' the DC motor will go forward
    if (state == '1') {
        digitalWrite(in1Pin, HIGH);
        digitalWrite(in2Pin, LOW); 
        
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }

    }
    
    else if (state == '2') {
        digitalWrite(in1Pin, LOW);
        digitalWrite(in2Pin, HIGH);
        
        if(flag == 0){
          Serial.println("GO BACK");
          flag=1;
        }
    }
    
    // if the state is '3' the motor will Stop
    else if (state == '3') {
        digitalWrite(in1Pin, LOW);
        digitalWrite(in2Pin, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    //For debugging purpose
    //Serial.println(state);
}
