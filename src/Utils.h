#ifndef UTILS_H
#define UTILS_H

enum WorkMode
{
    TEMPERATURE_SENSOR_ONLY,
    SLOT_SENSOR_ONLY,
    FULL_EQUIPMENT
};

struct Settings
{
    WorkMode workMode = FULL_EQUIPMENT;
    float maxTemperature = 79.0f;
    uint32_t stabilziationTime = (600000); //10 min
    uint32_t skipSlotSensorTime = (300000); //5min
};

template<typename T>
struct SettingParams
{
    T minValue;
    T maxValue;
    T smallStep;
    T bigStep;
    T currentStep;
    SettingParams(T minValue, T maxValue, T smallStep, T bigStep);
};

template <typename T>
inline SettingParams<T>::SettingParams(T minValue, T maxValue, T smallStep, T bigStep)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->smallStep = smallStep;
    this->bigStep = bigStep;
    this->currentStep = smallStep;
}

#endif

