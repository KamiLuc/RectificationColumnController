#include "MaxTemperatureEditor.h"

MaxTemperatureEditor::MaxTemperatureEditor(Peripherials *Peripherials, Settings *settings, SettingParams<float> settingParams) :
 ControllerSettingEditor(Peripherials, settings, settingParams)
{
}

void MaxTemperatureEditor::editSetting()
{
    if (this->peripherials->menuButton.scanForFallingEdge())
    {
        this->swapStep();
    }
    else if (this->peripherials->upButton.scanForFallingEdge())
    {
        
        if (this->settings->maxTemperature + this->settingParams.currentStep <= this->settingParams.maxValue)
        {
            this->settings->maxTemperature += this->settingParams.currentStep;
            this->printUpdatedValue();
        }
    }
    else if (this->peripherials->downButton.scanForFallingEdge())
    {
        auto temp = this->settings->maxTemperature - this->settingParams.currentStep;
        if(temp >= this->settingParams.minValue && temp > 0)
        {
            this->settings->maxTemperature -= this->settingParams.currentStep;
            this->printUpdatedValue();
        }
    }
    else if(this->peripherials->okButton.scanForFallingEdge())
    {
        this->done = true;
    }
}

void MaxTemperatureEditor::printUpdatedValue()
{
    this->peripherials->lcd.setCursor(0,1);
    this->peripherials->lcd.print(this->settings->maxTemperature);
    this->peripherials->lcd.print(" C ");
}

void MaxTemperatureEditor::onEnter()
{
    this->peripherials->lcd.clear();
    this->peripherials->lcd.setCursor(0,0);
    this->peripherials->lcd.print("Max temperature:");
    this->printUpdatedValue();
}
