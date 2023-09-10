/************************************
 * INCLUDES
 ************************************/

#include "Inc/MCAL/GPIO/GPIO_config.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"



/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/



const Port_ConfigType portConfig[NUM_PINS] =
{
 /* Pin          Direction           Mode         AF typr                    Attach Type         Output Current */
 // { PIN_F1,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},
 // { PIN_F2,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},
 // { PIN_F3,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},

 { PIN_B7,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//SIDE_A_PIN0
 { PIN_B1,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//SIDE_A_PIN1
 { PIN_B5,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//SIDE_B_PIN0
 { PIN_E5,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//SIDE_B_PIN1

 { PIN_B4,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_ENABLE_TIMER,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//TIMER1
 { PIN_B0,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_ENABLE_TIMER,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//TIMER2

 { PIN_A3,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//LCD_D4
 { PIN_A4,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//LCD_D5
 { PIN_A5,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//LCD_D6
 { PIN_A6,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//LCD_D7

 { PIN_E2,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//LCD_EN
 { PIN_E3,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//LCD_RS

 { PIN_B2,       PIN_INPUT,         PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLDOWN,          PIN_CURRENT_2mA},//ECHO
 { PIN_B3,       PIN_OUTPUT,        PIN_DIO,     PIN_AF_DISABLE,            PIN_PULLUP,            PIN_CURRENT_2mA},//TIGGER

 { PIN_NC }

 /* This is the sentinel terminating element of the array and should never be changed */

};


/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
