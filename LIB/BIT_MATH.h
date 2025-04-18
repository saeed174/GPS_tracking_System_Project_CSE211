/***************************************************/
/********* Author    : Saeed Nabawy ********/
/********* DATA      : 1 Feb 2025  ********/
/********* Version   : 1          ********/
/********* File      : BIT_MATH.h ******/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#include "STD_Types.h"
/**
BIT MATH Functions
*/

#define SET_BIT(REG, bit) REG|= (1 << bit)
#define CLEAR_BIT(REG, bit) REG &= ~(1 << bit)
#define TOGGLE_BIT(REG, bit) REG ^= (1 << bit)
#define GET_BIT(REG, bit) ((REG & (1 << bit)) >> bit)


#endif