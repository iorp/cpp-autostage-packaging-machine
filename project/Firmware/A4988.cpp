#include "A4988.h"

A4988::A4988(uint8_t stepPin,uint8_t directionPin,float stepResolution,uint16_t rpm=0){ // step , dir
  this->stepPin = stepPin;
  this->directionPin = directionPin;
  this->stepResolution = stepResolution;
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
 if(rpm!=0) this->setSpeed(rpm);
  }

void A4988::setSpeed(uint16_t rpm){ 
 this->stepDelay = ( 1 / (rpm / ( (this->stepResolution/360) * 60)))*1000000 ;//( 1 / (RPM / ( (RESOLUTION/360) * 60)))*1000000 = Time in microseconds
}

void A4988::setDirection(uint8_t direction){
  digitalWrite(this->directionPin,direction); 
  }

void A4988::move(){ 
    digitalWrite(this->stepPin, !digitalRead(this->stepPin));
    delayMicroseconds(this->stepDelay); 
  }
 
    

  
