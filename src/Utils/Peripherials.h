#ifndef PERIPHERIALS_H
#define PERIPHERIALS_H

#include "LiquidCrystal.h"
#include "IO/Input.h"
#include "IO/Output.h"
#include "Button.h"

struct Peripherials {
    Button upButton;
    Button downButton;
    Button menuButton;
    Button okButton;
    LiquidCrystal lcd;
    Input slotSensor;
    Output valveRelay;
    Peripherials(Button&& upButton, Button&& downButton, Button&& menuButton, Button&& okButton, LiquidCrystal&& lcd,
    Input&& slotSensor, Output&& valveRelay ) :
        upButton(upButton), downButton(downButton), menuButton(menuButton), okButton(okButton), lcd(lcd),
        slotSensor(slotSensor), valveRelay(valveRelay)
    {
    }
};

#endif