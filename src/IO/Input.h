#ifndef __INPUT_H__
#define __INPUT_H__

#include <Arduino.h>

class Input
{
private:
    const uint8_t pin;

public:
    Input(uint8_t pin);
    bool isHigh() const;
    bool isLow() const;
};

#endif 