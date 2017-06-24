float pinoPotenciometro = 1;    //  variavel que define a porta do potenciometro.
int LABEL = 1;  
int valor = 0;   // variavel que guarda o valor lido do potenciometro
int amostra = 0;
int T_amostragem = 2000; // período de amostragem = 1 segundo
void setup(){
Serial.begin(9600);                     //  inicialização da comunicação serial
Serial.println("CLEARDATA");            // Reset da comunicação serial
Serial.println("LABEL,Hora,Leitura,Data, , ,Amostra,Leitura");   // Nomeia as colunas
}
 
void loop(){
 if (Serial.available()){ 
  valor = analogRead(pinoPotenciometro);   // faz a leitura do potenciometro e guarda o valor em val.
  amostra++; // incrementa a linha do excel para que a leitura pule de linha em linha
  // Coluna 1
  Serial.print("DATA,TIME,"); //inicia a impressão de dados, sempre iniciando
  // Coluna 2
  Serial.print(valor);
  Serial.print(",");
  // Coluna 3
  Serial.print("DATE");
  Serial.print(",");
  // Coluna 4
  Serial.print(",");
  // Coluna 5
  Serial.print(",");
  // Coluna 6
  Serial.print(amostra);
  Serial.print(",");
  // Coluna 7
  Serial.print(valor);
  Serial.println(",");
  
//  if (amostra > 10000) //laço para limitar a quantidade de dados
//    {  
//    amostra = 0;
//    Serial.println("ROW,SET,2"); // alimentação das linhas com os dados sempre iniciando
//    }
  delay(T_amostragem);  // espera 200 milisegundos
 
 }
}
