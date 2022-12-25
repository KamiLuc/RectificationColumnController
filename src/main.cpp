#include <Arduino.h>
#include "LiquidCrystal.h"
#include "Controller.h"

void setup()
{
  pinMode(13, OUTPUT);
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