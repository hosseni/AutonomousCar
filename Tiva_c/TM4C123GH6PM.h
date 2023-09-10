//#include "Inc/LIB/STD_TYPES.h"
//
///* ================================================================================ */
///* ================                     SYSCTL                     ================ */
///* ================================================================================ */
//
//

#ifndef _TM4C123GH6PM_H_
#define _TM4C123GH6PM_H_

#include "Inc/LIB/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**************************************
*   NVIC REGISTRE
***************************************/
#define NVIC_ENABLE_BASE_ADDRESS              ((volatile uint32*)0xE000E100)
#define NVIC_PRIORITY_BASE_ADDRESS            ((volatile uint32*)0xE000E400)

#define APINT_KEY                                       0x05FA
#define APINT_SYSRESREQ                                 2
#define APINT_KEY_START_BIT                         16
#define NVIC_GROUPING_SYSTEM_START_BIT  8


/**************************************
*   SYSTEM CONTROL REGISTRES
***************************************/

#define APINT                            *((volatile uint32*)0xE000ED0C)
#define SYSCTR_BASE_ADDRESS              0x400FE000
#define RESC                             *((volatile uint32*)0x400FE05C)
#define RCGCGPIO_OFFSET                  0x608
#define RCGCGPIO                         *((volatile uint32*)(SYSCTR_BASE_ADDRESS+RCGCGPIO_OFFSET)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

typedef struct
{
    uint32 MOSCDIS  :1;
    uint32          :3;
    uint32 OSCSRC   :2;
    uint32 XTAL     :5;
    uint32 BYPASS   :1;
    uint32          :1;
    uint32 PWRDN    :1;
    uint32          :3;
    uint32 PWMDIV   :3;
    uint32 USEPWMDIV:1;
    uint32          :1;
    uint32 USESYSDIV:1;
    uint32 SYSDIV   :4;
    uint32 ACG      :1;
    uint32          :4;
}Mcu_StrBF;

typedef union
{
    uint32 R;
    Mcu_StrBF B;

}RCC_TAG;

#define RCC                     (*((volatile RCC_TAG*)0x400FE060))
#define RCC2                    (*((volatile RCC2_TAG*)0x400FE070))
#define PLLSTAT                 (*((volatile uint32*)0x400FE168))
#define SYSCTR_RCG_BASE_ADDR    0x400FE600
/**************************************
*   GPIO REGISTRE
***************************************/
#if (DIO_USED_BUS == APB_BUS)


#define GPIO_PORT_A_BASE          0x40004000
#define GPIO_PORT_B_BASE          0x40005000
#define GPIO_PORT_C_BASE          0x40006000
#define GPIO_PORT_D_BASE          0x40007000
#define GPIO_PORT_E_BASE          0x40024000
#define GPIO_PORT_F_BASE          0x40025000





#elif(DIO_USED_BUS == AHB_BUS)
#define GPIO_PORT_A_BASE          0x40008000
#define GPIO_PORT_B_BASE          0x40009000
#define GPIO_PORT_C_BASE          0x4000A000
#define GPIO_PORT_D_BASE          0x4000B000
#define GPIO_PORT_E_BASE          0x4002C000
#define GPIO_PORT_F_BASE          0x4002D000

#endif

#define GPIODATA_OFFSET     0x000
#define GPIODIR_OFFSET      0x400
#define GPIOIS_OFFSET       0x404
#define GPIOIBE_OFFSET      0x408
#define GPIOIEV_OFFSET      0x40C

#define GPIODIR_REG(BaseAddr)                  *((volatile uint32*)(BaseAddr+GPIODIR_OFFSET))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
//#define GET_REG(BaseAddr,RegOffset)                              *((volatile uint32*)(BaseAddr+RegOffset))
//#define BASE_ADDRESS_PRE                              0x40000000
//#define BASE_ADDRESS_PRE_ALIAS                        0x42000000
//
//#define ACCESS_ADR(x)                           (*((volatile uint32* )(x)))
//#define ACCESS_BITBAND_ADR(adr, bit, base)      ACCESS_ADR((32u*adr)+base+(4u*bit))
//
//
//#define GET_RegisterOffset(RegisterAddr)              ((RegisterAddr - BASE_ADDRESS_PRE)/4)
//#define GET_BitOffset(RegisterAddr,BitPos)            ((GET_RegisterOffset(RegisterAddr)*32) + BitPos)
//#define GET_BBAlIAS_PRE_REG(RegisterAddr, BitPos)     (*(volatile uint32*)((GET_BitOffset(RegisterAddr,BitPos)*4) + BASE_ADDRESS_PRE_ALIAS))
//
//#define SET_BIT(Reg, bitnum)       (Reg |=(1<<bitnum))
//#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
//#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
//#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
//#define SET_BYTE(Reg,value)              ( Reg = value )


#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
