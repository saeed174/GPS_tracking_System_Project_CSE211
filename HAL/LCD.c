#include "LCD.h"


void LCD_Init_AB(void)
{
	delay_ms(50);
		
	GPIO_PORTA_Init();
	GPIO_PORTB_Init();
		
		
	LCD_SendCommand(LCD_HOME);
	delay_ms(1);
		
	LCD_SendCommand(EIGHT_BIT_MODE);
	delay_ms(1);
		
	LCD_SendCommand(LCD_DISPLAYON_CURSOROFF);
	delay_ms(1);
		
	LCD_ClearScreen();
		
	LCD_SendCommand(LCD_ENTRYMODE);
	delay_ms(1);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------


void LCD_DisplayShutdown(void)
{
	LCD_ClearScreen();
	LCD_SendCommand(LCD_DISPLAYOFF_CURSOROFF);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------


void LCD_SendData(uint8_t Data)
{	
	GPIO_WritePortA(Data);
	GPIO_WritePortB(SEND_DATA);
	LCD_SendFallingEdge();
	
	delay_ms(1);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void LCD_SendCommand (uint8_t Command)
{
	GPIO_WritePortA(Command);
	GPIO_WritePortB(SEND_COMMAND);
	LCD_SendFallingEdge();

	delay_ms(1);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void LCD_SendString(const uint8_t *String)
{
	uint8_t LOC_Iterator = 0;

	while(String[LOC_Iterator] != '\0')
	{
		LCD_SendData(String[LOC_Iterator]);
		LOC_Iterator++;
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------


void LCD_ClearScreen(void)
{
	LCD_SendCommand(LCD_CLEAR);
	delay_ms(10);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------


void LCD_SendFallingEdge(void)
{
	GPIO_WritePortB 	(EN_HIGH_SIGNAL);
	delay_ms(1);
	GPIO_WritePortB   	(EN_LOW_SIGNAL);
	delay_ms(1);
}
