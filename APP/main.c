#include "microconfig.h"


char x;
char longt[25];
char latt[25];
float currentlongitude = 0.0f;
float currentlatitude = 0.0f;
char name_nearest_location[50];

//const uint8_t ss[] = "Besm Allah";
const uint8_t ss2[] = "Searching...";

int main(void)
{
	//UART0_Init();
	UART5_Init();
	SysTick_Init();
	LCD_Init_AB();
	//GPIO_PORTB_Init();
	GPIO_PORTF_Init();
	GPIO_PORTF_NVIC_Init();
	
	
  while(1)
  {
		GPS_read_latitude_longitude(&currentlatitude , &currentlongitude);
		//===========================================
		// check your current coordinates
		
		/*sprintf(latt , "%.10f" , currentlatitude);
		sprintf(longt , "%.10f" , currentlongitude);
		UART0_SendString("\r\n===============================\r\n\n");
		UART0_SendString("Lattitude : ");
		UART0_SendString(latt);
		UART0_SendString("\r\n");
		UART0_SendString("longitude : ");
		UART0_SendString(longt);
		UART0_SendString("\r\n\n");
		delay_ms(50);*/
		
		//===========================================
	
		search(currentlatitude , currentlongitude , name_nearest_location);
		//UART0_SendString(name_nearest_location);
  }

}

void GPIOF_Handler(void)
{
	GPIO_PORTF_ICR_R = 0x10;
	
	
	RGB_LED_SetColor(RED_LED);
	BUZZ_PortB(3, ON);
	LCD_ClearScreen();
	LCD_SendString(ss2);
	delay_ms(300);
	RGB_LED_Off();
	BUZZ_PortB(3, OFF);
	LCD_ClearScreen();
	LCD_SendString(name_nearest_location);
}
