#include <Arduino.h>
#include "LiquidCrystal.h"
#include "Controller.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Controller controller{};

  while (!controller.isDone())
  {
    controller.update();
  }

  Serial.print("Nie dziala");
}