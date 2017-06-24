
const int portaLed = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop()
{
  if (Serial.available())
  {
    int c = Serial.read();
    if (c == '1')
    {
      digitalWrite(11, HIGH);
      Serial.println("Ok, led 1 ligado!");
    }
     if (c == '2')
    {
      digitalWrite(8, HIGH);
      Serial.println("Ok, led 2 ligado!");
    }
     if (c == '3')
    {
      digitalWrite(5, HIGH);
      Serial.println("Ok, led 3 ligado!");
    }
    else if (c == 'a')
    {
      digitalWrite(11, LOW);
      Serial.println("Ok, led 1 desligado!");
    }
    if (c == 'b')
    {
      digitalWrite(8, LOW);
      Serial.println("Ok, led 2 desligado!");
    }
    if (c == 'c')
    {
      digitalWrite(5, LOW);
      Serial.println("Ok, led 3 desligado!");
    }
  }
}
