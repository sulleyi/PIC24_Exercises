/* 
 * File: main_serial.c
 * Author: Ian Sulley
 * Date: 01/20/2022
 * Purpose:
 * Modified:
 */
/*********** COMPILER DIRECTIVES *********/

// #include for textbook library header files
#include "pic24_all.h"
//#include <stdio.h>

// #defines for handy constant macros (uppercase by convention)
#define LED (_LATA0)  // Example: LED on microstick, RA0 (pin 2)


/*********** GLOBAL VARIABLE AND FUNCTION DEFINITIONS *******/

void init_message (void){
    outString("\e[1;1H\e[2J");//Write a null-terminated string to the serial port. 
    outString("Initializing...\n\r");//Write a null-terminated string to the serial port. 
    outString("Enter 2 character password...\n\r");//Write a null-terminated string to the serial port. 

    //printf("\e[1;1H\e[2J");//Write a null-terminated string to the serial port. 
    //printf("Initializing...\n\r");//Write a null-terminated string to the serial port. 
    //printf("Enter 2 character password...\n\r");//Write a null-terminated string to the serial port. 

}

void readPassword(){
    char password[] = "77"; //initial password
     
    char char0 = inChar();
    outChar(char0); //Write a character to the serial port.
    char char1 = inChar();
    outChar(char1); //Write a character to the serial port.
    
    if(password[0] == char0 && password[1] == char1){
        outString("--PASSED...\n\r");//Write a null-terminated string to the serial port.   
        //printf("--PASSED...\n\r");//Write a null-terminated string to the serial port.   
    }
    else{
      outString("--FAILED...Try again\n\r");//Write a null-terminated string to the serial port.  
      //printf("--FAILED...Try again\n\r");//Write a null-terminated string to the serial port.  
    }
}

void serialTest(){
     /*
          *receives a character from the keyboard and outputs the character to 
          * the terminal screen. Use the variable you declared.
          */ 
        uint8_t keyChar; 

        keyChar = inChar(); //Read a character from the serial port. 
        outChar(keyChar); //Write a character to the serial port.
        outChar('\n'); //Write a character to the serial port.  
        outChar('\r'); //Write a character to the serial port.  

}

/********** MAIN PROGRAM ********************************/
int main ( void )  //main function that....
{ 
/* Define local variables */
   
/* Call configuration routines */
	configClock();  //Sets the clock to 40MHz using FRC and PLL
    configUART1(230400);  //parameter is the baudrate for serial communication

/* Initialize ports and other one-time code */
    init_message();
    
    
/* Main program loop */
	while (1) {	
        //serialTest();
        readPassword();
    }
return 0;
}