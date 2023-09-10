#include "Inc/MCAL/GPIO/GPIO_private.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/MCAL/GPIO/GPIO_config.h"


/***************************************************************************************************
 *  Function: DIO_SetType
 *  Description:
 *      This function configures the digital enable (DEN) bit of the specified GPIO pin in a
 *      specific port based on the provided pin mode.
 *  Parameters:
 *      pin_num: The pin number to configure.
 *      pin_mode: The desired pin mode (PIN_DIO or other modes).
 *  Return Value:
 *      None
 ***************************************************************************************************/
static void DIO_SetType (Port_PinType pin_num, Port_PinDModeType pin_mode)
{
    switch (((uint8)pin_num / 8u))
    {
    /* Case Port A */
    case PORT_A:
        if (pin_mode == PIN_DIO)
            SET_BIT(GPIODEN_APB_A, (pin_num % 8));
        else
            CLR_BIT(GPIODEN_APB_A, (pin_num % 8));
        break;
        /* Case Port B */
    case PORT_B:
        if (pin_mode == PIN_DIO)
            SET_BIT(GPIODEN_APB_B, (pin_num % 8));
        else
            CLR_BIT(GPIODEN_APB_B, (pin_num % 8));
        break;
        /* Case Port C */
    case PORT_C:
        if (pin_mode == PIN_DIO)
            SET_BIT(GPIODEN_APB_C, (pin_num % 8));
        else
            CLR_BIT(GPIODEN_APB_C, (pin_num % 8));
        break;
    case PORT_D:
        if (pin_mode == PIN_DIO)
            SET_BIT(GPIODEN_APB_D, (pin_num % 8));
        else
            CLR_BIT(GPIODEN_APB_D, (pin_num % 8));
        break;
    case PORT_E:
        if (pin_mode == PIN_DIO)
            SET_BIT(GPIODEN_APB_E, (pin_num % 8));
        else
            CLR_BIT(GPIODEN_APB_E, (pin_num % 8));
        break;

        /* Case Port F */
    case PORT_F:
        if (pin_mode == PIN_DIO)
            SET_BIT(GPIODEN_APB_F, (pin_num % 8));
        else
            CLR_BIT(GPIODEN_APB_F, (pin_num % 8));
        break;
    }

}
/***************************************************************************************************
 *  Function: DIO_SetAtt
 *  Description:
 *      This function configures the pull-up or pull-down resistor for the specified GPIO pin in a
 *      specific port based on the provided attachment type.
 *  Parameters:
 *      pin_num: The pin number to configure.
 *      pin_att: The desired attachment type (PIN_PULLUP or other types).
 *  Return Value:
 *      None
 ***************************************************************************************************/
static void DIO_SetAtt (Port_PinType pin_num, Port_PiInternalAttachType pin_att)
{
    /* Adjust the pin attachement */
    switch (((uint8)pin_num / 8u))
    {
    /* Case Port A */
    case PORT_A:
        if (pin_att == PIN_PULLUP)
            SET_BIT(GPIOPUR_APB_A, (pin_num % 8));
        else
            SET_BIT(GPIOPDR_APB_A, (pin_num % 8));
        break;
        /* Case Port B */
    case PORT_B:
        if (pin_att == PIN_PULLUP)
            SET_BIT(GPIOPUR_APB_B, (pin_num % 8));
        else
            SET_BIT(GPIOPDR_APB_B, (pin_num % 8));
        break;
        /* Case Port C */
    case PORT_C:
        if (pin_att == PIN_PULLUP)
            SET_BIT(GPIOPUR_APB_C, (pin_num % 8));
        else
            SET_BIT(GPIOPDR_APB_C, (pin_num % 8));
        break;
        /* Case Port D */
    case PORT_D:
        if (pin_att == PIN_PULLUP)
            SET_BIT(GPIOPUR_APB_D, (pin_num % 8));
        else
            SET_BIT(GPIOPDR_APB_D, (pin_num % 8));
        break;
    case PORT_E:
        if (pin_att == PIN_PULLUP)
            SET_BIT(GPIOPUR_APB_E, (pin_num % 8));
        else
            SET_BIT(GPIOPDR_APB_E, (pin_num % 8));
        break;
    case PORT_F:
        if (pin_att == PIN_PULLUP)
            SET_BIT(GPIOPUR_APB_F, (pin_num % 8));
        else
            SET_BIT(GPIOPDR_APB_F, (pin_num % 8));
        break;
    }

}
static void DIO_SetDir (Port_PinType pin_num, Port_PinDirectionType pin_dir)
{
    /* Adjust the pin direction */
    switch (((uint8)pin_num / 8u))
    {
    /* Case Port A */
    case PORT_A:
        if (pin_dir == PIN_OUTPUT)
            SET_BIT(GPIODIR_APB_A, (pin_num % 8));
        else
            CLR_BIT(GPIODIR_APB_A, (pin_num % 8));
        break;
        /* Case Port B */
    case PORT_B:
        if (pin_dir == PIN_OUTPUT)
            SET_BIT(GPIODIR_APB_B, (pin_num % 8));
        else
            CLR_BIT(GPIODIR_APB_B, (pin_num % 8));
        break;
        /* Case Port C */
    case PORT_C:
        if (pin_dir == PIN_OUTPUT)
            SET_BIT(GPIODIR_APB_C, (pin_num % 8));
        else
            CLR_BIT(GPIODIR_APB_C, (pin_num % 8));
        break;
        /* Case Port D */
    case PORT_D:
        if (pin_dir == PIN_OUTPUT)
            SET_BIT(GPIODIR_APB_D, (pin_num % 8));
        else
            CLR_BIT(GPIODIR_APB_D, (pin_num % 8));
        break;
    case PORT_E:
        if (pin_dir == PIN_OUTPUT)
            SET_BIT(GPIODIR_APB_E, (pin_num % 8));
        else
            CLR_BIT(GPIODIR_APB_E, (pin_num % 8));
        break;
    case PORT_F:
        if (pin_dir == PIN_OUTPUT)
            SET_BIT(GPIODIR_APB_F, (pin_num % 8));
        else
            CLR_BIT(GPIODIR_APB_F, (pin_num % 8));
        break;
    }

}
/***************************************************************************************************
 *  Function: DIO_SetDir
 *  Description:
 *      This function configures the direction (input/output) of the specified GPIO pin in a specific
 *      port based on the provided pin direction.
 *  Parameters:
 *      pin_num: The pin number to configure.
 *      pin_dir: The desired pin direction (PIN_OUTPUT or other direction).
 *  Return Value:
 *      None
 ***************************************************************************************************/
static void DIO_SetAF (Port_PinType pin_num, Port_PinAFType AF)
{
    switch (pin_num / 8u)
    {
    case PORT_A:
        SET_BIT(GPIOAFSEL_APB_A, (pin_num % 8));
        if (AF == PIN_AF_ENABLE_TIMER)
            GPIOPCTL_APB_A |= (AF_TIMER<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_I2C)
            GPIOPCTL_APB_A |= (AF_I2C<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_UART)
            GPIOPCTL_APB_A |= (AF_UART<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_SPI)
            GPIOPCTL_APB_A |= (AF_SPI<< (4*(pin_num % 8)));
        break;

    case PORT_B:
        SET_BIT(GPIOAFSEL_APB_B, (pin_num % 8));
        if (AF == PIN_AF_ENABLE_TIMER)
            GPIOPCTL_APB_B |= (AF_TIMER<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_I2C)
            GPIOPCTL_APB_B |= (AF_I2C<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_UART)
            GPIOPCTL_APB_B |= (AF_UART<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_SPI)
            GPIOPCTL_APB_B |= (AF_SPI<< (4*(pin_num % 8)));

        break;

    case PORT_C:
        SET_BIT(GPIOAFSEL_APB_C, (pin_num % 8));
        if (AF == PIN_AF_ENABLE_TIMER)
            GPIOPCTL_APB_C |= (AF_TIMER<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_I2C)
            GPIOPCTL_APB_C |= (AF_I2C<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_UART)
            GPIOPCTL_APB_C |= (AF_UART<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_SPI)
            GPIOPCTL_APB_C |= (AF_SPI<< (4*(pin_num % 8)));
        break;

    case PORT_D:
        SET_BIT(GPIOAFSEL_APB_D, (pin_num % 8));
        if (AF == PIN_AF_ENABLE_TIMER)
            GPIOPCTL_APB_D |= (AF_TIMER<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_I2C)
            GPIOPCTL_APB_D |= (AF_I2C<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_UART)
            GPIOPCTL_APB_D |= (AF_UART<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_SPI)
            GPIOPCTL_APB_D |= (AF_SPI<< (4*(pin_num % 8)));

        break;
    case PORT_E:
        SET_BIT(GPIOAFSEL_APB_E, (pin_num % 8));
        if (AF == PIN_AF_ENABLE_TIMER)
            GPIOPCTL_APB_E |= (AF_TIMER<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_I2C)
            GPIOPCTL_APB_E |= (AF_I2C<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_UART)
            GPIOPCTL_APB_E |= (AF_UART<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_SPI)
            GPIOPCTL_APB_E |= (AF_SPI<< (4*(pin_num % 8)));
        break;

    case PORT_F:
        SET_BIT(GPIOAFSEL_APB_F, (pin_num % 8));
        if (AF == PIN_AF_ENABLE_TIMER)
            GPIOPCTL_APB_F |= (AF_TIMER << (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_I2C)
            GPIOPCTL_APB_F |= (AF_I2C<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_UART)
            GPIOPCTL_APB_F |= (AF_UART<< (4*(pin_num % 8)));

        else if (AF == PIN_AF_ENABLE_SPI)
            GPIOPCTL_APB_F |= (AF_SPI<< (4*(pin_num % 8)));
        break;
    }

}

/***************************************************************************************************
 *  Function: DIO_Config
 *  Description:
 *      This function configures the GPIO pins according to the provided configuration array.
 *  Parameters:
 *      portConfig: Pointer to an array of Port_ConfigType containing pin configuration settings.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void DIO_Init(const Port_ConfigType portConfig[])
{
    Port_ConfigType currentConfig;

    uint8 i = 0;

    /* Loop until either the sentinel value is reached to detect the end of array or until maximum number of pins is reached */
    for (i = 0; i < NUM_PINS; i++)
    {
        /* Get the values of the current iteration of the array  */
        currentConfig = portConfig[i];

        /* Exit if this is the PORT_NC pin*/
        if (currentConfig.pin == PIN_NC)
            break;


        if ((currentConfig.pin == PIN_F0)||(currentConfig.pin == PIN_F4))
        {
            GPIOLOCK_APB_F = 0x4C4F434Bu;
            GPIOCR_APB_F = 0x01u;
        }
        if ((currentConfig.pin == PIN_A0)||(currentConfig.pin == PIN_A1))
        {
            GPIOLOCK_APB_A = 0x4C4F434Bu;
            GPIOCR_APB_A = 0x01u;
        }

        if ((currentConfig.direction == PIN_OUTPUT)||(currentConfig.direction == PIN_INPUT))
            DIO_SetDir((currentConfig.pin), (currentConfig.direction));

        if (currentConfig.type != PIN_AF_DISABLE)
            DIO_SetAF((currentConfig.pin), currentConfig.type);

        if ((currentConfig.mode == PIN_DIO)||(currentConfig.mode == PIN_DIO_INTERRUPT))
            DIO_SetType(currentConfig.pin, currentConfig.mode);

        if ((currentConfig.internalAttach == PIN_PULLUP)||(currentConfig.internalAttach == PIN_PULLDOWN))
            DIO_SetAtt(currentConfig.pin , currentConfig.internalAttach);


        /* Lock the pin if it was originally locked */
        if ((currentConfig.pin == PIN_F0)||(currentConfig.pin == PIN_F4))
        {
            GPIOLOCK_APB_F = 0x4C4F434Bu;
            GPIOCR_APB_F = 0x00u;
        }
        if ((currentConfig.pin == PIN_A0)||(currentConfig.pin == PIN_A1))
        {
            GPIOLOCK_APB_A = 0x4C4F434Bu;
            GPIOCR_APB_A = 0x00u;
        }
    }
}
/***************************************************************************************************
 *  Function: DIO_ReadChannel
 *  Description:
 *      This function reads the logical level of a specific GPIO channel.
 *  Parameters:
 *      Channelid: The ID of the GPIO channel to be read.
 *  Return Value:
 *      DIO_LevelType: The logical level of the specified channel.
 ***************************************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType Channelid)
{
    DIO_LevelType value;

    uint32 bitPos;
    //uint32 regOffset;

    bitPos = Channelid%8u;

    switch ((Channelid / 8))
    {
    case PORT_A:
        value = GET_BIT(GPIODATA_APB_A, bitPos);
        break;
    case PORT_B:
        value = GET_BIT(GPIODATA_APB_B, bitPos);
        break;
    case PORT_C:
        value = GET_BIT(GPIODATA_APB_C, bitPos);
        break;
    case PORT_D:
        value = GET_BIT(GPIODATA_APB_D, bitPos);
        break;
    case PORT_E:
        value = GET_BIT(GPIODATA_APB_E, bitPos);
        break;
    case PORT_F:
        value = GET_BIT(GPIODATA_APB_F, bitPos);
        break;
    }
    /* This should be replaced with an array access (or a hash function) to reduce access time*/
    //regOffset = (Channelid/8u)*(GPIO_B_APB_BASE-GPIO_A_APB_BASE) + 0x3FCu + GPIO_A_APB_BASE - BITBAND_PRPH_BASE; /* The 0x3FCu is essential to allow writing to the GPIO regsiter (check datasheet) */
    //value = ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE);

    return value;
}
/***************************************************************************************************
 *  Function: DIO_WriteChannel
 *  Description:
 *      This function writes a logical level to a specific GPIO channel.
 *  Parameters:
 *      Channelid: The ID of the GPIO channel to be written.
 *      Level: The logical level to be written (HIGH or LOW).
 *  Return Value:
 *      None
 ***************************************************************************************************/
void DIO_WriteChannel(DIO_ChannelType Channelid, DIO_LevelType Level)
{

    uint32 bitPos;
    //uint32 regOffset;

    bitPos = Channelid%8u;
    switch (Channelid / 8)
    {
    case PORT_A:
        if (HIGH == Level)
            SET_BIT(GPIODATA_APB_A, bitPos);
        else
            CLR_BIT(GPIODATA_APB_A, bitPos);
        break;
    case PORT_B:
        if (HIGH == Level)
            SET_BIT(GPIODATA_APB_B, bitPos);
        else
            CLR_BIT(GPIODATA_APB_B, bitPos);
        break;
    case PORT_C:
        if (HIGH == Level)
            SET_BIT(GPIODATA_APB_C, bitPos);
        else
            CLR_BIT(GPIODATA_APB_C, bitPos);
        break;
    case PORT_D:
        if (HIGH == Level)
            SET_BIT(GPIODATA_APB_D, bitPos);
        else
            CLR_BIT(GPIODATA_APB_D, bitPos);
        break;
    case PORT_E:
        if (HIGH == Level)
            SET_BIT(GPIODATA_APB_E, bitPos);
        else
            CLR_BIT(GPIODATA_APB_E, bitPos);
        break;
    case PORT_F:
        if (HIGH == Level)
            SET_BIT(GPIODATA_APB_F, bitPos);
        else
            CLR_BIT(GPIODATA_APB_F, bitPos);
        break;
    }
    /* This should be replaced with an array access (or a hash function) to reduce access time*/
    //       regOffset = (Channelid/8u)*(GPIO_B_APB_BASE-GPIO_A_APB_BASE) + 0x3FCu + GPIO_A_APB_BASE - BITBAND_PRPH_BASE; /* The 0x3FCu is essential to allow writing to the GPIO regsiter (check datasheet) */
    //
    //       if((Level == HIGH)&&(Channelid/8 != PORT_F))
    //       {
    //           ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE) = 1;
    //       }
    //       else if ((Level == LOW)&&(Channelid/8 != PORT_F))
    //       {
    //           ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE) = 0;
    //       }
}
/***************************************************************************************************
 *  Function: DIO_ReadPort
 *  Description:
 *      This function reads the logical levels of all pins within a specific GPIO port.
 *  Parameters:
 *      Portid: The ID of the GPIO port to be read.
 *  Return Value:
 *      DIO_PortLevelType: The logical levels of all pins within the specified port.
 ***************************************************************************************************/
DIO_PortLevelType DIO_ReadPort(DIO_PortType Portid)
{
    DIO_PortLevelType value;

    switch (Portid)
    {
    case PORT_A:
        value = (DIO_PortLevelType)GPIODATA_APB_A;
        break;
    case PORT_B:
        value = (DIO_PortLevelType)GPIODATA_APB_B;
        break;
    case PORT_C:
        value = (DIO_PortLevelType)GPIODATA_APB_C;
        break;
    case PORT_D:
        value = (DIO_PortLevelType)GPIODATA_APB_D;
        break;
    case PORT_E:
        value = (DIO_PortLevelType)GPIODATA_APB_E;
        break;
    case PORT_F:
        value = (DIO_PortLevelType)GPIODATA_APB_F;
        break;
    }
    return value;
}
/***************************************************************************************************
 *  Function: DIO_WritePort
 *  Description:
 *      This function writes logical levels to all pins within a specific GPIO port.
 *  Parameters:
 *      Portid: The ID of the GPIO port to be written.
 *      Level: The logical levels to be written to all pins within the specified port.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void DIO_WritePort(DIO_PortType Portid, DIO_PortLevelType Level)
{
    switch (Portid)
    {
    default:
        GPIODATA_APB_A = Level;
        break;
    case PORT_B:
        GPIODATA_APB_B = Level;
        break;
    case PORT_C:
        GPIODATA_APB_C = Level;
        break;
    case PORT_F:
        GPIODATA_APB_F = Level;
        break;
    }
}
/***************************************************************************************************
 *  Function: DIO_FlipChannel
 *  Description:
 *      This function toggles the logical level of a specific GPIO channel and returns its previous
 *      logical level.
 *  Parameters:
 *      Channelid: The ID of the GPIO channel to be toggled.
 *  Return Value:
 *      DIO_LevelType: The previous logical level of the specified channel.
 ***************************************************************************************************/
DIO_LevelType DIO_FlipChannel(DIO_ChannelType Channelid)
{
    DIO_LevelType oldLevel = DIO_ReadChannel(Channelid);
    DIO_WriteChannel(Channelid, (1u - oldLevel));
    return oldLevel;
}
