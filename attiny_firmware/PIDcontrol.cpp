#include "PIDcontrol.h"

/******************************************************************************/
const unsigned int T_min = 100;
const int stop_level = 90;

const float Kp = 0.5;
const float Ki = sampleT * 4e-4;

void PID_control(long deltaT)
{
  // Previous input value
  static float u = 0;
  static int e = 0;

  // Measure speed output (range: 0 ~ 1023)
  int y = (long(T_min) << 10) / deltaT;

  // Measure speed input (range: 0 ~ 1023)
  int x = (analogRead(speedPinCoarse) | 0x1e0) | (analogRead(speedPinFine) | 0x1f);

  // Estimate error
  float new_e = x - y;

  // Apply PI gain
  float new_u = u + (new_e - e) * Kp + new_e * Ki;

  // Prevent integral windup
  if(new_u < 0) new_u=0;
  else if(new_u > 1023) new_u = 1023;

  u = new_u;
  e = new_e;

  // Update the driving signal (Map to 90 ~ 255)
  analogWrite(spinPin, stop_level+long(u * (255-stop_level))>>10 );
}

