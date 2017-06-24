/******************************************************************************
*  Programa de teste para o Sensor de Ultrasom HC-SR04 com LCD 16x2           *
*  Desenvolvedor: Misael S. Sales                                             *
*  Versão: 1.0                                                                *
*  Data: 02/11/2012                                                           *
*  PIC: Linha 16F de 40 pinos (Para usar em outros mude o nome das portas )   *
*  Display: HD44780                                                           *
*  Licença: Livre para uso e modificação                                      *
*                                                                             *
*  MSS Eletrônica - www.msseletronica.com - msseletronica@hotmail.com.br      *
*                                                                             *
*******************************************************************************/

#include <16F877A.h>
#device *=16
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES XT                       //Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected

#use delay(clock=4000000)

#ZERO_RAM

#include <LCD_MSS.h>
/******************************************************************************
*  Ligações do LCD                                                            *
*   D7 -> RD7 (PORTD 7)                                                       *
*   D6 -> RD6 (PORTD 6)                                                       *
*   D5 -> RD5 (PORTD 5)                                                       *
*   D4 -> RD4 (PORTD 4)                                                       *
*   RS -> RD3 (PORTD 3)                                                       *
*   EN -> RD2 (PORTD 2)                                                       *
*   R/W -> Deve ser conectado ao GND                                          *
*   VCC -> Deve ser conectado ao +5V                                          *
*   GND -> Deve ser conectado ao GND                                          *
*   VO -> Deve ser conectado ao potenciômetro/trimpot de ajuste de brilho     *
******************************************************************************/

/******************************************************************************
* Ligações do Sensor HC-SR04                                                  *
*  Trig -> Pino RC0 do PORTC                                                  *
*  Echo -> Pino RC1 do PORTC                                                  *
*  VCC -> Deve ser conectado ao +5V                                           *
*  GND -> Deve ser conectado ao GND                                           *
******************************************************************************/
  
#use fast_io(c)//O Controle de direção (Entrada/Saida) dos pinos será feito no programa
#use fast_io(d)//O Controle de direção (Entrada/Saida) dos pinos será feito no programa

#byte PORTC = 0x07//Endereço do PORTC
#byte PORTD = 0x08//Endereço do PORTD

#bit Trig = PORTC.0 //pino que dispara o ultrasom
#bit Echo = PORTC.1 //pino que lê a resposta


//Declaração de funções
unsigned int16 ler_US(void); //função que lê e retorna a distância em mm
void exibe_distancia(unsigned int16);//rotina que converte a distância em caracteres e envia para o LCD

void main()
{

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2);
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_2);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   
   // TODO: USER CODE!!
   
   //Os Pinos RD2 a RD7 são usados pelo LCD, os pinos RD0 e RD1 estão livre para uso
   set_tris_d(0b00000000);//Configurando todos os pinos como saída
   //Os pinos Trig e Echo estão conectados no PORTC, Trig -> RC0 e Echo -> RC1
   set_tris_c(0b00000010);//Pino RC1 como entrada e o restante como saída
   
   PORTC = 0;//Inicia com todos os pinos que forem saída em zero
   PORTD = 0;//Inicia com todos os pinos que forem saída em zero
  
   configura_lcd();//Chama a rotina que faz as configurações básica para o LCD funcionar
   inicio_lcd();//Coloca o cursor no inicio
   limpa_lcd();//Limpra o LCD
   
   linha_1_lcd(4);//Começa a escrever apartir do caracter 4 na primeira linha
   caracter_lcd('D');
   caracter_lcd('I');
   caracter_lcd('S');
   caracter_lcd('T');
   caracter_lcd(':');
   caracter_lcd(' ');
  
   while(1)//Loop infinito do programa
      {
      linha_1_lcd(10);//Imprime a distância apartir do caracter 10
      
      delay_ms(250); //Garante o tempo minimo para aquisição de nova distancia (O fabricante exige minimo 50ms)
      exibe_distancia(ler_US());//Chama a rotina que exibe a distancia no LCD, e passa como parametro a distancia lida em ler_US()
      }

}

unsigned int16 ler_US(void)//Esta rotina realiza a leitura da distancia e a retorna em mm
   {
   unsigned int16 vl_timer = 0;//Variavel para armazenar o tempo
   unsigned int16 distancia = 0;//Armazena a distancia convertida
   Trig = 1;//Dispara o Ultrasom
   delay_us(20);//Aguarda um tempo (minimo de 10us)
   Trig = 0;//Volta para 0 (zero)
   
   while(!Echo){}//Aguarda começar a enviar a resposta
   
   set_timer1(0);//Reinicia o TIMER1
         
   while(Echo){}//Fica parado até receber a resposta
   
   vl_timer = get_timer1();//Le o tempo em que ficou recebendo a resposta (Tempo de instrução / 2 em uS)

   distancia = ((((vl_timer * 2) * 10) / 58) + 10);//Como o divisor do TIMER1 estar 1:2, multiplicamos por 10, passo para mm (x 10) e converto ( / 58)
   return distancia;//A função retorna o valor convertido em mm
   }

void exibe_distancia(unsigned int16 distancia)//Rotina responsavel por converter em caracter e enviar a distância
   {
   unsigned int16 x;//declara uma váriavel auxiliar
   
   x = distancia / 10000;//Pega a dezena de milhar(Ex: 12345, pega apenas o '1') Inteiro de 12345/10000
   x = x + 48; //Converte em caracter ASCII
   caracter_lcd(x);//Envia para o LCD
   
   x = distancia / 1000;//Pega a Dezena e Unidade de Milhar (Ex: 12345, pega '12') Inteiro de 12345/1000
   x = x % 10; //Pega a Unidade de milhar (Ex: 12345, pega apenas '2') resto da divisão 12/10
   x = x + 48; //Converte em caracter ASCII
   caracter_lcd(x); //Envia para o LCD
   
   x = distancia / 100; //Pega dezena, unidade de milhar e a centena (Ex:12345, pega '123') Inteiro de 12345/100
   x = x % 10; //Pega a centena (Ex: 12345, pega apenas '3') o resto da divisão 123/10
   x = x + 48; //Converte em caracter ASCII
   caracter_lcd(x);//Envia para o LCD
   
   x = distancia / 10; //Pega dezena e unidade de milhar, centena e desena (Ex: 12345, pega '1234') Inteiro de 12345/10
   x = x % 10; //Pega a dezena (Ex: 12345, pega apenas '4') o resto da divisão 1234/10
   x = x + 48;//Converte em caracter ASCII
   caracter_lcd(x);//Envia para o LCD
   
   x = distancia % 10;//Pega a unidade (Ex: 12345, pega apenas '5')  Resto de 12345/10
   x = x + 48;//Converte em caracter ASCII
   caracter_lcd(x);//Envia para o LCD
   caracter_lcd('m');
   caracter_lcd('m');//Exibe mm   
   }

