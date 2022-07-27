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

#define PIN_LED 2

/**
 * @brief 
 * 
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
}

/**
 * @brief código da aplicação
 * 
 */
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_LED, HIGH);
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  delay(1000);
}
