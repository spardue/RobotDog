

// G S D
const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;


void forward() {
 digitalWrite(A, HIGH);
 digitalWrite(B, HIGH);
 digitalWrite(C, LOW);
 digitalWrite(D, LOW);
}


void reverse() {
 digitalWrite(A, LOW);
 digitalWrite(B, LOW);
 digitalWrite(C, HIGH);
 digitalWrite(D, HIGH);
}


void brake() {
 digitalWrite(A, LOW);
 digitalWrite(B, HIGH);
 digitalWrite(C, LOW);
 digitalWrite(D, HIGH);
}

void coast() {
 digitalWrite(A, LOW);
 digitalWrite(B, LOW);
 digitalWrite(C, LOW);
 digitalWrite(D, LOW);
}

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  //pinMode(4, OUTPUT);
}

void loop() {
  //digitalWrite(4, HIGH);
  //analogWrite(4, 255);
  //delay(1000);
  forward();
  delay(2000);
  brake();
  delay(1000);
  reverse();
  delay(2000);
  analogWrite(C, 50);
  digitalWrite(D, HIGH);
  delay(3000);
  coast();
  delay(1000);
}
