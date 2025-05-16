#include "microconfig.h"


char x;
char longt[25];
char latt[25];
float currentlongitude = 0.0f;
float currentlatitude = 0.0f;
char name_nearest_location[50];

const uint8_t ss[] = "Searching...";

int main(void)
{
	UART5_Init();
	SysTick_Init();
	LCD_Init_AB();	//Initialization of Port A & B are already done here
	GPIO_PORTF_Init();
	GPIO_PORTF_NVIC_Init();
	
	
  while(1)
  {
	GPS_read_latitude_longitude(&currentlatitude , &currentlongitude);
	search(currentlatitude , currentlongitude , name_nearest_location);
  }

}

void GPIOF_Handler(void)
{
	GPIO_PORTF_ICR_R = 0x10;
	
	
	RGB_LED_SetColor(RED_LED);
	BUZZ_PortB(3, ON);
	LCD_ClearScreen();
	LCD_SendString(ss);
	
	delay_ms(300);
	RGB_LED_Off();
	BUZZ_PortB(3, OFF);
	LCD_ClearScreen();
	LCD_SendString(name_nearest_location);
}
