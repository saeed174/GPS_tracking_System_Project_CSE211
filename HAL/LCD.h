#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <stdint.h>
#include "GPIO.h"
#include "systick.h"


#define EIGHT_BIT_MODE 	0x38

#define SEND_DATA					  0x01		
#define SEND_COMMAND				  0x00
#define EN_HIGH_SIGNAL				  0x04	
#define EN_LOW_SIGNAL				  0x00	

#define LCD_DISPLAYON_CURSOROFF       0x0C                   
#define LCD_DISPLAYOFF_CURSOROFF      0x08
#define LCD_CLEAR                     0x01          
#define LCD_ENTRYMODE                 0x06          
#define LCD_HOME                      0x02          


void LCD_Init_AB(void); // This LCD initialization function initializes the LCD to be mounted on Ports A and B
void LCD_DisplayShutdown(void);
void LCD_SendData(uint8_t Data);
void LCD_SendCommand(uint8_t Commend);
void LCD_SendString(const uint8_t *String);
void LCD_ClearScreen(void);


void LCD_SendFallingEdge(void);

#endif
