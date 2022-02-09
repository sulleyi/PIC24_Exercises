/* 
 * File: main_lcd.c  
 * Author: Ian Sulley
 * Date: 02/02/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"
#include "lcd4bit_lib.h"

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
    configControlLCD(); //configures the RS, RW and E control lines as outputs and initializes them low
    initLCD(); // executes the initialization sequence specified in the Hitachi HD44780 LCD controller datasheet, clears the screen and sets the cursor position to upper left (home)
    
    /*
     * writeLCD(uint8_t u8_Cmd, uint8_t u8_DataFlag, uint8_t u8_CheckBusy, uint8_t u8_Send8Bits);
     * 
     * this function writes a command or data to the display. It requires 4 parameters as follows:
     * u8_Cmd: 4-bit value (bits DB3-DB0 of Table 2 in Appendix) to send to LCD
     * u8_DataFlag: 1 for sending data, 0 for sending a command
     * u8_CheckBusy ?0 to use delay between transfers, 1 to check the busy flag
     * u8_Send8Bits ? 0 for sending 4bits only, 1 for sending 8 bits
     */
    
   // outStringLCD(char *psz_s); this function sends out a string to the LCD display
    

/* Initialize ports and other one-time code */
    
    outStringLCD("Hello there!"); //Write string ?Hello there!?
    writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
    outStringLCD("Enjoy LCD Demo");//Write string ?Enjoy LCD Demo?


    
/* Main program loop */
	while (1) {	
		
		}
return 0;
}