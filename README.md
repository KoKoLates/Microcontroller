# Microcontroller
Some Projects in the Microcontroller Mechatronics lesson. <br>
[Lecture Video](https://www.youtube.com/playlist?list=PLVHBjRDK0kAJSpLpuJwE5W5nt2gtq3ECq)
## Arduino
```
Microcontroller   | ATmega328 -- Atmel 8-bit MCU
                  | RISC -- 135 instructions
                  | 2 8-bit timers
                  | 1 16-bit timer
Operating voltage | 5V
Input Voltage     | 7 to 12V
DC I/O current    |40mA
```
#### [Lab01 : Electronic Piano](https://github.com/KoKoLates/Microcontroller/tree/main/Lab01_Arduino_Electronic_Piano)
Use the piano to play the song “twinkle twinkle little star” and Write a program that plays the song “twinkle twinkle little star” automatically.<br/>
```c
void setup(){
    //all of the code within the curly braces will be run
    //ONCE when the program first runs
}

void loop(){
    //this function is run AFTER setup has finished, and
    //all of the code within the curly braces will be run again and again
    //until the power is removed
}
```

#### [Lab02 : Digital Watch](https://github.com/KoKoLates/Microcontroller/tree/main/Lab02_Arduino_Digital_Watch)
```c
void setup(){
    Serial.begin(9600); //initialize serial communication at 9600 bps
}
```
Arduino function and library : [Reference](https://www.arduino.cc/reference/en/) <br/><br/>

A `7-segment` LED is an electronic device for displaying decimal numerals. These displays are widely used in digital clocks, electronic meters, and basic calculators. In a typical `7-segment` LED package, all of the cathodes or all of the anodes of the segment LEDs are connected to a common pin. This is referred to as a "common cathode" or "common anode" device <br/><br/>

In this project, it's required to design a digital watch using an Arduino MCU and two `7-segment` LEDs that display time in second. The watch must has two modes: a clock mode and a stopwatch mode and has three main buttons: mode, start(adjust), and reset.


#### [Lab03 : Wheel Robot](https://github.com/KoKoLates/Microcontroller/tree/main/Lab03_Arduino_Wheel_Robot)
```c
void loop(){
    //clockwise
    digitalWrite(MotorA, HIGH);
    digitalWrite(MotorB, LOW);
    //counter-clockwise
    digitalWrite(MotorA, LOW);
    digitalWrite(MotorB, HIGH);
}
```
An `H-bridge` is a circuit that enables a voltage to be applied across a DC motor in either direction, and then the `dual H-bridge` board could be used to control up 2 DC motors. The board comes with an `L298 H-bridge` chip and can provide up to 1 Amps of current to each DC motor. The H-bridge board needs to be wired to the motors, Arduino MCU, and battery appropriately.<br/><br/>

In the project, it's required to design and build a wheel robot, and also asked to navigate the wheel robot to circle around a field. To complete this task, it will need to learn how to control two direct current (DC) motors, moving the wheel robot forward and making right and left turns by modifying the voltage value of each `H-bridge`.


#### [Lab04 : Line Tracking And Obstacle Avoidance](https://github.com/KoKoLates/Microcontroller/tree/main/Lab04_Arduino_Line_Tracking_with_Obstacles_Evasion)
#### Infrared sensor (IR)
An `infrared (IR) sensor` is an electronic device that emits and detects IR radiation in order to sense some aspect of its surroundings. An IR sensor is composed of an `emitter` and a `receiver`. The basic concept of IR obstacle detection is to transmit an IR signal from the emitter in a direction. If there is an object in the direction, the IR signal bounces back and is received by the IR receiver.<br>
<br>
IR sensors are `color sensitive`. Black color patches block all the light. The IR signal from the emitter does not bounce back to the receiver if the obstacle surface is in black.The IR sensor module we will use is an integrated IR component. It has an analog output `A0` and a digital output `D0`. The analog output pin A0 is the output of the IR receiver and can be used to evaluate the distance between the IR sensor module and an obstacle using the ADC of a MCU. The pin D0 outputs HIGH when the object distance is greater than a threshold; otherwise, the pin D0 outputs LOW. The threshold can be adjusted by rotating the blue potentiometer in the back of the module.
#### DMS sensor
`DMS` sensors (Sharp IR rangers) are specially designed IR sensors. These sensors are not affected by color as much as regular IR sensors. A Sharp `GP2Y0A21YK` DMS sensor. The DMS sensor uses triangulation and a small linear `CCD array` to compute the distance and presence of objects in the field of view. The principle of the triangulation. Similar to regular IR sensors, a pulse of IR light is emitted by the DMS sensor. If the light reflects off an object, it returns to the detector and creates a triangle between the emitter and the detector. The incident angle of the reflected light varies based on the distance to the object. The receiver portion of the DMS sensor is a precision lens that transmits reflected light onto various portions of the enclosed linear CCD array based on the incident angle of the reflected light. The CCD array can then determine the incident angle, and thus calculate the distance to the object. This method of ranging is very immune to interference from ambient light and offers indifference to the color of the object being detected. The output distance characteristics of the Sharp `GP2Y0A21YK` sensor. The distance measuring range is approximately `10 to 80 cm`. For details of the sensor, please refer to its datasheet.<br>
<br>
You are required to design and build a line following robot. The robot needs to have a function that detect and bypass obstacles on its path automatically. The robot returns to its path of the black line after bypassing the obstacles.



## AVR-C
#### [Lab05 : Number Display](https://github.com/KoKoLates/Microcontroller/tree/main/Lab05_AVR_C_Button_Display) 
Use `Ports C` and `Ports D` as the input from the buttons. Connect the buttons to Ports C and D. Note that this connection only works when the pull-up resistors are enabled. Use `Port B` as the output to the `7-segment` LED. Connect the pins of Port B to the 7-segment display. Place appropriate resistors when wiring the display to the microcontroller to prevent burnout. Write a `C` program that displays the number on the 7-segment LED when a corresponding button is pressed.<br>
<br>
You are required to design and build a button display using an AVR `ATmega328P` microcontroller. The display will use buttons as the input peripheral and a 7-segment LED as the output peripheral. The display has 10 keys, including digits 0 to 9. The display will show the character of a key on the 7-segment LED if the key is pressed. After completing this lab you should be able to master in AVR I/O programming


#### [Lab06 : Electronic Piano With 7 Segment](https://github.com/KoKoLates/Microcontroller/tree/main/Lab06_AVR_C_Electronic_Piano)
You are required to design and build a digital piano using an AVR `ATmega328P` microcontroller. The piano you are required to build will only use a small subset of keys. Each key is associated with a frequency which will give a key its own unique musical tone. The musical tones are digitally produced using the timer of the microcontroller and are played through a buzzer. The piano should play a tone as long as the corresponding key is pressed.


#### [Lab07 : DMS Distance Meter](https://github.com/KoKoLates/Microcontroller/tree/main/Lab07_AVR_C_Distance_Meter)
Use the pins of Port C to read the DMS signals. Use `PD1` as the `TX` to send the readings to a computer. Use the rest of the pins of `Port D` as the output to a `7-segment` LED. Use `Port B` as the output to the other 7-segment LED. Remember to calibrate the meter you build so that it gives the actual distances rather than the voltages of the DMS sensor.<br>
<br>
You are required to design and build a distance meterusing an AVR `ATmega328P` microcontroller. The meter you are required to build will acquire distance using a DMS sensor. It will display the distance in centimeters of 2 decimals on two 7-segment LEDs continuously. The meter will also send the distance readings back to a personal computer.


#### [Lab08 : Wheel Robot](https://github.com/KoKoLates/Microcontroller/tree/main/Lab08_AVR_C_Wheel_Robot)
Use `Timer0` and `Timer2` to generate the `PWM` signals. Connect `OC0A` and `OC0B` (`PD6` and `PD5`) to `IN1` and `IN2`. These two output signals control a DC motor. Connect `OC2A` and `OC2B` (`PB3` and `PD3`) to `IN3` and `IN4`. These two output signals control the other DC motor. Write a C program that navigates the wheel robot to circle around the field <br>
<br>
You are required to design and build a wheel robot. You are also asked to navigate the wheel robot to circle around a field. To complete this task, you will need to learn how to control two direct current (DC) motors, moving the wheel robot forward and making right and left turns.



## AVR-Assembly
#### [Lab09 : Number Digits Display](https://github.com/KoKoLates/Microcontroller/tree/main/Lab09_AVR_Assembly_Number_Display)
Connect appropriate pins of the `ATmega328P` to the 7-segment displays. Remember that `7-segment` display is composed of 7 LEDs. Place appropriate resistors when wiring the display to the microcontroller to prevent burnout. For details of the 7-segment display, please refer to its data sheet. Write an assembly program that shows the number digits 0 through 99 indefinitely. You are required to display number digits on two 7-segment LED using an AVR `ATmega328P` microcontroller. The digits to be displayed are from 0 through 99. Each digit is displayed for a short period of time (e.g., 0.2 sec). The digits are displayed indefinitely using a loop.


#### [Lab10 : Assembly Program Simulation](https://github.com/KoKoLates/Microcontroller/tree/main/Lab10_AVR_Assembly_Program_Simulation)
You will gain familiarity with assembly program tracking and debugging using Atmel Studio.


#### [Lab11 : Eletronic Piano Keyboard With 7 Segment](https://github.com/KoKoLates/Microcontroller/tree/main/Lab11_AVR_Assembly_Electronic_Keyboard)
Use a port as keyboard input, and another port as output to the `7-segment` display. The keyboard is composed of several keys (switches). Connect a switch to a pin of the input port. Connect the pins of the output port to a 7-segment display. Remember that 7-segment display is composed of 7 LEDs. Place appropriate resistors when wiring the display to the microcontroller to prevent burnout. Write an assembly program that shows the letter of a note when the corresponding key on the keyboard is pressed.<br>
<br>
In this lab, you are required to design and build an electronic piano keyboard. The keyboard should contain 7 keys for musical notes C, D, E, F, G, A, and B. It also contains a 7-segment display. The display is used to show the letter of a note when the corresponding key on the keyboard is pressed.

## Installation
#### [Arduino](https://www.arduino.cc/)
