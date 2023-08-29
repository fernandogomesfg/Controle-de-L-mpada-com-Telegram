# Controle de Lâmpada com Telegram usando ESP8266

Este é um projeto de exemplo que demonstra como controlar uma lâmpada usando o módulo ESP8266 e a plataforma de mensagens Telegram. O ESP8266 se conecta à sua rede Wi-Fi local e recebe comandos de ligar/desligar a lâmpada via Telegram.

## Funcionalidades

- Liga/desliga a lâmpada remotamente usando comandos do Telegram.
- Utiliza a biblioteca ESP8266WiFi.h para conexão Wi-Fi.
- Utiliza a biblioteca FastBot.h para interação com a API do Telegram.

## Requisitos do Hardware

- Módulo ESP8266
- Lâmpada controlada (pode ser uma lâmpada real, LED ou outro dispositivo simulado)
- Smartphone com Telegram para envio de comandos

## Configuração

1. Clone este repositório para o seu computador.
2. Abra o arquivo `config.h` e insira suas credenciais Wi-Fi e as chaves da API do Telegram.
3. Faça as conexões necessárias entre o ESP8266 e a lâmpada conforme esquema fornecido.
4. Compile o código e faça o upload para o ESP8266.

## Uso

1. Inicie o ESP8266.
2. Abra o chat do Telegram configurado com o bot.
3. Envie os comandos `/ligar` ou `/desligar` para controlar a lâmpada.

## Exemplo de Comandos

- `/ligar` - Liga a lâmpada.
- `/desligar` - Desliga a lâmpada.
- `/status` - Verifica o status atual da lâmpada.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests.

## Agradecimentos

- Este projeto foi inspirado no artigo XYZ (link do artigo).
