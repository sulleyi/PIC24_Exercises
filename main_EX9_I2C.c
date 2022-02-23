/* 
 * File: main_EX9_I2C.c 
 * Author: Ian Sulley
 * Date: 02/23/22
 * Purpose: Use I2C to read temperature data
 * Modified: 02/23/22
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/


    
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */


/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
	configI2C1(I2C_CLK_SPEED);
	startI2C1();


/* Initialize ports and other one-time code */


    
/* Main program loop */
	while (1) {	
		
		}
return 0;
}
