/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SCB.c
 *        \brief  Microcontroller Unit Driver
 *
 *      \details The SCB driver provides services for basic microcontroller initialization,
 *               Clock Control and reset
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/LIB/BIT_MATH.h"
#include "TM4C123GH6PM.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define APINT_VECTKEY_FIELD_OFFSET   16u
#define SYSRESREQ_FIELD_OFFSET       2u
#define APINT_VECTKEY                0x05FA
#define SCB_PLL_OUTPUT_DIV2          200

#define MCU_NOT_INITIALIZED          0
#define MCU_INITIALIZED              1


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const SCB_ConfigType* SCB_ConfigPtr = 0;
static SCB_StatusType SCB_Status = MCU_NOT_INITIALIZED;



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void SCB_Init ( const SCB_ConfigType* ConfigPtr )
{
    SCB_Status = SCB_INITIALIZED;
    SCB_ConfigPtr = ConfigPtr;
}


/******************************************************************************
* \Syntax          : SCB_RawResetType SCB_GetResetRawValue( void )
* \Description     : The service reads the reset type from the hardware, if supported.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : SCB_RawResetType   Reset raw value
*******************************************************************************/
SCB_RawResetType SCB_GetResetRawValue( void )
{
    SCB_RawResetType resetCause = RESC;
    RESC = 0x0;
    return resetCause;
}

/******************************************************************************
* \Syntax          : void SCB_PerformReset( void )
* \Description     : The service performs a microcontroller reset.
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/


void SCB_PerformReset( void )
{
    /*Clear Reset Cause Register */
    RESC = 0x0;
    /*Perform Reset */
    APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIELD_OFFSET) |
            (1<<SYSRESREQ_FIELD_OFFSET);

}

/******************************************************************************
* \Syntax          : void SCB_Init ( const SCB_ConfigType* ConfigPtr )
* \Description     : This service initializes the PLL and other SCB specific clock options.
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ClockSetting       ClockSetting.
* \Parameters (out): None
* \Return value:   : Std_ReturnType

*******************************************************************************/
Std_ReturnType SCB_InitClock( SCB_ClockType ClockSetting )
{
    Std_ReturnType ret = NOT_OK;
    uint8 i, locGateRegOffset = 0,locGateBitOffset = 0;
    uint8 locSourceFreq_MHz;
    volatile uint32 xTest;
    if(SCB_Status == SCB_INITIALIZED)
    {
        /*Enable Configured Pripherals Gates */
        for(i=0;i<SCB_ACTIVATED_CLOCK_GATES_SIZE;i++)
        {
            locGateRegOffset = (SCB_ActivatedClockGates[i] / 10) * 4 ;
            locGateBitOffset = SCB_ActivatedClockGates[i] % 10 ;
            SET_BIT(GET_REG(SYSCTR_RCG_BASE_ADDR,locGateRegOffset ), locGateBitOffset);
        }
        RCC.B.OSCSRC = SCB_ConfigPtr[ClockSetting].ClockSource;

        /* Calculate SYS_DIV Value */

        if(SCB_ConfigPtr[ClockSetting].PllUse == ENABLE)
        {
            /*Enable PLL*/
            RCC.B.PWRDN = 0x0;
            xTest = (SCB_PLL_OUTPUT_DIV2 / (SCB_ConfigPtr[ClockSetting].Freq_KHz/1000))-1;
            RCC.B.SYSDIV = (SCB_PLL_OUTPUT_DIV2 / (SCB_ConfigPtr[ClockSetting].Freq_KHz/1000))-1;
        }
        else
        {
            if (SCB_ConfigPtr[ClockSetting].ClockSource == SCB_CLOCK_SOURCE_LFIOSC)
            {
                RCC.B.SYSDIV = 0x0;
            }
            else
            {
                if(SCB_ConfigPtr[ClockSetting].ClockSource == SCB_CLOCK_SOURCE_MOSC)
                {
                    RCC.B.MOSCDIS = 0x0;
                    RCC.B.XTAL = SCB_XTAL_CLOCK_FREQ_MHZ ; /*TODO : The value need to be mapped */
                    locSourceFreq_MHz = SCB_XTAL_CLOCK_FREQ_MHZ;
                }
                else if (SCB_ConfigPtr[ClockSetting].ClockSource == SCB_CLOCK_SOURCE_PIOSC)
                {
                    locSourceFreq_MHz = 16;

                }
                else if (SCB_ConfigPtr[ClockSetting].ClockSource == SCB_CLOCK_SOURCE_PIOSC_Div4)
                {
                    locSourceFreq_MHz = 4;

                }
                RCC.B.SYSDIV = (locSourceFreq_MHz / (SCB_ConfigPtr[ClockSetting].Freq_KHz/1000))-1;
            }
        }
        ret = OK;
    }
    return ret;
}

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
Std_ReturnType SCB_DistributePllClock( void ){
    Std_ReturnType ret = NOT_OK;
    /*Check if PLL is Enabled */
    if(RCC.B.PWRDN == 0)
    {
        /*Check if PLL locked */
        if(SCB_GetPllStatus() == 0)
        {
            /* Distrubute PLL */
            RCC.B.BYPASS = 1;
            ret = OK;
        }
    }
    return ret;
}

/******************************************************************************
* \Syntax          : SCB_PllStatusType SCB_GetPllStatus
* \Description     : This service provides the lock status of the PLL.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : SCB_PllStatusType  PLL Status
*******************************************************************************/
SCB_PllStatusType SCB_GetPllStatus( void )
{
    return PLLSTAT;
}



/**********************************************************************************************************************
 *  END OF FILE: SCB.c
 *********************************************************************************************************************/
