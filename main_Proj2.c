/* 
 * File: main_Proj2  
 * Author: Ian Sulley & Joe  McDonaugh
 * Date: 02/03/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files

#include "pic24_all.h"
#include "lcd4bit_lib.h"

// #defines for handy constant macros (uppercase by convention)
#define SWITCH (_RA4)
#define POT (_RA1)

#define PWM_PERIOD 3125
#define P_CONT_MIN 203
#define P_CONT_MAX 265
#define P_POS_MIN 117
#define P_POS_MAX 351
/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

uint16_t pwm_pos; // PWM for positional servo
uint16_t pwm_cont; // PWM for continuous servo 



void configTimer2(void){
    
    T2CONbits.TON = 0;  // Turn off Timer 2 
    T2CONbits.TCKPS = 0b11; //prescale 1:256 
    PR2 = PWM_PERIOD;
    TMR2 = 0; // init timer to 0
    _T2IF = 0; // init flag to 0
    T2CONbits.TON = 1;  // Turn on Timer 2
}

void   _ISR   _T2Interrupt(void){
    OC1RS = pwm_pos;        // OC1RS register assigned pwm for positional
    OC2RS = pwm_cont;       //OC2RS register assigned pwm for continuous
    _T2IF = 0;
}

/*Standard Servo*/
void configOC1(void){
    T2CONbits.TON = 0;  // Turn off Timer 2
    CONFIG_OC1_TO_RP(RB1_RP); //Map OC1 to pin RP1 (pin 5)
    
    //Use Timer2 as clock for OC1
    OC1RS = 0; // Clear
    OC1R = 0; // Clear
    
    OC1CONbits.OCTSEL = 0; // output compare module to use Timer 2 as the clock source
    OC1CONbits.OCM = 0b110; // operate in PWM mode with fault pin disabled
}

/*Continuous Servo*/
void configOC2(void){
    T2CONbits.TON = 0;  // Turn off Timer 2
    CONFIG_OC2_TO_RP(RB2_RP); //Map OC1 to pin RP2 (pin 6)
    
    //Use Timer2 as clock for OC2
    OC2RS = 0; // Clear
    OC2R = 0; // Clear
    
    OC2CONbits.OCTSEL = 0; // output compare module to use Timer 2 as the clock source
    OC2CONbits.OCM = 0b110; // operate in PWM mode with fault pin disabled
}

void configIO(void){
    CONFIG_RA4_AS_DIG_INPUT(); //SWITCH
    CONFIG_RA1_AS_ANALOG();//MOTOR CONTRL POTENTIOMETER
} 

float scale(float reading, uint16_t min, uint16_t max){
    float readRatio = ( (float) reading *  3.3) / 1023;
    uint16_t ServoDiff = max - min; // calculates difference in servo
    float readRatio_ServoDiff = readRatio * ServoDiff;
    return readRatio_ServoDiff + min;
}

/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Declare local variables */ 
  
/* Call configuration routines */
    configClock();  //Sets the clock to 40MHz using FRC and PLL
    configTimer2();
    configIO();
    configOC1();
    configOC2();
    configControlLCD(); //configures the RS, RW and E control lines as outputs and initializes them low
    initLCD(); // executes the initialization sequence specified in the Hitachi HD44780 LCD controller datasheet, clears the screen and sets the cursor position to upper left (home)
    configADC1_ManualCH0(RA1_AN, 31, 0);        // configures ADC 
    _T2IF = 0;
    _T2IE = 1;
    T2CONbits.TON = 1;
    DELAY_MS(500);


    pwm_pos= 156;  // setting pwm to midway for pos servo
    pwm_cont = 234; // setting pwm to midway for cont servo
    
/* Main program loop */
	while (1) {        

        
	    switch(SWITCH){
            /* Continuous Servo Control*/
            case 0:
                writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
                outStringLCD("Continuous");
 
                pwm_cont = scale(convertADC1(), P_CONT_MIN, P_CONT_MAX);
                break;
                
            /*Standard Servo Control*/
            case 1:
                pwm_cont = 0;
                
                writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
                outStringLCD("Positional");
                
                pwm_pos= scale(convertADC1(), P_POS_MIN, P_POS_MAX);
                break;
	    }
	}
    return 0;
}
