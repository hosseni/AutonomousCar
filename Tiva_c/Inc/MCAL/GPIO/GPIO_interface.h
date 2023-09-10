


#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "../../../Inc/LIB/BIT_MATH.h"
#include "../../../Inc/LIB/STD_TYPES.h"
#include "../../../TM4C123GH6PM.h"
/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
#define AF_GPIO     0x00
#define AF_UART     0x01
#define AF_SPI      0x05
#define AF_I2C      0x03
#define AF_TIMER    0x07

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/

/*typedef enum
{
    LOW,
    HIGH
} DIO_LevelType;*/
typedef uint8 DIO_LevelType;
#define LOW 0
#define HIGH 1
typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
} Port_PortType;

typedef enum
{
    PIN_NC = -1, /* Sentinel value to detect an unvalid pin */

    PIN_A0 = 0,
    PIN_A1 = 1,
    PIN_A2 = 2,
    PIN_A3 = 3,
    PIN_A4 = 4,
    PIN_A5 = 5,
    PIN_A6 = 6,
    PIN_A7 = 7,

    PIN_B0 = 8,
    PIN_B1 = 9,
    PIN_B2 = 10,
    PIN_B3 = 11,
    PIN_B4 = 12,
    PIN_B5 = 13,
    PIN_B6 = 14,
    PIN_B7 = 15,

    PIN_C0 = 16,
    PIN_C1 = 17,
    PIN_C2 = 18,
    PIN_C3 = 19,
    PIN_C4 = 20,
    PIN_C5 = 21,
    PIN_C6 = 22,
    PIN_C7 = 23,

    PIN_D0 = 24,
    PIN_D1 ,
    PIN_D2 ,
    PIN_D3 ,
    PIN_D4 ,
    PIN_D5 ,
    PIN_D6 ,
    PIN_D7 ,


    PIN_E0 = 32,
    PIN_E1 ,
    PIN_E2 ,
    PIN_E3 ,
    PIN_E4 ,
    PIN_E5 ,

    PIN_F0 = 40,
    PIN_F1 = 41,
    PIN_F2 = 42,
    PIN_F3 = 43,
    PIN_F4 = 44
} Port_PinType;

typedef enum
{
    PIN_OUTPUT,
    PIN_INPUT
} Port_PinDirectionType;

typedef enum
{
    PIN_DIO,
    PIN_DIO_INTERRUPT,
} Port_PinDModeType;
typedef enum
{
   PIN_AF_DISABLE,
   PIN_AF_ENABLE_UART,
   PIN_AF_ENABLE_SPI,
   PIN_AF_ENABLE_I2C,
   PIN_AF_ENABLE_TIMER,

}Port_PinAFType;


typedef enum
{
    PIN_OPENDRAIN,
    PIN_PULLUP,
    PIN_PULLDOWN
} Port_PiInternalAttachType;

typedef enum
{
    PIN_CURRENT_2mA,
    PIN_CURRENT_4mA,
    PIN_CURRENT_8mA
} Port_PinOutputCurrentType;

typedef struct
{
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinDModeType mode;
    Port_PinAFType    type;
    Port_PiInternalAttachType internalAttach;
    Port_PinOutputCurrentType outputCurrent;
} Port_ConfigType;

typedef Port_PinType DIO_ChannelType;

typedef Port_PortType DIO_PortType;

typedef uint8 DIO_PortLevelType;

#define NUM_PINS 43

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
void DIO_Init(const Port_ConfigType portConfig[]);
DIO_LevelType DIO_ReadChannel(DIO_ChannelType Channelid);
void DIO_WriteChannel(DIO_ChannelType Channelid, DIO_LevelType Level);
DIO_PortLevelType DIO_ReadPort(DIO_PortType Portid);
void DIO_WritePort(DIO_PortType Portid, DIO_PortLevelType Level);
DIO_LevelType DIO_FlipChannel(DIO_ChannelType Channelid);

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* DIO_H_INCLUDED */
