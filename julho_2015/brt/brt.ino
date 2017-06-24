int C_HIGH = 11;
int C_LOW = 10;
int B_HIGH = 9;
int B_LOW = 8;
int A_HIGH = 7;
int A_LOW = 6;
int tim = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(C_HIGH,OUTPUT);
  pinMode(C_LOW,OUTPUT);
  pinMode(B_HIGH,OUTPUT);
  pinMode(B_LOW,OUTPUT);
  pinMode(A_HIGH,OUTPUT);
  pinMode(A_LOW,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(A_HIGH,1);
 digitalWrite(B_HIGH,1);
 digitalWrite(C_HIGH,0);
 digitalWrite(A_LOW,0);
 digitalWrite(B_LOW,0);
 digitalWrite(C_LOW,1);
 delay(tim);
 digitalWrite(A_HIGH,1);
 digitalWrite(B_HIGH,0);
 digitalWrite(C_HIGH,0);
 digitalWrite(A_LOW,0);
 digitalWrite(B_LOW,1);
 digitalWrite(C_LOW,1);
 delay(tim);
 digitalWrite(A_HIGH,1);
 digitalWrite(B_HIGH,0);
 digitalWrite(C_HIGH,1);
 digitalWrite(A_LOW,0);
 digitalWrite(B_LOW,1);
 digitalWrite(C_LOW,0);
 delay(tim);
 digitalWrite(A_HIGH,0);
 digitalWrite(B_HIGH,0);
 digitalWrite(C_HIGH,1);
 digitalWrite(A_LOW,1);
 digitalWrite(B_LOW,1);
 digitalWrite(C_LOW,0);
 delay(tim);
 digitalWrite(A_HIGH,0);
 digitalWrite(B_HIGH,1);
 digitalWrite(C_HIGH,1);
 digitalWrite(A_LOW,1);
 digitalWrite(B_LOW,0);
 digitalWrite(C_LOW,0);
 delay(tim);
 digitalWrite(A_HIGH,0);
 digitalWrite(B_HIGH,1);
 digitalWrite(C_HIGH,0);
 digitalWrite(A_LOW,1);
 digitalWrite(B_LOW,0);
 digitalWrite(C_LOW,1);
 delay(tim); 
}
