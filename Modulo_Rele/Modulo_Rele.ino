int rele1 = 5;
int rele2 = 7;
int rele3 = 8;
int rele4 = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.println("1/Q - ON/OFF Rele 1");
  Serial.println("2/W - ON/OFF Rele 2");
  Serial.println("3/E - ON/OFF Rele 3");
  Serial.println("4/R - ON/OFF Rele 4");
  Serial.println(" 0 - Ler instruções novamente"); 
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
  digitalWrite(rele4, HIGH);
}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();
if (c == '0')
    {
      Serial.println("1/Q - ON/OFF Rele 1");
      Serial.println("2/W - ON/OFF Rele 2");
      Serial.println("3/E - ON/OFF Rele 3");
      Serial.println("4/R - ON/OFF Rele 4");
    }
    if (c == 'R')
    {
      digitalWrite(rele4, HIGH);
      Serial.println("Rele 4 desligado!");
    }
     if (c == 'E')
    {
      digitalWrite(rele3, HIGH);
      Serial.println("Rele 3 desligado!");
    }
     if (c == 'W')
    {
      digitalWrite(rele2, HIGH);
      Serial.println("Rele 2 desligado!");
    }
     if (c == 'Q')
    {
      digitalWrite(rele1, HIGH);
      Serial.println("Rele 1 desligado!");
    }
    else if (c == '4')
    {

      digitalWrite(rele4, LOW);
      Serial.println("Rele 4 ligado!");
    }
    if (c == '3')
    {
      digitalWrite(rele3, LOW);
      Serial.println("Rele 3 ligado!");
    }
    if (c == '2')
    {
      digitalWrite(rele2, LOW);
      Serial.println("Rele 2 ligado!");
    }
     if (c == '1')
    {
      digitalWrite(rele1, LOW);
      Serial.println("Rele 1 ligado!");
    }
  }
}
