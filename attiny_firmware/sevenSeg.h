#ifndef __sevenSeg_H_
#define __sevenSeg_H_

// include types & constants of Wiring core API
#include "WConstants.h"
#include "core_pins.h"

//Pin connected to ST_CP of 74HC595
const int latchPin = PIN_A7;
//Pin connected to SH_CP of 74HC595
const int clockPin = PIN_B1;
////Pin connected to DS of 74HC595
const int dataPin = PIN_B0;
///Digit reset pin
const int resetPin = PIN_A6;

void DisplayReset();
void convert2Digits(long num100);
void DisplayDigits();

#endif
