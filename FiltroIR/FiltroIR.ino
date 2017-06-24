int i, filtered[300], value[300];
double A[5] = {1.0, -3.1806, 3.8612, -2.1122, 0.4383};
double B[5] = {0.0004, 0.0017, 0.0025, 0.0017, 0.0004};
int filtroIR(int readA){
  if (i < 300){
  value[i] = readA;
  if (i == 1){
    filtered[i] = B[0]*value[i];
  }else if (i == 2){
    filtered[i] = B[0]*value[i] + B[1]*value[i-1] - A[0]*value[i-1];
  }else if (i == 3){
    filtered[i] = B[0]*value[i] + B[1]*value[i-1] + B[2]*value[i-2] - A[0]*value[i-1] - A[1]*value[i-2];
  }else if (i == 4){
    filtered[i] = B[0]*value[i] + B[1]*value[i-1] + B[2]*value[i-2] + B[3]*value[i-3] - A[0]*value[i-1] - A[1]*value[i-2] - A[2]*value[i-3]; 
  }else if (i >= 5){
    filtered[i] = B[0]*value[i] + B[1]*value[i-1] + B[2]*value[i-2] + B[3]*value[i-3] + B[4]*value[i-4] - A[0]*value[i-1] - A[1]*value[i-2] - A[2]*value[i-3] - A[3]*value[i-4];
  }
  }else{
    i = 1; 
  }
  return filtered[i];
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  i = 1;

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(filtroIR(analogRead(0)));
  

}
