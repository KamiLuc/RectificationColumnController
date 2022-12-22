#ifndef PERIPHERIALS_H
#define PERIPHERIALS_H

#include "LiquidCrystal.h"
#include "Button.h"

struct Peripherials {
    Button upButton;
    Button downButton;
    Button menuButton;
    Button okButton;
    LiquidCrystal lcd;
    Peripherials(Button&& upButton, Button&& downButton, Button&& menuButton, Button&& okButton, LiquidCrystal&& lcd) :
        upButton(upButton), downButton(downButton), menuButton(menuButton), okButton(okButton), lcd(lcd)
    {
    }
};

#endif