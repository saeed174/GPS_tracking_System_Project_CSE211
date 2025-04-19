#include "GPIO.h"

//void GPIO_PORTA_Init(void)
//void GPIO_PORTB_Init(void)  	
//void GPIO_PORTC_Init(void)		
//void GPIO_PORTD_Init(void)
//void GPIO_PORTE_Init(void)  	

void GPIO_PORTF_Init(void)
{
	// Enable clock for GPIO Port F
    	SYSCTL_RCGCGPIO_R |= 0x20;
    	while ((SYSCTL_PRGPIO_R & 0x20) == 0);
	
	//PortF Initialization Sequence
    	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    	GPIO_PORTF_CR_R |= 0x0E;
    	GPIO_PORTF_AFSEL_R &= ~0x1F;
    	GPIO_PORTF_AMSEL_R &= ~0x1F;
    	GPIO_PORTF_PCTL_R &= ~0x000FFFFF;
    	GPIO_PORTF_DEN_R |= 0x1F;
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DIR_R &= ~0x11;
}


void RGB_LED_SetColor(uint8_t color)
{
	GPIO_PORTF_DATA_R &= ~0x0E;
	GPIO_PORTF_DATA_R |= color;
}

void RGB_LED_Off()
{
	GPIO_PORTF_DATA_R &= ~0x0E;
}

uint8_t GPIO_PORTF_Input_SW1()
{
	uint8_t sw1_state = (GPIO_PORTF_DATA_R & SWITCH_1) >> 4; // Read PF4
	return sw1_state;
}

uint8_t GPIO_PORTF_Input_SW2()
{
	uint8_t sw2_state = (GPIO_PORTF_DATA_R & SWITCH_2); // Read PF0
    	return sw2_state;
}
