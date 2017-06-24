int pinTrig = 10;//Pino que deve ser conectado ao pino "Trig" do sensor de Ultrasom
int pinEcho = 11;//Pino que deve ser conectado ao pino "Echo" do sensor de Ultrasom
int pinLed = 13;

unsigned long tempo = 0;//Variável para armazenar o tempo da resposta do sensor
unsigned long distancia = 0;//Variável para receber a distância convertida em milimetros (mm)

void setup()
{ 
  Serial.begin(9600); 
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
 }

void loop() 
{ 
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(20);
  digitalWrite(pinTrig,LOW);
  tempo = pulseIn(pinEcho, HIGH);
  distancia = ((tempo * 10) / 58)+ 10 ;

    
      Serial.print("Distancia em mm: ") ;
      Serial.println(distancia);
    
  if (distancia > 100)
  {
    digitalWrite(pinLed, HIGH);
  }
  else
  {
    digitalWrite(pinLed, LOW);
  }
  
}

