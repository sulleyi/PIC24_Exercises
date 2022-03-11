/* 
 * File: main_Proj4.c   
 * Author: Ian Sulley & Gabe Seger
 * Date: 03/07/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

#include "pic24_all.h"
#include "lcd4bit_lib.h"
#include "keypad_SM.h"
#include "stdio.h"
#include "string.h"

#define BUZZER (_LATA1)
#define DETECTION (_LATB10 == 1)

/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
uint8_t AUTH = 0;

uint8_t centerMessage(uint8_t len){
    uint8_t offset = ((float)(16 - len))/ 2.0;
    return offset;
}


void printLCD(char *line1){
       
    uint8_t len1= strlen(line1);
   
    uint8_t offset1=centerMessage(len1);
      
    writeLCD(0x80+offset1, 0, 0, 1);
    outStringLCD(line1); //Write string 'Hello there!'
}

enum SM1_STATES { SM1_Reset, SM1_Active, SM1_Alarm, SM1_Override} SM1_STATE;

void main_Tickfct(void) { 
    char *line1;
    
   switch(SM1_STATE) { 
      case SM1_Reset:
         if (1) {
            SM1_STATE = SM1_Active;
         }
         break;
      case SM1_Active:
         if (DETECTION & !AUTH) {
            SM1_STATE = SM1_Alarm;
         }
         else if((DETECTION || !DETECTION) && AUTH){
            SM1_STATE = SM1_Override;
         }
         break;
      case SM1_Alarm:
         if (DETECTION && !AUTH) {
            SM1_STATE = SM1_Alarm;
         }
         else if (DETECTION && AUTH) {
            SM1_STATE = SM1_Override;
         }
         else if (!DETECTION && !AUTH){
            SM1_STATE = SM1_Active;
         }
         break;
      case SM1_Override:
         if (!AUTH) {
            SM1_STATE = SM1_Active;
         }
         else if (AUTH) {
            SM1_STATE = SM1_Override;
         }
         else {
            SM1_STATE = SM1_Override;
         }
         break;
      default:
         SM1_STATE = SM1_Reset;
         break;
   }
   switch(SM1_STATE) { 
      case SM1_Reset:
         break;
      case SM1_Active:
          BUZZER = 0;
          line1="  Active  ";
          printLCD(line1);         
         break;
      case SM1_Alarm:
          BUZZER = 1;
          line1="Alarm!";
          printLCD(line1); 
          break;
      case SM1_Override:
          BUZZER = 0;
		 line1="Override";
         printLCD(line1);
         break;
   }
}

/********** MAIN PROGRAM ********************************/
int main(void) {
    configClock();
    config_keypad();  //Set up RB pins connected to keypad
    configControlLCD(); // configures the RS, RW and E control lines as outputs and initializes them low
    initLCD();// clears the screen
    initKeypad();
    
    CONFIG_RA1_AS_OUTPUT();
    CONFIG_RB10_AS_DIG_INPUT();
    
    SM1_STATE = SM1_Reset;
    //outString("Keypad Demo \n \r");
    T2CONbits.TON = 1;  // Turn on timer
	_T2IE = 1; //Enable Timer 2 interrupts, keypad
    // Local variable for column 
    while(1){
          main_Tickfct();
          keypad_syncSM();
          AUTH = getAuth();
    }
}
