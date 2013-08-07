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


/* 7-Segment display */
const byte letterE = 0x61;
const byte letterR = 0xf5;
const byte letterO = 0x03;
const byte letterV = 0xc7;
byte digits09[] = {
  0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09};

byte decimalPoint = 0xfe;

// Defaults to Error
byte showDigits[3] = {
//  letterE, letterR, letterR};
  0x61, 0xf5, 0xf5};

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

void convert2Digits(float num)
{
  if (num > 999) //overflow
  {
    showDigits[0] = letterO;
    showDigits[1] = letterV;
    showDigits[2] = letterR;
  }
  else if (num > 99.9) // between 100. to 999.
  {
  int hundred = int(num / 100) % 10;
  int ten = int(num / 10) % 10;
  int one = int(num) % 10;

    showDigits[0] = digits09[hundred];
    showDigits[1] = digits09[ten];
    showDigits[2] = digits09[one] & decimalPoint;
  }
  else if(num > 9.99) // between 10.0 to 99.9
  {
  int ten = int(num / 10) % 10;
  int one = int(num) % 10;
  int tenth = int(num * 10) % 10;

    showDigits[0] = digits09[ten];
    showDigits[1] = digits09[one] & decimalPoint;
    showDigits[2] = digits09[tenth];
  }
  else // between 0.00 to 9.99
  {
  int one = int(num) % 10;
  int tenth = int(num * 10) % 10;
  int hundredth = int(num * 100) % 10;

    showDigits[0] = digits09[one] & decimalPoint;
    showDigits[1] = digits09[tenth];
    showDigits[2] = digits09[hundredth];
  }

}

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

