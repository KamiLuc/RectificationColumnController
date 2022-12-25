#include "State.h"

State::State(Peripherials* peripherials, Settings* settings): nextState(nullptr), peripherials(peripherials), settings(settings)
{
}

bool State::isDone()
{
    return (this->nextState != nullptr);
}
