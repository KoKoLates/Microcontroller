# Microcontroller
Some Projects in the Microcontroller Mechatronics lesson. <br>
* [Lecture Video](https://www.youtube.com/playlist?list=PLVHBjRDK0kAJSpLpuJwE5W5nt2gtq3ECq)
## Arduino
```
Microcontroller   | ATmega328 -- Atmel 8-bit MCU
                  | RISC -- 135 instructions
                  | 2 8-bit timers
                  | 1 16-bit timer
Operating voltage | 5V
Input Voltage     | 7 to 12V
DC I/O current    | 40mA
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
* Arduino function and library : [Reference](https://www.arduino.cc/reference/en/) <br/><br/>

A `7-segment` LED is an electronic device for displaying decimal numerals. These displays are widely used in digital clocks, electronic meters, and basic calculators. In a typical `7-segment` LED package, all of the cathodes or all of the anodes of the segment LEDs are connected to a common pin. This is referred to as a "common cathode" or "common anode" device. <br/><br/>
![image](https://github.com/KoKoLates/Microcontroller/blob/main/images/7segament.PNG)

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

![image](https://github.com/KoKoLates/Microcontroller/blob/main/images/Hbridge.PNG)

In the project, it's required to design and build a wheel robot, and also asked to navigate the wheel robot to circle around a field. To complete this task, it will need to learn how to control two direct DC motors, moving the wheel robot forward and making right and left turns by modifying the voltage value of each `H-bridge`.


#### [Lab04 : Line Tracking And Obstacle Avoidance](https://github.com/KoKoLates/Microcontroller/tree/main/Lab04_Arduino_Line_Tracking_with_Obstacles_Evasion)
* **DMS sensor**<br/>
`DMS` sensors is used to detect objects or walls within a fixed distance, and the sensor is not affected by color as much as IR Sensors enabling it to measure precise distance. The recommand voltage supply is around `4.5 to 5.5V`, and it could detect in the distance region between `10 to 80 cm`. From the graph below, we could know, even if the color and reflection percentage change, the output value for the distance is barely changed.<br/><br/>

![image](https://github.com/KoKoLates/Microcontroller/blob/main/images/DMSreflect.PNG)
```c
void setup(){
    Serial.begin(9600);
    pinMode(A0, INPUT); //set in analog pin
}

void loop(){
    int senserValue = analogRead(A0);
    delay(100);
}
```
* Signal smoothing : 
```c
int readings[10];
int readIndex, total, average = 0;
void setup(){
    Serial.begin(9600);
    for (int i = 0; i < 10; i++) { readings[i] = 0; } //initialize
}

void loop(){
    total = total - readings[readIndex];
    readings[readIndex] = analogRead(A0);
    total = total + readings[readIndex];
    readIndex++ ;
    if (readIndex >= 10) readIndex = 0;
    average = total / 10;
    Serial.println(average);
    delay(10);
}
```
* Serial Plotter :
```
Arduino > Tools > Serial Plotter (Ctrl + Shift + L)
```

* **Ultrasonic senser**
```c
int TRIGPIN = 12; // Pin to send trigger pulse
int ECHOPIN = 13; // Pin to receive echo pulse
void setup() {
    Serial.begin(9600);
    pinMode(ECHOPIN, INPUT);
    pinMode(TRIGPIN, OUTPUT);
}

void loop() {
    digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2us
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW); // Send pin low again
    int distance = pulseIn(ECHOPIN, HIGH);
    distance = distance/58; // Calculate distance (in cm) from time of pulse
    Serial.println(distance);
    delay(50);
}
```

* **IR senser** <br/>
An infrared (IR) sensor is an electronic device that emits and detects infrared radiation to sense surroundings. It's `color sensitive`. The IR signal from the emitter does not bounce back to the receiver if the obstacle surface is in black. The threshold of IR could be adjusted by rotating the blue potentiometer in the back of the module.
```c
void setup() {
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(A0);
delay(1000);
}
```
This project is required to design and build a line following robot that have a function detecting and bypassing obstacles on its path automatically. The robot has to returns to its path of the black line after bypassing the obstacles.


## AVR-C
ATmega328p : <br/><br/>
![image](https://github.com/KoKoLates/Microcontroller/blob/main/images/ATmega328p.PNG)
**AVR MCU Programing**
* Programing the source code in Assembler or higher language (C/C++).
* Compiling to obtain executable file (hex-file, machine language).
* Using programmer (Arduino) and software to download hex-file to the MCU.
* Arduino ISP :
```
File > Examples > 11.ArduinoISP > ArduinoISP
```
![image](https://github.com/KoKoLates/Microcontroller/blob/main/images/arduinoISP.PNG)
**AVRDudess**
```
Programmer  | Arduino
Port        | proper Port
MCU         | ATmega328p
Baud rate   | 19200
Read        | Deflaut : L-0xE2 H-0xD9 E-0x07
Flasf File  | the hex-file
Programming | click
```
#### [Lab05 : Number Display](https://github.com/KoKoLates/Microcontroller/tree/main/Lab05_AVR_C_Button_Display) 
```
DDRx : Data Direction
PORTx : Output Mode
PINx : Input Mode
x = B, C or D
```
* I/O :
```C
//Output
DDRD = 0b11111111; //0xFF
PORTD = 0b11110000; //HIGH from PD4 to PD7

//Input
DDRB = 0x0;
DDRD = 0xFF; 
while(True){
    PORTD = PINB + 5;
}

//Input with pull-up
DDRB = 0x0;
PORTB = 0xFF;
DDRD = 0xFF;
while(True){
    PORTD = PINB;
}
```
You are required to design and build a button display using an AVR `ATmega328P` microcontroller. The display will use buttons as the input peripheral and a `7-segment` LED as the output peripheral. The display has 10 keys, including digits 0 to 9. The display will show the character of a key on the 7-segment LED if the key is pressed. After completing this lab you should be able to master in AVR I/O programming.


#### [Lab06 : Electronic Piano With 7 Segment](https://github.com/KoKoLates/Microcontroller/tree/main/Lab06_AVR_C_Electronic_Piano)
ATmega328p has two 8-bit timers (Timer0/Timer2) and one 16-bit Timer2.
**Timer0 :**
* TCNT0 (Timer/counter register)
* TCCR0A/B (Timer/counter control register)
* TOV0 (Timer overflow flag)
* OCR0A (Output compare register)
* OCF0A (Output compare match flag)
```c
//Square Wave at 10Hz 
int main(void){
    CLKPR = (1 << CLKPCE);
    CLKPR = 0b00000011; // set clk to 1Mhz
    DDRD=0b00000001; // PD0 as output
    PORTD = 0; // initial output 0
    while(True){
        TCNT0 = 206;
        TCCR0A = 0; // normal mode, int clk
        TCCR0B = 0b00000101; // p=1024, start Timer
        while ((TIFR0 & (1 << TOV0)) == 0); // wait for flag TOV0=1
        TCCR0B = 0; // stop Timer
        TIFR0 = TIFR0 | (1 << TOV0); // clear TOV0
        PORTD=PORTD^0b00000001;
    }
}
```
It's required to design and build a digital piano using an AVR `ATmega328P` microcontroller. The piano you are required to build will only use a small subset of keys. Each key is associated with a frequency which will give a key its own unique musical tone. The musical tones are digitally produced using the timer of the microcontroller and are played through a buzzer. The piano should play a tone as long as the corresponding key is pressed.


#### [Lab07 : DMS Distance Meter](https://github.com/KoKoLates/Microcontroller/tree/main/Lab07_AVR_C_Distance_Meter)
* Reading the value from DMS senser :
```c
int main(void){
    CLKPR = (1 << CLKPCE);
    CLKPR = 0b00000011; // set clk to 1Mhz
    DDRB = 0xFF; // PORTB as output
    DDRD = 0xFF; // PORTD as output
    DDRC = 0; // PORTC as input
    ADCSRA = 0b10000111; // enable + prescaler
    ADMUX = 0b11000000; // ref volt + channel
    while (1) {
        ADCSRA |= (1 << ADIF); // clear ADIF
        ADCSRA |= (1 << ADSC); // start ADC
        while((ADCSRA & (1 << ADIF)) == 0); // wait for ADC done
        PORTD = ADCL; // read low byte first
        PORTB = ADCH;
        _delay_ms(200);
    }
}
```
* Reading the value from DMS senser in free running mode : <br/>
Read data from ADC0 and displays the result on Port B and Port D indefinitely, enable ADC and select ADC clock to be ck/128 (ADCSRA = 0xAF and ADCSRB = 0x00). Select 1.1V internal reference voltage and ADC0 (ADMUX = 0xC0).
```c
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void){
    CLKPR = (1 << CLKPCE);
    CLKPR = 0b00000011; // set clk to 1Mhz
    DDRB = 0xFF; // PORTB as output
    DDRD = 0xFF; // PORTD as output
    DDRC = 0; // PORTC as input
    ADCSRA = 0b10100111; // free running mode
    ADMUX = 0b11000000; // ref volt + channel
    ADCSRA |= (1 << ADSC); // start ADC
    while (1) {
        PORTD = ADCL; // read low byte first
        PORTB = ADCH;
        _delay_ms(200);
    }
}
```
The projects required to design and build a distance meterusing an AVR `ATmega328P` microcontroller. The meter you are required to build will acquire distance using a DMS sensor. It will display the distance in centimeters of 2 decimals on two `7-segment` LEDs continuously. The meter will also send the distance readings back to a personal computer.

#### [Lab08 : Wheel Robot](https://github.com/KoKoLates/Microcontroller/tree/main/Lab08_AVR_C_Wheel_Robot)
Pulse Width Modulation (PWM) providing control on output power pf a binary output device without changing hardware. And the heat dissipated versus using resistor for intermediate voltage values.
```c
CLKPR = (1 << CLKPCE);
CLKPR = 0b00000011;
DDRD = 0xFF; 
OCR0A = 203; 
OCR0B = 50; 
TCCR0A = 0b10100001; 
TCCR0B = 0b00000101;
```
* ADC Interrupt Program :
```c
#include <avr/io.h>
#include <avr/interrupt.h>
volatile unsigned int value;

int main(void){
    DDRC = 0;
    sei(); // enable global interrupts
    ADMUX = 0b01000000;
    ADCSRA = 0xFF;
    while(1);
}

ISR(ADC_vect) {
    unsigned char low, high;
    ADCSRA |= (1 << ADIF); // clear ADIF
    low = ADCL; // read low byte first
    high = ADCH;
    value = (high << 8) + low;
}
```

It's required to design and build a wheel robot. You are also asked to navigate the wheel robot to circle around a field. To complete this task, you will need to learn how to control two direct current (DC) motors, moving the wheel robot forward and making right and left turns.


## AVR-Assembly
#### [Lab09 : Number Digits Display](https://github.com/KoKoLates/Microcontroller/tree/main/Lab09_AVR_Assembly_Number_Display)
* LDI (Load Immediate) : <br/>
loading values into the general purpose registers. The value of RD is from 16 to 31, and K is 0 to 255.
```assembly
LDI RD, K; 
```
* ADD : <br/>
add and store values in the general purpose registers where RD between 0 to 31 and RS between 0 to 31.
```assembly
ADD RD, RS;
```
* SUB : <br/>
subtract and store values in the general purpose registers, RD between 0 to 31 and RS between 0 to 31.
```assembly
SUB RD, RS;
```
* INC & DEC : <br/>
increment / decrement the contents of a register by one and RD is 0 to 31.
```assembly
INC RD;
DEC RD;
```
Input mode with pull-up :
```assembly
LDI R20, 0x0; //R20 = 00000000
OUT DDRB, R20; //DDRB = R20
LDI R20, 0xFF; //R20 = 11111111
OUT DDRD, R20; //DDRD = R20
OUT PORTB, R20; //pull-up enabled
IN R20, PINB; //R20 = PINB
OUT PORTD, R20; //PORTD = R20
```
You are required to display number digits on two 7-segment LED using an AVR `ATmega328P` microcontroller. The digits to be displayed are from 0 through 99. Each digit is displayed for a short period of time. The digits are displayed indefinitely using a loop.


#### [Lab10 : Assembly Program Simulation](https://github.com/KoKoLates/Microcontroller/tree/main/Lab10_AVR_Assembly_Program_Simulation)
You will gain familiarity with assembly program tracking and debugging using Atmel Studio.


#### [Lab11 : Eletronic Piano Keyboard With 7 Segment](https://github.com/KoKoLates/Microcontroller/tree/main/Lab11_AVR_Assembly_Electronic_Keyboard)
Use a port as keyboard input, and another port as output to the `7-segment` display. The keyboard is composed of several keys (switches). Connect a switch to a pin of the input port. Connect the pins of the output port to a 7-segment display. Remember that 7-segment display is composed of 7 LEDs. Place appropriate resistors when wiring the display to the microcontroller to prevent burnout. Write an assembly program that shows the letter of a note when the corresponding key on the keyboard is pressed.<br>
<br>
In this lab, you are required to design and build an electronic piano keyboard. The keyboard should contain 7 keys for musical notes C, D, E, F, G, A, and B. It also contains a 7-segment display. The display is used to show the letter of a note when the corresponding key on the keyboard is pressed.

## Installation
#### [Arduino](https://www.arduino.cc/)
#### [Atmel Studio](https://www.space.ntu.edu.tw/navigate/s/75A6ED71D81449949E2587E865B819E2QQY)
#### [AVR Dudess](https://github.com/KoKoLates/Microcontroller/tree/main/AVR_installation/AVRdudess)

