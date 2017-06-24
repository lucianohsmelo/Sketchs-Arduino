   
#define DIGITO_1 2 //Anodo 12
#define DIGITO_2 5 //Anodo 9
#define DIGITO_3 6 // Anodo 8

#define SEGMENTO_A 3 // display 11
#define SEGMENTO_B 7 // dysplay 7
#define SEGMENTO_C 11 // display 4
#define SEGMENTO_D 9 // display 2
#define SEGMENTO_E 8 // display 1
#define SEGMENTO_F 4 // display 10
#define SEGMENTO_G 12 // display 5
#define PONTO 10 // display 3
 
#define ON  HIGH
#define OFF LOW
 
void setup()
{
 
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
 
}
 
void loop()
{
  
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(50);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   UM();
   delay(50);
   
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
