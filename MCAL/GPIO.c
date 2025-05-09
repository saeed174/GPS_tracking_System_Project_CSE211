#include "GPIO.h"
#include "microconfig.h"


void GPIO_PORTA_Init(void)
{
	// Enable clock for GPIO Port A
    	SYSCTL_RCGCGPIO_R |= 0x01;
    	while ((SYSCTL_PRGPIO_R & 0x01) == 0);
	
	//PortA Initialization Sequence
    	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
    	GPIO_PORTA_CR_R |= 0xFF;
    	GPIO_PORTA_AFSEL_R &= ~0xFF;
    	GPIO_PORTA_AMSEL_R &= ~0xFF;
    	GPIO_PORTA_PCTL_R &= ~0xFFFFFFFF;
    	GPIO_PORTA_DEN_R |= 0xFF;
		GPIO_PORTA_PUR_R |= 0x00;
		GPIO_PORTA_DIR_R |= 0xFF;
}


void GPIO_WritePortA(uint8_t value)
{
		GPIO_PORTA_DATA_R &= ~0xFF;
		GPIO_PORTA_DATA_R |= value;
}

void GPIO_PORTB_Init(void)
{
	// Enable clock for GPIO Port B
    	SYSCTL_RCGCGPIO_R |= 0x02;
    	while ((SYSCTL_PRGPIO_R & 0x02) == 0);
	
	//PortB Initialization Sequence
    	GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
    	GPIO_PORTB_CR_R |= 0xFF;
    	GPIO_PORTB_AFSEL_R &= ~0xFF;
    	GPIO_PORTB_AMSEL_R &= ~0xFF;
    	GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;
    	GPIO_PORTB_DEN_R |= 0xFF;
			GPIO_PORTB_PUR_R |= 0x00;
			GPIO_PORTB_DIR_R |= 0xFF;
}

void GPIO_WritePortB(uint8_t value)
{
		GPIO_PORTB_DATA_R &= ~0xFF;
		GPIO_PORTB_DATA_R |= value;	
}


 	
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
		GPIO_PORTF_CR_R |= 0x1F;
		GPIO_PORTF_AFSEL_R &= ~0x1F;
		GPIO_PORTF_AMSEL_R &= ~0x1F;
		GPIO_PORTF_PCTL_R &= ~0x000FFFFF;
		GPIO_PORTF_DEN_R |= 0x1F;
		GPIO_PORTF_PUR_R |= 0x11;
		GPIO_PORTF_DIR_R |= 0x0E;
		GPIO_PORTF_DIR_R &= ~0x11;
}

void GPIO_PORTF_NVIC_Init(void)
{
	GPIO_PORTF_ICR_R = 0x10;
	GPIO_PORTF_IM_R = 0x10;
	GPIO_PORTF_IS_R &= ~0x10;
	GPIO_PORTF_IBE_R &= ~0x10;
	GPIO_PORTF_IEV_R &= ~0x10;
	NVIC_EN0_R = (1 << 30);
	NVIC_PRI7_R &= ~0x00FF0000;
	Enable_Interrupts();
}

void GPIO_PORTE_Init(void)
{
    // Enable clock for GPIO Port E
    SYSCTL_RCGCGPIO_R |= 0x10;                  // Enable Port E clock (bit 4)
    while ((SYSCTL_PRGPIO_R & 0x10) == 0);      // Wait until Port E is ready

    // Port E Initialization Sequence
    GPIO_PORTE_AFSEL_R &= ~0x3F;                // Disable alternate functions on PE0-PE5
    GPIO_PORTE_AMSEL_R &= ~0x3F;                // Disable analog mode on PE0-PE5
    GPIO_PORTE_PCTL_R &= ~0xFFFFFFFF;           // Clear PCTL register (PE0-PE5)
    GPIO_PORTE_DEN_R |= 0x3F;                   // Enable digital function on PE0-PE5
    GPIO_PORTE_DIR_R |= 0x3F;                   // Set PE0-PE5 as output (change as needed)
}


void GPIO_WriteHighNibblePortA(uint8_t value)
{
    value <<= 4;

    GPIO_PORTA_DATA_R &= 0x0F;
    GPIO_PORTA_DATA_R |= value;
}


void GPIO_SetPinPortB(uint8_t Pin_number, uint8_t status)
{
	if(status == HIGH)
	{
		SET_BIT(GPIO_PORTB_DATA_R, Pin_number);
	}
	
	else if(status == LOW)
	{
		CLEAR_BIT(GPIO_PORTB_DATA_R, Pin_number);
	}
}

void BUZZ_PortB(uint8_t Pin_number, uint8_t status)
{
	GPIO_SetPinPortB(Pin_number, status);
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
