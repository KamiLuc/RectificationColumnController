#ifndef SKIPSLOTSENSORTIMEEDITOR_H
#define SKIPSLOTSENSORTIMEEDITOR_H

#include "ContollerSettingEditor.h"

class SkipSlotSensorTimeEditor : public ControllerSettingEditor<int32_t>
{
private:
    void printUpdatedValue() override;
public:
    SkipSlotSensorTimeEditor(Peripherials *Peripherials, Settings *settings, SettingParams<int32_t> settingParams);
    void editSetting();
    void onEnter() override;
    ~SkipSlotSensorTimeEditor() = default;
};

#endif