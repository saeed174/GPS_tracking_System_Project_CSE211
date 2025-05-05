#include "LCD.h"


void LCD_Init_AB(void)
{
	delay_ms(50);
		
	GPIO_PORTA_Init();
	GPIO_PORTB_Init();

	LCD_SendCommand(LCD_HOME);
	delay_ms(1);

	LCD_SendCommand(FOUR_BIT_MODE);
	delay_ms(1);

	LCD_SendCommand(LCD_DISPLAYON_CURSOROFF);
	delay_ms(1);

	LCD_SendCommand(LCD_CLEAR);
	delay_ms(5);

	LCD_SendCommand(LCD_ENTRYMODE);
	delay_ms(1);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------


void LCD_SendData(uint8_t Data)
{	
	GPIO_WriteHighNibblePortA(Data>>4);
	GPIO_SetPinPortB(RS_PIN, HIGH);
	LCD_SendFallingEdge();
	GPIO_WriteHighNibblePortA(Data);
	LCD_SendFallingEdge();
	
	delay_ms(1);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void LCD_SendCommand (uint8_t Command)
{
	GPIO_WriteHighNibblePortA(Command>>4);
	GPIO_SetPinPortB(RS_PIN, LOW);
	LCD_SendFallingEdge();
	GPIO_WriteHighNibblePortA(Command);
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

void LCD_SetPosition(uint8_t Row, uint8_t Col)
{
	uint8_t Position = LCD_SETCURSOR;

	if(Row == 1)
	{
		Position += Col - 1;
	}

	else if(Row == 2)
	{
		Position += 64 + Col - 1;
	}

	LCD_SendCommand(Position);
	delay_ms(1);
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
	GPIO_SetPinPortB(EN_PIN, HIGH);
	delay_ms(1);
	GPIO_SetPinPortB(EN_PIN, LOW);
	delay_ms(1);
}
