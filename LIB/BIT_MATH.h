#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#include <stdint.h>

#define SET_BIT(REG, bit) REG|= (1 << bit)
#define CLEAR_BIT(REG, bit) REG &= ~(1 << bit)
#define TOGGLE_BIT(REG, bit) REG ^= (1 << bit)
#define GET_BIT(REG, bit) ((REG & (1 << bit)) >> bit)

#endif
