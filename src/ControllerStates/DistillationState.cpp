#include "DistillationState.h"
#include "SettingsChangeState.h"

void DisttilationState::displayTemperature()
{
    this->peripherials->lcd.setCursor(10,1);
    this->peripherials->lcd.print(this->getTemperature());
    this->peripherials->lcd.print("C");
}

float DisttilationState::getTemperature()
{
    this->peripherials->ds18b20.requestTemperatures();
    float t = this->peripherials->ds18b20.getTempC();
    return t;
}

DisttilationState::DisttilationState(Peripherials *peripherials, Settings *settings, unsigned long long slotSensorSkipTime) : State(peripherials, settings),
 temperatureReadInterval(1000), lastTemperatureReadTime(0), skipSlotSensorTimeGuard(slotSensorSkipTime)
{
    Serial.println("DistillationState Created");
}

void DisttilationState::onEnter()
{
    this->peripherials->lcd.clear();
    this->peripherials->lcd.setCursor(0,0);
    this->peripherials->lcd.print("Distillation");
    this->peripherials->valveRelay.setLow();
    Serial.println("DistillationState Entered");
    
    if(this->settings->workMode == WorkMode::FULL_EQUIPMENT || this->settings->workMode == WorkMode::TEMPERATURE_SENSOR_ONLY)
    {
        this->peripherials->lcd.setCursor(0,1);
        this->peripherials->lcd.print("Tem-ture:");
    }
}

bool DisttilationState::canReadTemperature()
{
    auto newUpdateTime = millis();
    bool result = (newUpdateTime - lastTemperatureReadTime > temperatureReadInterval);
    if (result)
    {
        this->lastTemperatureReadTime = newUpdateTime;
    }
    return result;
}

DisttilationState::~DisttilationState()
{
    Serial.println("DistillationState Destroyed");
}
