#ifndef __INPUT_H__
#define __INPUT_H__

#include <Arduino.h>

class Input
{
private:
    const uint_8t pin;

public:
    Input(uint_8t pin);
    bool isHigh() const;
    bool isLow() const;
};

#endif 