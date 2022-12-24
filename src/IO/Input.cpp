#include "Input.h"

Input::Input(uint_8t pin) : pin(pin)
{
    pinMode(pin, INPUT);
}

bool Input::isHigh() const
{
    return digitalRead(pin) == HIGH;
}

bool Input::isLow() const
{
    return digitalRead(pin) == LOW;
}
