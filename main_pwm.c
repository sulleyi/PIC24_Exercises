/* 
 * File: main_pwm
 * Author: Ian Sulley
 * Date: 01-26-2022
 * Purpose: 
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"

// #defines for handy constant macros (uppercase by convention)
#define PWM_PERIOD 3125
#define P_MIN 117
#define P_MAX 351

/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
uint16_t pulse_width =0;

void configTimer2(){
    
    T2CONbits.TON = 0;  // Turn off Timer 2 
    T2CONbits.TCKPS = 0b11; //prescale 1:256 
    PR2 = PWM_PERIOD;
    TMR2 = 0; // init timer to 0
    _T2IF = 0; // init flag to 0
    T2CONbits.TON = 1;  // Turn on Timer 2
}

void   _ISR   _T2Interrupt(void){
    OC1RS = pulse_width; // Clear
    _T2IF = 0;
}

void configOC1(void){
    T2CONbits.TON = 0;  // Turn off Timer 2
    CONFIG_OC1_TO_RP(RB1_RP); //Map OC1 to pin RP1 (pin 5)
    
    //Use Timer2 as clock for OC2
    OC1RS = 0; // Clear
    OC1R = 0; // Clear
    
    OC1CONbits.OCTSEL = 0; // output compare module to use Timer 2 as the clock source
    OC1CONbits.OCM = 0b110; // operate in PWM mode with fault pin disabled
}


/********** MAIN PROGRAM ********************************/
int main ( void ) { 
/* Declare local variables */

/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
//  configBasic(HELLO_MSG);  //This can be used instead of the above if connected to terminal	
    configTimer2();
    configOC1();
    _T2IF = 0;
    _T2IE = 1;
    T2CONbits.TON = 1;
    pulse_width = 234;
    DELAY_MS(500);
    
/* Initialize ports and other one-time code */


/* Main program loop */
	while (1) {
        int i;
		for(i = P_MIN; i <= P_MAX; i++){
            pulse_width = i;
            DELAY_MS(50);
        }
        int j;
        for(j=P_MAX; i >= P_MIN; i--){
            pulse_width = i;
            DELAY_MS(50);
        }
	}
return 0;
}