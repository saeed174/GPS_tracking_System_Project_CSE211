#ifndef MICROCONFIG_H_
#define MICROCONFIG_H_
#include <stdint.h>
#include "BIT_MATH.H"
#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "systick.h"
#include "LCD.h"
#include "UART.h"
#include "GPS.h"
#include "Map.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#define F_CPU 16000000 /* Internal frequency 16 MHz */
#define CSV 1

/* Enable IRQ Interrupts by clearing the I bit in the PRIMASK */
#define Enable_Interrupts()  __asm("CPSIE I")
/* Disable IRQ Interrupts by setting the I bit in the PRIMASK */
#define Disable_Interrupts() __asm("CPSID I")


#endif /* MICROCONFIG_H_ */









