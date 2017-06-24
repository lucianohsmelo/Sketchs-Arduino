
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
  

  
  if(distancia < 4000)
    {
      Serial.print("Distancia em mm:  ");
      Serial.println(distancia); 
      }
  
  
  delay(200);
  
}

