#include "WorkModeChooseState.h"
#include "SettingsChangeState.h"

WorkModeChooseState::WorkModeChooseState(Peripherials* peripherials, Settings* settings) : 
    State(peripherials, settings),  currentIndex(0), possibleOptions({"Temp + Slot", "Temperature only", "Slot only"})
{
    this->peripherials->lcd.clear();
    this->peripherials->lcd.setCursor(0,0);
    this->peripherials->lcd.print("Work mode:");
    this->displayNewOption();
}

bool WorkModeChooseState::isDone()
{
    return (this->nextState != nullptr);
}

void WorkModeChooseState::update()
{
    if (this->peripherials->downButton.scanForFallingEdge())
    {
        this->moveIndexUp();
        this->displayNewOption();
    }
    else if (this->peripherials->upButton.scanForFallingEdge())
    {
        this->moveIndexDown();
        this->displayNewOption();
    }
    else if(this->peripherials->okButton.scanForFallingEdge())
    {
        this->chooseCurrentOption();
    }
}

void WorkModeChooseState::onEnter()
{
    this->peripherials->lcd.clear();
}

void WorkModeChooseState::moveIndexUp()
{
    if (this->currentIndex == 2)
    {
        this->currentIndex = 0;
    }
    else
    {
        this->currentIndex++;
    }
}

void WorkModeChooseState::moveIndexDown()
{
    if (this->currentIndex == 0)
    {
        this->currentIndex = 2;
    }
    else
    {
        this->currentIndex--;
    }
}

void WorkModeChooseState::chooseCurrentOption()
{
    if(this->currentIndex == 0)
    {
        this->settings->workMode = WorkMode::FULL_EQUIPMENT;
    }
    else if(this->currentIndex == 1)
    {
        this->settings->workMode = WorkMode::TEMPERATURE_SENSOR_ONLY;
    }
    else
    {
        this->settings->workMode = WorkMode::SLOT_SENSOR_ONLY;
    }

    this->nextState = new SettingsChangeState(this->peripherials, this->settings);
}

void WorkModeChooseState::displayNewOption()
{
    
    this->peripherials->lcd.setCursor(0,1);
    this->peripherials->lcd.print(this->possibleOptions[this->currentIndex]);
    for (uint8_t i = 0; i < this->possibleOptions[this->currentIndex].length(); i++)
    {
        this->peripherials->lcd.print(" ");
    }
}
