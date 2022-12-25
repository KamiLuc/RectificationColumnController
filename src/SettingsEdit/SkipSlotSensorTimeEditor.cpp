#include "SkipSlotSensorTimeEditor.h"

void SkipSlotSensorTimeEditor::printUpdatedValue()
{
    this->peripherials->lcd.setCursor(6,1);
    auto timeInMinutes = (int32_t)(this->settings->skipSlotSensorTime / 1000);
    this->peripherials->lcd.print(timeInMinutes);
    this->peripherials->lcd.print(" Sec ");
}

SkipSlotSensorTimeEditor::SkipSlotSensorTimeEditor(Peripherials *Peripherials, Settings *settings, SettingParams<int32_t> settingParams) :
 ControllerSettingEditor(Peripherials, settings, settingParams)
{
}

void SkipSlotSensorTimeEditor::editSetting()
{
    if (this->peripherials->menuButton.scanForFallingEdge())
    {
        this->swapStep();
    }
    else if (this->peripherials->upButton.scanForFallingEdge())
    {
        if (this->settings->skipSlotSensorTime + this->settingParams.currentStep <= this->settingParams.maxValue)
        {
            this->settings->skipSlotSensorTime += this->settingParams.currentStep;
            this->printUpdatedValue();
        }
    }
    else if (this->peripherials->downButton.scanForFallingEdge())
    {
        this->settings->skipSlotSensorTime -= this->settingParams.currentStep;
        if (this->settings->skipSlotSensorTime < this->settingParams.minValue)
        {
            this->settings->skipSlotSensorTime = this->settingParams.minValue;
        }
        this->printUpdatedValue();
    }
    else if(this->peripherials->okButton.scanForFallingEdge())
    {
        this->done = true;
    }
    //Serial.println(this->settings->skipSlotSensorTime - this->settingParams.currentStep);
}

void SkipSlotSensorTimeEditor::onEnter()
{
    this->peripherials->lcd.clear();
    this->peripherials->lcd.setCursor(0,0);
    this->peripherials->lcd.print("Slot sensor skip");
    this->peripherials->lcd.setCursor(0,1);
    this->peripherials->lcd.print("time:");
    this->printUpdatedValue();
}
