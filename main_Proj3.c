/* 
 * File: main_Proj3.c
 * Author: Ian Sulley
 * Date:  02/21/22
 * Purpose: Automatic Cruise Control
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"
#include "lcd4bit_lib.h"

// #defines for handy constant macros (uppercase by convention)
#define POT (_RA1)     // Control Motor Speed
#define TRIG (_LATB2)  // Trigger Output
#define TOGGLE_CRUISE (_RA0)  // Toggle Cruise Control

#define PWM_PERIOD 3125
#define P_CONT_MIN 203
#define P_CONT_MAX 265

#define ADC_MIN 0
#define ADC_MAX 1023

/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
volatile uint8_t echo_rise; 
volatile uint8_t echo_fall; //True/False flags to keep track of which edge of the echo pulse has occurred. 
//The echo_fall will also communicate from the ISR to the main program that the pulse is complete.

//hold the rising and falling edge timer values captured by the IC1 peripheral
volatile uint16_t rise_time; 
volatile uint16_t fall_time;
    
uint16_t pwmCont; // PWM for continuous servo 

void configTimer2(void){
    
    T2CONbits.TON = 0;  // Turn off Timer 2 
    T2CONbits.TCKPS = 0b11; //prescale 1:256 
    PR2 = PWM_PERIOD;
    TMR2 = 0; // init timer to 0
    _T2IF = 0; // init flag to 0
    T2CONbits.TON = 1;  // Turn on Timer 2
}

void   _ISR   _T2Interrupt(void){
    OC1RS = pwmCont;       //OC2RS register assigned pwm for continuous
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
    CONFIG_RA1_AS_ANALOG();//MOTOR CONTRL POTENTIOMETER
    CONFIG_RA0_AS_DIG_INPUT(); // Cruise Control Switch
} 

//USE TIMER 3 for IC
void configTimer3(){
    
    T3CONbits.TON = 0;  // Turn off Timer 3 
    T3CONbits.TCKPS = 0b10; //prescale 1:64
    PR3 = 0xFFFF; //maximum value
    TMR3 = 0; // init timer to 0
    _T3IF = 0; // init flag to 0
    T3CONbits.TON = 1;  // Turn on Timer 2
}

void configIC1(void){
	T3CONbits.TON=0; //Turn off timer 3
	CONFIG_IC1_TO_RP(RB4_RP);//attach input capture to RB4 (pin 11)
	IC1CONbits.ICTMR = 1; // Uses timer 3
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


/* Return  num in ASCII format 000*/
char *numToASCII(uint8_t num, char *str){
    	uint16_t Nint = num;
	str[0] =0x30;str[1] = 0x30; str[2] = 0x30; //formated ASCII
    
	while(Nint > 100){
        	Nint = Nint -100;
        	str[0]++;
    	}
    	while(Nint > 10){
        	Nint = Nint - 10;
        	str[1]++;
    	}
	while(Nint > 0){
		Nint = Nint - 1;
		str[2]++;
	}
	return str;
}

/*TODO make sure this scale works for all uses (both limiting speed & reading potentiometer value*/
float scale(float reading, uint16_t min, uint16_t max){
    float readRatio = ( (float) reading *  3.3) / 1023;
    uint16_t ServoDiff = max - min; // calculates difference in servo
    float readRatio_ServoDiff = readRatio * ServoDiff;
    return readRatio_ServoDiff + min;
}

float scale2(float x, uint16_t x_min, uint16_t x_max, uint16_t y_min, uint16_t  y_max){
	uint16_t output_range = y_max - y_min;
	uint16_t input_range = x_max - x_min;
	
	float y;
	y = (x - x_min) * (float) output_range / (float) input_range + y_min;
	return y;
}

float calcDistance(float echo_duration){
	//Distance in centimeters = echo_duration(us)/58
	return echo_duration / 58;
}

uint8_t limitSpeed(uint8_t maxSpeed, uint8_t distance){
	if(distance > 25){ //if no car ahead, go full speed 
		return maxSpeed;
	}
	else if(15 < distance && distance < 25){ //return a scaled speed to relative to the distance from the car ahead 
		return scale2(distance, 0, 25, 0, maxSpeed); //**TODO** confirm scale function works  
	}
	else if(distance < 15){ //if car ahead is getting too close,STOP
		return 0;
	}
	return 0;
}

void displayDashboard(uint8_t speed, uint8_t distance, char *spdStr, char *distStr){
    writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
    outStringLCD("Speed: ");
    writeLCD(0xCA, 0, 0, 1); //Write command to position cursor at 0x40
    outStringLCD(numToASCII(speed, spdStr));
    writeLCD(0xC0, 0, 0, 1); //Write command to position cursor at 0x40
    outStringLCD("Distance: ");
    writeLCD(0xCA, 0, 0, 1); //Write command to position cursor at 0x40
    outStringLCD(numToASCII(distance, distStr));
}

uint32_t pulseUltrasonic(void){
	TRIG = 1;
	DELAY_US(10);
	TRIG = 0;
	echo_rise = 1;
	while(!echo_fall){
	}
	uint32_t echo_duration = fall_time - rise_time; //in Tcks
	echo_duration = echo_duration *1.6;
	return echo_duration;
}

/********** MAIN PROGRAM ********************************/
int main ( void ){
	/* Declare local variables */
	uint8_t maxSpeed;
	uint8_t currentSpeed;
	uint8_t distance;
	uint32_t echo_duration;
	char *spdStr;
	char *dstStr;

	/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
	configTimer2();
	configIO();
	configOC1();
	configIC1();
	configControlLCD(); //configures the RS, RW and E control lines as outputs and initializes them low
	initLCD(); // initialization LCD: clears the screen and sets the cursor position to upper left (home)
	configTimer3();
	configSensor();
	configADC1_ManualCH0(RA1_AN, 31, 0);        // configures ADC 

	/* Initialize ports and other one-time code */
	outStringLCD("Initializing");
	pwmCont = 234; // setting pwm to midway for cont servo
	_T3IF = 0;
	_T3IE = 1;
	_T2IF = 0;
	_T2IE = 1;
	T2CONbits.TON = 1;
	T3CONbits.TON = 1;
	DELAY_MS(500);
  
	/* Main program loop */
	while (1) {

		/* collect & compute inputs*/
		echo_duration = pulseUltrasonic();
		distance = calcDistance(echo_duration);
		maxSpeed = scale2(convertADC1(), ADC_MIN, ADC_MAX, P_CONT_MIN, P_CONT_MAX);
		currentSpeed = limitSpeed(maxSpeed, distance);

		switch(TOGGLE_CRUISE){
			/* CRUISE CONTROL DE-ACTIVATED*/
			case 0:
                pwmCont = maxSpeed;
				displayDashboard(maxSpeed, distance, spdStr, dstStr);
                break;
                
            /*CRUISE CONTROL ACTIVATED*/
            case 1:
                pwmCont = limitSpeed(maxSpeed, distance);
				displayDashboard(currentSpeed, distance, spdStr, dstStr);
				break;
	    }
	}
	return 0;
}
