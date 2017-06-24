void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.println("1/Q - ON/OFF LED 1");
  Serial.println("2/W - ON/OFF LED 2");
  Serial.println("3/E - ON/OFF LED 3");
  Serial.println("4/R - ON/OFF LED 4");
  Serial.println(" 0 - Menu");
}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();
    if (c == '0')
    {
      Serial.println("1/Q - ON/OFF LED 1");
      Serial.println("2/W - ON/OFF LED 2");
      Serial.println("3/E - ON/OFF LED 3");
      Serial.println("4/R - ON/OFF LED 4");
      Serial.println(" 0 - Menu");
    }
    if (c == '4')
    {
      digitalWrite(10, HIGH);
      Serial.println("Led 4 ligado!");
    }
     if (c == '3')
    {
      digitalWrite(8, HIGH);
      Serial.println("Led 3 ligado!");
    }
     if (c == '2')
    {
      digitalWrite(7, HIGH);
      Serial.println("Led 2 ligado!");
    }
     if (c == '1')
    {
      digitalWrite(5, HIGH);
      Serial.println("Led 1 ligado!");
    }
    else if (c == 'R')
    {

      digitalWrite(10, LOW);
      Serial.println("Led 4 deligado!");
    }
    if (c == 'E')
    {
      digitalWrite(8, LOW);
      Serial.println("Led 3 deligado!");
    }
    if (c == 'W')
    {
      digitalWrite(7, LOW);
      Serial.println("Led 2 deligado!");
    }
     if (c == 'Q')
    {
      digitalWrite(5, LOW);
      Serial.println("Led 1 deligado!");
    }
  }
}
