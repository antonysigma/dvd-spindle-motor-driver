#include "PIDcontrol.h"

/******************************************************************************/
const unsigned int T_min = 100;
const int stop_level = 90;

//const int Kp = 2;
//const int Ki = 1;

void PID_control(long deltaT)
{
  // Previous input value
  static double u = 0;
  static double e = 0;
  float new_u = 0;

  // Measure output RPM (range: 0 ~ 255)
  float y = (long(T_min) << 8) / deltaT;

  // Measure speed input (range: 0 ~ 255)
  float x = analogRead(speedPin) >> 3;
  float z = analogRead(speedPinBlue) >> 3;

  // Estimate error
  float new_e = x + z - y;

  // Apply PI gain
  new_u = u + (new_e - e) + int((long(new_e) * sampleT) >> 11);

  // Prevent integral windup
  if(new_u < 0) new_u=0;
  else if(new_u > 255) new_u = 255;

  u = new_u;
  e = new_e;
  int out = u;
  // Update the driving signal (Map to 100~255)
  analogWrite(spinPin, stop_level+out>>1);
}

