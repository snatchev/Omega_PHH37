/*
 * Omega_PHH37
 * Library for communicating with the Omega PHH37
 * pH/mV Temperature meter over RS232
 *
 * Stefan Natchev - 2013
 */

#ifndef Omega_PHH37_h
#define Omega_PHH37_h

#include "Arduino.h"

class Omega_PHH37
{
  public:
    Omega_PHH37();
    void begin();
    bool read();
    float mV();
    float temp();
    char tempUnits();
    float pH();
    int rangeCode();
  private:
    char _input[64];
    char _range_code[3];
    char _value_1[7];
    char _value_2[7];
    bool validInput();
};

#endif
