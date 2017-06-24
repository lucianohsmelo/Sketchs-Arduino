int saida = 5;
int temp = 100;


void setup()
{
  Serial.begin(9600);
  pinMode(saida, OUTPUT);
  digitalWrite( saida,LOW);

}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();
   
    if (c == 'o')
    {
      digitalWrite(saida ,HIGH);
      delay(1000);
      digitalWrite(saida ,LOW);
      Serial.println("   OPEN!");
    }
   
  }
}
