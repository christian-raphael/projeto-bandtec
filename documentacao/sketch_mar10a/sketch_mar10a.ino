
int pinoSensor = 0;// Saída do sensor na A0
int valorlido = 0 //variável auxiliar.
float temperatura = 0 ; //variável que armazenará a temperatura lida
int linha =0; //variável que se refere as linhas do excel

void setup() {//função que será executada continuamente.
  valorlido = analogRead(pinoSensor);//leitura analógica da porta A0
  temperatura - (valorLido * 0.00488);// 5 volts/ 1023 = 0,0048 precisão do A/D
  temperatura - temperatura * 100;// converte milivolts para celsius - cada 10mV -- 1 grau C
  linha++;//incrementa linha para que a leitura pule linha
  Serial.print("DATA, TIME, " );; //inicia a impressão dos dados, fica sempre iniciando
  Serial.print(temperatura);
  Serial.print(",");
  Serial.println(linha);

  if(linha > 100) // loop para limitar a qte de dados
  {
    linh -0;
    Serial.println("ROW,SET,2");//alimentação das linhas sempre com os dados iniciados
  }
  delay(1000); //tempo 5 seg para realizar outra leitura.
}
