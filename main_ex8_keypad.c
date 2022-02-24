/* 
 * File:   
 * Author: 
 * Date:
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"

// #defines for handy constant macros (uppercase by convention)
#define LED (_LATA0)  // Example: LED on microstick, RA0 (pin 2)


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/


    
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */


/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
//  configBasic(HELLO_MSG);  //This can be used instead of the above if connected to terminal	


/* Initialize ports and other one-time code */


    
/* Main program loop */
	while (1) {	
		
		}
return 0;
}