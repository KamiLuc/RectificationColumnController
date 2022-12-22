#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
private:
    byte pin;
    byte state;
    byte lastReading;
    void init();
public:
    bool scanForFallingEdge();
    byte getCurrentState();
    Button(const byte pin);
};

#endif