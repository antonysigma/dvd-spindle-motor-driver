//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************
#include "sevenSeg.h"

/******************************************************************************/

/* Time interval */
long deltaT = 0;


/******************************************************************************/
long timePast = millis();
void measureSpin()
{
  //static long timePast = millis();
  long timeNow = millis();

  deltaT = timeNow - timePast;
  timePast = timeNow;

  // Update revolution per sec ( rev per sec / 100 )
  int rev100 = long(102400) / deltaT / 6;
  convert2Digits(rev100);
}

/******************************************************************************/
const unsigned int T_min = 100;
const unsigned int sampleT = 200;
const int stop_level = 90;

//const int Kp = 2;
//const int Ki = 1;

void PID_control()
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
  analogWrite(spinPin, map(u, 0, 255, stop_level, 255));
}

/******************************************************************************/
void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(resetPin, OUTPUT);

  //pinMode(spinPin, OUTPUT);
  //pinMode(speedPin, INPUT);

  // Reset the Display
  DisplayReset();

  // Counter based on external input (On pin B2)
  attachInterrupt(0, measureSpin, RISING);

  // Set torque output (default brake)
  analogWrite(spinPin, 0);
}

long timePID_Past = millis();
void loop() {

  // static long timePast=millis();
  long timeNow = millis();

  if(timeNow - timePID_Past > sampleT)
  {
    PID_control();
    timePID_Past = timeNow;
  }
  DisplayDigits();
}


