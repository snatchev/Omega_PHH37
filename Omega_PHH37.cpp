/*
 * Omega_PHH37
 * Library for communicating with the Omega PHH37
 * pH/mV Temperature meter over RS232
 *
 * Stefan Natchev - 2013
 */


#include "Arduino.h"
#include "Omega_PHH37.h"

Omega_PHH37::Omega_PHH37()
{
  memset(_input, '\0', 64);
  memset(_range_code, '\0', 3);
  memset(_value_1, '\0', 7);
  memset(_value_2, '\0', 7);
}

void Omega_PHH37::begin()
{
  Serial.begin(9600, SERIAL_8E2);
}

bool Omega_PHH37::read()
{
  memset(_input, '\0', 64);

  Serial.write("#001N\r\n");

  delay(1);

  if(Serial.available()) {
    Serial.readBytes(_input, 21);
  }

  strncpy(_range_code, _input+5, 2);
  strncpy(_value_1, _input+7, 6);
  strncpy(_value_2, _input+13, 6);

  return validInput();
}

float Omega_PHH37::mV()
{
  float value = 0.0;

  switch(rangeCode()) {
    case 0:
    case 4:
    case 8:
      value = atof(_value_1) / 10.0;
      break;
    case 1:
    case 5:
    case 9:
      value = atof(_value_1);
      break;
  }

  return value;
}

float Omega_PHH37::temp()
{
  return 0.0;
}

char Omega_PHH37::tempUnits()
{
  int rc = rangeCode();

  if(rc > 0 && rc <= 3)
    return 'C';

  if(rc > 3 && rc <= 11)
    return 'F';

  return '\0';
}

float Omega_PHH37::pH()
{
  float value = 0.0;

  switch(rangeCode()) {
    //pH_A
    case 2:
    case 6:
    case 11:
    //pH_M
    case 3:
    case 7:
    case 10:
      value = atof(_value_1) / 100.0;
      break;
  }

  return value;
}

int Omega_PHH37::rangeCode()
{
  return atoi(_range_code);
}

int Omega_PHH37::displayMode()
{
  return Omega_PHH37_DisplayMode_mV;
}

bool Omega_PHH37::validInput()
{
  if(strlen(_input) != 21)
    return false;

  if(strncmp(_input, ">001N", 5) != 0)
    return false;
  return true;
}
