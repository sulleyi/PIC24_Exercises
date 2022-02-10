/* 
 * File:   main_proj7_ultrasonic.c
 * Author: Ian Sulley
 * Date: 02/09/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"
#include "stdio.h"

// #defines for handy constant macros (uppercase by convention)
#define TRIG (_LATB2)  // Trigger Output


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
volatile uint8_t echo_rise; 
volatile uint8_t echo_fall; //True/False flags to keep track of which edge of the echo pulse has occurred. 
//The echo_fall will also communicate from the ISR to the main program that the pulse is complete.

//hold the rising and falling edge timer values captured by the IC1 peripheral
volatile uint16_t rise_time; 
volatile uint16_t fall_time;

    
void configTimer2(){
    
    T2CONbits.TON = 0;  // Turn off Timer 2 
    T2CONbits.TCKPS = 0b10; //prescale 1:64
    PR2 = 0xFFFF; //maximum value
    TMR2 = 0; // init timer to 0
    _T2IF = 0; // init flag to 0
    T2CONbits.TON = 1;  // Turn on Timer 2
}


void configIC1(void){
	T2CONbits.TON=0; //Turn off timer 2
	CONFIG_IC1_TO_RP(RB4_RP);//attach input capture to RB4 (pin 11)
	IC1CONbits.ICTMR = 1;
	IC1CONbits.ICI= 0b00;
	IC1CONbits.ICM= 0b001;
}

/*function will set the pin direction and digital mode for both the Trig(output) function will set the pin direction and digital mode for both the Trig(output)
 * and echo(input) signals.
 */
void configSensor(void){
	CONFIG_RB2_AS_DIG_OUTPUT();
	CONFIG_RB4_AS_DIG_INPUT();
	TRIG = 0;
}


void   _ISR   _IC1Interrupt(void){
	uint16_t T_edge; //Variable to hold edge time
	T_edge = IC1BUF; //get timer value of edge from IC1 Buffer
	_IC1IF = 0;//clear interrupt flag

	switch(echo_rise){
		
		case 1:
			rise_time = T_edge;
			echo_rise = 0;
			break;

		case 0:
			fall_time = T_edge;
			echo_fall = 1;
			break;
	}
}

float calcDistance(float echo_duration){
	//Distance in centimeters = echo_duration(μs)/58
	return echo_duration / 58;
}
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */
float distance;
float echo_duration;

/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
	configUART1(230400);
	configIC1();
	configTimer2();
	configSensor();

/* Initialize ports and other one-time code */
TRIG = 0;
echo_rise = 1;
echo_fall = 0;
printf("\e[1;1H\e[2J");//Write a null-terminated string to the serial port. 
_IC1IE = 1;
T2CONbits.TON = 1;

    
/* Main program loop */
	while (1) {	
		TRIG = 1;
		DELAY_US(10);
		TRIG = 0;
		echo_rise = 1;
		while(!echo_fall){
		}
		echo_duration = fall_time - rise_time; //in Tcks
		echo_duration = echo_duration *1.6;
		distance = calcDistance(echo_duration);
		printf("\e[1;1H\e[2J");//Write a null-terminated string to the serial port. 
		printf("Distance:  %3.2f  cm\n\r", (double) distance);	//print to serial
		echo_fall = 0;
		DELAY_US(50);
		}
return 0;
} 
