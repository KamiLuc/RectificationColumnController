#include "Controller.h"
#include "ControllerStates/WorkModeChooseState.h"
#include "IO/Input.h"
#include "IO/Output.h"

//9 slot sensor
//11 relay

Controller::Controller() :
    peripherials(Button(0), Button(1), Button(2), Button(3), LiquidCrystal(A0, A1, A2, A3, A4, A5), Input(9), Output(11))
{
    peripherials.lcd.setCursor(0,0);
    peripherials.lcd.begin(16,2);
    peripherials.valveRelay.setLow();
    this->currentState = new WorkModeChooseState(&peripherials, &settings);
    this->currentState->onEnter();
}

bool Controller::isDone() const
{
    return false;
}

void Controller::update()
{
    if (this->currentState->isDone())
    {
        auto tempPtr = this->currentState->getNextState();
        delay(100);
        delete this->currentState;
        this->currentState = tempPtr; 
        this->currentState->onEnter();
    }
    else
    {
        this->currentState->update();
    }
}

Controller::~Controller()
{
    delete this->currentState;
}
