#ifndef SETTINGSCHANGESTATE_H
#define SETTINGSCHANGESTATE_H

#include "SettingsEdit/MaxTemperatureEditor.h"
#include "SettingsEdit/StabilizationTimeEditor.h"
#include "SettingsEdit/SkipSlotSensorTimeEditor.h"
#include "State.h"

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
    bool isDone();
    void update();
    virtual ~SettingsChangeState() = default;
};

#endif