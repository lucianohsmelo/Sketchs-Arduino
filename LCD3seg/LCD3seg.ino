#include <dht.h>

int DIGITO_1 = 13;
int SEGMENTO_A = 11;
int SEGMENTO_F = 10;
int DIGITO_2 = 9;
int SEGMENTO_E = 8;
int SEGMENTO_G = 7;
int SEGMENTO_C = 6;
int SEGMENTO_D = 5;
int PONTO = 4;
int DIGITO_3 = 3;
int SEGMENTO_B = 2;

int temp = 100;

void setup(){
  Serial.begin(9600);
  pinMode(DIGITO_1, OUTPUT);
  pinMode(DIGITO_2, OUTPUT);
  pinMode(DIGITO_3, OUTPUT);
  pinMode(PONTO, OUTPUT);
  pinMode(SEGMENTO_A, OUTPUT);
  pinMode(SEGMENTO_B, OUTPUT);
  pinMode(SEGMENTO_C, OUTPUT);
  pinMode(SEGMENTO_D, OUTPUT);
  pinMode(SEGMENTO_E, OUTPUT);
  pinMode(SEGMENTO_F, OUTPUT);
  pinMode(SEGMENTO_G, OUTPUT);
  digitalWrite(DIGITO_1, HIGH);
  digitalWrite(DIGITO_3, HIGH);
  digitalWrite(DIGITO_2, HIGH);
  delay(1000);//Aguarda 1 seg antes de acessar as informações do sensor
}

void loop(){
  
   ZERO();
  delay(temp);
   UM();
  
 delay(temp);
   DOIS();
 delay(temp);
   
   TRES();
  delay(temp);
   QUATRO();
  delay(temp);
   CINCO();
  delay(temp);
   SEIS();
  delay(temp);
   SETE();
  delay(temp);
   OITO();
   delay(temp);
   NOVE(); 
   delay(temp);
  
}



void ZERO()
{
   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, LOW);
   digitalWrite(SEGMENTO_E, LOW);
   digitalWrite(SEGMENTO_F, LOW);
   digitalWrite(SEGMENTO_G, HIGH);
}
void UM()
{
   digitalWrite(SEGMENTO_A, HIGH);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, HIGH);
   digitalWrite(SEGMENTO_E, HIGH);
   digitalWrite(SEGMENTO_F, HIGH);
   digitalWrite(SEGMENTO_G, HIGH);
}
void DOIS()
{
   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, HIGH);
   digitalWrite(SEGMENTO_D, LOW);
   digitalWrite(SEGMENTO_E, LOW);
   digitalWrite(SEGMENTO_F, HIGH);
   digitalWrite(SEGMENTO_G, LOW);
 
}
void TRES()
{
   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, LOW);
   digitalWrite(SEGMENTO_E, HIGH);
   digitalWrite(SEGMENTO_F, HIGH);
   digitalWrite(SEGMENTO_G, LOW);
}
void QUATRO()
{
   digitalWrite(SEGMENTO_A, HIGH);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, HIGH);
   digitalWrite(SEGMENTO_E, HIGH);
   digitalWrite(SEGMENTO_F, LOW);
   digitalWrite(SEGMENTO_G, LOW);
 
}
void CINCO()
{
   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, HIGH);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, LOW);
   digitalWrite(SEGMENTO_E, HIGH);
   digitalWrite(SEGMENTO_F, LOW);
   digitalWrite(SEGMENTO_G, LOW);
}
void SEIS()
{
   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, HIGH);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, LOW);
   digitalWrite(SEGMENTO_E, LOW);
   digitalWrite(SEGMENTO_F, LOW);
   digitalWrite(SEGMENTO_G, LOW);
}
void SETE()
{   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, HIGH);
   digitalWrite(SEGMENTO_E, HIGH);
   digitalWrite(SEGMENTO_F, HIGH);
   digitalWrite(SEGMENTO_G, HIGH);
 
}
void OITO()
{
   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, LOW);
   digitalWrite(SEGMENTO_E, LOW);
   digitalWrite(SEGMENTO_F, LOW);
   digitalWrite(SEGMENTO_G, LOW);
 
}
void NOVE()
{   digitalWrite(SEGMENTO_A, LOW);
   digitalWrite(SEGMENTO_B, LOW);
   digitalWrite(SEGMENTO_C, LOW);
   digitalWrite(SEGMENTO_D, HIGH);
   digitalWrite(SEGMENTO_E, HIGH);
   digitalWrite(SEGMENTO_F, LOW);
   digitalWrite(SEGMENTO_G, LOW);
 
}






