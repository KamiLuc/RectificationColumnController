#ifndef __DISTILLATIONSTATE_H__
#define __DISTILLATIONSTATE_H__

#include "State.h"
#include "Utils/ExecutionTimeGuard.h"

class DisttilationState : public State
{
private:
    unsigned long long temperatureReadInterval;
    unsigned long long lastTemperatureReadTime;
    ExecutionTimeGuard skipSlotSensorTimeGuard;
public:
    DisttilationState(Peripherials* peripherials, Settings* settings, unsigned long long slotSensorSkipTime);
    virtual void update() override;
    void onEnter() override;
    bool canReadTemperature();
    ~DisttilationState();
};

#endif 