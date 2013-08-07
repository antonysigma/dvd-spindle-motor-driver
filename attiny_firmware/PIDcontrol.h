#ifndef __PIDcontrol_H_
#define __PIDcontrol_H_

// include types & constants of Wiring core API
#include "WConstants.h"
#include "core_pins.h"


///Torque control pin
const int spinPin = PIN_A5;

///Speed input pin (PIN_A2, PIN_A1)
const int speedPinCoarse = 2;
const int speedPinFine = 1;

const unsigned int sampleT = 200;
void PID_control(long deltaT);

#endif
