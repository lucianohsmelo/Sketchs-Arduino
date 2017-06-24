int rele1 = 5;
int rele2 = 7;
int rele3 = 8;
int rele4 = 10;

boolean out1, out2, out3, out4;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
  digitalWrite(rele4, HIGH);
  out1 = false;
  out2 = false;
  out3 = false;
  out4 = false;
}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();
    if (c == '4')
    {
      if (out4 == false){
        digitalWrite(rele4, LOW);
        out4 = true;
      }
      else{
        digitalWrite(rele4, HIGH);
        out4 = false;
      }
    }

    if (c == '3')
    {
      if (out3 == false){
        digitalWrite(rele3, LOW);
        out3 = true;
      }
      else{
        digitalWrite(rele3, HIGH);
        out3 = false;
      }
    }

    if (c == '2')
    {
      if (out2 == false){
        digitalWrite(rele2, LOW);
        out2 = true;
      }
      else{
        digitalWrite(rele2, HIGH);
        out2 = false;
      }
    }

    if (c == '1')
    {
      if (out1 == false){
        digitalWrite(rele1, LOW);
        out1 = true;
      }
      else{
        digitalWrite(rele1, HIGH);
        out1 = false;
      }
    }
  }
}
