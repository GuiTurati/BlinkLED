#include <BlinkLED.h>

//DEFINE O PINO DO LED
#define pinLed 13

//INSTANCIANDO OBJETO COM O NOME LED
BlinkLED led(pinLed);

char comando;
char comandoAnt;
bool troca = false;

void setup() {
  // INICIA A COMUNICAÇÃO SERIAL
  Serial.begin(9600);
  
  //DIZ O MODO DE OPERAÇÃO
  Serial.println("---------------------------------------");
  Serial.println("   Exemplo de uso da BlinkLED.h");
  Serial.println("  Digite 'P' maiusculo para Piscar");
  Serial.println(" Digite 'p' minusculo para Desligar");
  Serial.println("Digite 'E' maiusculo para ver o estado");
  Serial.println("---------------------------------------");

}

void loop() {
  led.loop();

  if(Serial.available()){     
    comando = Serial.read();
    if ( comandoAnt != comando) {      
      troca = true;
      comandoAnt = comando;
    }    
  }
  
  if (troca == true){
    if (comando == 'P') {
      led.play();
      troca = false ;
      Serial.println("Led Piscando");
    }  
    
    if ( comando == 'p') {
      led.stop();
      troca = false;
      Serial.println("Led Apagado");  
    }
	if ( comando == 'E') {
      troca = false;
	  if (led.estado()) {
		 Serial.println("Ligado");
	  } else {
		 Serial.println("Desligado");
	  }
    }
  }
}