#ifndef MAXTEMPERATUREEDITOR_H
#define MAXTEMPERATUREEDITOR_H

#include "ContollerSettingEditor.h"

class MaxTemperatureEditor : public ControllerSettingEditor<float>
{
private:
    void printUpdatedValue() override;
public:
    MaxTemperatureEditor(Peripherials *Peripherials, Settings *settings, SettingParams<float> settingParams);
    void editSetting();
    void onEnter() override;
    ~MaxTemperatureEditor() = default;
};

#endif