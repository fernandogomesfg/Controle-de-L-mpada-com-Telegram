#include <ESP8266WiFi.h>  //Bliblioteca para todos projectos usando ESP
#include <FastBot.h>


//Instancia - criando um objecto
FastBot bot;

//Para as credencias da rede WIFI
const char* nomeWifi = "Fernando WiFi";
const char* senha = "fernando1610";


//funcao responsavel pela conexao do ESP
//se ele falha na  conexao, ele renecia a conexao
void conectarWifi() {
  WiFi.begin(nomeWifi, senha);

  //se fosse para o ESP-WEONS
  Serial.begin(15200);

  //enquanto a resposta for diferente WL_CONNECTED ele para 1 segundo e depois tenta novamente a conexao
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(nomeWifi, senha);
    Serial.print(".");
    delay(1000);

    //tentar a conexao durante 15 segundos, apos isso, ele renicia o ESP
    if (millis() > 15000) {
      ESP.restart();
    }
    Serial.print("Conectado com sucesso");
  }
}

//Definindo as saidas
#define lampada 0

//Variavel para o token do bot
#define botToken  "2034905971:AAHhbmh51xbAtv7Tf0apQg4y5ITyDALwDDw"

//Variavel para o id da mensagem
#define chatId "154782142"


void setup() {
  //Chamando a a funcao de conexao do ESP
  conectarWifi();

  //Chamando a lampada
  pinMode(lampada, OUTPUT);

  //chamando o botToken
  bot.setToken(botToken);
  bot.attach(newMsg);

}

void  newMsg (FB_msg & msg ) {
  if (msg.text.equals("liga")) {
    digitalWrite(lampada, LOW);
    bot.sendMessage ("Lampada Ligada", chatId );
  } else if (msg.text.equals("desligar")) {
    digitalWrite(lampada, HIGH);
    bot.sendMessage ("Lampada Desligada", chatId );
  }
}

void loop() {
  //Metodo para verificar novas mensagens
  bot.tick();

}
