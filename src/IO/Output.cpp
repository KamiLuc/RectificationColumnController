#include "Output.h"

Output::Output(uint8_t pin) : pin(pin)
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    this->currentState = LOW;
}

void Output::setHigh()
{
    digitalWrite(this->pin, HIGH);
    this->currentState = HIGH;
}

void Output::setLow()
{
    digitalWrite(this->pin, LOW);
    this->currentState = LOW;
}
