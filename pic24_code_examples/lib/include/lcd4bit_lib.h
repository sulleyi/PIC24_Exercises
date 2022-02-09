/* 
 * File: lcd4bit_lib.h
 * Author: CT
 * Comments: Created to package LCD functions in library
 * Revision history: 
 */
#include <stdint.h>
//#include "pic24_all.h"
//#include "pic24_chip.h"
void configBusAsOutLCD(void);
void configBusAsInLCD(void);
void outputToBusLCD(uint8_t u8_c);
void configControlLCD(void);
void pulseE(void);
void writeLCD(uint8_t u8_Cmd, uint8_t u8_DataFlag,
              uint8_t u8_CheckBusy, uint8_t u8_Send8Bits);
void initLCD();
void outStringLCD(char *psz_s);

