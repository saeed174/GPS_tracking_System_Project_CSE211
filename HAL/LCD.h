#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <stdint.h>
#include "GPIO.h"
#include "systick.h"


#define FOUR_BIT_MODE 	0x28

#define RS_PIN 	0
#define RW_PIN 	1 //Shorted to GND	"No Read operations"
#define EN_PIN 	2

//D4 	-> A4
//D5 	-> A5
//D6 	-> A6
//D7 	-> A7

#define LCD_DISPLAYON_CURSOROFF       0x0C                   
#define LCD_DISPLAYOFF_CURSOROFF      0x08
#define LCD_CLEAR                     0x01          
#define LCD_ENTRYMODE                 0x06          
#define LCD_HOME                      0x02
#define LCD_SETCURSOR				  0x80
    


void LCD_Init_AB(void); // This LCD initialization function initializes the LCD to be mounted on Ports A and B
void LCD_SendData(uint8_t Data);
void LCD_SendCommand(uint8_t Commend);
void LCD_SendString(const uint8_t *String);
void LCD_ClearScreen(void);
void LCD_SetPosition(uint8_t Row, uint8_t Col);


void LCD_SendFallingEdge(void);

#endif
