/*******************************************************
 *
 * UART_porogram.h
 * Created on: 8/9/2023
 * Author: HOSSENI
 *******************************************************/
#include "Inc/MCAL/UART/UART_interface.h"
#include "Inc/MCAL/UART/UART_private.h"
#include "Inc/MCAL/UART/UART_config.h"

static void setParity (uint32 baseAdd ,ParityType parity);
static void setStopBit (uint32 baseAdd , StopBitType num_ofStopBit);
static void SetFIFO (uint32 baseAdd, FIFO_StateType fifo_State);
static void setDataLength (uint32 baseAdd, DataLengthType data_Length);
static void setBoudrate (uint32 baseAdd, BoudrateType boudrate);

/***************************************************************************************************
 * Function: UART_GetBaseAdr
 * Description:
 *   This function maps the UART number (UART_NumType) to its corresponding base address (uint32).
 * Parameters:
 *   uart_num: UART_NumType value representing the UART number.
 * Return Value:
 *   uint32: Base address of the specified UART module.
 ***************************************************************************************************/

static uint32 UART_GetBaseAdr(UART_NumType uart_num)
{
    uint32 baseAdr = UART0_BASE;
    switch(uart_num)
    {
    case UART_0_:
        baseAdr = UART0_BASE;
        break;
    case UART_1_:
        baseAdr = UART1_BASE;
        break;
    case UART_2_:
        baseAdr = UART2_BASE;
        break;
    case UART_3_:
        baseAdr = UART3_BASE;
        break;
    case UART_4_:
        baseAdr = UART4_BASE;
        break;
    case UART_5_:
        baseAdr = UART5_BASE;
        break;
    case UART_6_:
        baseAdr = UART6_BASE;
        break;
    case UART_7_:
        baseAdr = UART7_BASE;
        break;
    }

    return baseAdr;
}

/***************************************************************************************************
 * Function: setParity
 * Description:
 *   This function configures the parity settings for a UART module.
 * Parameters:
 *   baseAdd: Base address of the UART module.
 *   parity: ParityType value representing the desired parity setting (even, odd, or none).
 * Return Value:
 *   None.
 ***************************************************************************************************/
static void setParity (uint32 baseAdd ,ParityType parity)
{
    if (parity == evenParity)
    {
        /*enable parity check*/
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 1);
        /*enable even parity*/
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 2);
    }
    else if (parity == oddParity)
    {
        /*enable parity check*/
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 1);
        /*enable even parity*/
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 2);        }
    else
    {
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 1);
    }

}

/***************************************************************************************************
 * Function: setStopBit
 * Description:
 *   This function configures the number of stop bits for a UART module.
 * Parameters:
 *   baseAdd: Base address of the UART module.
 *   num_ofStopBit: StopBitType value representing the number of stop bits (1 or 2).
 * Return Value:
 *   None.
 ***************************************************************************************************/
static void setStopBit (uint32 baseAdd , StopBitType num_ofStopBit)
{
    if (num_ofStopBit == oneStopBit)
    {
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 3);
    }
    else if (num_ofStopBit == twoStopBits)
    {
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 3);
    }
}

/***************************************************************************************************
 * Function: SetFIFO
 * Description:
 *   This function enables or disables the FIFO (First-In-First-Out) buffer for a UART module.
 * Parameters:
 *   baseAdd: Base address of the UART module.
 *   fifo_State: FIFO_StateType value representing the FIFO state (FIFO_ENABLE or FIFO_DISABLE).
 * Return Value:
 *   None.
 ***************************************************************************************************/
static void SetFIFO (uint32 baseAdd, FIFO_StateType fifo_State)
{
    if (fifo_State == FIFO_ENABLE)
    {
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 4);
    }
    else if (fifo_State == FIFO_DISABLE)
    {
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 4);
    }
}

/***************************************************************************************************
 * Function: setDataLength
 * Description:
 *   This function configures the data length for a UART module.
 * Parameters:
 *   baseAdd: Base address of the UART module.
 *   data_Length: DataLengthType value representing the data length (5, 6, 7, or 8 bits).
 * Return Value:
 *   None.
 ***************************************************************************************************/
static void setDataLength (uint32 baseAdd, DataLengthType data_Length)
{
    if (data_Length == _5_BitData)
    {
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 5);
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 6);
    }
    else if (data_Length == _6_BitData)
    {
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 5);
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 6);
    }
    else if (data_Length == _7_BitData)
    {
        CLR_BIT(ACCESS_UARTLCRH(baseAdd), 5);
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 6);
    }
    else if (data_Length == _8_BitDatat)
    {
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 5);
        SET_BIT(ACCESS_UARTLCRH(baseAdd), 6);
    }
}


/***************************************************************************************************
 * Function: setBoudrate
 * Description:
 *   This function configures the baud rate for a UART module, including fractional settings.
 * Parameters:
 *   baseAdd: Base address of the UART module.
 *   boudrate: BoudrateType value representing the desired baud rate.
 * Return Value:
 *   None.
 ***************************************************************************************************/
static void setBoudrate (uint32 baseAdd, BoudrateType boudrate)
{
    float32 BD_rate = (SYS_CLK / (16.0 * boudrate));
    uint32 integerDiv = (uint32)BD_rate;
    float32 fractionDiv = BD_rate - integerDiv;
    ACCESS_UARTIBRD(baseAdd) = integerDiv;
    ACCESS_UARTFBRD(baseAdd) = (fractionDiv*64 + 0.5);
}

/***************************************************************************************************
 * Function: UART_init
 * Description:
 *   This function initializes UART modules based on the provided configuration settings.
 * Parameters:
 *   uartConfig: Pointer to an array of UART_ConfigType structures containing UART configuration data.
 * Return Value:
 *   None.
 ***************************************************************************************************/
void UART_init (UART_ConfigType const * uartConfig)
{
    uint8  i = 0;
    uint32 baseAdd = 0x0;
    for (; i < NUM_OF_UARTS; i++)
    {
        baseAdd = UART_GetBaseAdr (uartConfig[i].uart);
        if (uartConfig[i].uart == END_OF_LIST) break;

        /*disable UART*/
        CLR_BIT(ACCESS_UARTCTL(baseAdd), 0);

        /*set boudrate*/
        setBoudrate (baseAdd, uartConfig[i].boudrate);

        /*set parity*/
        setParity(baseAdd, uartConfig[i].parity);

        /*set stop bit*/
        setStopBit(baseAdd, uartConfig[i].num_of_stop_bits);

        /*set fifo state*/
        SetFIFO(baseAdd, uartConfig[i].fifo_state);

        /*set data length*/
        setDataLength (baseAdd, uartConfig[i].data_length);

        /*enable UART*/
        SET_BIT(ACCESS_UARTCTL(baseAdd), 0);
    }

}


void UART_sendChar (UART_NumType uart,  uint8 ch)
{
    uint32 baseAdd = UART_GetBaseAdr(uart);
    ACCESS_UARTDR(baseAdd) = ch;
    /*bug*/
    while (GET_BIT(ACCESS_UARTFR(baseAdd), 5) == 1);
}





