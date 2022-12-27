#include "ExecutionTimeGuard.h"

ExecutionTimeGuard::ExecutionTimeGuard(unsigned long long executionDelayTime) : executionDelayTime(executionDelayTime)
{
    this->guardCreationTime = millis();
}

unsigned long long ExecutionTimeGuard::getTimeLeft() const
{
    auto temp = millis();
    return executionDelayTime - (temp - this->guardCreationTime);
}

double ExecutionTimeGuard::getTimeLeftAsPercentage() const
{
    auto temp = millis();
    return ((double)temp - (double)this->guardCreationTime)/ (double)this->executionDelayTime * 100;
}

bool ExecutionTimeGuard::canExecute() const
{
    unsigned long long currentTime = millis();
    return (currentTime - this->guardCreationTime >= this->executionDelayTime);
}