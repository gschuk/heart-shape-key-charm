# Firmware
The .ino file presented in this directory is just an example software and shows a few animation and blinking sequences. It is not trimmed for great readability or efficient runtime. 

## Ring Dimming
The function *void ring_dimming(unsigned int delay_each_step = 10)* controls 3 LEDs at a time. One LED which starts as off at 0% brightness and gets increasingly brighter, the next one which holds its brightest state and the last one which starts at 100% brightness and is dimmed until 0% brightness. Once one cycle is complete the LEDs that are controlled will be shifted by 1. <br> 
*Example:* <br>
| State  | Current LED | Next LED |
| ------------- | ------------- | ---|
| Falling   | LED_A  | LED_B   |
| Holding   | LED_B  | LED_C   |
| Rising    | LED_C  | LED_D   |




<!-- The function *void ring_dimming(unsigned int delay_each_step = 10)* controls 3 LEDs depending on 3 Phases. Phase 1 is the rising state the A_LED will get brighter until reaching the brightest point. The second phase holds the brightest state for the next B_LED. The third and last state decreases the brightness until the other C_LED is turned off completely. Next the same logic gets applied again but the LEDs will change the phase. A_LED will now be controlled according to the second phase, B_LED according to the third state and a new Z_LED will now be controlled according to the first phase. -->

## Flashing
The key charm is intended to be programmed by an Arduino ISP programmer (e.g. Arduino Uno). Generally any boardmanager can be used that supports the Attiny84a examples for boardmanagers are the following:
- https://github.com/SpenceKonde/ATTinyCore
- https://github.com/damellis/attiny

