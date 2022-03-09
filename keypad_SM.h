/* 
 * File: keypadSM_lib.h
 * Author: Ian Sulley
 * Comments: Created to package keypad functions
 * Revision history: 
 */
#include <stdint.h>
void config_keypad(void);
uint8_t get_row(void);
char print_key(uint8_t row, uint8_t col);
char *syncSM(void);
void initSM(void);
