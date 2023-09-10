/*******************************************************
 * UART_interface.h
 *
 *  Created on: 8/9/2023
 *      Author: HOSSENI
 *******************************************************/

#ifndef INC_MCAL_UART_UART_INTERFACE_H_
#define INC_MCAL_UART_UART_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#define ACCESS_UARTDR(x)        ACCESS_ADR(x + 0x000u)
#define ACCESS_UARTCTL(x)       ACCESS_ADR(x + 0x030u)
#define ACCESS_UARTIBRD(x)       ACCESS_ADR(x + 0x024u)
#define ACCESS_UARTFBRD(x)       ACCESS_ADR(x + 0x028u)
#define ACCESS_UARTLCRH(x)       ACCESS_ADR(x + 0x02Cu)
#define ACCESS_UARTFR(x)       ACCESS_ADR(x + 0x018u)



typedef enum
{
    noParity,
    evenParity,
    oddParity
}ParityType;

typedef float32 BoudrateType ;

typedef enum
{
    oneStopBit,
    twoStopBits
}StopBitType;

typedef enum
{
    _5_BitData,
    _6_BitData,
    _7_BitData,
    _8_BitDatat
}DataLengthType;

typedef enum
{
    UART_0_,
    UART_1_,
    UART_2_,
    UART_3_,
    UART_4_,
    UART_5_,
    UART_6_,
    UART_7_

}UART_NumType;

typedef enum
{
    UART_INTERRUPT_ENABLE,
    UART_INTERRUPT_DESABLE
}UART_InterruptStateType;
typedef enum
{
    FIFO_ENABLE,
    FIFO_DISABLE
}FIFO_StateType;
typedef struct
{
    UART_NumType            uart;
    BoudrateType            boudrate;
    DataLengthType          data_length;
    ParityType              parity;
    StopBitType             num_of_stop_bits;
    UART_InterruptStateType interrupt_state;
    FIFO_StateType          fifo_state;
}UART_ConfigType;

void UART_init (UART_ConfigType const * uartConfig);
void UART_sendChar (UART_NumType uart,  uint8 ch);


#endif /* INC_MCAL_UART_UART_INTERFACE_H_ */
