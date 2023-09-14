/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   gpio.h                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Amr Gafar, Kareem Abd-elrasheed,                *
 *                Mohamed Abosreea, Ahmed Maher, and Mohamed Ramadan           *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        09/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for switch driver                                *
 *                                                                             *
 *******************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H
/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*
 * Description:
 * Enum to specify hardware connection of the switch,
 * including GPIO.
 */
typedef enum {
    PULL_DOWN = 0,
    PULL_UP
} buttonConnection_t;
/*
 * Description:
 * Enum to specify the state of the switch,
 * including GPIO.
 */
typedef enum {
    RELEASED = 0,
    PRESSED
}buttonState_t;
/*
 * Description:
 * Struct to specify configuration of the switch,
 * including GPIO.
 */
typedef struct
{
    DIO_ChannelType  btnPin;
    buttonConnection_t btn_conn;
    buttonState_t btn_state ;
}button_t;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * This function initializes the switch pin on the specified port and pin number.
 * It configures the pin as output based on the provided direction,
 * and sets up the necessary GPIO settings including pull-up/pull-down resistors.
 * Parameters:
 * - sensor: pointer to the switch configuration (PORT_ID , PIN_ID , HARDWARE CONNECTION , INITIAL STATE ).
 * - btn_state: pointer to return the current state of a switch (PRESSED , RELEASED).
 * Returns: None.
 */

buttonState_t button_get_state(button_t *btn) ;


#endif  /* BUTTON_H */
