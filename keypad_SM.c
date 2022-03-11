/*
 * File:   main_keypad_SM.c
 * Author: Ian Sulley and Gabriel Seger
 * 
 * 
 * This program uses a state machine to detect a key pressed and print key to serial monitor
 */

#include "pic24_all.h" //generic header for Pic24H family */         
#include "lcd4bit_lib.h" // include this lcd library
#include "stdio.h"
#include "string.h"

// Define row pins
#define R0 (_RB15)
#define R1 (_RB12)
#define R2 (_RB4)
#define R3 (_RB2)

// Define column pins
#define C0 (_LATB0)
#define C1 (_LATB1)
#define C2 (_LATB3)
// Value to check if any key is pressed
#define KP() (!R0 || !R1 || !R2 || !R3)

/**display constants for Sparkfun serial LCD display*/
#define CMD 0XFE  /**put display in command mode*/
#define CLS 0X01  /**clear dispaly*/

#define ENTER '#'
#define CLR '*'
// Define State Machine period to 1562 timer ticks of 6.4us
#define period 1562

uint8_t keypad_auth = 0;
char *PASSWORD = "1001#";

volatile uint8_t t2flag = 0;  //timer flag to synchronize state machine
char input_password[5];    /**password character array used to store user input*/
    

// Lookup table for keypad
char keypad_table[4][3] = 
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

void _ISR _T2Interrupt(void){
    t2flag = 1;
    _T2IF = 0; //set the flag bit to 0
}

void configTimer2(void) {
    T2CON = 0x0030; //TMR2 off, FCY clk, prescale 1:256
    PR2 = period; //delay = PWM_PERIOD
    TMR2 = 0x0000; //clear the timer
    _T2IF = 0; //clear interrupt flag initially
}

void config_keypad(void) {
	AD1PCFGL = 0xFFFF;  //Using all digital I/O
    _TRISB15 = 1; _TRISB2 = 1; _TRISB4 = 1; _TRISB12 = 1; // Pin 26,6,11,23 inputs
    _CN6PUE = 1; _CN11PUE = 1; _CN1PUE = 1; _CN14PUE = 1; // Enable pull-up resistor on pins 6,26,11,23
	_TRISB0 = 0; _TRISB1 = 0; _TRISB3 = 0; //Pin 4,5,7 outputs
}
uint8_t get_row(void) {  //return the row of the key pressed
    //uint8_t row;
    if(!R0){
        return 0;
    }else if(!R1){
        return 1;
    }else if(!R2){
        return 2;
    }else {
        return 3;
    }
}
// Function to print key	
void print_key(uint8_t row, uint8_t col) { 
    char key = keypad_table[row][col];
    outStringLCD("Key Pressed:  ");
    outChar(key); 
    outChar('\n'); //new line
    outChar('\r'); //return  
} 

void reset_pw_capture(void){
    input_password[0] = '\0'; /**initializes password character array used to store user input*/
    writeLCD(0xC0, 0, 0, 1);
    outStringLCD("PW:                ");
}
void updateAuth(void) {
    writeLCD(0xC0, 0, 0, 1);
    outStringLCD("PW READ: ");
    //password[strlen(password)-1] = '\0'; 
    outStringLCD(input_password);
    
    if (strcmp(input_password, PASSWORD) == 0) {
        keypad_auth = 1;
    } else {
        keypad_auth = 0;
    }
    DELAY_MS(3000);
    reset_pw_capture();
}

// Declare global state variable and states
enum SM_states {S_C0, S_C1, S_C2, P, WR} state;
void SM_fct(void) {
/* Inputs: KP()
*  Outputs: C0, C1, C2
*  Variables: col, row - col needs to be static because 
*  it is used as a transition condition*/
    uint8_t rw; // local row  
    static uint8_t col;  //static column variable - default initialization is 0 on first call
	switch (state) { //transitions
	    case S_C0:
	      if (KP()) {
			  state = P;
			  col = 0;  //Mealy output action
		  } else  {
			  state = S_C1;
		  } break;
		case S_C1:
		   if (KP()) {
			  state = P;
			  col = 1;  //Mealy output action
		  } else  {
			  state = S_C2;
		  } break;
		case S_C2:
		   if (KP()) {
			  state = P;
			  col = 2;  //Mealy output action
		  } else  {
			  state = S_C0;
		  } break;
		case P:
		  state = WR;
		  break;
		case WR:
		  if (KP()) {state = WR; }
		  if (!KP() && (col == 0)) { state = S_C1;}
		  if (!KP() && (col == 1)) { state = S_C2;}
		  if (!KP() && (col == 2)) { state = S_C0;}
		  break;
		  default:
		  state = S_C0;
	}
	switch (state) { //outputs
	    case S_C0:
		   C0=0; C1=1; C2=1;
		break;
		case S_C1:
		   C0=1; C1=0; C2=1;
		break;
		case S_C2:
		   C0=1; C1=1; C2=0;
		break;	 
		case P:
		   rw = get_row();
           strncat(input_password,&keypad_table[rw][col],1);
           writeLCD(0xC4, 0, 0, 1);
           outStringLCD(input_password);
           if(keypad_table[rw][col] == ENTER){
               updateAuth();
           }
		break;
		case WR:
		break;
		default:
		break;
	}
}

void initKeypad(){
    configClock();
    configTimer2();
    T2CONbits.TON =1;
    _T2IE = 1;
    state = S_C0;  /**set initial state*/
    reset_pw_capture();
}

uint8_t getAuth(){
    return keypad_auth;
}

void keypad_syncSM(void){    
    SM_fct();
    while(!t2flag);
    t2flag = 0;    
}