#include "PIDcontrol.h"

/******************************************************************************/
const unsigned int T_min = 100;
const int stop_level = 90;

const float Kp = 1.509;
const float Ki = sampleT * 4e-4;

void PID_control(long deltaT)
{
  // Previous input value
  static float u = 0;
  static int e = 0;

  // Measure speed output (range: 0 ~ 1023)
  float y = (long(T_min) << 10) / deltaT;

  // Measure speed input (range: 0 ~ 1023)
  //int x = (analogRead(speedPinCoarse) | 0x1e0) | (analogRead(speedPinFine) | 0x1f);
  int x = (analogRead(speedPinCoarse) & 0x3E0) | (analogRead(speedPinFine) >> 5);

  // Estimate error
  float new_e = x - y;

  // Apply PI gain
  float new_u = u + (new_e - e) * Kp + new_e * Ki;

  // Prevent integral windup
  if(new_u < 0) new_u=0;
  else if(new_u > 1023) new_u = 1023;

  u = new_u;
  e = new_e;
  int out = u;
  // Update the driving signal
  analogWrite(spinPin, stop_level+out>>3 ); //maintain previous config because of stability issues
}

