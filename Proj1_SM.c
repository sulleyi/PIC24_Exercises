/*
 * File:   Proj1_SM.c
 * Author: Ian Sulley & Michael Teta
 *
 * Created on January 20, 2022, 6:21 PM
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"
#include <stdio.h>

// #defines for handy constant macros (uppercase by convention)
#define BUZZER (_LATB1)  //RB1 (pin 5)
#define BUTTON (_RB2) // Active low BUTTON attached to RB2 (pin 6)


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

uint8_t currentTemp;// continuously store ADC value from temp sensor
char str[2]; //stores ASCII representation of currentTemp
static const int HOT=80; //Cutoff Temp in degrees F

void numToASCII(uint8_t num){
    /*
     * Uses a global character array str[] of size 2 to hold result
     */
    str[0] =0x30; str[1] = 0x30; //formated ASCII - Initialize the 2 character array elements to 0x30, 0x30 (ASCII for 00)
     
    if(num < 100){
        uint8_t lsd = num%10; //most significant digit (10^2 place)
    
        str[0] = str[0] + (num -lsd)/10;            //10s place '0' + shift
        str[1]= str[1]+ lsd;  //1s place '0' + shift
    }
    else{
        str[0] = 0x45; // E for error
        str[1] = 0x45; // E for error
    }
}

uint8_t adcToF (uint16_t dig){
        //float temp;
		//temp = ((( (float) voltage  - 1034.0)/ 5.50)*1.8)  + 32.0;
        //return temp;
    
    float voltage;
    voltage = (3.3 * dig)/1023.0;
    float mv = voltage * 1000;
    
    uint8_t temp;//t range(0C-50C), v range(760mv-1034mv)
	temp = (uint8_t)((((( (float) mv  - 1034.0)*50.0)/(-274.0))*(1.8))+ 32.0);
    return temp;
}



void initMessage (void){
    outString("\e[1;1H\e[2J");//Write a null-terminated string to the serial port. 
    outString("Initializing...\n\r");//Write a null-terminated string to the serial port. 
}

void configIO (void){
    CONFIG_RB1_AS_OUTPUT();  //BUZZER on RB1 (pin 5)
    CONFIG_RB2_AS_DIG_INPUT(); //pushBUTTON switch on RB2 (pin 6))
    CONFIG_RA1_AS_INPUT(); //temp sensor on RA1 (pin 3))
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

int main(){
    /*
    * MAIN FUNCTIONALITY OUTLINE
    * 
    * RESET
    * "Disarmed: Temp degrees F"
    * PUSHBUTTON -> "ARMED"
    * Sound Alarm @ 80F
    * "Alarm! Press Button to Stop!"
    * PUSHBUTTON -> "Disarmed"
    */
    
    /*local variables*/
    uint16_t voltage; //stores adc value
    
    /* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
    configUART1(230400);  //parameter is the baudrate for serial communication
    configADC1_ManualCH0(RA1_AN, 31, 0); //using pin RA1, a 31 cycle hold time, and 10-bit conversion.
    
    /* Initialize ports and other one-time code */
    configIO();
    SM1_STATE = SM1_SMStart; //Initialize the state machine
    initMessage(); //Initialization
    
   /*Main Loop*/
   while(1){
   
       //uint8_t myNum = 78;
        voltage = convertADC1(); //read voltage from temp sensor
        currentTemp = adcToF(voltage); //convert voltage to temp in F
        
        numToASCII(currentTemp);
	    Tickfct(); // Tick SM
        DELAY_MS(250); //To account for switch bounce
   }
    return 1;
}