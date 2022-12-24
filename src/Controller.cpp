#include "Controller.h"
#include "ControllerStates/WorkModeChooseState.h"

Controller::Controller() :
    peripherials(Button(0), Button(1), Button(2), Button(3), LiquidCrystal(A0, A1, A2, A3, A4, A5))
{
    peripherials.lcd.setCursor(0,0);
    peripherials.lcd.begin(16,2);
    peripherials.lcd.print("Test");
    this->currentState = new WorkModeChooseState(&peripherials, &settings);
}

bool Controller::isDone() const
{
    return false;
}

void Controller::update()
{
    this->currentState->update();
    if (this->currentState->isDone())
    {
        auto tempPtr = this->currentState->getNextState();
        delete this->currentState;
        this->currentState = tempPtr;
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
