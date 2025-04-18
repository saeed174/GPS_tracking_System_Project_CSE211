#include "UART.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include <stdio.h>

void UART0_Init(void)
{
    SYSCTL_RCGCUART_R |= 0x01;
    while((SYSCTL_PRUART_R & 0x01) == 0);

    SYSCTL_RCGCGPIO_R |= 0x01;
    while((SYSCTL_PRGPIO_R & 0x01) == 0);

    UART0_CTL_R &= ~0x01;
    UART0_IBRD_R = 104;     // recalculate according to the divider
    UART0_FBRD_R = 11;     // recalculate according to the divider
    UART0_LCRH_R = 0x70;
    UART0_CTL_R |= 0x301;

    GPIO_PORTA_AFSEL_R |= 0x03;
    GPIO_PORTA_PCTL_R |= (GPIO_PORTA_PCTL_R & ~0x000000FF) | 0x00000011;
    GPIO_PORTA_DEN_R |= 0x03;
}

void UART0_SendChar(char c)
{
    while ((UART0_FR_R & 0x20) != 0);  // check if the transmit FIFO is full
    UART0_DR_R = c;
}

void UART0_SendString(const char* str)
{
    while (*str)
    {
        UART0_SendChar(*str++);
    }
}

uint8_t UART0_ReceiveChar(void)
{
    while ((UART0_FR_R & 0x10) != 0);  // check if the receive FIFO is empty
    return (uint8_t)(UART0_DR_R & 0xFF);
}

void UART5_Init(void)
{
    SYSCTL_RCGCUART_R |= 0x20;
    while((SYSCTL_PRUART_R & 0x20) == 0);

    SYSCTL_RCGCGPIO_R |= 0x10;
    while((SYSCTL_PRGPIO_R & 0x10) == 0);

    UART5_CTL_R &= ~0x01;
    UART5_IBRD_R = 104;     // recalculate according to the divider
    UART5_FBRD_R = 11;     // recalculate according to the divider
    UART5_LCRH_R = 0x70;
    UART5_CTL_R |= 0x301;

    GPIO_PORTE_AFSEL_R |= 0x03; 
    GPIO_PORTE_PCTL_R |= (GPIO_PORTE_PCTL_R & ~0x000000FF) | 0x00000011; 
    GPIO_PORTE_DEN_R |= 0x03;
}

void UART5_SendChar(char c)
{
    while ((UART5_FR_R & 0x20) != 0);  // check if the transmit FIFO is full
    UART5_DR_R = c;
}

void UART5_SendString(const char* str)
{
    while (*str)
    {
        UART5_SendChar(*str++);
    }
}

uint8_t UART5_ReceiveChar(void)
{
    while ((UART5_FR_R & 0x10) != 0);  // check if the receive FIFO is empty
    return (uint8_t)(UART5_DR_R & 0xFF);
}
