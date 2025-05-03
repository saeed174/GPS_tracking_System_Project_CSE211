#ifndef MICROCONFIG_H_
#define MICROCONFIG_H_
#include <stdint.h>
#include "BIT_MATH.H"
#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "systick.h"
//#include "LCD.h"
#include "UART.h"
#include "GPS.h"
//#include "MAP.H"
#include <stdio.h>
#include <string.h>




#define F_CPU 80000000 /* Internal frequency 80 MHz */
#define CSV 1

/* Enable IRQ Interrupts by clearing the I bit in the PRIMASK */
#define Enable_Interrupts()  __asm("CPSIE I")
/* Disable IRQ Interrupts by setting the I bit in the PRIMASK */
#define Disable_Interrupts() __asm("CPSID I")


#endif /* MICROCONFIG_H_ */









