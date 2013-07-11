v 20110115 2
C 40000 40000 0 0 0 title-bordered-A3.sym
C 45500 42600 1 0 0 ATtiny44_DIP.sym
{
T 47200 45500 5 10 1 1 0 6 1
refdes=U1
T 45800 45700 5 10 0 0 0 0 1
device=attiny44
T 45800 45900 5 10 0 0 0 0 1
footprint=DIP14_op
T 45500 42600 5 10 0 1 0 0 1
value=attiny85
}
C 40800 40700 1 0 0 connector6-1.sym
{
T 42600 42500 5 10 0 0 0 0 1
device=CONNECTOR_6
T 40900 42700 5 10 1 1 0 0 1
refdes=CONN2
T 40800 40700 5 10 0 1 0 0 1
footprint=CONNECTOR 1 6
}
T 44200 45800 9 15 1 0 0 0 1
Microcontroller
T 40500 43000 9 15 1 0 0 0 1
SPI Bus
C 45900 49500 1 0 1 switch-spdt-1.sym
{
T 45500 50300 5 10 0 0 0 6 1
device=SPDT
T 45500 50100 5 10 1 1 0 6 1
refdes=S2
T 45900 49500 5 10 0 1 0 0 1
footprint=CONNECTOR 1 3
}
T 44300 50400 9 15 1 0 0 0 1
Motor Enable (ON/OFF)
C 54600 43300 1 0 0 vdd-1.sym
C 54600 43300 1 270 0 capacitor-2.sym
{
T 55300 43100 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 55100 43100 5 10 1 1 270 0 1
refdes=C101
T 55500 43100 5 10 0 0 270 0 1
symversion=0.1
T 54600 43300 5 10 0 0 0 0 1
value=220u
}
C 55000 42400 1 180 0 vss-1.sym
C 45900 49600 1 0 0 output-2.sym
{
T 46800 49800 5 10 0 0 0 0 1
net=MODE:1
T 46100 50300 5 10 0 0 0 0 1
device=none
T 46900 49700 5 10 1 1 0 1 1
value=MODE
}
C 44600 49900 1 0 0 vdd-1.sym
N 44800 49500 45000 49500 4
C 45500 44100 1 0 1 output-2.sym
{
T 44600 44300 5 10 0 0 0 6 1
net=DIG_IO:1
T 45300 44800 5 10 0 0 0 6 1
device=none
T 44600 44200 5 10 1 1 0 7 1
value=DIG_IO
}
C 44100 42900 1 0 0 input-2.sym
{
T 44100 43100 5 10 0 0 0 0 1
net=RESET:1
T 44700 43600 5 10 0 0 0 0 1
device=none
T 44600 43000 5 10 1 1 0 7 1
value=\_RESET\_
}
C 45500 43700 1 0 1 output-2.sym
{
T 44600 43900 5 10 0 0 0 6 1
net=SCLK:1
T 45300 44400 5 10 0 0 0 6 1
device=none
T 44600 43800 5 10 1 1 0 7 1
value=SLCK
}
C 41200 47100 1 270 0 switch-pushbutton-no-1.sym
{
T 41500 46900 5 10 1 1 270 0 1
refdes=S1
T 41800 46700 5 10 0 0 270 0 1
device=SWITCH_PUSHBUTTON_NO
}
C 41100 45800 1 0 0 gnd-1.sym
C 41200 47000 1 0 0 output-2.sym
{
T 42100 47200 5 10 0 0 0 0 1
net=\_RESET\_:1
T 41400 47700 5 10 0 0 0 0 1
device=none
T 42200 47100 5 10 1 1 0 1 1
value=\_RESET\_
}
C 41100 48000 1 270 0 resistor-1.sym
{
T 41500 47700 5 10 0 0 270 0 1
device=RESISTOR
T 41400 47700 5 10 1 1 270 0 1
refdes=R101
T 41100 48000 5 10 0 0 0 0 1
value=20k
T 41100 48000 5 10 0 1 0 0 1
footprint=R400
}
C 41000 48000 1 0 0 vdd-1.sym
T 41600 47800 9 15 1 0 0 0 1
System Reset
C 51900 45700 1 0 0 4040-1.sym
{
T 52200 49850 5 10 0 0 0 0 1
device=4040
T 53600 49700 5 10 1 1 0 6 1
refdes=U2
T 52200 50050 5 10 0 0 0 0 1
footprint=DIP16_op
T 51900 45700 5 10 0 1 0 0 1
value=74hc4040
}
C 50500 47600 1 0 0 input-2.sym
{
T 50500 47800 5 10 0 0 0 0 1
net=FOSC:1
T 51100 48300 5 10 0 0 0 0 1
device=none
T 51000 47700 5 10 1 1 0 7 1
value=FOSC
}
C 52100 47400 1 180 0 vss-1.sym
T 50400 50000 9 15 1 0 0 0 1
Pulse counter (divide by 512)
C 53900 46800 1 0 0 output-2.sym
{
T 54800 47000 5 10 0 0 0 0 1
net=TRIG:1
T 54100 47500 5 10 0 0 0 0 1
device=none
T 54800 46900 5 10 1 1 0 1 1
value=TRIG
}
C 45000 49500 1 180 0 vss-1.sym
C 42300 42400 1 0 0 vdd-1.sym
C 42700 40900 1 180 0 vss-1.sym
C 48900 42900 1 0 1 input-2.sym
{
T 48900 43100 5 10 0 0 0 6 1
net=MISO:1
T 48300 43600 5 10 0 0 0 6 1
device=none
T 48400 43000 5 10 1 1 0 1 1
value=MISO
}
C 48900 43300 1 0 1 input-2.sym
{
T 48900 43500 5 10 0 0 0 6 1
net=SCK:1
T 48300 44000 5 10 0 0 0 6 1
device=none
T 48400 43400 5 10 1 1 0 1 1
value=SCK
}
C 42500 42000 1 0 0 output-2.sym
{
T 43400 42200 5 10 0 0 0 0 1
net=\_RESET\_:1
T 42700 42700 5 10 0 0 0 0 1
device=none
T 43500 42100 5 10 1 1 0 1 1
value=\_RESET\_
}
C 42500 41700 1 0 0 output-2.sym
{
T 43400 41900 5 10 0 0 0 0 1
net=MOSI:1
T 42700 42400 5 10 0 0 0 0 1
device=none
T 43500 41800 5 10 1 1 0 1 1
value=MOSI
}
C 42500 41400 1 0 0 output-2.sym
{
T 43400 41600 5 10 0 0 0 0 1
net=MISO:1
T 42700 42100 5 10 0 0 0 0 1
device=none
T 43500 41500 5 10 1 1 0 1 1
value=MISO
}
C 42500 41100 1 0 0 output-2.sym
{
T 43400 41300 5 10 0 0 0 0 1
net=SCK:1
T 42700 41800 5 10 0 0 0 0 1
device=none
T 43500 41200 5 10 1 1 0 1 1
value=SCK
}
N 44800 49900 45000 49900 4
C 40800 48900 1 0 0 connector5-1.sym
{
T 42600 50400 5 10 0 0 0 0 1
device=CONNECTOR_5
T 40900 50600 5 10 1 1 0 0 1
refdes=CONN1
T 40800 48900 5 10 0 1 0 0 1
footprint=CONNECTOR 1 5
}
N 47500 43000 47500 42500 4
C 48700 42400 1 0 0 output-2.sym
{
T 49600 42600 5 10 0 0 0 0 1
net=SPIN:1
T 48900 43100 5 10 0 0 0 0 1
device=none
T 49600 42500 5 10 1 1 0 1 1
value=SPIN
}
C 47500 42400 1 0 0 resistor-1.sym
{
T 47800 42800 5 10 0 0 0 0 1
device=RESISTOR
T 47700 42700 5 10 1 1 0 0 1
refdes=R102
T 47500 42400 5 10 0 1 0 0 1
footprint=R400
T 47500 42400 5 10 0 0 0 0 1
value=2k
}
C 48200 42500 1 270 0 capacitor-2.sym
{
T 48900 42300 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 48700 42300 5 10 1 1 270 0 1
refdes=C102
T 49100 42300 5 10 0 0 270 0 1
symversion=0.1
T 48200 42500 5 10 0 1 0 0 1
value=22u
}
N 48400 42500 48700 42500 4
C 48600 41600 1 180 0 vss-1.sym
C 42500 49300 1 0 0 output-2.sym
{
T 43400 49500 5 10 0 0 0 0 1
net=FOSC:1
T 42700 50000 5 10 0 0 0 0 1
device=none
T 43500 49400 5 10 1 1 0 1 1
value=FOSC
}
C 43900 49600 1 0 1 input-2.sym
{
T 43900 49800 5 10 0 0 0 6 1
net=MODE:1
T 43300 50300 5 10 0 0 0 6 1
device=none
T 43400 49700 5 10 1 1 0 1 1
value=MODE
}
C 43900 49900 1 0 1 input-2.sym
{
T 43900 50100 5 10 0 0 0 6 1
net=SPIN:1
T 43300 50600 5 10 0 0 0 6 1
device=none
T 43400 50000 5 10 1 1 0 1 1
value=SPIN
}
T 49400 41000 9 20 1 0 0 0 1
DVD-ROM Speed Controller
T 49800 40300 9 10 1 0 0 0 1
1
T 51300 40300 9 10 1 0 0 0 1
2
C 42300 50300 1 0 0 vdd-1.sym
C 42700 49100 1 180 0 vss-1.sym
C 44800 48400 1 270 0 resistor-variable-1.sym
{
T 45700 47600 5 10 0 0 270 0 1
device=VARIABLE_RESISTOR
T 45200 47800 5 10 1 1 270 0 1
refdes=R103
T 44800 48400 5 10 0 1 0 0 1
value=250k
}
C 44700 48400 1 0 0 vdd-1.sym
C 45100 47500 1 180 0 vss-1.sym
C 45900 47800 1 0 0 output-2.sym
{
T 46800 48000 5 10 0 0 0 0 1
net=SPEED:1
T 46100 48500 5 10 0 0 0 0 1
device=none
T 46800 47900 5 10 1 1 0 1 1
value=SPEED
}
N 45900 47900 45400 47900 4
C 46100 47000 1 90 0 capacitor-1.sym
{
T 45400 47200 5 10 0 0 90 0 1
device=CAPACITOR
T 45600 47200 5 10 1 1 90 0 1
refdes=C102
T 45200 47200 5 10 0 0 90 0 1
symversion=0.1
T 46100 47000 5 10 0 0 0 0 1
value=10n
}
C 46100 47000 1 180 0 vss-1.sym
C 45500 44900 1 0 1 output-2.sym
{
T 44600 45100 5 10 0 0 0 6 1
net=SRST:1
T 45300 45600 5 10 0 0 0 6 1
device=none
T 44600 45000 5 10 1 1 0 7 1
value=SRST
}
C 44100 45300 1 0 0 input-2.sym
{
T 44100 45500 5 10 0 0 0 0 1
net=MOSI:1
T 44700 46000 5 10 0 0 0 0 1
device=none
T 44600 45400 5 10 1 1 0 7 1
value=MOSI
}
N 45500 45400 45500 45000 4
C 45500 44500 1 0 1 output-2.sym
{
T 44600 44700 5 10 0 0 0 6 1
net=LATCH:1
T 45300 45200 5 10 0 0 0 6 1
device=none
T 44600 44600 5 10 1 1 0 7 1
value=LATCH
}
C 44100 43300 1 0 0 input-2.sym
{
T 44100 43500 5 10 0 0 0 0 1
net=TRIG:1
T 44700 44000 5 10 0 0 0 0 1
device=none
T 44600 43400 5 10 1 1 0 7 1
value=TRIG
}
C 48900 44900 1 0 1 input-2.sym
{
T 48900 45100 5 10 0 0 0 6 1
net=MODE:1
T 48300 45600 5 10 0 0 0 6 1
device=none
T 48400 45000 5 10 1 1 0 1 1
value=MODE
}
C 48900 44500 1 0 1 input-2.sym
{
T 48900 44700 5 10 0 0 0 6 1
net=SPEED:1
T 48300 45200 5 10 0 0 0 6 1
device=none
T 48400 44600 5 10 1 1 0 1 1
value=SPEED
}
