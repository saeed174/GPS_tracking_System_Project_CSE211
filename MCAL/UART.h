#ifndef UART0_H
#define UART0_H
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "GPIO.h"

void UART0_Init(void);                                                  // Initialize UART0 ---------> (Should be called in main)
void UART0_SendChar(char c);                                            // Send a character via UART0 ----------> Parameter is a char will be sent
void UART0_SendString(const char* str);                                 // Send a string via UART0
uint8_t UART0_ReceiveChar(void);                                       // Receive a character via UART0

void UART5_Init(void);                                                  // Initialize UART5 ---------> (Should be called in main)
void UART5_SendChar(char c);                                            // Send a character via UART5 ----------> Parameter is a char will be sent
void UART5_SendString(const char* str);                                 // Send a string via UART5
uint8_t UART5_ReceiveChar(void);                                      // Receive a character via UART5

#endif