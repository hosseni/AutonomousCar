/*****************************************************
 * ultrasonic_sensor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal, Ahmed Abdalla
 *****************************************************/
#include "ultrasonic.h"
//
//void ultarsonicSensorInit(ultraSonic_t *sensor)
//{
//
//        TimerDisable(TIMER1_BASE, TIMER_A);
//        /*Configure Timer1-A to one shot mode in  down counting mode*/
//        TimerConfigure(TIMER1_BASE , TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT);
//        /*To stop timer during debugging*/
//        TimerControlStall(TIMER1_BASE , TIMER_A , true);
//        /*To load timer with initial value = 0xFFFF */
//        TimerLoadSet(TIMER1_BASE , TIMER_A , 0xFFFF);
//
//}

void delay_micro (int delay_micro)
{
    int i = 0;
    for (   ; i < delay_micro*16;  i++)
    {
        __asm("NOP");
    }
}


uint32 ultarsonicSensorReadValue(ultraSonic_t *sensor)
{
    if(sensor == NULL)
    {
        return 0 ;
    }else{
        /*Variable to store time of ultrasonic*/
        uint32 duration = 0U;
        /*Variable to store distance*/
        uint32 reading = 0U ;
        /*Variable to store the state of echo pin*/
        uint8 pinValue = 0U ;
        /*Sending 10uS pulse on trigger pin to enable ultrasonic sensor*/
        DIO_WriteChannel(sensor->ultrasonicTriggerPin, HIGH);
        /*Delay 10 micro Second*/
        delay_micro(10);
        DIO_WriteChannel(sensor->ultrasonicTriggerPin, LOW);


        /*Waiting for echo pin to be high*/
        while(pinValue == 0)
        {
            pinValue = DIO_ReadChannel(sensor->ultrasonicEchoPin);
        }
        /*Start calculating time*/
        GPT_StartTimer(GPT_CHNL_TIMER0, ~0U);

//        TimerEnable(TIMER1_BASE, TIMER_A);

        /*Waiting for echo pin to be low*/
        while(pinValue == 1)
        {
            pinValue = DIO_ReadChannel(sensor->ultrasonicEchoPin);
        }
        /*Getting the time value*/
        duration = GPT_getValue(GPT_CHNL_TIMER0);
        /*Calculate the actual time*/
        duration = 0xffffffff - duration;
        /*Disable timer1-A*/
       GPT_stopTimer(GPT_CHNL_TIMER0);
        /*Calculating distance in cm*/
        reading = (duration *340.0 *100) / (2.0*16000000);
        /*Returning distance*/
        return reading;
    }
}

