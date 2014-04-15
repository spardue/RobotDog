
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

Servo servo1b;
Servo servo2b;
Servo servo3b;
Servo servo4b;

int state;
int flag = 0;


HardwareSerial mySerial = HardwareSerial();


void setup() {
    servo1.attach(21);
    servo2.attach(20);
    servo3.attach(19);
    servo4.attach(18);
   
    servo1b.attach(17);
    servo2b.attach(16);
    servo3b.attach(15);
    servo4b.attach(14);
    

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
 
    // if the state is '0', stop
    if (state == '0') {
        servo1.write(90);
        servo2.write(90);
        servo3.write(90);
        servo4.write(90);
        servo1b.write(90);
        servo2b.write(90);
        servo3b.write(90);
        servo4b.write(90);
        
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
    }
    
    // if the state is '1', go forward
    else if (state == '1') {
      
      
      forward();
      
      
   
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
 
    else if(state == '3') {
      servo1.write(120);
      servo4.write(60);
      
      servo2.write(120);
      servo3.write(60);
      
      delay(300);
      
      servo1.write(90);
      servo4.write(90);
      
      servo2.write(90);
      servo3.write(90);
      
      delay(300);
      
      servo1.write(60);
      servo4.write(120);
      
      servo2.write(60);
      servo3.write(120);
      
      delay(300);
      
      servo1.write(90);
      servo4.write(90);
      
      servo2.write(90);
      servo3.write(90);
      
      if(flag == 0){
          Serial.println("GO LEFT");
          flag=1;
        }
    }
    else if(state == '4') {
      
      servo1b.write(130);
      servo3b.write(130);
      servo4b.write(130);
      forward();
      
      if(flag == 0){
          Serial.println("GO RIGHT");
          flag=1;
        }
    }
    // if the state is '5', bow
    else if (state == '5') {

      servo1.write(30);     
      servo2.write(150);

        if(flag == 0){
          Serial.println("Puppy Bow!");
          flag=1;
        }

    }
    else if (state == '6') {

      run();

        if(flag == 0){
          Serial.println("RUNNNN!!!");
          flag=1;
        }

    }
}

void forward(){
      servo1.write(60);
      servo2.write(100);
 
      delay(10);
      servo1.write(120);
      servo2.write(60);
    
      
      delay(500);
      servo1.write(90);
      servo2.write(90);
      
      servo3.write(60);
      servo4.write(120);
      delay(10);
      servo3.write(120);
      servo4.write(60);
      delay(500);
      servo3.write(90);
      servo4.write(90);

     
}

void run(){
      servo1.write(60);
      servo2.write(100);
      servo3.write(120);
      servo4.write(60);
      delay(10);
      servo1.write(120);
      servo2.write(60);
      servo3.write(90);
      servo4.write(90);
      
      
      
}
