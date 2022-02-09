/* 
 * File:   main_t2_blink
 * Author: Ian Sulley
 * Date: 01-26-2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"

// #defines for handy constant macros (uppercase by convention)
#define LED (_LATA0)  // Example: LED on microstick, RA0 (pin 2)


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/ 
void configTimer2(){
    
    T2CONbits.TON = 0;  // Turn off Timer 2 
    T2CONbits.TCKPS = 0b11; //prescale 1:256 
    PR2 = 39061.5; // 0.25s delay
    TMR2 = 0; // init timer to 0
    _T2IF = 0; // init flag to 0
    T2CONbits.TON = 1;  // Turn on Timer 2
    return;
     
}
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */


/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
//  configBasic(HELLO_MSG);  //This can be used instead of the above if connected to terminal	
    configTimer2();

/* Initialize ports and other one-time code */
 _PCFG0 = 1; //Initialize pin RA0 to be digital
 _TRISA0 = 0; //Initialize pin RA0 to be output
 LED = 0; //Initialize pin RA0 output to be 0
    
/* Main program loop */
	while (1) {	
        if(_T2IF){
            LED = !LED;
            _T2IF = 0;
        }	
	}
return 0;
}