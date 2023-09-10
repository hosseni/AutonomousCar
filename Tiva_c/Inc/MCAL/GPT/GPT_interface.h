/*************************
 * GPT_interface.h
 *
 *  Created on: 25/8/2023
 *      Author: HOSSENI
 *************************/

#ifndef GPT_TYPES_H_INCLUDED
#define GPT_TYPES_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "../../../Inc/LIB/STD_TYPES.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
#define NUM_TIMER               12u
#define END_LIST                0xFE


#define ACCESS_GPTMCFG(x)       ACCESS_ADR(x + 0x000u)
#define ACCESS_GPTMTAMR(x)      ACCESS_ADR(x + 0x004u)
#define ACCESS_GPTMTBMR(x)      ACCESS_ADR(x + 0x008u)
#define ACCESS_GPTMCTL(x)       ACCESS_ADR(x + 0x00Cu)
#define ACCESS_GPTMIMR(x)       ACCESS_ADR(x + 0x018u)
#define ACCESS_GPTMTAV(x)       ACCESS_ADR(x + 0x050u)
#define ACCESS_GPTMTAR(x)       ACCESS_ADR(x + 0x048u)
#define ACCESS_GPTMTAPR(x)      ACCESS_ADR(x + 0x038u)
#define ACCESS_GPTMICR(x)       ACCESS_ADR(x + 0x024u)
#define ACCESS_GPTMTAILR(x)     ACCESS_ADR(x + 0x028u)
#define ACCESS_GPTMTAMATCHR(x)  ACCESS_ADR(x + 0x030u)
/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/
typedef enum
{
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
} GPT_ModeType;

typedef enum
{
    GPT_CH_MODE_CONTINUOUS,//periodic
    GPT_CH_MODE_ONESHOT,
    GPT_CH_MODE_CAPTURE_MODE,
    GPT_CH_MODE_PWM
} GPT_ChannelModeType;

typedef enum
{
    GPT_CHNL_TIMER0,
    GPT_CHNL_TIMER1,
    GPT_CHNL_TIMER2,
    GPT_CHNL_TIMER3,
    GPT_CHNL_TIMER4,
    GPT_CHNL_TIMER5,
    GPWT_CHNL_TIMER0,
    GPWT_CHNL_TIMER1,
    GPWT_CHNL_TIMER2,
    GPWT_CHNL_TIMER3,
    GPWT_CHNL_TIMER4,
    GPWT_CHNL_TIMER5
} GPT_ChannelType;

typedef enum
{
    No_Extensions,
    Extended,
    RTC
}GPT_OpType;
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
} GPT_PredefTimerType;

typedef uint32 GPT_ValueType;

typedef uint8 GPT_PrescaleType;

typedef struct
{
    GPT_ChannelType gptChannelid;
    GPT_OpType type;
    GPT_PrescaleType prescaler;
    GPT_ChannelModeType channelMode;

}GPT_ConfigType;

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
void GPT_Init(const GPT_ConfigType *gptConfig);
void GPT_StartTimer(const GPT_ChannelType gptChannelid, const GPT_ValueType value);
uint32 GPT_getValue (GPT_ChannelType gptChannelid);
void GPT_SetPWM (GPT_ChannelType gptChannelid, uint32 val);
void GPT_EnableNotification(GPT_ChannelType gptChannelid, void (*fun_ptr)(void));

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif /* INC_MCAL_GPT_GPT_INTERFACE_H_ */
