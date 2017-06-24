int filtered;
int vals[10];

int filter(int value, int n){
  for (int i = n - 1; i>0; i--){
    vals[i] = vals[i-1];
  }
  vals[0] = value;
  long sum = 0;
  for (int i = 0; i < n; i++){
    sum = sum + vals[i];
  }
  int avg = sum/n;
  return avg;
}

int mediaMovel(int analog,int n){
  long sum;
  int value[n];
  for (int i = 1; i <= n; i++){
    value[i] = analogRead(analog);
    sum = sum + value[i];
  }
  int avg = sum/n;
  return sum;
}
  
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int data = analogRead(0);
  //filtered = filter(data);
  int n = 10;
  int value[n];
  int sum;
  for (int i = 1; i <= n; i++){
    value[i] = analogRead(0);
    sum = sum + value[i];
  }
  int avg = sum/n;
  
  filtered = avg;
  Serial.print(data);
  Serial.print('\t');
  Serial.println(filtered);
  delay(100);
}
