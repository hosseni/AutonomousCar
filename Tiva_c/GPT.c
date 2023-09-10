/****************************
 * GPT.c
 *
 *  Created on: 25/8/2024
 *      Author: HOSSENI
 ****************************/
#include "Inc/MCAL/GPT/GPT_config.h"
#include "Inc/MCAL/GPT/GPT_interface.h"
#include "Inc/MCAL/GPT/GPT_private.h"

extern const  GPT_ConfigType gptConfig[NUM_TIMER];
static void (*isr_timer[12])(void);
uint32 captured_val[12] ;

/***************************************************************************************************
 *  Function: TIMER0A_Handler
 *  Description:
 *      This is the interrupt handler for Timer 0A. It invokes the corresponding user-defined
 *      callback function and clears the interrupt flags based on the configured channel mode.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void TIMER0A_Handler(void)
{
    isr_timer[0]();
    /* Clear the timeout interrupt flag */
    if ((gptConfig[0].channelMode == GPT_CH_MODE_CONTINUOUS)||(gptConfig[0].channelMode == GPT_CH_MODE_ONESHOT))
    {
        ACCESS_GPTMICR(GPT_0_BASE) |= 0x01;
    }
    else if (gptConfig[0].channelMode == GPT_CH_MODE_CAPTURE_MODE)
    {
        ACCESS_GPTMICR(GPT_0_BASE) |= 0x10;
        captured_val[0] = ACCESS_GPTMTAILR(GPT_0_BASE);
    }
}

/***************************************************************************************************
 *  Function: TIMER1A_Handler
 *  Description:
 *      This is the interrupt handler for Timer 1A. It invokes the corresponding user-defined
 *      callback function and clears the interrupt flags based on the configured channel mode.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void TIMER1A_Handler(void)
{
    isr_timer[1]();
    /* Clear the timeout interrupt flag */
    if ((gptConfig[1].channelMode == GPT_CH_MODE_CONTINUOUS)||(gptConfig[1].channelMode == GPT_CH_MODE_ONESHOT))
    {
        ACCESS_GPTMICR(GPT_1_BASE) |= 0x01;
    }
    else if (gptConfig[1].channelMode == GPT_CH_MODE_CAPTURE_MODE)
    {
        ACCESS_GPTMICR(GPT_1_BASE) |= 0x10;
        captured_val[1] = ACCESS_GPTMTAILR(GPT_1_BASE);
    }
}

/***************************************************************************************************
 *  Function: TIMER2A_Handler
 *  Description:
 *      This is the interrupt handler for Timer 2A. It invokes the corresponding user-defined
 *      callback function and clears the interrupt flags based on the configured channel mode.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void TIMER2A_Handler(void)
{
    isr_timer[2]();
    /* Clear the timeout interrupt flag */
    if ((gptConfig[2].channelMode == GPT_CH_MODE_CONTINUOUS)||(gptConfig[2].channelMode == GPT_CH_MODE_ONESHOT))
    {
        ACCESS_GPTMICR(GPT_2_BASE) |= 0x01;
    }
    else if (gptConfig[2].channelMode == GPT_CH_MODE_CAPTURE_MODE)
    {
        ACCESS_GPTMICR(GPT_2_BASE) |= 0x10;
        captured_val[2] = ACCESS_GPTMTAILR(GPT_2_BASE);
    }
}

/***************************************************************************************************
 *  Function: GPT_GetTimerBaseAdr
 *  Description:
 *      This function maps the GPT channel ID to its corresponding base address.
 *  Parameters:
 *      gptChannelid: GPT_ChannelType value representing the GPT channel ID.
 *  Return Value:
 *      uint32: Base address of the specified GPT channel.
 ***************************************************************************************************/
static uint32 GPT_GetTimerBaseAdr(GPT_ChannelType gptChannelid)
{
    uint32 baseAdr = GPT_0_BASE;
    switch(gptChannelid)
    {
    case GPT_CHNL_TIMER0:
        baseAdr = GPT_0_BASE;
        break;
    case GPT_CHNL_TIMER1:
        baseAdr = GPT_1_BASE;
        break;
    case GPT_CHNL_TIMER2:
        baseAdr = GPT_2_BASE;
        break;
    case GPT_CHNL_TIMER3:
        baseAdr = GPT_3_BASE;
        break;
    case GPT_CHNL_TIMER4:
        baseAdr = GPT_4_BASE;
        break;
    case GPT_CHNL_TIMER5:
        baseAdr = GPT_5_BASE;
        break;
    case GPWT_CHNL_TIMER0:
        baseAdr = GPWT_0_BASE;
        break;
    }

    return baseAdr;
}

/***************************************************************************************************
 *  Function: GPT_Init
 *  Description:
 *      This function initializes the specified GPT channels based on the provided configuration.
 *  Parameters:
 *      gptConfig: Pointer to an array of GPT_ConfigType containing timer configuration settings.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void GPT_Init(const GPT_ConfigType *gptConfig)
{
    uint32 baseAdr;
    uint8 i = 0;

    for(i = 0; i < NUM_TIMER; i++)
    {
        if (gptConfig[i].gptChannelid == END_LIST) break;
        baseAdr = GPT_GetTimerBaseAdr(gptConfig[i].gptChannelid);

        /* Disable the timer before any operation */
        CLR_BIT(ACCESS_GPTMCTL(baseAdr), 0u);

        if(gptConfig[i].type == No_Extensions)
        {
            /* Use the timer in 16 bit mode (or 32 bit mode in wide timers) */
            ACCESS_GPTMCFG(baseAdr) |= 0x04;
        }
        else if (gptConfig[i].type == Extended)
        {
            /* Use the timer in 32 bit mode (or 64 bit mode in wide timers) */
            ACCESS_GPTMCFG(baseAdr) |= 0x0;
        }
        else if (gptConfig[i].type == RTC)
        {
            /*For a 16/32-bit timer, this value selects the 32-bit real-time clock (RTC) counter configuration*/
            /*For a 32/64-bit timer, this value selects the 64-bit real-time clock (RTC) counter configuration*/
            ACCESS_GPTMCFG(baseAdr) |= 0x1;
        }
        /* Set the timer mode */
        CLR_BIT(ACCESS_GPTMTAMR(baseAdr), 4);  /* Set to count down mode*/
        //ACCESS_GPTMTAPR(baseAdr) = gptConfig[i].prescaler;  /* to set pre-scaler */

        if(gptConfig[i].channelMode == GPT_CH_MODE_CONTINUOUS)
            ACCESS_GPTMTAMR(baseAdr) |= 0x02;  /* Set to periodic mode*/
        else if(gptConfig[i].channelMode == GPT_CH_MODE_ONESHOT)
            ACCESS_GPTMTAMR(baseAdr) |= 0x01;  /* Set to one shot mode*/
        else if (gptConfig[i].channelMode == GPT_CH_MODE_CAPTURE_MODE)
        {

        }
        else if (gptConfig[i].channelMode == GPT_CH_MODE_PWM)
        {

               SET_BIT(ACCESS_GPTMTAMR(baseAdr), 3u);/*enable PWM*/
               CLR_BIT(ACCESS_GPTMTAMR(baseAdr), 2u);/*edge count mode*/
               ACCESS_GPTMTAMR(baseAdr) |=0x2;/*periodic*/
               SET_BIT(ACCESS_GPTMCTL(baseAdr) , 6u);
        }

    }

}
/***************************************************************************************************
 *  Function: GPT_SetPWM
 *  Description:
 *      This function sets up PWM operation for the specified GPT channel and adjusts the match value.
 *  Parameters:
 *      gptChannelid: GPT_ChannelType value representing the GPT channel ID.
 *      val: Value to be loaded into the GPTM Timer n Match (GPTMTnMATCHR) register.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void GPT_SetPWM (GPT_ChannelType gptChannelid, uint32 val)
{
    uint32 baseAdr;
    baseAdr = GPT_GetTimerBaseAdr(gptChannelid);

    //Load the timer start value into the GPTM Timer n Interval Load (GPTMTnILR) register./
       ACCESS_GPTMTAILR(baseAdr) = 10000;

     //Load the GPTM Timer n Match (GPTMTnMATCHR) register with the match value./
       ACCESS_GPTMTAMATCHR(baseAdr) = val-1;

       //Set the TnEN bit in the GPTMCTL register to enable the timer and start counting./
       SET_BIT(ACCESS_GPTMCTL(baseAdr), 0u);

       //Polling on match flag/
       //while((READ_BIT(ACCESS_GPTMRIS(baseAdr) , 4u) & 0x01) == 0);

       //clear flag/
       //SET_BIT(ACCESS_GPTMICR(baseAdr), 4u);
}
/***************************************************************************************************
 *  Function: GPT_EnableNotification
 *  Description:
 *      This function enables the interrupt notification for the specified GPT channel and associates
 *      the provided callback function with the interrupt event.
 *  Parameters:
 *      gptChannelid: GPT_ChannelType value representing the GPT channel ID.
 *      fun_ptr: Pointer to the user-defined callback function to be invoked on interrupt.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void GPT_EnableNotification(GPT_ChannelType gptChannelid, void (*fun_ptr)(void))
{
    uint32 baseAdr;

    baseAdr = GPT_GetTimerBaseAdr(gptChannelid);

    isr_timer[gptChannelid] = fun_ptr;

    /* Clear the timeout interrupt flag */
    ACCESS_GPTMICR(baseAdr) |= 0x01;

    /* Enable time-out interrupt for timer A */
    if ((gptConfig[gptChannelid].channelMode == GPT_CH_MODE_CONTINUOUS)||(gptConfig[gptChannelid].channelMode == GPT_CH_MODE_ONESHOT))
        ACCESS_GPTMIMR(baseAdr) |= 0x01;
    else if (gptConfig[gptChannelid].channelMode == GPT_CH_MODE_CAPTURE_MODE)
        ACCESS_GPTMIMR(baseAdr) |= 0x10;
}
/***************************************************************************************************
 *  Function: GPT_StartTimer
 *  Description:
 *      This function starts the specified GPT channel with the provided initial value.
 *  Parameters:
 *      gptChannelid: GPT_ChannelType value representing the GPT channel ID.
 *      value: Initial value to be set in the GPTMTAILR register.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void GPT_StartTimer(const GPT_ChannelType gptChannelid, const GPT_ValueType value)
{
    uint32 baseAdr;
    baseAdr = GPT_GetTimerBaseAdr(gptChannelid);

    /* Set the value of timer A */
    ACCESS_GPTMTAILR(baseAdr) = value;

    /* Start the timer */
    ACCESS_GPTMCTL(baseAdr) |= 0x01;
}
uint32 GPT_getValue (GPT_ChannelType gptChannelid)
{
    uint32 baseAdr;

    baseAdr = GPT_GetTimerBaseAdr(gptChannelid);

    return ACCESS_GPTMTAR(baseAdr);
}
void GPT_stopTimer (GPT_ChannelType gptChannelid)
{
    uint32 baseAdr;

    baseAdr = GPT_GetTimerBaseAdr(gptChannelid);
    /* Start the timer */
    ACCESS_GPTMCTL(baseAdr) |= 0x00;
}

