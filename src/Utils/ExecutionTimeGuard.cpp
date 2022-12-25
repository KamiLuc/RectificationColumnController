#include "ExecutionTimeGuard.h"

ExecutionTimeGuard::ExecutionTimeGuard(unsigned long long executionDelayTime) : executionDelayTime(executionDelayTime)
{
    this->guardCreationTime = millis();
}

bool ExecutionTimeGuard::canExecute()
{
    unsigned long long currentTime = millis();
    return (currentTime - guardCreationTime >= this->executionDelayTime);
}
