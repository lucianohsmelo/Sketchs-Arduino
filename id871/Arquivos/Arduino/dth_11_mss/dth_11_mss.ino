/******************************************************************************************************
*  Programa exemplo para uso do Sensor de Umidade e Temperatura DHT-11 - MSS Eletrônica               *
*  Produto: Sensor de Ultrasom HC-SR04 (http://www.msseletronica.com/loja/detalhes.php?urlid=871)     *
*  Produtos relacionados: http://www.msseletronica.com/loja/produtos.php?urlcat=15&urlsubcat=173      *
*  Desenvolvedor: Misael                                                                              *
*  Data: 31/10/2012                                                                                   *
*                                                                                                     *
*  Objetivo: Usar o sensor DHT-11 lendo a umidade e temperatura e mostrando em um LCD 16x2            *
*  Bibliotecas usadas:                                                                                *
*   LiquidCrystal.h - http://arduino.cc/en/Reference/LiquidCrystal                                    *
*   dht11.h - http://www.arduino.cc/playground/Main/DHTLib/                                           *
*                                                                                                     *
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
*  Pinos usados para o Sensor DHT-11:                                                                 *
*    3 -> Sensor (Pino para comunicação como o sensor)                                                *
*    Você deve alimentar o sensor: Ligue VCC ao Pino 5V e o GND ao GND                                *
*******************************************************************************************************/
//Para melhores informações sobre o sensor DTH-11, consulte o datasheet

//Para informações sobre a Biblioteca LiquidCrystal.h, vá na guia Help/Reference/Libraries/LiquidCrystal
#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2
#include <dht11.h>//Inclui a biblioteca para leitura do sensor DHT-11

LiquidCrystal lcd(2, 4, 7, 8, 12, 13);//Configurando os pinos que estão conectados ao LCD
//2 -> RS do LCD, 4 -> EN do LCD, 7 -> D4 do LCD, 8 -> D5 do LCD, 12 -> D6 do LCD, 13 -> D7 do LCD

//Declaração de variaveis
dht11 sensor;//Declarando uma variavel de nome "sensor" do tipo dht11 (Da biblioteca importada por #include <dht11.h>)

//Declaração de constantes
#define pinSensor 3//Constante que deve receber o número do pino ao qual esta conectado o pino de comunicaçao do sensor DHT-11

//Rotina de configurações iniciais do programa
void setup() {
  
  lcd.begin(16, 2);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
 }

// Rotina que será executada infinitamente
void loop() {
 
  if(sensor.read(pinSensor)==0)//Solicita a leitura do sensor e testa se o sensor respondeu 
    {
    lcd.setCursor(0,0);//Coloca o cursor do LCD no primeiro caracter e primeira linha (setCursor(caracter,linha))
    lcd.print("RH: ");//Imprime a sigla
    lcd.print(sensor.humidity);//Imprime a umidade
    lcd.print("%");//Imprime o simbolo
    lcd.setCursor(0,1);//Coloca o cursor do LCD no primeiro caracter e segunda linha (setCursor(caracter,linha))
    lcd.print("TEMP: ");//Imprime a sigla
    lcd.print(sensor.temperature);//Imprime a temperatura
    lcd.print("C");//Imprime o simbolo sem o "º"
    }
  
  delay(1000);//Aguarda 1s, intervalo entre as leituras exigido pelo fabricante
}

