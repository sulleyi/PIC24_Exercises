/* 
 * File:   main_SM.c
 * Author: 
 * Date: 
 * Purpose: Template for state machine for Exercise 1A
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"

// #defines for handy constants 
#define LED1 (_LATA1)  // Red LED on the Microstick II board. 
#define BUTTON (_RB2) // Active low BUTTON attached to RB2 (pin 6)

/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

enum States {init, R0, P0, R1, P1} state; //define global state variable

void Tickfct () {  //Define state machine
    //local function variables
    
    switch (state) {    //transition switch statement
        case init:  //initialize state
            state = R0;
            break;
        case R0:
            if (BUTTON == 0) {state = P0;}
            else if (BUTTON == 1) {state = R0;}
            break;
        case P0: 
            if (BUTTON == 0) {state = P0;}
            else if (BUTTON = 1) {state = R1;}
            break;
        case R1:
            if (BUTTON == 1) {state = R1;}
            else if (BUTTON == 0) {state = P1;}
            break;
        case P1:
            if(BUTTON == 0) {state = P1;}
            else if (BUTTON == 1) {state = R0;}
            break;
        default:
            state = init;
            break;
    }
    switch (state) {    //output switch statement
        case init:  //Initialize outputs
            LED1 = 0;
            break;
        case R0:
            LED1 = 0;
            break;
        case P0:
            LED1=0;
            break;
        case R1:
            LED1 = 1;
            break;
        case P1:
            LED1 = 1;
            break;
        default:
            LED1 = 0;
            break;
    }   
 }

/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that configures pins, and runs state machine.
{ 
/* Define local variables */

/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
     configADC1_ManualCH0(RA1_AN, 31, 0);
    
/* Initialize ports and other one-time code */
    CONFIG_RA1_AS_OUTPUT();  //LED on RA1 (pin 3)
    CONFIG_RB2_AS_DIG_INPUT(); //pushBUTTON switch on RB2 (pin 6))
    state = init; //Initialize the state machine
/* Main program loop */
	while (1) {	
     //initialize state
	    Tickfct();
        DELAY_MS(10); //To account for switch bounce
		}
	return 0;
}