#include "ExecutionTimeGuard.h"

ExecutionTimeGuard::ExecutionTimeGuard(unsigned long long executionDelayTime) : executionDelayTime(executionDelayTime)
{
    this->guardCreationTime = millis();
}

bool ExecutionTimeGuard::canExecute() const
{
    unsigned long long currentTime = millis();
    return (currentTime - this->guardCreationTime >= this->executionDelayTime);
}