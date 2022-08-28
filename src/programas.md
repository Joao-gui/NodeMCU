/**
 * @file main.cpp
 * @author Eng. João Pellacani (eng.joaopellacani@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>

// Definição do pino do led
#define PIN_LED D1
// Definição do pino button
#define Button D2
// Varialvel para leitura do push button
int estado = 0;
// Variavel que armazena o valor do push button
int guarda_estado = LOW;

// Pode ser usado tanto o #define quanto o cont byte para definit uma porta do ESP8266
// const byte LED = D1;

/**
 * @brief 
 * 
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  // Definindo PIN_LED sempre LOW, para sbre iniciar com ele desligado
  digitalWrite(PIN_LED, LOW);
  // Defini o button como pull up.
  pinMode(Button, INPUT_PULLUP);
}

/**
 * @brief código da aplicação
 * 
 */
void loop() {
  // put your main code here, to run repeatedly:
  // Le o estado do push button se esta Low ou High
  estado = digitalRead(Button);

  if (estado == HIGH)
  {
    estado = !estado;
    guarda_estado = !guarda_estado;
    delay(500);
    digitalWrite(PIN_LED, HIGH);
  }
  else
  {
    estado = !estado;
    guarda_estado = !guarda_estado;
    delay(500);
    digitalWrite(PIN_LED, LOW);
  }
  
}




/**
 * @file main.cpp
 * @author Eng. João Pellacani (eng.joaopellacani@gmail.com)
 * @brief Leitura de entrada analógica com sensor de luminosidade LDR 5 mm
 * @version 1.0
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>

#define LED D1

int valor, novo_valor;

void setup() {

  Serial.begin(9600);
  
}


void loop() {

  valor = analogRead(A0);
  novo_valor = map(valor, 0, 45, 0, 255);
  analogWrite(LED, novo_valor);
  Serial.println(analogRead(A0));;
  delay(500);

}
