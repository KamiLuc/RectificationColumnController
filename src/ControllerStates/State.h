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
    bool done;

public:
    virtual void update() = 0;
    virtual bool isDone() = 0;
    State *getNextState() { return this->nextState; }
    State(Peripherials* peripherials, Settings* settings);
    virtual ~State() {};
};

#endif