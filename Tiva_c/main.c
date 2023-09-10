#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"
#include "Inc/MCAL/GPT/GPT_interface.h"
#include "Inc/MCAL/UART/UART_interface.h"
#include "Inc/MCAL/UART/UART_config.h"
#include "Inc/SERVICES/SCHEDULAR/Schedular_interface.h"

#include "Inc/HAL/ULTRASONIC/ultrasonic.h"
#include "Inc/HAL/LCD/lcd.h"
#include "Inc/HAL/MOTOR/motor.h"

#include "Inc/APP/AutonomousCar/AutonomousCar.h"
#include "Inc/LIB/DELAY.h"
#include <stdlib.h>

//extern const UART_ConfigType uartConfig [NUM_OF_UARTS];
extern const SYSTIC_ConfigType   SYSTIC_Config [1] ;
extern const SCB_ConfigType      SCBConfig[SCB_CLOCK_SETTINGS_SIZE];
extern const Port_ConfigType     portConfig[NUM_PINS];
extern const GPT_ConfigType      gptConfig [NUM_TIMER];


ultraSonic_t ultraSonic1 = {PIN_B2, PIN_B3};
lcd_t        lcd_car     = {PIN_E2, PIN_E3, { PIN_A3, PIN_A4, PIN_A5, PIN_A6}, _4_BIT};
//PIN_D0, PIN_D1, PIN_D2, PIN_D3,
uint32 destance ;

void check_destacne (void)
{
    destance =  ultarsonicSensorReadValue(&ultraSonic1);
}
void print_destance (void)
{
    lcd_send_command(&lcd_car, _LCD_CLEAR);
    lcd_send_string_pos(&lcd_car , "Distance: ", ROW1, COL0);
    lcd_send_number_pos(&lcd_car , destance, ROW1, COL11);
}



// Main function
void main(void)
{
    /* Initialize System */
    SCB_Init(SCBConfig);
    SCB_InitClock(CLOCK_0);
    DIO_Init(portConfig);
    SYSTICK_Init (SYSTIC_Config);
    GPT_Init(gptConfig);
    lcd_init(&lcd_car);

    lcd_send_string_pos(&lcd_car , "Autonomous Car", ROW0, COL1);
    robotInit();

    RTOS_voidCreatTask(0, 200, check_destacne, 0);
    RTOS_voidCreatTask(1, 1000, print_destance, 100);

//     RTOS_voidInit();

    /* Infinite Loop */
    while (1)
    {

        destance =  ultarsonicSensorReadValue(&ultraSonic1);

        lcd_send_command(&lcd_car, _LCD_CLEAR);
        lcd_send_string_pos(&lcd_car , "Distance: ", ROW1, COL0);
        lcd_send_number_pos(&lcd_car , destance, ROW1, COL11);

        if (destance > 10 && destance < 400)
        {
            lcd_send_string_pos(&lcd_car , "Running", ROW0, COL0);
            robotMoveForward();
        }
        else
        {
            lcd_send_string_pos(&lcd_car , "Stopped  ", ROW0, COL0);
            robotMoveStop();
        }
    }
}
