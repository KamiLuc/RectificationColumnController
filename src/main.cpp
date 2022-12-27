#include <Arduino.h>
#include "LiquidCrystal.h"
#include "Controller.h"

void setup()
{
  //Serial.begin(9600);
}

void loop()
{
  
  Controller controller{};

  while (!controller.isDone())
  {
    controller.update();
  }

  Serial.print("NIE DZIERZY");
  
}

/*
#include <OneWire.h>
#include <DS18B20.h>

#define ONE_WIRE_BUS  10

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

uint32_t start, stop;
uint8_t res = 12;


void setup()
{
  Serial.begin(9600);

  // wait until address found
  if (sensor.begin() == false)
  {
    Serial.println("ERROR: No device found");
    while (!sensor.begin()); // wait until device comes available.
  }

  sensor.setResolution(12);
  sensor.setConfig(DS18B20_CRC);  // or 1
  sensor.requestTemperatures();
}


void loop()
{
  sensor.requestTemperatures();

  float t = sensor.getTempC();

  Serial.print(res);
  Serial.print("\t");
  Serial.print("\t");
  Serial.println( t, 1); // 1 decimal makes perfect sense
}*/