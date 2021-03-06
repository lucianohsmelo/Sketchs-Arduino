#include <dht.h>

int temp = 10;

#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1
#define DIGITO_1 13 //Anodo 12
#define DIGITO_2 9 //Anodo 9
#define DIGITO_3 3 // Anodo 8

#define SEGMENTO_A 11 // display 11
#define SEGMENTO_B 2 // dysplay 7
#define SEGMENTO_C 6 // display 4
#define SEGMENTO_D 5 // display 2
#define SEGMENTO_E 8 // display 1
#define SEGMENTO_F 10 // display 10
#define SEGMENTO_G 7 // display 5
#define PONTO 4 // display 3
 
#define ON  HIGH
#define OFF LOW
dht DHT; //Inicializa o sensor

void setup()
{
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
  delay(1000);//Aguarda 1 seg antes de acessar as informações do sensor
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop()
{
    DHT.read11(dht_dpin); //Lê as informações do sensor
    int T = DHT.temperature;
    if (T == 1 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
 }

  if (T == 2 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
 }

  if (T == 3 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
 }

  if (T == 4 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
 }

  if (T == 5 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   CINCO();
   delay(temp);
 }

  if (T == 6 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SEIS();
   delay(temp);
 }

  if (T == 7 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SETE();
   delay(temp);
 }

  if (T == 8 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   OITO();
   delay(temp);
 } 
  if (T == 9 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   NOVE();
   delay(temp);
 }
    
  if (T == 10 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
 }
 
  if (T == 11 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
 }
 
  if (T == 12 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
 }
 
  if (T == 13 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
 }
 
  if (T == 14 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
 }
 if (T == 15 ){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   CINCO();
   delay(temp);
 }
  if (T == 16){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SEIS();
   delay(temp);
 }
 
 
  if (T == 17){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SETE();
   delay(temp);
 }
 
 
  if (T == 18){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, HIGH);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   OITO();
   delay(temp);
 }
 
 
  if (T == 19){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, HIGH);
   UM();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   NOVE();
   delay(temp);
 }
 
 
  if (T == 20){
    delay(temp);
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, HIGH);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   ZERO();
   
 }
 
  if (T == 21){
    delay(temp);
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, HIGH);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   UM();
   
 }
 
  if (T == 22){
    delay(temp);
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, HIGH);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   DOIS();
   
 }
 
  if (T == 23){
    delay(temp);
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, HIGH);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   TRES();
   
 }
 
 if (T == 24){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
 }
 
 if (T == 25){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   CINCO();
   delay(temp);
 }
   
   if (T == 26){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SEIS();
   delay(temp);
 }
 
 if (T == 27){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SETE();
   delay(temp);
 }
 
 if (T == 28){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   OITO();
   delay(temp);
 }
 
 if (T == 29){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   NOVE();
   delay(temp);
 }
   
   if (T == 30){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
 }
 
  if (T == 31){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
 }
 
  if (T == 32){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
 }
 
  if (T == 33){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
 }
 
  if (T == 34){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
 }
 
  if (T == 35){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   CINCO();
   delay(temp);
 }
 
  if (T == 36){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SEIS();
   delay(temp);
 }
 
  if (T == 37){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SETE();
   delay(temp);
 }
 
  if (T == 38){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   OITO();
   delay(temp);
 }
 
  if (T == 39){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   NOVE();
   delay(temp);
 }
 
  if (T == 40){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
 }
 
 if (T == 41){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   UM();
   delay(temp);
 }
 
 if (T == 42){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   DOIS();
   delay(temp);
 }
 
 if (T == 43){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   TRES();
   delay(temp);
 }
 
 if (T == 44){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
 }
 
 if (T == 45){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   CINCO();
   delay(temp);
 }
  if (T == 45){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SEIS();
   delay(temp);
 }
  if (T == 45){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   SETE();
   delay(temp);
 }
  if (T == 45){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   OITO();
   delay(temp);
 }
  if (T == 45){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   QUATRO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   NOVE();
   delay(temp);
 }
  if (T == 45){
   digitalWrite(DIGITO_2, HIGH);
   digitalWrite(DIGITO_3,LOW);
   digitalWrite(PONTO, LOW);
   CINCO();
   delay(temp);
   digitalWrite(DIGITO_2, LOW);
   digitalWrite(DIGITO_3, HIGH);
   digitalWrite(PONTO, LOW);
   ZERO();
   delay(temp);
 }
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
