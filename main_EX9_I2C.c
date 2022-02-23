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
#include "stdio.h"

#define I2C_CLK_SPEED  100//in kHz
/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

    
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */
uint8_t send_bits;
uint8_t ack_bits;

uint16_t temp;

/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
	configI2C1(I2C_CLK_SPEED); //clock speed in kHZ
	startI2C1();
	configUART1(230400);

/* Initialize ports and other one-time code */
putI2C1(send_bits);
temp = getI2C1(ack_bits);
DELAY_MS(100);

/* Main program loop */
	while (1) {	
		putI2C1(send_bits);
		temp = getI2C1(ack_bits);

		DELAY_MS(100);
		}
return 0;
}
