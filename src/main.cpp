/**
 * @file main.cpp
 * @author Eng. João Pellacani (eng.joaopellacani@gmail.com)
 * @brief Conectando esp8266 no Wifi
 * @version 1.0
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
//Biblioteca do Wifi para o esp8266
#include <ESP8266WiFi.h>

char* const ssid = "JOAO";
char* const pass = "jo23va05";

WiFiServer server(80);

void setup(){
 Serial.begin(115200);
 delay(10);

 Serial.println("");
 Serial.println("");
 Serial.print("Conectando a ");
 Serial.print(ssid);

 WiFi.begin(ssid, pass);

 while (WiFi.status() != WL_CONNECTED)
 {
  delay(500);
  Serial.print(".");
 }

 Serial.println("");
 Serial.print("Conectado a rede sem fio ");
 Serial.println(ssid);
 server.begin();
 Serial.println("Servidor inicializado");

 Serial.print("IP para se conectar ao ESP8266: ");
 Serial.print("http://");
 Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Novo cliente se conectou!");
  while (!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r'); //FAZ A LEITURA DA PRIMEIRA LINHA DA REQUISIÇÃO
  Serial.println(request); //ESCREVE A REQUISIÇÃO NA SERIAL
  client.flush(); //AGUARDA ATÉ QUE TODOS OS DADOS DE SAÍDA SEJAM ENVIADOS AO CLIENTE

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");  //INFORMA AO NAVEGADOR A ESPECIFICAÇÃO DO HTML
  client.println("<html>"); //ABRE A TAG "html"
  client.println("<h1><center>Ola cliente!</center></h1>"); //ESCREVE "Ola cliente!" NA PÁGINA
  client.println("<center><font size='5'>Seja bem vindo!</center>"); //ESCREVE "Seja bem vindo!" NA PÁGINA
  client.println("</html>"); //FECHA A TAG "html"
  delay(1);
  Serial.println("Cliente desconectado.");
  Serial.println("");
}
