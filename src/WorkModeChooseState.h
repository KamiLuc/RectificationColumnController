#ifndef WORKMODECHOOSESTATE_H
#define WORKMODECHOOSESTATE_H

#include "State.h"
#include "Peripherials.h"
#include "WorkModeChooseState.h"
#include "Utils.h"

class WorkModeChooseState : public State
{
private:
    uint8_t currentIndex;
    String possibleOptions[3];
    void moveIndexUp();
    void moveIndexDown();
    void chooseCurrentOption();
    void displayNewOption();
public:
    WorkModeChooseState(Peripherials* peripherials, Settings* settings);
    bool isDone();
    void update();
};

#endif