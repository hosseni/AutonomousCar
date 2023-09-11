/******************************************
 * SCHEDULAR.c
 *
 *  Created on: 9/8/2023
 *      Author: HOSSENI GAMAL
 ******************************************/

#include "Inc/SERVICES/SCHEDULAR/Schedular_interface.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"

static TASK_TCB_t  TASKS[NUM_OF_TASKS];
static uint16 Ticks;

static void Run_Tasks (void)
{
    uint8 i = 0;
    for (i = 0 ; i < NUM_OF_TASKS ; i++)
    {
        if (TASKS [i].Delay  == 0)
        {
            /*call [i] task */
            TASKS[i].Copy_PF();
            TASKS[i].Delay = TASKS[i].periodicty -1;
        }
        else
        {
            TASKS[i].Delay --;
        }
    }
    Ticks++;
}

void tasks_scheduler (void)
{
    /*SysTick to be 1 msesc with interval */
    SYSTIC_voidSetIntervalPeriodic (35, Run_Tasks);
}

void create_task (uint8 Priotity, uint16 periodicity , void (*Copy_PF)(void), uint16 Delay)
{
    TASKS[Priotity].periodicty = periodicity;
    TASKS[Priotity].Copy_PF    = Copy_PF;
    TASKS[Priotity].Delay = Delay;
}
