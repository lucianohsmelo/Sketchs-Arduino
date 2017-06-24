/******************************************************************************************************
*  Programa exemplo para uso do Sensor de Ultrasom HC-SR04 - MSS Eletrônica                           *
*  Produto: Sensor de Ultrasom HC-SR04 (http://www.msseletronica.com/loja/detalhes.php?urlid=)                                                               *
*  Desenvolvedor: Misael                                                                              *
*  Data: 31/10/2012                                                                                   *
*                                                                                                     *
*  Objetivo: Usar o sensor HC-SR04 para fazer a leitura de distância e mostrar em um LCD 16x2         *
*  Biblioteca usada: LiquidCrystal.h                                                                  *
*  Referencia para a Biblioteca: http://arduino.cc/en/Reference/LiquidCrystal                         *
*******************************************************************************************************/

/******************************************************************************************************
*  Informação sobre o programa:                                                                       *
*                                                                                                     *
*  Pinos usados para o LCD:                                                                           *
*    2 -> RS do LCD                                                                                   *
*    4 -> EN do LCD                                                                                   *
*    7 -> D4 do LCD                                                                                   *
*    8 -> D5 do LCD                                                                                   *
*    12 -> D6 do LCD                                                                                  *
*    13 -> D7 do LCD                                                                                  *
*    Você deve alimentar o LCD                                                                        *
*    Ligar um Potenciômetro/trimpot ao pino VO do LCD para controlar o contraste                      *
*    Ligar o R/W do LCD ao GND                                                                        *
*    Ligar os pinos D0, D1, D2, D3 do LCD ao GND                                                      *
*                                                                                                     *
*  Pinos usados para o Sensor de Ultrasom:                                                            *
*    5 -> Trig (Pino para disparo do sensor)                                                          *
*    6 -> Echo (Pino em que recebemos a resposta do sensor)                                           *
*    Você deve alimentar o sensor: Ligue VCC ao Pino 5V e o GND ao GND                                *
*******************************************************************************************************/
//Para melhores informações sobre o sensor HC-SR04, consulte o datasheet

//Para informações sobre a Biblioteca LiquidCrystal.h, vá na guia Help/Reference/Libraries/LiquidCrystal
#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2

LiquidCrystal lcd(2, 4, 7, 8, 12, 13);//Configurando os pinos que estão conectados ao LCD
//2 -> RS do LCD, 4 -> EN do LCD, 7 -> D4 do LCD, 8 -> D5 do LCD, 12 -> D6 do LCD, 13 -> D7 do LCD

//Declaração de variaveis
int pinTrig = 5;//Pino que deve ser conectado ao pino "Trig" do sensor de Ultrasom
int pinEcho = 6;//Pino que deve ser conectado ao pino "Echo" do sensor de Ultrasom

unsigned long tempo = 0;//Variável para armazenar o tempo da resposta do sensor
unsigned long distancia = 0;//Variável para receber a distância convertida em milimetros (mm)

//Rotina de configurações iniciais do programa
void setup() {
  
  Serial.begin(9600);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
  
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
 }

// the loop routine runs over and over again forever:
void loop() {
 
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(20);
  digitalWrite(pinTrig,LOW);
  tempo = pulseIn(pinEcho, HIGH);
  distancia = ((tempo * 10) / 58)+ 10 ;
  
  .clear();
  //lcd.setCursor(caracter, linha);
  lcd.setCursor(0, 0);
  lcd.print("Distancia:");
  
  if(distancia > 4000)
    {
    lcd.print("Limite");
    }
    else
      {
      lcd.print(distancia); 
      lcd.print("mm");
      }
  
  lcd.setCursor(1, 1);//Coloca o display na Segunda coluna e Segundo caracter
  lcd.print("MSS ELETRONICA");//Escreve a mensagem no LCD
  delay(200);
  
}

