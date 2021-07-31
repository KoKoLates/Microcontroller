# Microcontroller
some projects of Microcontroller Mechatronics
## Arduino
#### Lab01 : Electronic Piano
The piano generates a square wave at the specific frequency when the corresponding key is pressed. For example, the piano generates a square wave at a frequency of 261.63 Hz when the key C is pressed. Since period is the inverse of frequency, the cycle duration of the signal is 3.816 ms. In a cycle, the signal connected to the buzzer system is ON for 1.908 ms then is OFF for 1.908 ms and so on. This applies to all piano keys, only the frequencies change<br>
<br>
Use your piano to play the song “twinkle twinkle little star” and Write a program that plays the song “twinkle twinkle little star” automatically.
#### Lab02 : Digital Watch
A 7-segment LED is an electronic device for displaying decimal numerals. These displays are widely used in digital clocks, electronic meters, and basic calculators. In a typical 7-segment LED package, all of the cathodes or all of the anodes of the segment LEDs are connected to a common pin. This is referred to as a "common cathode" or "common anode" device <br>
<br>
You are required to design and build a digital watch using an Arduino MCU. The digital watch you are required to build comprises two 7-segment LEDs that display time in second. The watch has two modes: a clock mode and a stopwatch mode. The watch has three keys: mode, adjust/start, and reset.
#### Lab03 : Wheel Robot
An H-bridge is a circuit that enables a voltage to be applied across a DC motor in either direction. The circuit is known as an H-Bridge because it resembles the capital letter H. An H-bridge typically comprises 4 switches. The open and close of the switches determine the motor operation. A dual H-bridge board that can be used to control up to 2 DC motors. The board comes with an L298 H-bridge chip and can provide up to 1 Amps of current to each DC motor. The H-bridge board needs to be wired to the motors, Arduino MCU, and battery appropriately.<br>
<br>
You are required to design and build a wheel robot. You are also asked to navigate the wheel robot to circle around a field (Fig. 1). To complete this task, you will need to learn how to control two direct current (DC) motors, moving the wheel robot forward and making right and left turns.
#### Lab04 : Line Tracking And Obstacle Avoidance
##### Infrared sensor (IR)
An infrared (IR) sensor is an electronic device that emits and detects IR radiation in order to sense some aspect of its surroundings. An IR sensor is composed of an emitter and a receiver. The basic concept of IR obstacle detection is to transmit an IR signal from the emitter in a direction. If there is an object in the direction, the IR signal bounces back and is received by the IR receiver.<br>
<br>
IR sensors are color sensitive. Black color patches block all the light. The IR signal from the emitter does not bounce back to the receiver if the obstacle surface is in black.The IR sensor module we will use is an integrated IR component. It has an analog output A0 and a digital output D0. The analog output pin A0 is the output of the IR receiver and can be used to evaluate the distance between the IR sensor module and an obstacle using the ADC of a MCU. The pin D0 outputs HIGH when the object distance is greater than a threshold; otherwise, the pin D0 outputs LOW. The threshold can be adjusted by rotating the blue potentiometer in the back of the module.
##### DMS sensor
DMS sensors (Sharp IR rangers) are specially designed IR sensors. These sensors are not affected by color as much as regular IR sensors. A Sharp GP2Y0A21YK DMS sensor. The DMS sensor uses triangulation and a small linear CCD array to compute the distance and presence of objects in the field of view. The principle of the triangulation. Similar to regular IR sensors, a pulse of IR light is emitted by the DMS sensor. If the light reflects off an object, it returns to the detector and creates a triangle between the emitter and the detector. The incident angle of the reflected light varies based on the distance to the object. The receiver portion of the DMS sensor is a precision lens that transmits reflected light onto various portions of the enclosed linear CCD array based on the incident angle of the reflected light. The CCD array can then determine the incident angle, and thus calculate the distance to the object. This method of ranging is very immune to interference from ambient light and offers indifference to the color of the object being detected. The output distance characteristics of the Sharp GP2Y0A21YK sensor. The distance measuring range is approximately 10 to 80 cm. For details of the sensor, please refer to its datasheet.<br>
<br>
You are required to design and build a line following robot. The robot needs to have a function that detect and bypass obstacles on its path automatically. The robot returns to its path of the black line after bypassing the obstacles.
## AVR-C
#### Lab05 : Number Display 
#### Lab06 : Electronic Piano With 7 Segment
#### Lab07 : DMS Distance Meter
#### Lab08 : Wheel Robot
## AVR-Assembly
#### Lab09 : Number Digits Display
#### Lab10 : Assembly Program Simulation
#### Lab11 : Eletronic Piano Keyboard With 7 Segment
