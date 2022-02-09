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

// #defines for handy constant macros (uppercase by convention)
#define LED (_LATA0)  // Example: LED on microstick, RA0 (pin 2)


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/
char str[4];


void numToASCII(float num){
    /*
     * 1. Declare a global character array of size 4 in the main program to hold result, including decimal 
     * point.
     * 2. In the function, define an unsigned 16-bit integer, Nint
     * 3. Initialize the 4 character array elements to 0x30, 0x2E, 0x30, 0x30 (ASCII for 0.00).
     * 4. Multiply the real number by 100 to convert to an integer, Nint.
     * a. use a loop that counts the number of 100?s in Nint (using subtraction) to find the unit digit,
     * incrementing the 0 th place of the character array each time.
     * b. use a loop that counts the number of 10?s in the remaining Nint (using subtraction) to find
     * the tenth?s digit, incrementing in 2 nd place of character array each time.
     * c. the remaining Nint is the hundreths digit, so convert to ASCII by adding it to the 3 rd place of
     * character array.     
     */
    
    
    uint16_t Nint;
    Nint = num*100;
    str[0] =0x30;str[1] = 0x2E; str[2] = 0x30; str[3] = 0x30; //formated ASCII
    
    
    while(Nint > 100){
        Nint = Nint -100;
        str[0]++;
    }
    while(Nint > 10){
        Nint = Nint - 10;
        str[2]++;
    }
    str[3]= str[3]+Nint;  
    
}

float digToVoltage(int dig){
    float voltage;
    voltage = (3.3 * dig)/1023;
    return voltage;
}
   
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Define local variables */
    float f_voltage;
    uint16_t u16_adcValue;

/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
//  configBasic(HELLO_MSG);  //This can be used instead of the above if connected to terminal	

/*
 * two configurations needed to set up pin 3 (RA1) to be analog, and to configure 
 * the ADC for manual conversion using channel 0, 
 * using pin RA1, a 31 cycle hold time, and 10-bit conversion.
 */
    CONFIG_RA1_AS_INPUT();
    //CONFIG_RA1_AS_ANALOG();
    configADC1_ManualCH0(RA1_AN, 31, 0);
     
/* Initialize ports and other one-time code */
   
/* Main program loop */
	while (1) {	
		
        // Use the convertADC1() function to do a conversion and assign it to the u16 variable.
        // Convert the digital value to the voltage it corresponds to.
        // Delay for 100 ms. (arbitrary delay between conversions)
        
        u16_adcValue = convertADC1();
        f_voltage = digToVoltage(u16_adcValue);
        numToASCII(f_voltage);

        DELAY_MS(100);
		}
return 0;
}