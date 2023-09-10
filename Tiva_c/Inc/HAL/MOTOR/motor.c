/*
 * motor.c
 *
 *  Created on: 10/9/2023
 *      Author: HOSSENI GAMAL
 */







#include "motor.h"
#include "../../MCAL/GPT/GPT_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void carSideInit(carSide_t * sideA , carSide_t * sideB)
{
    GPT_SetPWM (GPT_CHNL_TIMER1, sideA->carSideSpeed*100);
    GPT_SetPWM (GPT_CHNL_TIMER2, sideB->carSideSpeed*100);
}

void carSideConfig(carSide_t * carSide , carSideDirection_t direction)
{

        switch(direction)
        {
            case forward:
                /*Set direction to moving forward*/
                DIO_WriteChannel(carSide->carSideDir1Pin  , HIGH);
                DIO_WriteChannel(carSide->carSideDir2Pin  , LOW);
                break;
            case backward:
                /*Set direction to moving backward*/
                DIO_WriteChannel(carSide->carSideDir1Pin  , LOW);
                DIO_WriteChannel(carSide->carSideDir2Pin  , HIGH);
                break;
            case stop:
                /*Stop car side motors*/
                DIO_WriteChannel(carSide->carSideDir1Pin  , LOW);
                DIO_WriteChannel(carSide->carSideDir2Pin  , LOW);
                break;
            default:
                ;
        }

}


