/* 
 * File: main_Proj4.c   
 * Author: Ian Sulley & Gabe Seger
 * Date: 03/07/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

#include "pic24_all.h"
#include "lcd4bit_lib.c"
#include "main_keypad_SM.c"
/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

uint8_t centerMessage(uint8_t len){
    uint8_t offset = ((float)(16 - len))/ 2.0;
    return offset;
}

enum SM1_STATES { SM1_SMStart, SM1_DISARMED, SM1_ARMED, SM1_ALARM} SM1_STATE;
void Tickfct(void) { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_DISARMED;
         }
         break;
      case SM1_DISARMED:
         if (BUTTON) {
            SM1_STATE = SM1_ARMED;
         }
         else if (!BUTTON) {
            SM1_STATE = SM1_DISARMED;
         }
         else {
            SM1_STATE = SM1_DISARMED;
         }
         break;
      case SM1_ARMED:
         if (currentTemp <  HOT) {
            SM1_STATE = SM1_ARMED;
         }
         else if (currentTemp >= HOT) {
            SM1_STATE = SM1_ALARM;
         }
         else {
            SM1_STATE = SM1_ARMED;
         }
         break;
      case SM1_ALARM:
         if (BUTTON) {
            SM1_STATE = SM1_DISARMED;
         }
         else if (!BUTTON) {
            SM1_STATE = SM1_ALARM;
         }
         else {
            SM1_STATE = SM1_ALARM;
         }
         break;
      default:
         SM1_STATE = SM1_DISARMED;
         break;
   }
   switch(SM1_STATE) { 
      case SM1_SMStart:
          BUZZER = 0;
          outString("\e[1;1H\e[2J");//Clear serial display 
          outString("Initializing...\n\r");
         break;
      case SM1_DISARMED:
         //DISPLAY: "DISARMED"
          BUZZER = 0;
          outString("\e[1;1H\e[2J");//Clear serial display 
          outString("DISARMED\n\r");// "Disarmed : Temp degrees F"
          outString(str);
          outString(" degrees F \n\r");
         break;
      case SM1_ARMED:
          BUZZER = 0;
         //DISPLAY: "ARMED"
          outString("\e[1;1H\e[2J");//Clear serial display 
          outString("ARMED\n\r");
         
         break;
      case SM1_ALARM:
         BUZZER = 1; //Activate Buzzer
		 // DISPLAY: "ALARM!"
         outString("\e[1;1H\e[2J");//Clear serial display 
         outString("ALARM! Press Button to Stop\n\r");   //"Alarm! Press Button to Stop!"
         break;
   }
}
    
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */


/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
    	configControlLCD(); //configures the RS, RW and E control lines as outputs and initializes them low
    	initLCD(); // executes the initialization sequence specified in the Hitachi HD44780 LCD controller datasheet, clears the screen and sets the cursor position to upper left (home)
    


/* Initialize ports and other one-time code */


    
/* Main program loop */
	while (1) {	
		
		}
return 0;
}
