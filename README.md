# 4-Bit-Digital-to-Analog-Converter
An Arduino-driven 4-bit Digital-to-Analog Converter built with an R-2R resistor ladder network and an op-amp buffer stage. The firmware steps through all 16 possible 4-bit input combinations to generate a 16-step staircase waveform, verified against theoretical predictions on an oscilloscope.
 
Built at Rutgers IEEE Workshop

A digital-to-Analog Converter takes a digital binary value like '1010' and converts it to a corresponding analog voltage.

For example, with a 4-bit DAC and a 5 V reference:

0000 → lowest output voltage
0101 → intermediate voltage
1010 → higher voltage
1111 → maximum output voltage

This project builds a 4-bit DAC which means it can represent 16 different digital values (0000 through 1111)

Parts needed: 10k ohm resistors, 20k ohm resistors, LM1458 op-amp, Arduino Uno, Dual-rail power supply, Oscilloscope

How it Works:
1) The arduino has 4 output pins. Each pin is either high (5V) or low (0V). This is the 4-bit Binary Number
2) Those 4 pins connect into a network of resistors arranged in a repeating pattern called an R2R Ladder. We want the output voltage to reflect the whole 4-bit number
where the leftmost bit is the most significant and rightmost bit is least significant. eg: 1000 generates a much bigger voltage than 0001
The R2R does this weighing by using just 2 resistor values (10k and 20k ohm). The resistor arrangement makes each bit have half the value of the one to its left.
This makes the relative weights: 1/2, 1/4, 1/8 and 1/16
3) The voltage from the 4 bits combines into the output
ex: if our binary number is 1010, voltage is 5[(1/2 * 1) + (1/4*0) + (1/8*1) + (1/16*0)] = 5 * 0.625 = 3.125 V
So in an idealized DAC, 1010 should show a voltage of 3.125 V on Oscilloscope.
4) The Voltage passes through an op-amp which acts as a high-impedance buffer. This means that the op-amp isolates the R-2R ladder from the load so that the DAC's
output voltage does not significantly change when another circuit is connected.
5) The arduino passes through all 16 4-bit combinations, creating a waveform on oscilloscope

| Binary | Decimal | Ideal Output Voltage |
|--------|--------:|---------------------:|
| 0000   | 0       | 0.000 V |
| 0001   | 1       | 0.3125 V |
| 0010   | 2       | 0.6250 V |
| 0011   | 3       | 0.9375 V |
| 0100   | 4       | 1.2500 V |
| 0101   | 5       | 1.5625 V |
| 0110   | 6       | 1.8750 V |
| 0111   | 7       | 2.1875 V |
| 1000   | 8       | 2.5000 V |
| 1001   | 9       | 2.8125 V |
| 1010   | 10      | 3.1250 V |
| 1011   | 11      | 3.4375 V |
| 1100   | 12      | 3.7500 V |
| 1101   | 13      | 4.0625 V |
| 1110   | 14      | 4.3750 V |
| 1111   | 15      | 4.6875 V |




