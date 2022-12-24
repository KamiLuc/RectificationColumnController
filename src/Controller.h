#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ControllerStates/State.h"
#include "Utils/Peripherials.h"

class Controller {
private:
    Peripherials peripherials;
    Settings settings;
    State* currentState;
public:
    Controller();
    bool isDone() const;
    void update();
    ~Controller();
};

#endif