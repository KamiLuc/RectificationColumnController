#include "State.h"

State::State(Peripherials* peripherials, Settings* settings): done(false), nextState(nullptr), peripherials(peripherials), settings(settings)
{
}