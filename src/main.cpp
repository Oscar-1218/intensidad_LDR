#include <Arduino.h>
bool parpadear, valor;
const byte ldr = A0;
byte leds[7] ={3,5,6,9,10,11,12};

void flag(){
  parpadear = !parpadear;
}

void setup() {
  for(byte i = 0; i < 8; i++ ){
    pinMode(leds[i],OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), flag, RISING);
  parpadear = false;  
}

void loop() {
  int valorLdr = analogRead(ldr);
  int valueByte = map(valorLdr,1022,713, 254,0);
  valueByte > 36  ? digitalWrite(leds[0],valueByte) : digitalWrite(leds[0],LOW) ;
  valueByte > 72  ? digitalWrite(leds[1],valueByte) : digitalWrite(leds[1],LOW);
  valueByte > 108 ? digitalWrite(leds[2],valueByte) : digitalWrite(leds[2],LOW);
  valueByte > 144 ? digitalWrite(leds[3],valueByte) : digitalWrite(leds[3],LOW);
  valueByte > 180 ? digitalWrite(leds[4],valueByte) : digitalWrite(leds[4],LOW);
  valueByte > 216 ? digitalWrite(leds[5],valueByte) : digitalWrite(leds[5],LOW);
  valueByte > 235 ? digitalWrite(leds[6],HIGH) : digitalWrite(leds[6],LOW); //Este puerto no tiene pwm, por eso lo manejamos con valores logicos.

  while(parpadear){
       valor = !valor;
       delay(300);
          for(byte i = 0; i < 8; i++){
            digitalWrite(leds[i],valor);
          }
  }
}