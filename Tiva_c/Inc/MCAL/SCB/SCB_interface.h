/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  SCB.h
 *       Module:  SCB
 *
 *  Description:  Header file for SCB Module
 *
 *********************************************************************************************************************/
#ifndef SCB_H_
#define SCB_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "SCB_config.h"
#include "../../../TM4C123GH6PM.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CLOCK_0 0
#define CLOCK_1 1


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern uint8 SCB_ActivatedClockGates[];

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 SCB_ClockType;


typedef uint32 SCB_FreqType;

typedef uint8 SCB_StatusType;

#define SCB_NOT_INITIALIZED          0
#define SCB_INITIALIZED              1



typedef uint32 SCB_RawResetType;

#define SCB_MOSC_FAILURE_RESET            0x10000uL
#define SCB_WDT_1_RESET                   32u
#define SCB_SOFTWARE_RESET                16u
#define SCB_WDT_0_RESET                   8u
#define SCB_BROWN_OUT_RESET               4u
#define SCB_POWER_ON_RESET                2u
#define SCB_EXTERNAL_RESET                1u

typedef enum
{
    SCB_PLL_UNPOWERED_UNLOCKED,
    SCB_PLL_POWERED_LOCKED,
    SCB_PLL_STATUS_UNDEFINED

}SCB_PllStatusType;
typedef enum
{
    SCB_CLOCK_SOURCE_MOSC,    // main
    SCB_CLOCK_SOURCE_PIOSC,
    SCB_CLOCK_SOURCE_PIOSC_Div4,
    SCB_CLOCK_SOURCE_LFIOSC,
    SCB_CLOCK_SOURCE_HibOSC

}SCBClockSourceType;


typedef struct
{
   SCB_ClockType ClockSource;
   uint8 PllUse;
   SCB_FreqType Freq_KHz;

}SCB_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void SCB_Init ( const SCB_ConfigType* ConfigPtr )
* \Description     : This service initializes the SCB driver.
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ConfigPtr       Pointer to SCB driver configuration set.
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void SCB_Init ( const SCB_ConfigType* ConfigPtr );

/******************************************************************************
* \Syntax          : SCB_RawResetType SCB_GetResetRawValue( void )
* \Description     : The service reads the reset type from the hardware, if supported.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : SCB_RawResetType   Reset raw value
*******************************************************************************/
SCB_RawResetType SCB_GetResetRawValue( void );

/******************************************************************************
* \Syntax          : void SCB_PerformReset( void )
* \Description     : The service performs a microcontroller reset.
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void SCB_PerformReset( void );
/******************************************************************************
* \Syntax          : void SCB_Init ( const SCB_ConfigType* ConfigPtr )
* \Description     : This service initializes the PLL and other SCB specific clock options.
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ClockSetting       ClockSetting.
* \Parameters (out): None
* \Return value:   : Std_ReturnType
*******************************************************************************/
uint8 SCB_InitClock( SCB_ClockType ClockSetting );

/******************************************************************************
* \Syntax          : Std_ReturnType SCB_DistributePllClock( void )
* \Description     : This service activates the PLL clock to the SCB clock distribution.
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType
*                    E_OK: Command has been accepted
*                    E_NOT_OK: Command has not been accepted
*******************************************************************************/
uint8 SCB_DistributePllClock( void );

/******************************************************************************
* \Syntax          : SCB_PllStatusType SCB_GetPllStatus
* \Description     : This service provides the lock status of the PLL.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : SCB_PllStatusType  PLL Status
*******************************************************************************/
SCB_PllStatusType SCB_GetPllStatus( void );


#endif  /* SCB_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
