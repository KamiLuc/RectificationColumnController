#ifndef __SETTINGPARAMS_H__
#define __SETTINGPARAMS_H__

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