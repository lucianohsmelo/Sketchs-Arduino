#define rele 4
#define contador 9
#define readCoin 3
#define readCup 2
int i, cont, test, erro;
bool coin, cup;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Iniciando");
  pinMode(readCup, INPUT);
  pinMode(13,OUTPUT);
  pinMode(contador,OUTPUT);
  pinMode(rele,OUTPUT);
}

void loop() {
  if ( erro < 900){
      if (analogRead(readCoin) >= 600){
        cont = cont + 1;
        Serial.println("Add Moeda");
      }
      
      if (cont >= 1){
        coin = true;   
      }else{
        coin = false;
      }
      if (digitalRead(readCup) == 1){
         cup = true;
      }else{
          cup = false;  
      }
     if (analogRead(readCoin) < 700){
        if (coin == true){
          if (cup == true){
            Serial.println("OUT OK");
            digitalWrite(rele,HIGH);
            digitalWrite(contador,HIGH);
            delay(1000);
            digitalWrite(rele,LOW);
            digitalWrite(contador,LOW);
            cont = 0;
          }
        }
     }

     test = test + analogRead(readCoin);
     i = i + 1;
     erro = test/3;
          
      Serial.print("Moeda: ");
      Serial.print(cont);
      Serial.print("  Copo: ");
      Serial.print(cup);
      Serial.print("  ");
      Serial.println(erro);
      delay(100);
      if (i == 4){
        i = 0;
        test = 0;
      }
  }else{
    Serial.println(erro);    
    if (analogRead(readCoin) < 600){
      erro = 0;
      cont = 0;
    }
  }
}
