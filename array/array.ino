char p;
String palavra;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available() > 0)
{
        p = (byte)Serial.read();
        if(p == ':')
        {
           break;
        }else{
           palavra += p;
        }
        delay(1);
}
  if palavra = "('4onn')
  {
    1 = atoi(palavras):
  }
  
 
 
}

