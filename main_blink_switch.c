
/* File: main_blink_switch.c
 * Author: C. Traver
 * Date: Dec 7 2018
 * Purpose: Program to blink a LED with the Microstick II board
 * The LED will be attached to Pin 3
 * The Switch will be attached to Pin 6
 */

/*********** COMPILER DIRECTIVES *********/
#include "pic24_all.h"  //Textbook library header file

#define LED1 (_LATA1)   // macro for _LATA1, the port write register bit for RA1 (pin 3).
#define sw (_RB2)
/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
// No variables or functions needed for blinking

/********** MAIN PROGRAM ********************************/
int main(void) {  //main function that blinks LED
  configClock();  //Sets the clock to 40MHz using FRC and PLL
  /* Initialize ports */
  AD1PCFGL = 0x0002; 	//set RA1 (pin3) to digital (others analog)
  _PCFG4= 1; //set RA4 (pin6) to digital
  
  _TRISA1 = 0;  //set RA1 (pin 3) as output
  _TRISB2 = 1;  //set RB2 (pin 6) as input
  LED1 = 0; //sets LED1 output to 0 (off) 
  sw = 0; 
  
  while (1) {    //loop for infinity
  
      if(sw == 1){
            // Delay long enough to see LED blink
          DELAY_MS(250);
          LED1 = !LED1; //Sets LED1 to the negation of its pervious value
      }
  } // end while (1)
  return 0;
}
