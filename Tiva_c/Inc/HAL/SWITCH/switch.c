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
 * [DESCRIPTION]: source file for switch driver                                *
 *                                                                             *
 *******************************************************************************/

#include <Inc/HAL/SWITCH/switch.h>
/*******************************************************************************
 *                              Functions Definition                           *
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
buttonState_t button_get_state(button_t *btn) {


    uint8 state ;
    buttonState_t btn_state ;
    state = DIO_ReadChannel(btn->btnPin);
    switch(btn-> btn_conn)
    {
    case PULL_UP :
        switch(state)
        {
        case LOW :
            btn_state = PRESSED ;
            break;
        case HIGH :
            btn_state = RELEASED ;
            break;
        }
        break;
        case PULL_DOWN :
            switch(state)
            {
            case LOW :
                btn_state = RELEASED ;
                break;
            case HIGH :
                btn_state = PRESSED ;
                break;
            default :
                break;
            }
            break;
    }
return btn_state;
}




