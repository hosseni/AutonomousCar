
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
#include "Inc/HAL/SWITCH/switch.h"

#include "Inc/APP/AutonomousCar/AutonomousCar.h"

#include "Inc/LIB/DELAY.h"
#include "hw_gpio.h"
#include <stdlib.h>

extern const SYSTIC_ConfigType   SYSTIC_Config [1] ;
extern const SCB_ConfigType      SCBConfig[SCB_CLOCK_SETTINGS_SIZE];
extern const Port_ConfigType     portConfig[NUM_PINS];
extern const GPT_ConfigType      gptConfig [NUM_TIMER];


ultraSonic_t ultraSonic1  = {PIN_B2, PIN_B3};
lcd_t        lcd_car      = {PIN_E2, PIN_E3, { PIN_A3, PIN_A4, PIN_A5, PIN_A6}, _4_BIT};

button_t     start_button = {PIN_F0, PULL_UP, RELEASED};
button_t     stop_button  = {PIN_F4, PULL_UP, RELEASED};


adc_config_t LDR_1 = {.ADCn = 0,  .ADC_Channel = ADC_CTL_CH4 ,.ADC_TRIGGER = 1, .sequencer = ADC_sequencer_3};
adc_config_t LDR_2 = {.ADCn = 0,  .ADC_Channel = ADC_CTL_CH5 ,.ADC_TRIGGER = 1, .sequencer = ADC_sequencer_3};

uint32 LDR_L_read;
uint32 LDR_R_read;
uint32 distance;
sint32 LDR_Direction;
uint8  move_flag;
uint8  start_move_flag;
uint16 temp ;

void start_stop_condition (void)
{
     if (PRESSED == button_get_state(&start_button))
     {
         start_move_flag = 1;
     }
     else if (PRESSED == button_get_state(&stop_button))
     {
         start_move_flag = 0;
     }
}
void ldr_swing_car(void)
{
    uint32 counter = 0;
    LDR_L_read = ADC_Read_Data(&LDR_2);
    LDR_R_read = ADC_Read_Data(&LDR_1);
    LDR_Direction = LDR_R_read - LDR_L_read;

    if (move_flag == 0)
    {
        robotMoveStop();
    }
    else if (move_flag == 1)
    {
        if (LDR_Direction > 400)
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
    else if (move_flag == 2)
    {
        while (counter < 50000)
        {
            counter++;
            robotMoveback();
        }
        counter = 0;
        while (counter < 50000)
        {
            counter++;
            robotMoveRotate();
        }
    }


}

void lcd_display(void)
{
    lcd_send_command(&lcd_car, _LCD_CLEAR);
    lcd_send_string_pos(&lcd_car , "D : ", ROW0, COL0);
    lcd_send_number_pos(&lcd_car , distance, ROW0, COL4);
}
void avoid_obstacles(void)
{
    distance =  ultarsonicSensorReadValue(&ultraSonic1);
    if (start_move_flag == 0)
    {
        move_flag = 0;
    }
    else if ((start_move_flag == 1)&&(distance > 15))
    {
        move_flag = 1;
    }
    else if (distance < 15)
    {
        move_flag = 2;
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

    create_task(0, 7, start_stop_condition, 0);
    create_task(1, 10, avoid_obstacles, 7);
    create_task(2, 12, ldr_swing_car, 5);

    tasks_scheduler();

    /* Infinite Loop */
    while (1)
    {
    }
}
