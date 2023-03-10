#ifndef SETTINGSCHANGESTATE_H
#define SETTINGSCHANGESTATE_H

#include "SettingsEdit/MaxTemperatureEditor.h"
#include "SettingsEdit/StabilizationTimeEditor.h"
#include "SettingsEdit/SkipSlotSensorTimeEditor.h"
#include "ControllerStates/State.h"

class SettingsChangeState : public State
{
private:
    MaxTemperatureEditor maxTemperatureEditor;
    StabilizationTimeEditor stabilizationTimeEditor;
    SkipSlotSensorTimeEditor skipSlotSensorTimeEditor;
    QueueableEditor* currentEditor;
    void setSettingsQueue();
public:
    SettingsChangeState(Peripherials* peripherials, Settings* settings);
    void update() override;
    void onEnter() override;
    ~SettingsChangeState();
};

#endif