#include "DistillationState.h"
#include "SettingsChangeState.h"

DisttilationState::DisttilationState(Peripherials *peripherials, Settings *settings) :
 State(peripherials, settings), temperatureReadInterval(1000), lastTemperatureReadTime(0)
{
}

void DisttilationState::onEnter()
{
    this->peripherials->lcd.clear();
    this->peripherials->lcd.setCursor(0,0);
    this->peripherials->lcd.print("Distillation");
    this->peripherials->valveRelay.setLow();
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
