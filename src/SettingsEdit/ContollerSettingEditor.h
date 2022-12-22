#ifndef CONTROLLERSETTINGEDITOR_H
#define CONTROLLERSETTINGEDITOR_H

#include "Peripherials.h"
#include "QueueableEditor.h"
#include "Utils.h"

template<typename T>
class ControllerSettingEditor : public QueueableEditor
{
protected:
    Peripherials* peripherials;
    Settings* settings;
    SettingParams<T> settingParams;
    virtual void printUpdatedValue() = 0;
    virtual void swapStep();
public:
    ControllerSettingEditor(Peripherials *Peripherials, Settings *settings,  SettingParams<T> settingParams);
    virtual void editSetting() = 0;
    virtual ~ControllerSettingEditor() = default;
};

template <typename T>
inline void ControllerSettingEditor<T>::swapStep()
{
    if (this->settingParams.currentStep == this->settingParams.bigStep)
    {
        this->settingParams.currentStep = this->settingParams.smallStep;
    }
    else
    {
        this->settingParams.currentStep = this->settingParams.bigStep;
    }
}

template <typename T>
inline ControllerSettingEditor<T>::ControllerSettingEditor(Peripherials *Peripherials, Settings *settings, SettingParams<T> settingParams):
peripherials(Peripherials), settings(settings), settingParams(settingParams)
{
}

#endif