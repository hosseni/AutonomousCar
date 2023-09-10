/**************************************************/
/******** Author      : Hosseni            *********/
/******** Date        : 13/8/2023          *********/
/******** version     : 1.0 V              *********/
/******** Description : SCB_CONFIG         *********/
/***************************************************/

#include "Inc/LIB/STD_TYPES.h"
#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/MCAL/SCB/SCB_config.h"

/* Configuartion file */

/*Activation Gate */



/*to get reg offset and bit offset*/
#define SCB_CLOCK_GATE_WD0           00u
#define SCB_CLOCK_GATE_WD1           01u

#define SCB_CLOCK_GATE_TIMER0        10u
#define SCB_CLOCK_GATE_TIMER1        11u
#define SCB_CLOCK_GATE_TIMER2        12u
#define SCB_CLOCK_GATE_TIMER3        13u
#define SCB_CLOCK_GATE_TIMER4        14u
#define SCB_CLOCK_GATE_TIMER5        15u

#define SCB_CLOCK_GATE_GPIOA         20u
#define SCB_CLOCK_GATE_GPIOB         21u
#define SCB_CLOCK_GATE_GPIOC         22u
#define SCB_CLOCK_GATE_GPIOD         23u
#define SCB_CLOCK_GATE_GPIOE         24u
#define SCB_CLOCK_GATE_GPIOF         25u

#define SCB_CLOCK_GATE_DMA           30u

#define SCB_CLOCK_GATE_Hibernation   50u

#define SCB_CLOCK_GATE_UART0         60u
#define SCB_CLOCK_GATE_UART1         61u
#define SCB_CLOCK_GATE_UART2         62u
#define SCB_CLOCK_GATE_UART3         63u
#define SCB_CLOCK_GATE_UART4         64u
#define SCB_CLOCK_GATE_UART5         65u
#define SCB_CLOCK_GATE_UART6         66u
#define SCB_CLOCK_GATE_UART7         67u

#define SCB_CLOCK_GATE_SSI0          70u
#define SCB_CLOCK_GATE_SSI1          71u
#define SCB_CLOCK_GATE_SSI2          72u
#define SCB_CLOCK_GATE_SSI3          73u

#define SCB_CLOCK_GATE_I2C0          80u
#define SCB_CLOCK_GATE_I2C1          81u
#define SCB_CLOCK_GATE_I2C2          82u
#define SCB_CLOCK_GATE_I2C3          83u

#define SCB_CLOCK_GATE_USB           100u

#define SCB_CLOCK_GATE_CAN0          130u
#define SCB_CLOCK_GATE_CAN1          131u

#define SCB_CLOCK_GATE_ADC0          140u
#define SCB_CLOCK_GATE_ADC1          141u

#define SCB_CLOCK_GATE_ACMP          150u

#define SCB_CLOCK_GATE_PWM0          160u
#define SCB_CLOCK_GATE_PWM1          161u

#define SCB_CLOCK_GATE_CQEI0          170u
#define SCB_CLOCK_GATE_CQEI1          171u

#define SCB_CLOCK_GATE_EEPROM         220u

#define SCB_CLOCK_GATE_WTIMER0        230u
#define SCB_CLOCK_GATE_WTIMER1        231u
#define SCB_CLOCK_GATE_WTIMER2        232u
#define SCB_CLOCK_GATE_WTIMER3        233u
#define SCB_CLOCK_GATE_WTIMER4        234u
#define SCB_CLOCK_GATE_WTIMER5        235u







#define SCB_Clock_0        0
#define SCB_Clock_1        1


uint8 SCB_ActivatedClockGates[SCB_ACTIVATED_CLOCK_GATES_SIZE]=
{
//      SCB_CLOCK_GATE_WD0        ,
//      SCB_CLOCK_GATE_WD1        ,
//
      SCB_CLOCK_GATE_TIMER0     ,
      SCB_CLOCK_GATE_TIMER1    ,
      SCB_CLOCK_GATE_TIMER2     ,

      SCB_CLOCK_GATE_GPIOA      ,

      SCB_CLOCK_GATE_GPIOF      ,
      SCB_CLOCK_GATE_GPIOB,
      SCB_CLOCK_GATE_GPIOD,
      SCB_CLOCK_GATE_GPIOE,

//      SCB_CLOCK_GATE_GPIOB      ,
//
//      SCB_CLOCK_GATE_GPIOF      ,
//
//      SCB_CLOCK_GATE_DMA        ,
//
//      SCB_CLOCK_GATE_Hibernation,
//      SCB_CLOCK_GATE_UART1,

      SCB_CLOCK_GATE_UART0,
//      SCB_CLOCK_GATE_UART1      ,
//      SCB_CLOCK_GATE_UART2      ,
//      SCB_CLOCK_GATE_UART3      ,
//      SCB_CLOCK_GATE_UART4      ,
//      SCB_CLOCK_GATE_UART5      ,
//      SCB_CLOCK_GATE_UART6      ,
//      SCB_CLOCK_GATE_UART7      ,
//      SCB_CLOCK_GATE_UART8

};

const SCB_ConfigType SCBConfig[SCB_CLOCK_SETTINGS_SIZE]=
{
    /*ClockSettingID*/ /* ClockSource                        PllUse     Freq_KHz  */
    /* 0            */ {  SCB_CLOCK_SOURCE_MOSC             ,ENABLE      ,16000},
    /* 1            */ {  SCB_CLOCK_SOURCE_PIOSC            ,DISABLE     ,16000},
};
