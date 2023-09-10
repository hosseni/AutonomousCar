/*
 * SYSTICK_interface.h
 *
 *  Created on: 24/8/2023
 *      Author: HOSSENI
 */

#ifndef INC_MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define INC_MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"


typedef enum
{
    Sys_Clock,
    Sys_Clock_div_4
}eSys_clock_t;

typedef enum
{
    Interrupt_Diable,
    Interrupt_Enable

}eInterrupt_state_t;

typedef enum
{
    Systick_Disable,
    Systick_Enable

}eOperation_Mode_t;

typedef struct
{
    eSys_clock_t sys_clock;
    eInterrupt_state_t intterrupt_state;
    eOperation_Mode_t op_mode;
}SYSTIC_ConfigType;


void SYSTICK_Init (const SYSTIC_ConfigType* ConfigPtr);
void SYSTICK_setBusyWait (uint32 delay_ms);
void SYSTIC_voidSetIntervalPeriodic (uint32 delay_ms, void (* Copy_PF)(void));


#endif /* INC_MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
