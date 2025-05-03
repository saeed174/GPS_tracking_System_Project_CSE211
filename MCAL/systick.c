#include "tm4c123gh6pm.h"
#include "systick.h"
#include "stdint.h"

void SysTick_Init(void){
NVIC_ST_CTRL_R = 0;				
NVIC_ST_RELOAD_R = 0x00FFFFFF;		
NVIC_ST_CURRENT_R = 0;			
NVIC_ST_CTRL_R = 0x00000005;					
}

void delay_us(int count){
NVIC_ST_RELOAD_R = count*80;
NVIC_ST_CURRENT_R = 0;
while((NVIC_ST_CTRL_R&0x10000)==0){}		
}


void delay_ms(int count){
int i ;
for( i = 0; i<(count*1000); i++){
delay_us(1);								
}
}
