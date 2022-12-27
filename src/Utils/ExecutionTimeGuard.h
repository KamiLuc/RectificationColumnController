#ifndef __EXECUTIONTIMEGUARD_H__
#define __EXECUTIONTIMEGUARD_H__

#include "Arduino.h"

class ExecutionTimeGuard
{
private:
    unsigned long long executionDelayTime;
    unsigned long long guardCreationTime;
public:
    ExecutionTimeGuard(unsigned long long executionDelayTime);
    unsigned long long getTimeLeft() const;
    double getTimeLeftAsPercentage() const;
    bool canExecute() const;
};

#endif 