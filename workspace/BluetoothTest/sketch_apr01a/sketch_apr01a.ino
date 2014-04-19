#include <SoftwareSerial.h>
#include <Servo.h> 

const int pmw1 = 12;
const int motor = 9;

 
Servo myservo;

void setup() {
  pinMode(pmw1, OUTPUT);
  Serial.begin(9600);
  myservo.attach(motor);
}


void mypmw() {
  int i;
  
  
 
  for (i = 0; i < 1000; i++){
    
    digitalWrite(pmw1, HIGH);
    delayMicroseconds(i);
    digitalWrite(pmw1, LOW);
    delayMicroseconds(1000-i);
  }
  
   for (i; i > 0; i--){
    
    digitalWrite(pmw1, HIGH);
    delayMicroseconds(i);
    digitalWrite(pmw1, LOW);
    delayMicroseconds(1000-i);
  }
  
}

void hardwarepmw() {
  String readStr = "";
  if (Serial.available() > 0) {
     Serial.println("panda");
     
     readStr += (char) Serial.read();
     Serial.println(readStr);
     if (readStr == "B") {
        readStr = "";
        for (int i = 0; i < 3; i++){
          readStr+= (char) Serial.read();
        }
        Serial.read();
        Serial.println(readStr.toInt());
        analogWrite(pmw1, readStr.toInt());
     }
  }
  
}

void loop() {
  
  //mypmw();
  //hardwarepmw();
  int pos = 90;
  myservo.write(pos);
  for (int i = 0; i < 30; i++){
    myservo.write(pos+i);
    delay(15);
  }
//  for (pos = 0; pos < 30; pos++) {
//   myservo.write(pos); 
//   delay(15);
//  }
//  for (pos = 30; pos > 0; pos--) {
//   myservo.write(pos); 
//   delay(15);
//  }
  
}
