/*
 * GPT_config.c
 *
 *  Created on: 25/8/2023
 *      Author: HOSSENI
 */


#include "Inc/MCAL/GPT/GPT_interface.h"

const GPT_ConfigType gptConfig[NUM_TIMER] =
{
 /* Channel                  (16or32)(32or64)        Prescale            Mode */
        {GPT_CHNL_TIMER0,     Extended,                    0,              GPT_CH_MODE_ONESHOT}, //ultrasonic
        {GPT_CHNL_TIMER1,     No_Extensions,               0,              GPT_CH_MODE_PWM}, //PWMsideA
        {GPT_CHNL_TIMER2,     No_Extensions,               0,              GPT_CH_MODE_PWM}, //PWMsideB

        {END_LIST}

};
