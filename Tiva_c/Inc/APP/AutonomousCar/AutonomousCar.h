

#ifndef INC_APP_AUTONOMOUSCAR_AUTONOMOUSCAR_H_
#define INC_APP_AUTONOMOUSCAR_AUTONOMOUSCAR_H_

#include "../../MCAL/SCB/SCB_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SYSTICK_interface.h"
#include "../../MCAL/GPT/GPT_interface.h"
#include "../../MCAL/ADC/adc.h"
#include "../../SERVICES/SCHEDULAR/Schedular_interface.h"

#include "../../HAL/ULTRASONIC/ultrasonic.h"
#include "../../HAL/LCD/lcd.h"
#include "../../HAL/MOTOR/motor.h"
#include "../../HAL/SWITCH/switch.h"

#include "AutonomousCar.h"

#include "Inc/LIB/DELAY.h"
#include "hw_gpio.h"

void robotInit();

void robotMoveForward(void);

void robotMoveStop(void);

void robotMoveRotate(void);

void robotMoveLeft(void);

void robotMoveRight(void);

void robotMoveback (void);


void autonomous_car_init(void);
void start_stop_condition (void);
void ldr_swing_car(void);
void lcd_display(void);
void avoid_obstacles(void);
void get_temp (void);






#endif /* INC_APP_AUTONOMOUSCAR_AUTONOMOUSCAR_H_ */
