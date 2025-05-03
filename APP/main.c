#include "microconfig.h"



float currentLatitude = 0.0;
float currentLongitude = 0.0;
int nearestLocationIndex = 0;




int main(void)
{
  //Set Core Clock to 80MHZ
  //SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
  
  
  // Gpio init
  GPIO_PORTA_Init();
  //GPIO_PORTB_Init();
  //GPIO_PORTF_Init();
  GPIO_PORTE_Init();

  
  
  // UART init
  UART0_Init();
  UART5_Init();
  
  //systick init
  SysTick_Init();
  
  //LCD
  //LCD_Init_AB();
  //LCD_ClearScreen();
  

// Define variables

/*
// Display initial message on LCD
    LCD_SendString((uint8_t*)"Initializing...");
    delay_ms(1000);


  while(1){
	   // Read GPS Latitude and Longitude
        GPS_read_latitude_longitude(&currentLatitude, &currentLongitude);
		
		 // If GPS data is received, search for the nearest location
        if (GPS_Received_Flag) {
            nearestLocationIndex = search(currentLatitude, currentLongitude);
			
			  // Get the name of the nearest location
               strcpy(nearestLocationName, MAP[nearestLocationIndex].name);

            // Clear the screen and display the nearest location
               LCD_ClearScreen();
               LCD_SendString((uint8_t*)"Nearest Location:");
               delay_ms(500); // Delay for better viewing
               LCD_ClearScreen();
               LCD_SendString((uint8_t*)nearestLocationName);

            // Reset the GPS Received Flag after processing
               GPS_Received_Flag = 0;

            // Wait for some time before checking for the next GPS data
            delay_ms(1000);
        }
		
  }
*/

while(1)
{
    char latStr[20];  // Buffer to hold string version of latitude
    char lonStr[20];  // Buffer to hold string version of longitude

    GPS_read_latitude_longitude(&currentLatitude, &currentLongitude);

    // Convert float to string
    sprintf(latStr, "Lat: %.6f\r\n", currentLatitude);  // 6 decimal places
    sprintf(lonStr, "Lon: %.6f\r\n", currentLongitude);

    // Send string via UART
    UART0_SendString(latStr);
    delay_ms(1000);
    UART0_SendString(lonStr);
		delay_ms(1000);
}


}