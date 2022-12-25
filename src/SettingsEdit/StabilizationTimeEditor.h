#ifndef STABILIZATIONTIMEDITOR_H
#define STABILIZATIONTIMEDITOR_H

#include "ContollerSettingEditor.h"

class StabilizationTimeEditor : public ControllerSettingEditor<int32_t>
{
private:
    void printUpdatedValue() override;
public:
    StabilizationTimeEditor(Peripherials *Peripherials, Settings *settings, SettingParams<int32_t> settingParams);
    void editSetting();
    void onEnter() override;
    ~StabilizationTimeEditor() = default;
};

#endif