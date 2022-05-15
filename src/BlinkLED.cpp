#include "BlinkLED.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

BlinkLED::BlinkLED(byte pinLED, int tempoPisca) {
  pinMode(pinLED, OUTPUT);
  pino = pinLED;
  tempo = tempoPisca;
  estadoPisca = false;
}

void BlinkLED::play() {
  estadoPisca = true;
  delayPisca = millis();
}

void BlinkLED::stop() {
  estadoPisca = false;
  digitalWrite(pino, LOW); 
}

void BlinkLED::loop() {

  if (estadoPisca) {

     if ((millis() - delayPisca) < tempo )  {
        digitalWrite(pino, LOW);   
     } else if ((millis() - delayPisca) < (tempo * 2) ) {
        digitalWrite(pino, HIGH);
     } else {
        delayPisca = millis();
     }
     
  } else {
    digitalWrite(pino, LOW); 
  }
}

bool BlinkLED::estado(){
	return estadoPisca;
}