/**************************************************
 * Schedular_interface.h
 *
 *  Created on: 9/8/2023
 *      Author: HOSSENI GAMAL
 **************************************************/

#ifndef INC_SERVICES_SCHEDULAR_SCHEDULAR_INTERFACE_H_
#define INC_SERVICES_SCHEDULAR_SCHEDULAR_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"

#define NUM_OF_TASKS        3



typedef struct
{
    uint16 periodicty;
    uint16 Delay;
    void (*Copy_PF) (void);
}TASK_TCB_t;


void tasks_scheduler (void);
void create_task (uint8 Priotity, uint16 periodicity , void (*Copy_PF)(void), uint16 Delay);
#endif /* INC_SERVICES_SCHEDULAR_SCHEDULAR_INTERFACE_H_ */
