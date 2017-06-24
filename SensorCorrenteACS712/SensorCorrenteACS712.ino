//20A = 100mV
int pinoSensor = A0;
int sensorValue_aux = 0;
float valorSensor = 0;
float valorCorrente = 0;
float voltsporUnidade = 0.004887586;// 5%1023
float sensibilidade = 0.100;

//Tensao da rede AC 110 Volts e na verdade (127 volts)
int tensao = 127;



void setup() {


  //Incia a Serial
  Serial.begin(9600); 
  pinMode(pinoSensor, INPUT);  
}

void loop() {

  for(int i=10000; i>0; i--){
    // le o sensor na pino analogico A0 e ajusta o valor lido ja que a saída do sensor é (1023)vcc/2 para corrente =0
    sensorValue_aux = (analogRead(pinoSensor) - 511.4); 
    // somam os quadrados das leituras.
    valorSensor += pow(sensorValue_aux,2); 
  
  }

  // finaliza o calculo da média quadratica e ajusta o valor lido para volts
  valorSensor = (sqrt(valorSensor/ 10000)) * voltsporUnidade; 
  // calcula a corrente considerando a sensibilidade do sernsor (185 mV por amper)
  valorCorrente = (valorSensor/sensibilidade); 

  //tratamento para possivel ruido
  //O ACS712 para 30 Amperes é projetado para fazer leitura
  // de valores alto acima de 0.25 Amperes até 30.
  // por isso é normal ocorrer ruidos de até 0.20A
  //por isso deve ser tratado
  if(valorCorrente <= 0.095){
    valorCorrente = 0; 
  }

  valorSensor =0;


  //Escreve
  //Calcula e mostra o valor da potencia
  Serial.print("Corrente: ");
  Serial.print(valorCorrente);
  Serial.println(" A");
  Serial.print("Potencia (Consumo) : ");
  Serial.print(valorCorrente * tensao);
  Serial.println(" Watts ");
  delay(100);

}
