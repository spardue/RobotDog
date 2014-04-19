#include <Stepper.h>

#define STEPS 48

Stepper stepper(STEPS, 11, 12, 13, 14);


void setup() {
  Serial.begin(9600);
  stepper.setSpeed(72);
  
}

int steps = 0;
int neg = 1;
void loop() {
 stepper.step(48 * neg);
 steps+=1;
 Serial.println(steps);
 if (steps >= 4  && neg == 1) {
  delay(1000);
  stepper.setSpeed(36);
  steps = 0;
  neg = -1;
 }
 else if (steps >= 2 && neg == -1) {
  delay(1000);
  stepper.setSpeed(72);
  steps = 0;
  neg = 1;
 }
 
}
