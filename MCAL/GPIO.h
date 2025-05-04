#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "BIT_MATH.h"

#define RED_LED     0x02
#define BLUE_LED    0x04
#define GREEN_LED   0x08

#define SWITCH_1    0x10
#define SWITCH_2    0x01

#define PRESSED      0
#define NOT_PRESSED  1


void GPIO_PORTA_Init(void);  	
void GPIO_PORTA_NVIC_Init(void); // should call GPIO_PORTA_Init() before it
void GPIO_WritePortA(uint8_t Data);
void GPIO_PORTB_Init(void);  	
void GPIO_WritePortB(uint8_t Data);

void GPIO_PORTC_Init(void);		// Not Implemented
void GPIO_PORTD_Init(void);		// Not Implemented
void GPIO_PORTE_Init(void);  	// Not Implemented
void GPIO_PORTF_Init(void);  


// Implement the functions needed for GPIO
//
//
//
//

//Input RED_LED, BLUE_LED, GREEN_LED
void RGB_LED_SetColor(uint8_t color);
void RGB_LED_Off(void);

//Return the status PRESSED or NOT_PRESSED
uint8_t GPIO_PORTF_Input_SW1(void);
uint8_t GPIO_PORTF_Input_SW2(void);

#endif
