
#include <Servo.h>

Servo servo1a;
Servo servo1b;
int state;
int flag = 0;


HardwareSerial mySerial = HardwareSerial();


void setup() {
    servo1a.attach(21);
    servo1b.attach(20);

    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(mySerial.available() > 0){     
      state = mySerial.read();
      Serial.println("STOP!");   
      flag=0;
    }
    // if the state is '1' the DC motor will go forward
    if (state == '1') {
         /* servo1a.write(90); 
            servo1b.write(90);
            delay(600);
          */
      servo1a.write(120);
      servo1b.write(120);
      delay(300);
  
      servo1a.write(60);
      servo1b.write(60);
      delay(300); 
        
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }

    }
    
    else if (state == '2') {

        
        if(flag == 0){
          Serial.println("GO BACK");
          flag=1;
        }
    }
    
    // if the state is '3' the motor will Stop
    else if (state == '3') {
        servo1a.write(90);
        servo1b.write(90);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
    }
    //For debugging purpose
    //Serial.println(state);
}
