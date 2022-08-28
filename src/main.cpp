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

//Definindo o ssid da rede Wifi
const char *ssid = "JOAO";
const char *senha = "jo23va05";

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.print("Conectando a rede ");
  Serial.println(ssid);

  //Iniciando o wifi com os parametros de ssid e senha configurados
  WiFi.begin(ssid, senha);

  //Código de espera até o wifi conectar
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" ");
  Serial.println("Wifi conectado.");
  Serial.println("Endereço de Ip: ");
  Serial.println(WiFi.localIP());
  
}


void loop() {


}
