#include "Inc/APP/AutonomousCar/AutonomousCar.h"

int main(int argc, char **argv) {


    /* Initialize the autonomous car's hardware components and peripherals. */
    autonomous_car_init();

    /* Create tasks with their respective priorities and delays. */
    create_task(0, 7, start_stop_condition, 0);    /* Task 0: start_stop_condition with priority 7 and no initial delay. */
    create_task(1, 10, avoid_obstacles, 5);        /* Task 1: avoid_obstacles with priority 10 and an initial delay of 5 system ticks. */
    create_task(2, 12, ldr_swing_car, 7);          /* Task 2: ldr_swing_car with priority 12 and an initial delay of 7 system ticks. */
    create_task(3, 16, lcd_display, 9);            /* Task 3: lcd_display with priority 16 and an initial delay of 9 system ticks. */


    tasks_scheduler();    /* Start the task scheduler to manage task execution. */


    /** Infinite Loop */
    while (1) {
        /** The main function enters an infinite loop, as task management is now handled by the scheduler. */
    }
}
