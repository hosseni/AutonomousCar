#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"
#include "Inc/MCAL/GPT/GPT_interface.h"
#include "Inc/MCAL/UART/UART_interface.h"
#include "Inc/MCAL/ADC/adc.h"
#include "Inc/MCAL/UART/UART_config.h"
#include "Inc/SERVICES/SCHEDULAR/Schedular_interface.h"

#include "Inc/HAL/ULTRASONIC/ultrasonic.h"
#include "Inc/HAL/LCD/lcd.h"
#include "Inc/HAL/MOTOR/motor.h"

#include "Inc/APP/AutonomousCar/AutonomousCar.h"
#include "Inc/LIB/DELAY.h"
#include "hw_gpio.h"
#include <stdlib.h>

extern const SYSTIC_ConfigType   SYSTIC_Config [1] ;
extern const SCB_ConfigType      SCBConfig[SCB_CLOCK_SETTINGS_SIZE];
extern const Port_ConfigType     portConfig[NUM_PINS];
extern const GPT_ConfigType      gptConfig [NUM_TIMER];


ultraSonic_t ultraSonic1 = {PIN_B2, PIN_B3};
lcd_t        lcd_car     = {PIN_E2, PIN_E3, { PIN_A3, PIN_A4, PIN_A5, PIN_A6}, _4_BIT};

adc_config_t LDR_1 = {.ADCn = 0,  .ADC_Channel = ADC_CTL_CH4 ,.ADC_TRIGGER = 1, .sequencer = ADC_sequencer_3};
adc_config_t LDR_2 = {.ADCn = 0,  .ADC_Channel = ADC_CTL_CH5 ,.ADC_TRIGGER = 1, .sequencer = ADC_sequencer_3};

uint32 LDR_L_read;
uint32 LDR_R_read;
uint32 distance;
sint32 LDR_Direction;
uint8  move_flag;
void ldr_swing_car(void)
{
    LDR_L_read = ADC_Read_Data(&LDR_2);
    LDR_R_read = ADC_Read_Data(&LDR_1);
    LDR_Direction = LDR_R_read - LDR_L_read;

    if (move_flag == 1)
    {
        if (LDR_Direction > 1000)
        {
            robotMoveRight();
        }
        else if (LDR_Direction < 0)
        {
            robotMoveLeft();
        }
        else
        {
            robotMoveForward();
        }
    }

}

void lcd_display(void)
{
    lcd_send_string_pos(&lcd_car , "Autonomous Car", ROW0, COL1);
}
void avoid_obstacles(void)
{
    distance =  ultarsonicSensorReadValue(&ultraSonic1);

    if (distance < 10)
    {
        robotMoveStop();
        move_flag = 0;
    }
    else
    {
        move_flag = 1;
        robotMoveForward();
    }

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
    robotInit();

    GPIO_PORTD_AFSEL_R |= (1<<2);
    GPIO_PORTD_DEN_R &= ~(1<<2);
    GPIO_PORTD_AMSEL_R|= (1<<2);

    GPIO_PORTD_AFSEL_R |= (1<<3);
    GPIO_PORTD_DEN_R &= ~(1<<3);
    GPIO_PORTD_AMSEL_R|= (1<<3);

    ADC_Init(&LDR_2);
    ADC_Init(&LDR_1);

    create_task(0, 7, ldr_swing_car, 0);
    create_task(1, 10, avoid_obstacles, 5);
    create_task(2, 25, lcd_display, 12);

    tasks_scheduler();

    /* Infinite Loop */
    while (1)
    {



//        distance =  ultarsonicSensorReadValue(&ultraSonic1);
//
//        LDR_L_read = ADC_Read_Data(&LDR_2);
//        LDR_R_read = ADC_Read_Data(&LDR_1);
//        LDR_Direction = LDR_R_read - LDR_L_read;
//
//        if (distance < 10)
//        {
//            robotMoveStop();
//        }
//
//        else if (distance > 10)
//        {
//            if (LDR_Direction > 1000)
//            {
//                robotMoveRight();
//            }
//            else if (LDR_Direction < 0)
//            {
//                robotMoveLeft();
//            }
//            else
//            {
//                robotMoveForward();
//            }
//        }
    }
}
