#include <Arduino.h>
#include "LiquidCrystal.h"
#include "Button.h"
#include "Controller.h"

void setup()
{
  pinMode(13, OUTPUT);
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