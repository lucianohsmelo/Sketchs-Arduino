int Frente = 10, Re = 11, Esquerda = 6, Direita = 5; // declaração de variável para as portas digitais
int aux = 0;// declaração de variável aux
int pwm = 0;// declaração de variável pwm


void setup(){
  Serial.begin(9600);   //Inicializa a comunicação serial
  pinMode(Frente, OUTPUT);//pino 10 como sáida
  pinMode(Re, OUTPUT);//pino 11 como sáida
  pinMode(Direita, OUTPUT);//pino 5 como sáida
  pinMode(Esquerda,OUTPUT);//pino 6 como sáida
  
  //programa inicia com estado inicial parado
  digitalWrite(Frente, LOW);
  digitalWrite(Re, LOW);
  digitalWrite(Direita, LOW);
  digitalWrite(Esquerda, LOW);
  
  
}


void loop(){    
 
     if (Serial.available())//se ocorrer comunicação serial faz:
  {
      int c = Serial.read();// c = leitura da porta serial
      if ((c == 'U') && (aux == 0)){  //se c = U e aux = 0, carro anda para frente com 25% da tensão
        pwm = 64;
        analogWrite(Re, 0);// porta digital da 'Re' fica em estado baixo
        analogWrite(Frente,127);
        delay(1000);
        analogWrite(Frente, pwm);  //pwm = 64(25% da tensão)
        aux = aux + 1;  //aux = 0 + 1 = 1
      }
      
      
      else if ((c == 'U') && (aux == 1)){  //se c = U e aux = 1, carro anda para frente com 50% da tensão
        pwm = 127;
        analogWrite(Re, 0); // porta digital da 'Re' fica em estado baixo
        analogWrite(Frente, pwm);//pwm = 127(50% da tensão)
        aux = aux + 1; //aux = 1 + 1 = 2
      }
      
      
      else if ((c == 'U') && (aux == 2)){ //se c = U e aux = 2, carro anda para frente com 75% da tensão
        pwm = 191;
        analogWrite(Re, 0);  // porta digital da 'Re' fica em estado baixo
        analogWrite(Frente, pwm); //pwm = 191(75% da tensão)
        aux = aux + 1; //aux = 2 + 1 = 3
      }
      
      
      else if ((c == 'U') && (aux == 3)){   //se c = U e aux = 3, carro anda para frente com 100% da tensão
        pwm = 255;
        analogWrite(Re, 0);  // porta digital da 'Re' fica em estado baixo
        analogWrite(Frente, pwm); //pwm = 255 (100% da tensão)
        aux = aux + 1; // aux = 3 + 1 = 4
      }
      
      
      else if ((c == 'D') && (aux == 4)){ //diminui a velocidade do carro (75% da tensão)
        pwm = 191;
        analogWrite(Re, 0);  // porta digital da 'Re' fica em estado baixo
        analogWrite(Frente, pwm);//pwm = 191(75% da tensão)
        aux = aux - 1; // aux = 
      }
      
      
      else if ((c == 'D') && (aux == 3)){ //diminui a velocidade do carro (50% da tensão)
        pwm = 127;
        analogWrite(Re, 0);  // porta digital da 'Re' fica em estado baixo
        analogWrite(Frente, pwm);//pwm = 127(50% da tensão)
        aux = aux - 1; // aux = 
      }
      
      
      else if ((c == 'D') && (aux == 2)){ //diminui a velocidade do carro (25% da tensão)
        pwm = 64;
        analogWrite(Re, 0);  // porta digital da 'Re' fica em estado baixo
        analogWrite(Frente, pwm); //pwm = 64(25% da tensão)
        aux = aux - 1; // aux = 
      }
      
      
      else if ((c == 'D') && (aux == 1)){ //diminui a velocidade do carro (0% da tensão)
        pwm = 0;
        analogWrite(Re, 0); // porta digital da 'Re' fica em estado baixo
        digitalWrite(Frente, LOW);
        aux = aux - 1; // aux = 0
      
      }
      
      else if ((c == 'D') && (aux == 0)){ 
        pwm = 64;
        analogWrite(Frente, 0); // porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re,127);
        delay(1000);
        analogWrite(Re, pwm); //pwm = 64(25% da tensão)
        aux = aux - 1; // aux = 
         
      }
      
      else if ((c == 'D') && (aux == -1)){
        pwm = 127;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re, pwm);//pwm = 127(50% da tensão)
        aux = aux - 1; // aux = 
        Serial.println("50% da tensao - R"); //escreve na serial   
      }
      
      else if ((c == 'D') && (aux == -2)){
        pwm = 191;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re, pwm);//pwm = 191(75% da tensão)
        aux = aux - 1; // aux = 
        Serial.println("75% da tensao - R"); //escreve na serial   
      }
      
      else if ((c == 'D') && (aux == -3)){
        pwm = 255;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re, pwm);//pwm = 255 (100% da tensão)
        aux = aux - 1; // aux = 
        Serial.println("100% da tensao - R");  //escreve na serial
      }
      
      else if ((c == 'U') && (aux == -4)){
        pwm = 191;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re, pwm);//pwm = 191(75% da tensão)
        aux = aux + 1; // aux = 
        Serial.println("75% da tensao - R");//escreve na serial
      }
      
      else if ((c == 'U') && (aux == -3)){
         pwm = 127;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re, pwm);//pwm = 127(50% da tensão)
        aux = aux + 1;
        Serial.println("50% da tensao - R");//escreve na serial
      }
      
      else if ((c == 'U') && (aux == -2)){
        pwm = 64;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo 
        analogWrite(Re, pwm);//pwm = 64(25% da tensão)
        aux = aux + 1;
       Serial.println("25% da tensao - R");//escreve na serial
      }
      
      else if ((c == 'U') && (aux == -1)){
        pwm = 0;
        analogWrite(Frente, 0);// porta digital da direção 'Frente' fica em estado baixo
        analogWrite(Re, pwm);
        aux = aux + 1;
        Serial.println("0% da tensao - P");//escreve na serial
      }
      
      
     else if (c == 'L')
    {
      analogWrite(Direita, 0); //pino 'Direita' fica em estado baixo
      delay(100);
      analogWrite(Esquerda,127);//pino 'Esquerda' fica em estado alto
    }
    else if (c == 'C')
    {
      analogWrite(Direita, 0);//pino 'Direita' fica em estado baixo
      delay(100); //espera 100ms
      analogWrite(Esquerda, 127);//pino 'Esquerda' fica em estado alto
      delay(100); //espera 100ms
      analogWrite(Esquerda, 0);//pino 'Direita' fica em estado baixo
    }
     else if (c == 'R')
    {
      
      analogWrite(Esquerda, 0); //pino 'Esquerda' fica em estado baixo
      delay(100); //espera 100ms
      analogWrite(Direita,127);//pino 'Direita' fica em estado alto
    }
    else if (c == 'T')
    {
      analogWrite(Esquerda, 0);//pino 'Esquerda' fica em estado baixo
      delay(100); //espera 100ms
      analogWrite(Direita, 127);//pino 'Direita' fica em estado alto
      delay(100); //espera 100ms
      analogWrite(Direita, 0);//pino 'Direita' fica em estado baixo
    }
     else if (c == 'P')
    {
      aux = 0;
      analogWrite(Direita, 0);//pino 'Direita' fica em estado baixo
      analogWrite(Esquerda, 0);
      analogWrite(Re, 0);
      analogWrite(Frente, 0);
      Serial.println("Parado");
    }
      
      
    }
}
      
