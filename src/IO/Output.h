#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include <Arduino.h>

class Output
{
private:
    const uint8_t pin;
    uint8_t currentState;

public:
    Output(uint8_t pin);
    void setHigh();
    void setLow();
};

#endif 