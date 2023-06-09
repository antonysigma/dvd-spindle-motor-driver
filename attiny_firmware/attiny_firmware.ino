//**************************************************************//
//  Name    : shiftOutCode, Hello World
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis
//  Date    : 25 Oct, 2006
//  Modified: 23 Mar 2010
//  Version : 2.0
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255
//****************************************************************
#include "PIDcontrol.h"
#include "sevenSeg.h"

/******************************************************************************/
long deltaT = 1000;

long timePast = millis();
void
measureSpin() {
    // static long timePast = millis();
    long timeNow = millis();

    deltaT = timeNow - timePast;
    timePast = timeNow;

    // Update kilo-revolution per minute =
    // (128 / dT) / (18 Ticks / Rev)
    //        * (60k millisecond / 1 minute) * (1 kiloRev / 1000 Rev)
    // dT = millisecond / tick
    float kilo_rev = 1280. / (deltaT * 3);
    convert2Digits(kilo_rev);
}

/******************************************************************************/
void
setup() {
    // set pins to output so you can control the shift register
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(resetPin, OUTPUT);

    // pinMode(spinPin, OUTPUT);
    // pinMode(speedPin, INPUT);

    // Reset the Display
    DisplayReset();

    // Counter based on external input (On pin B2)
    attachInterrupt(0, measureSpin, RISING);

    // Set torque output (default brake)
    analogWrite(spinPin, 0);
}

long timePID_Past = millis();
void
loop() {
    // static long timePast=millis();
    long timeNow = millis();

    if (timeNow - timePID_Past > sampleT) {
        PID_control(deltaT);
        timePID_Past = timeNow;
    }
    DisplayDigits();
}
