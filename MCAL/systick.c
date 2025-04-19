#include "microconfig.h"
#include "systick.h"
void SysTick_Init(void){
NVIC_ST_CTRL_R = 0;				
NVIC_ST_RELOAD_R = 16-1;		
NVIC_ST_CURRENT_R = 0;			
NVIC_ST_CTRL_R = 5;					
}

void delay_us(int count){
int i;
for( i = 0; i<count; i++){
while((NVIC_ST_CTRL_R&0x10000)==0){}		
}
}

void delay_ms(int count){
int i ;
for( i = 0; i<(count*1000); i++){
delay_us(1);								
}
}
