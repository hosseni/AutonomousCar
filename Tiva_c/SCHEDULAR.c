/******************************************
 * SCHEDULAR.c
 *
 *  Created on: 9/8/2023
 *      Author: HOSSENI GAMAL
 ******************************************
 *  File Description:
 *      This file contains the implementation of a simple task scheduler. It allows tasks to be
 *      executed at specified intervals and provides the functionality to create and manage tasks.
 *      The scheduler uses the SysTick timer for timing and task execution.
 ******************************************/

#include "Inc/SERVICES/SCHEDULAR/Schedular_interface.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"

static TASK_TCB_t  TASKS[NUM_OF_TASKS];
static uint16 Ticks;

/**********************************************************************************
 *  Executes tasks with zero delay and decrements the delay of other tasks.
 *        Called by the SysTick timer.
 ************************************************************************************/
static void Run_Tasks (void)
{
    uint8 i = 0;
    for (i = 0 ; i < NUM_OF_TASKS ; i++)
    {
        if (TASKS [i].Delay  == 0)
        {
            /* Call [i] task */
            TASKS[i].Copy_PF();
            TASKS[i].Delay = TASKS[i].periodicty - 1;
        }
        else
        {
            TASKS[i].Delay--;
        }
    }
    Ticks++;
}

/****************************************************************************
 * @brief Initializes the task scheduler and sets up the SysTick timer.
 *        This function should be called before creating tasks.
 *****************************************************************************/
void tasks_scheduler (void)
{
    /* SysTick to be 1 millisecond with interval, executing Run_Tasks. */
    SYSTIC_voidSetIntervalPeriodic(1, Run_Tasks);
}

/*****************************************************************************************************
 * @brief Creates a new task with the specified priority, periodicity, function, and initial delay.
 *        Tasks are managed and executed by the scheduler.
 * @param Priority: Task priority (lower value means higher priority).
 * @param periodicity: Task execution interval in milliseconds.
 * @param Copy_PF: Pointer to the task function.
 * @param Delay: Initial delay before the task starts executing.
 ******************************************************************************************************/
void create_task (uint8 Priority, uint16 periodicity, void (*Copy_PF)(void), uint16 Delay)
{
    TASKS[Priority].periodicty = periodicity;
    TASKS[Priority].Copy_PF = Copy_PF;
    TASKS[Priority].Delay = Delay;
}
