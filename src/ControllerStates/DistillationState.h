#ifndef __DISTILLATIONSTATE_H__
#define __DISTILLATIONSTATE_H__

#include "State.h"

class DisttilationState : public State
{
private:
    unsigned long long temperatureReadInterval;
    unsigned long long lastTemperatureReadTime;
public:
    DisttilationState(Peripherials* peripherials, Settings* settings);
    bool isDone() override;
    virtual void update() override;
    void onEnter() override;
    bool canReadTemperature();
    ~DisttilationState() = default;
};

#endif 