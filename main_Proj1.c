/* 
 * File: main_Proj1
 * Author: Ian Sulley
 * Date: 01/20/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"

// #defines for handy constant macros (uppercase by convention)
#define LED (_LATA0)  // Example: LED on microstick, RA0 (pin 2)


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

char str[4] = {0x30, 0x2E, 0x30, 0x30};

void numToASCII(uint8_t num){
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
     * c. the remaining Nint is the hundreth?s digit, so convert to ASCII by adding it to the 3 rd place of
     * character array.     
     */
    
    uint16_t Nint;
    Nint = num*100;
    while(Nint > 100){
        Nint = Nint -100;
        str[0]++;
    }
    while(Nint > 10){
        Nint = Nint - 10;
        str[1]++;
    }
    str[3]= str[3]+Nint;   
}

int numToTemp(uint16_t voltage){
    uint8_t temp;
    //TODO conversion
    return  temp;
}
    
/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Define local variables */


/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
//  configBasic(HELLO_MSG);  //This can be used instead of the above if connected to terminal	


/* Initialize ports and other one-time code */

    //PUSHBUTTON
    

    
/* Main program loop */
	while (1) {	
	
        //RESET
        // "Disarmed : Temp degrees F"
        //PUSHBUTTON -> "ARMED"
        //Sound Alarm @ 80F
        //"Alarm! Press Button to Stop!"
        //PUSHBUTTON -> "Disarmed"
        
		}
return 0;
}