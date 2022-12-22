#include "StabilizationTimeEditor.h"

void StabilizationTimeEditor::printUpdatedValue()
{
    this->peripherials->lcd.setCursor(6,1);
    auto timeInMinutes = (int32_t)(this->settings->stabilziationTime / 60000);
    this->peripherials->lcd.print(timeInMinutes);
    this->peripherials->lcd.print(" Min ");
}

StabilizationTimeEditor::StabilizationTimeEditor(Peripherials *Peripherials, Settings *settings, SettingParams<uint32_t> settingParams):
 ControllerSettingEditor(Peripherials, settings, settingParams)
{
}

void StabilizationTimeEditor::editSetting()
{
    if (this->peripherials->menuButton.scanForFallingEdge())
    {
        this->swapStep();
    }
    else if (this->peripherials->upButton.scanForFallingEdge())
    {
        if (this->settings->stabilziationTime + this->settingParams.currentStep <= this->settingParams.maxValue)
        {
            this->settings->stabilziationTime += this->settingParams.currentStep;
            this->printUpdatedValue();
        }
    }
    else if (this->peripherials->downButton.scanForFallingEdge())
    {
        if(this->settings->stabilziationTime - this->settingParams.currentStep >= this->settingParams.minValue)
        {
            this->settings->stabilziationTime -= this->settingParams.currentStep;
            this->printUpdatedValue();
        }
    }
    else if(this->peripherials->okButton.scanForFallingEdge())
    {
        this->done = true;
    }
}

void StabilizationTimeEditor::onEnter()
{
    this->peripherials->lcd.clear();
    this->peripherials->lcd.setCursor(0,0);
    this->peripherials->lcd.print("Stabilization");
    this->peripherials->lcd.setCursor(0,1);
    this->peripherials->lcd.print("time:");
    this->printUpdatedValue();
}
