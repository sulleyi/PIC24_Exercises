# Project 2: Servo Motor Control

### ECE-218 EMBEDDED MICROCONTROLLER PROJECTS

Ian Sulley and Joe McDonagh

---

---

# Objectives

The goal of this project is to design, and implement a system that is capable of controlling two servo motors. One motor is a continuous servo, and the other motor is a positional servo. A simple switch will be used to toggle control back and forth between each motor, while a variable resistor (a potentiometer) will be used to control the speed/position of each motor respectively. When the switch is flipped to toggle control between motors the previous motor that was being controlled will remain stationary in its final position until the user decides to move it again. An additional feature that was added to this system is an LCD display which allows the user to see which motor is currently being controlled by the potentiometer. 

---

### Peripherals
 
The servo motor control system required the use of many of the **PIC24HJ128GP502** peripherals, including timers, interrupts, output compare, and ADC. All of these aside from the ADC were needed for pulse width modulation motor control. The ADC was required to read the analog value from the potentiometer that was converted to a discrete value corresponding to a pulse width. 

---

## Software

The following sections outline the main components of the C code that controls the pulse width modulation for the two servo motor control signals, as well as the user input control.

### Libraries

This project uses both the **`pic24_all`** and **`lcd4bit_lib`** libraries to control the hardware components of the project. 

```c
#include "pic24_all.h"
#include "lcd4bit_lib.h"
```

`**lcd4bit_lib**` provides the functions `configControlLCD(void)`, `initLCD(void)`, `writeLCD(int, int, int, int)`, and `outStringLCD(char*[])` which provide the necessary functionality to  configure and write to the LCD display. Likewise, **`pic24_all`** provides the functionality required for the C program to interface with the **PIC24HJ128GP502**. 

### Setup / Initialization

 The `#define` compiler directive was used to set the pin assignments for the switch and potentiometer hardware, as well as to define constants useful for motor control.

```c
// #defines for handy constant macros (uppercase by convention)
#define SWITCH (_RA4)
#define POT (_RA1)

#define PWM_PERIOD 3125
#define P_CONT_MIN 203
#define P_CONT_MAX 265
#define P_POS_MIN 117
#define P_POS_MAX 351
```

Two global variables `pwm_pos` and `pwm_cont` hold the pulse width values for the positional and continuous servo motors respectively.

```c
uint16_t pwm_pos; // PWM for positional servo
uint16_t pwm_cont; // PWM for continuous servo

```

### Global Functions

Many of the functions are merely wrappers for configuring various peripherals and I/O. `configIO()` configures the pins for the potentiometer, switch, and two motors. `configOC2()` and `configOC1()` configure the output compare modules to control the pulse width for each motor, while `configTimer2()` also configures the required timer. the interrupt service routine on timer 2 updates the output compare registers with the new values of `pwm_pos` and `pwm_cont` every time the interrupt flag is raised.  

```c
float scale(float reading, uint16_t min, uint16_t max);
void configIO(void);
void configOC2(void);
void configOC1(void);
void   _ISR   _T2Interrupt(void);
void configTimer2(void);

```

the `scale()` function allows for ADC input reading of the potentiometer to be converted to an appropriate pulse width value within the operating range of the two servo motors being controlled. 

```c
float scale(float reading, uint16_t min, uint16_t max){
    float readRatio = ( (float) reading *  3.3) / 1023;
    uint16_t ServoDiff = max - min; // calculates difference in servo
    float readRatio_ServoDiff = readRatio * ServoDiff;
    return readRatio_ServoDiff + min;
}
```

### Main Loop

The Behavior of the servo-motor control system was modeled by a single switch-case statement inside the main loop. the variable SWITCH is the state of the hardware switch. case 0 corresponds with control of the continuous servo motor, and case 1 corresponds with control of the standard positional servo motor. In each case the name of the motor, either “Continuous” or “Positional” is printed to the LCD display. When the continuous motor is being controlled the pulse width modulation value of the positional motor is held at its last stored value. When the positional servo is being controlled the continuous motor is stopped.

```c
/* Main program loop */
	while (1) {
        
	    switch(SWITCH){
            case 0: /* Continuous Servo Control*/
                writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
                outStringLCD("Continuous");  
             
                pwm_cont = scale(convertADC1(), P_CONT_MIN, P_CONT_MAX);
                break; 
            case 1: /*Standard Servo Control*/
                pwm_cont = 0;

                writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
                outStringLCD("Positional");
               
                pwm_pos= scale(convertADC1(), P_POS_MIN, P_POS_MAX);             
                break;
	    }
	}
```

---

# Results and Discussion

### Observed Behavior

This system which was described in detail in the beginning of this report in the **Objectives** section was able to be implemented, and is fully functional performing all the tasks that it was designed to. Control over the positional, and continuous servo motors is able to be toggled back and forth from one another using the switch, while the position/speed of each motor is controlled by tuning the potentiometer, i.e the potentiometer. When the potentiometer is tuned the continuous servo motor is capable of changing speeds, and direction. When the switch is flipped to gain control over the positional servo, the continuous servo remains stationary until the user decides to adjust it again. In addition to being able to successfully toggle control over each servo motor, the LCD was also able to output the current motor that is under the users control when the switch was flipped. Overall the final system preformed exactly how it was intended to preform, and as a bonus the LCD display was able to be integrated seamlessly.      

### Code Size (Memory Use)

| Total Data | Percetnage (%) | 8,192 (0x2000) Total bytes |
| ---------- | -------------- | -------------------------- |
| Data Used  | 4%             | 350 bytes                  |
| Data Free  | 96%            | 7,842 bytes                |

| Total Program | Percentage (%) | 43,776 (0xAB00) Total Words |
| ------------- | -------------- | --------------------------- |
| Program Used  | 18%            | 7,837 words                 |
| Program Free  | 82%            | 35,939                      |

### Debugging

We ran into a few perplexing issues while debugging our system, which all eventually led back to the same culprit. Our LCD screen appeared to behave erratically, displaying the correct value the majority of the time, which suddenly displayed random characters or no values at all. Additionally, we struggled to get the positional motor to maintain its previous position when control was switched to the continuous motor. The issue did not appear to be related to our code, and using the debugger we consistently saw the values we were expecting for each variable. Finally, when attempting to de-bounce the switch in hardware, we identified that the ground of the batter pack was not connected to the ground the pic24 controller. Unifying the ground resolved all of the persisting issues.

---

## Conclusion

Overall this project design was able to be implemented seamlessly in software, and then integrated with hardware to form the fully functional system. This system is of great significance due to the numerous real-world applications that it could be applied to. Two of the most important aspects of this system that make it so significant is being able to toggle control between each motor with a simple switch, and then being able to control the position/speed of that motor by tuning a potentiometer. The toggle between controls over each motor was able to be accomplished through the comparison of inputs using if statements within the software, and being able to map desired outputs to specific PWM pins. Furthermore, the equations used for scaling the analog potentiometer readings to pulse width modulated (PWM) signals were of great importance as they allowed the system to relate an input reading to a PWM output even though they had different ranges of values, and different units. The equation used for this scaling process is shown in the appendix labeled under **Appendix Figure #1: Scaling Function.** The application of this system can be seen in many products today such as vending machines, arcade claw games, and many other devices that would require motors to move to a particular location based on an input from a user. 

### Challenges

the primary challenge of this project was managing the increasing complexity that came with using many of the **PIC24HJ128GP502** pins, as well as peripherals. The hardware requirements necessitated organized circuits in order to speed up debugging and reduce the likelihood of breaking hardware. Additionally, the code controlling the micro-controller had to remain organized in order to ensure the various peripherals were functioning desirably. The pulse width sent to the motor relied on the output compare peripheral, which relied on the interrupt, which relied on the timer. If any of these peripherals were configured incorrectly, the system would either not work, or worse, potentially damage the servo and/or **PIC24HJ128GP502** hardware.
