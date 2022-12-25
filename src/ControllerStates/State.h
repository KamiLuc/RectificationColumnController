#ifndef STATE_H
#define STATE_H

#include "Utils/Settings.h"
#include "Utils/Peripherials.h"

class State
{
protected:
    State *nextState;
    Settings* settings;
    Peripherials* peripherials;

public:
    virtual void update() = 0;
    virtual void onEnter() = 0;
    State *getNextState() { return this->nextState; }
    State(Peripherials* peripherials, Settings* settings);
    bool isDone();
    virtual ~State() = default;
};

#endif