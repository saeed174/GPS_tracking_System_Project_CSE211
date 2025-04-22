#include <stdint.h>
#include "driverlib/sysctl.h"
//#include ""








int main(void)
{
  //Set Core Clock to 80MHZ
  SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);




  


}
