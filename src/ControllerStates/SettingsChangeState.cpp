#include "SettingsChangeState.h"
#include "DistillationState.h"

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
    Serial.println("SettingsChangeState Created");
}

void SettingsChangeState::update()
{
    if (this->currentEditor->isDone())
    {
        this->currentEditor = this->currentEditor->getNextEditor();
        if (this->currentEditor == nullptr)
        {
            this->nextState = new DisttilationState(this->peripherials, this->settings, 10000);
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
    Serial.println("SettingsChangeState Entered");
}

SettingsChangeState::~SettingsChangeState()
{
    Serial.println("SettingsChangeState Destroyed");
}

void DisttilationState::update()
{
    if (canReadTemperature())
    {
        auto temp = 0;
        if (temp < this->settings->maxTemperature)
        {
            //do stabilizacji
        } 
    }

    if (this->peripherials->slotSensor.isHigh() && this->skipSlotSensorTimeGuard.canExecute())
    {
        this->peripherials->valveRelay.setHigh();
    }
    else 
    {
        this->peripherials->valveRelay.setLow();
    }

    if (this->peripherials->slotSensor.isHigh())
    {
        //stabilizacja
    }
    else if (this->peripherials->menuButton.scanForFallingEdge())
    {
        this->peripherials->valveRelay.setHigh();
        this->nextState = new SettingsChangeState(this->peripherials, this->settings);
    }
}
