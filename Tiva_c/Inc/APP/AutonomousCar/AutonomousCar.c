/************************************
 *   AutonomousCar.c
 *
 *  Created on: 31/8/2023
 *      Author: HOSSENI GAMAL
 ************************************/

#include "AutonomousCar.h"

carSide_t LEFT_SIDE  = { PIN_B7, PIN_B1, PIN_B0, 60 };
carSide_t RIGHT_SIDE = { PIN_E5, PIN_B5, PIN_B4, 60 };

void robotInit()
{
    carSideInit(&LEFT_SIDE , &RIGHT_SIDE);
}

void robotMoveForward(void)
{
    carSideConfig(&LEFT_SIDE , forward);
    carSideConfig(&RIGHT_SIDE , forward);
}

void robotMoveStop(void)
{
    carSideConfig(&LEFT_SIDE , stop);
    carSideConfig(&RIGHT_SIDE , stop);
}

void robotMoveRotate(void)
{
    carSideConfig(&LEFT_SIDE , backward);
    carSideConfig(&RIGHT_SIDE , forward);
}

void robotMoveLeft(void)
{
    carSideConfig(&LEFT_SIDE , backward);
    carSideConfig(&RIGHT_SIDE , forward);
}

void robotMoveRight(void)
{
    carSideConfig(&LEFT_SIDE , forward);
    carSideConfig(&RIGHT_SIDE , backward);
}

void robotMoveback (void)
{
    carSideConfig(&LEFT_SIDE , backward);
    carSideConfig(&RIGHT_SIDE , backward);

}




