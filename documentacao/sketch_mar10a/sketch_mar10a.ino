int pinoSensor =0; //Saída do sensor na A0.
int valorLido =0; //variável auxiliar.
float temperatura =0; //variável que armazenará a temperatura lida
int linha =0; //variável que se refere as linhas do excel

void setup() {//função uma unica vez
  Serial.begin(9600); //inicia a comunição serial a 9600 bauds.
  Serial.println("CLEARDATA"); //reset comunicação serial
  Serial.println("LABEL,hora,temperatura,linha"); // nomeia a coluna
}

void loop() {//Função que será executada continuamente.
  valorLido= analogRead(pinoSensor); //Leitura analógica da porta A0
  temperatura = (valorLido * 0.00488);//5 volts/1023 = 0,0048 precisão do A/D
  temperatura = temperatura * 100; //converter milivolts para Celsius - cada 10mV = 1 grau C
  linha++;//incrementa linha para que a leitura pule linha
  Serial.println("DATA,TIME,"); //inicia a impressão dos dados, fica sempre iniciando
  Serial.println(temperatura);

  if(linha >100)// loop para limitar a qte de dados
  {
    linha=0;
    Serial.println("ROW,SET,2");//alimentação das linhas sempre com os dados iniciados
  }
  delay(1000); //tempo 5 seg para reaçizar outra leitura.
}