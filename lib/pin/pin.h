#ifndef __CUSTOM_PIN__
#define __CUSTOM_PIN__

#include <Arduino.h>

/*
 wrapper for default arduino pins, in order to change the negative logic more easily
 */
class Pin
{
public:
  boolean hasNegativeLogic;

  Pin(uint8_t pinNumber, uint8_t mode);
  Pin(uint8_t pinNumber, uint8_t mode, bool negativeLogic);

  void setState(uint8_t state);
  uint8_t getState() const;

  void setNegativeLogic(bool negativeLogic);

  bool getNegativeLogic();

private:
  uint8_t _pinNumber;
};

#endif
