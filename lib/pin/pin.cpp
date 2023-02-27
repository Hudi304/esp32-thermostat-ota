#include "pin.h"

Pin::Pin(uint8_t pinNumber, uint8_t mode)
{
  _pinNumber = pinNumber;
  pinMode(_pinNumber, mode);
}

Pin::Pin(uint8_t pinNumber, uint8_t mode, bool negativeLogic)
{
  _pinNumber = pinNumber;
  hasNegativeLogic = negativeLogic;
  pinMode(_pinNumber, mode);
}

void Pin::setState(uint8_t state)
{
  if (hasNegativeLogic)
  {
    digitalWrite(_pinNumber, !state);
  }
  else
  {
    digitalWrite(_pinNumber, state);
  }
}

uint8_t Pin::getState() const
{
  return digitalRead(_pinNumber);
}