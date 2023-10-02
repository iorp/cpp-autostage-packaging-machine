#ifndef H_A4988
#define H_A4988

#include <Arduino.h>
#define LEFT 0
#define RIGHT 1
class A4988{
  public:
  A4988(uint8_t stepPin,uint8_t directionPin,float resolution,uint16_t rpm);
  void move();
 
  void setSpeed(uint16_t rpm);
  void setDirection(uint8_t direction);
  
  private:
  uint8_t stepPin; // Step pin
  uint8_t directionPin; // Dir pin 
  float stepResolution=1.8; // Step resolution
  uint32_t stepDelay=2000; // Step delay in microseconds
 
};

#endif
