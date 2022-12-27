#ifndef PERIPHERIALS_H
#define PERIPHERIALS_H

#include "LiquidCrystal.h"
#include "IO/Input.h"
#include "IO/Output.h"
#include "Button.h"
#include <OneWire.h>
#include <DS18B20.h>

struct Peripherials {
    Button upButton;
    Button downButton;
    Button menuButton;
    Button okButton;
    LiquidCrystal lcd;
    Input slotSensor;
    Output valveRelay;
    OneWire oneWire;
    DS18B20 ds18b20;
    Peripherials(Button&& upButton, Button&& downButton, Button&& menuButton, Button&& okButton, LiquidCrystal&& lcd,
    Input&& slotSensor, Output&& valveRelay, uint8_t&& oneWireBus) :
        upButton(upButton), downButton(downButton), menuButton(menuButton), okButton(okButton), lcd(lcd),
        slotSensor(slotSensor), valveRelay(valveRelay), oneWire(oneWireBus), ds18b20(&oneWire)
    {
    }
};

#endif