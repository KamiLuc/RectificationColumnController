#include "Button.h"
Button::Button(const byte pin)
{
    this->pin = pin;
    this->lastReading = LOW;
    this->init();
}

void Button::init()
{
  pinMode(pin, INPUT_PULLUP); //zmienic
}

byte Button::getCurrentState()
{
  return digitalRead(this->pin);
}

bool Button::scanForFallingEdge()
{
    bool result;
    auto newReading = digitalRead(this->pin);

    if (lastReading == HIGH && newReading == LOW)
    {
      result = true;
    }
    else
    {
      result = false;
    }

    this->lastReading = newReading;
    return result;
}
