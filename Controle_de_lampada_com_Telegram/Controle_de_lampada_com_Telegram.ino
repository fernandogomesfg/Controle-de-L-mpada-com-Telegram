#include <ESP8266WiFi.h>  //Bliblioteca para todos projectos usando ESP
#include <FastBot.h>


//Instancia - criando um objecto
FastBot bot;

//Para as credencias da rede WIFI
const char* nomeWifi = "Fernando WiFi";
const char* senha = "fernando1610";


//funcao responsavel pela conexao do ESP
//se ele falha na  conexao, ele renecia a conexao
void conectarWife() {
  WiFi.begin(nomeWifi, senha);

  //se fosse para o ESP-WEONS
  Serial.begin(15200);

  //enquanto a resposta for diferente WL_CONNECTED ele para 1 segundo e depois tenta novamente a conexao
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(nomeWifi, senha);
    Serial.print(".");
    delay(1000);

    //tentar a conexao durante 15 segundos, apos isso, ele renicia o ESP
    if (millis() > 15 000) 
      ESP.restart();
    
    Serial.print("Conectado com sucesso");
  }
}

//Definindo as saidas
#define lampada 0

//Variavel para o token do bot
#define botToken  "2034905971:AAHhbmh51xbAtv7Tf0apQg4y5ITyDALwDDw"


void setup() {
  //Chamando a a funcao de conexao do ESP
  conectarWife();

  //Chamando a lampada
  pinMode(lampada, OUTPUT);

  //chamando o botToken
  bot.setToken(botToken);
  bot.attach(new Msg);

}

void loop() {
  // put your main code here, to run repeatedly:

}
