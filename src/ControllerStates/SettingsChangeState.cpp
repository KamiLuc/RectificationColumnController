#include "SettingsChangeState.h"

void SettingsChangeState::setSettingsQueue()
{
    auto workMode = this->settings->workMode;
    this->currentEditor = &this->stabilizationTimeEditor;
    if(workMode == WorkMode::FULL_EQUIPMENT)
    {
        this->stabilizationTimeEditor.setNextEditor(&this->maxTemperatureEditor);
        this->maxTemperatureEditor.setNextEditor(&this->skipSlotSensorTimeEditor);
    }
    else if (workMode == WorkMode::SLOT_SENSOR_ONLY)
    {
        this->stabilizationTimeEditor.setNextEditor(&this->skipSlotSensorTimeEditor);
    }
    else if (workMode == WorkMode::TEMPERATURE_SENSOR_ONLY)
    {
        this->stabilizationTimeEditor.setNextEditor(&this->maxTemperatureEditor);
    }
    this->currentEditor->onEnter();
}

SettingsChangeState::SettingsChangeState(Peripherials *peripherials, Settings *settings) : State(peripherials, settings),
    maxTemperatureEditor(peripherials, settings, SettingParams<float>{50.0f, 90.0f, 0.1f, 1.0f}),
    stabilizationTimeEditor(peripherials, settings, SettingParams<int32_t>{120000, 7200000, 60000, 600000}),
    skipSlotSensorTimeEditor(peripherials, settings, SettingParams<int32_t>{10000, 300000, 5000, 30000})
{    
    this->setSettingsQueue();
}

bool SettingsChangeState::isDone()
{
    return this->done;
}

void SettingsChangeState::update()
{
    if (this->currentEditor->isDone())
    {
        this->currentEditor = this->currentEditor->getNextEditor();
        if (this->currentEditor == nullptr)
        {
            this->done = true;
            return;
        }
        else
        {
            this->currentEditor->onEnter();
        }
    }
    else
    {
        this->currentEditor->editSetting();
    }
}

void SettingsChangeState::onEnter()
{
    this->peripherials->lcd.clear();
}
