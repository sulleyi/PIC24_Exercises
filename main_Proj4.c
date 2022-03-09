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

#define BUZZER _LATB2
#define DETECTION _LATB14
#define ACTIVE _LATB13


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
uint8_t AUTH = 0;

char *PASSWORD = "1001#";

uint8_t centerMessage(uint8_t len){
    uint8_t offset = ((float)(16 - len))/ 2.0;
    return offset;
}


void printLCD(char *line1, char *line2){
       
    uint8_t len1= strlen(line1);
    uint8_t len2= strlen(line2);
    uint8_t offset1=centerMessage(len1);
    uint8_t offset2=centerMessage(len2); 
    
    writeLCD(0x80+offset1, 0, 0, 1);
    outStringLCD(line1); //Write string 'Hello there!'

    writeLCD(0xC0+offset2, 0, 0, 1); //Write command to position cursor at 0x40
    outStringLCD(line2);//Write string 'Enjoy LCD Demo'
}

enum SM1_STATES { SM1_Reset, SM1_Active, SM1_Alarm, SM1_Override} SM1_STATE;

void Tickfct(void) { 
    char *line1;
    char *line2;
    
   switch(SM1_STATE) { 
      case SM1_Reset:
         if (1) {
            SM1_STATE = SM1_Active;
         }
         break;
      case SM1_Active:
         if (DETECTION && !AUTH) {
            SM1_STATE = SM1_Alarm;
         }
         else if (!DETECTION && !AUTH) {
            SM1_STATE = SM1_Active;
         }
         else if(DETECTION && AUTH){
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
         if (!DETECTION && AUTH) {
            SM1_STATE = SM1_Reset;
         }
         else if (DETECTION && AUTH) {
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
          BUZZER = 0;
          line1="Initializing";
          printLCD(line1, "");
         break;
      case SM1_Active:
         //DISPLAY: "DISARMED"
          BUZZER = 0;
          line1="No Detection";
          line2="No Authorization";
          printLCD(line1, line2);         
         break;
      case SM1_Alarm:
          BUZZER = 1;
          line1="Detection!";
          line2="No Authorization";
          printLCD(line1, line2);         
      case SM1_Override:
         BUZZER = 0; //Activate Buzzer
		 line1="Detection!";
         line2="Authorized";
         printLCD(line1, line2);
         break;
   }
}

/********** MAIN PROGRAM ********************************/
int main(void) {
    
    char *enteredPassword; 
    
    configClock();
    config_keypad();  //Set up RB pins connected to keypad
    configControlLCD(); // configures the RS, RW and E control lines as outputs and initializes them low
    initLCD();// clears the screen
    CONFIG_RA1_AS_DIG_OUTPUT(); //Sets pin 3 to digital output, used for buzzer
    
    //outString("Keypad Demo \n \r");
    T2CONbits.TON = 1;  // Turn on timer
	_T2IE = 1; //Enable Timer 2 interrupts, keypad
    // Local variable for column 
    while(1){
        enteredPassword = syncSM();
        if(enteredPassword == PASSWORD){
            AUTH = 1;
        }
        else{
            AUTH = 0;
        }
    }
}
