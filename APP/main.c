#include <stdint.h>
#include "microconfig.h"
//#include ""
char x;
char longt[25];
char latt[25];
float currentlongitude = 0.0f;
float currentlatitude = 0.0f;
char name_nearest_location[50];


int main(void)
{
	UART0_Init();
	UART5_Init();
	SysTick_Init();
  while(1)
  {
		GPS_read_latitude_longitude(&currentlatitude , &currentlongitude);
		
		//===========================================
		// check your current coordinates
		/*
		sprintf(latt , "%.10f" , currentlatitude);
		sprintf(longt , "%.10f" , currentlongitude);
		UART0_SendString("Lattitude : ");
		UART0_SendString(latt);
		UART0_SendString("\r\n");
		delay_ms(200);
		UART0_SendString("longitude : ");
		UART0_SendString(longt);
		UART0_SendString("\r\n");
		delay_ms(200);
		*/
		//===========================================
		
		search(currentlatitude , currentlongitude , name_nearest_location);
		
		
  }

}
