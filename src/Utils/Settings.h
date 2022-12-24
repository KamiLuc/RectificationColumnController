#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include "WorkMode.h"
#include "Arduino.h"

struct Settings
{
    WorkMode workMode = FULL_EQUIPMENT;
    float maxTemperature = 79.0f;
    uint32_t stabilziationTime = (600000); //10 min
    uint32_t skipSlotSensorTime = (300000); //5min
};

#endif 