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
#include "lcd4bit_lib.h"

// #defines for handy constant macros (uppercase by convention)
#define SWITCH (_RA4)
#define POT (_RA1)
#define TRIG (_LATB2)  // Trigger Output

#define PWM_PERIOD 3125
#define P_CONT_MIN 203
#define P_CONT_MAX 265

/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
volatile uint8_t echo_rise; 
volatile uint8_t echo_fall; //True/False flags to keep track of which edge of the echo pulse has occurred. 
//The echo_fall will also communicate from the ISR to the main program that the pulse is complete.

//hold the rising and falling edge timer values captured by the IC1 peripheral
volatile uint16_t rise_time; 
volatile uint16_t fall_time;

    
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
    OC1RS = pwm_cont;       //OC2RS register assigned pwm for continuous
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


void configTimer3(){
    
    T3CONbits.TON = 0;  // Turn off Timer 2 
    T3CONbits.TCKPS = 0b10; //prescale 1:64
    PR3 = 0xFFFF; //maximum value
    TMR3 = 0; // init timer to 0
    _T3IF = 0; // init flag to 0
    T3CONbits.TON = 1;  // Turn on Timer 2
}


void configIC1(void){
	T3CONbits.TON=0; //Turn off timer 2
	CONFIG_IC1_TO_RP(RB4_RP);//attach input capture to RB4 (pin 11)
	IC1CONbits.ICTMR = 1; //**TODO** check we are using the correct timer for IC
	IC1CONbits.ICI= 0b00;
	IC1CONbits.ICM= 0b001;
}

/*function will set the pin direction and digital mode for both the Trig(output) function will set the pin direction and digital mode for both the Trig(output)
 * and echo(input) signals.
 */
void configSensor(void){
	CONFIG_RB2_AS_DIG_OUTPUT();
	CONFIG_RB4_AS_DIG_INPUT();
	TRIG = 0;
}


void   _ISR   _IC1Interrupt(void){
	uint16_t T_edge; //Variable to hold edge time
	T_edge = IC1BUF; //get timer value of edge from IC1 Buffer
	_IC1IF = 0;//clear interrupt flag

	switch(echo_rise){
		
		case 1:
			rise_time = T_edge;
			echo_rise = 0;
			break;

		case 0:
			fall_time = T_edge;
			echo_fall = 1;
			break;
	}
}

float calcDistance(float echo_duration){
	//Distance in centimeters = echo_duration(μs)/58
	return echo_duration / 58;
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
	configControlLCD(); //configures the RS, RW and E control lines as outputs and initializes them low
	initLCD(); // executes the initialization sequence specified in the Hitachi HD44780 LCD controller datasheet, clears the screen and sets the cursor position to upper left (home)
	configTimer3();
	configSensor();
	configADC1_ManualCH0(RA1_AN, 31, 0);        // configures ADC 
	_T2IF = 0;
	_T2IE = 1;
	T2CONbits.TON = 1;
	DELAY_MS(500);

    pwm_cont = 234; // setting pwm to midway for cont servo

/* Initialize ports and other one-time code */


    
/* Main program loop */
	while (1) {	
		
		}
return 0;
}
