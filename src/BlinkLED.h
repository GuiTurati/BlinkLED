#ifndef BlinkLED_h
#define BlinkLED_h

#include "Arduino.h"

class BlinkLED {
  public:
    BlinkLED(byte pinLED, int tempoPisca = 1000);
    void play(); 
    void stop();
    void loop();
	bool estado();
  private:
    unsigned long delayPisca;
    bool estadoPisca;
    byte pino;
    int  tempo;
};

#endif