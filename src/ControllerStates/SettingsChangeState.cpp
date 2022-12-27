#include "SettingsChangeState.h"
#include "DistillationState.h"
#include "StabilizationState.h"

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
    stabilizationTimeEditor(peripherials, settings, SettingParams<int32_t>{1200, 7200000, 60000, 600000}), //120000
    skipSlotSensorTimeEditor(peripherials, settings, SettingParams<int32_t>{10000, 300000, 5000, 30000})
{    
    this->setSettingsQueue();
    Serial.println("SettingsChangeState Created");
}

void SettingsChangeState::update()
{
    if (this->currentEditor->isDone())
    {
        this->currentEditor = this->currentEditor->getNextEditor();
        if (this->currentEditor == nullptr)
        {
            this->nextState = new DisttilationState(this->peripherials, this->settings, 0);
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
    this->currentEditor->onEnter();
    this->peripherials->valveRelay.setHigh();
    Serial.println("SettingsChangeState Entered");
}

SettingsChangeState::~SettingsChangeState()
{
    Serial.println("SettingsChangeState Destroyed");
}

void DisttilationState::update()
{
    if (this->settings->workMode == WorkMode::FULL_EQUIPMENT || this->settings->workMode == WorkMode::TEMPERATURE_SENSOR_ONLY)
    {
        if (canReadTemperature())
        {
            auto temp = 0;
            if (temp < this->settings->maxTemperature)
            {
            //do stabilizacji
            } 
    }
    }

    if (this->settings->workMode == WorkMode::FULL_EQUIPMENT || this->settings->workMode == WorkMode::SLOT_SENSOR_ONLY)
    {
        if (this->peripherials->slotSensor.isHigh() && this->skipSlotSensorTimeGuard.canExecute())
        {
            this->nextState = new StabilizationState(this->peripherials, this->settings);
        }
    }

    if (this->peripherials->menuButton.scanForFallingEdge())
    {
        this->nextState = new SettingsChangeState(this->peripherials, this->settings);
    }
}

void StabilizationState::update()
{
    if (this->peripherials->menuButton.scanForFallingEdge())
    {
        this->nextState = new SettingsChangeState(this->peripherials, this->settings);
    }
    else if (this->endOfStabilizationTimeGuard.canExecute())
    {
        this->nextState = new DisttilationState(this->peripherials, this->settings, this->settings->skipSlotSensorTime);
    }

    this->printStabilizationProgress();
}

