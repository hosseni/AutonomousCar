/************************************
 * motor.h
 *
 *  Created on: 10/9/2023
 *      Author: HOSSENI GAMAL
 ************************************/

#ifndef INC_HAL_MOTOR_MOTOR_H_
#define INC_HAL_MOTOR_MOTOR_H_


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

typedef struct
{
    Port_PinType  carSideDir1Pin;
    Port_PinType  carSideDir2Pin;
    Port_PinType  carSideEnPin;
    uint8         carSideSpeed;
}carSide_t;

typedef enum
{
    forward=0,
    backward,
    stop
}carSideDirection_t;


void carSideInit(carSide_t * sideA , carSide_t * sideB);

void carSideConfig(carSide_t * carSide , carSideDirection_t direction);


#endif /* INC_HAL_MOTOR_MOTOR_H_ */
