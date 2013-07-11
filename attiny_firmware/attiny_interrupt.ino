//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************
//#include "TimerOne.h"

/******************************************************************************/
//Pin connected to ST_CP of 74HC595
int latchPin = PIN_B0;
//Pin connected to SH_CP of 74HC595
int clockPin = PIN_B1;
////Pin connected to DS of 74HC595
int dataPin = PIN_A7;
///Digit reset pin
int resetPin = PIN_A6;

///Torque control pin
int spinPin = PIN_A5;
///Speed input pin (PIN_A1)
int speedPin = 1;

/* 7-Segment display */
const byte letterE = 0x61;
const byte letterR = 0xf5;
const byte letterO = 0x03;
const byte letterV = 0xc7;
byte digits09[] = {
  0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09};

byte decimalPoint = 0xfe;
byte showDigits[3] = {
  letterE, letterR, letterR};

/* Time interval */
long deltaT = 0;

void DisplayReset(){
  // Reset position and cycle through once
  digitalWrite(resetPin, HIGH);
  delay(10);
  digitalWrite(resetPin, LOW);

  digitalWrite(latchPin, HIGH);
  delay(5);
  digitalWrite(latchPin, LOW);

  digitalWrite(latchPin, HIGH);
  delay(5);
  digitalWrite(latchPin, LOW);

  digitalWrite(latchPin, HIGH);
  delay(5);
  digitalWrite(latchPin, LOW);
}

//int idx=0;
void DisplayDigits(){
  static int idx=0;

  // take the latchPin low so 
  // the LEDs don't change while you're sending in bits:
  digitalWrite(latchPin, LOW);
  // shift out the bits:
  shiftOut(dataPin, clockPin, LSBFIRST, showDigits[idx]);  

  //take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);

  if(++idx >= 3) idx=0;

}

void convert2Digits(long num100)
{
  if (num100 > 9990) //overflow
  {
    showDigits[0] = letterO;
    showDigits[1] = letterV;
    showDigits[2] = letterR;
  }
  else if(num100 > 999)
  {
  int ten = (num100 / 1000) % 10;
  int one = (num100 / 100) % 10;
  int tenth = (num100 / 10) % 10;

    showDigits[0] = digits09[ten];
    showDigits[1] = digits09[one] & decimalPoint;
    showDigits[2] = digits09[tenth];
  }
  else
  {
  int one = (num100 / 100) % 10;
  int tenth = (num100 / 10) % 10;
  int hundredth = num100 % 10;

    showDigits[0] = digits09[one] & decimalPoint;
    showDigits[1] = digits09[tenth];
    showDigits[2] = digits09[hundredth];
  }

}
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


