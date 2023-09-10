#ifndef INC_MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define INC_MCAL_SYSTICK_SYSTICK_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define SYSTICK_BASE  0xE000E010


typedef struct
{
    volatile uint32 STCTRL;
    volatile uint32 STRELOAD;
    volatile uint32 STCURRENT;
}sSYSTICK_type;

#define SYSTICK ((sSYSTICK_type *)SYSTICK_BASE)

#endif /* INC_MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
