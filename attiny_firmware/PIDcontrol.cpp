#include "PIDcontrol.h"

/******************************************************************************/
const unsigned int T_min = 100;
const int stop_level = 90;

//const int Kp = 2;
//const int Ki = 1;

void PID_control(long deltaT)
{
  // Previous input value
  static int u = 0;
  static int e = 0;

  // Measure output RPM (range: 0 ~ 255)
  int y = (long(T_min) << 8) / deltaT;

  // Measure speed input (range: 0 ~ 255)
  int x = analogRead(speedPin) >> 2;

  // Estimate error
  int new_e = x - y;

  // Apply PI gain
  int new_u = u + (new_e - e) + int((long(new_e) * sampleT) >> 11);

  // Prevent integral windup
  if(new_u < 0) new_u=0;
  else if(new_u > 255) new_u = 255;

  u = new_u;
  e = new_e;

  // Update the driving signal (Map to 100~255)
  analogWrite(spinPin, stop_level+u>>1);
}

