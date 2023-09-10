/********************************************************************************
 *  File: stopWatch.c
 *  Created on: 24/8/2024
 *  Author: HOSSENI
 ********************************************************************************/

#include "Inc/LIB/STD_TYPES.h"
#include "Inc/APP/StopWatch/stopWatch.h"
#include "Inc/HAL/LCD/lcd.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"

// Global variables
uint16 sec_num = 0;
uint16 min_num = 0;
uint8 start_flag = 0;
uint8 stop_flag = 0;
uint8 reset_flag = 0;
uint8 stop_watch_flag;

// LCD configuration structure
lcd_t lcd2 = {PIN_C7, PIN_C6, {PIN_A2, PIN_A3, PIN_A4, PIN_A6, PIN_B4, PIN_B5, PIN_B6, PIN_B7}, _8_BIT};

// External SysTick configuration
extern SYSTIC_ConfigType SYSTIC_Config[1];

/***************************************************************************************************
 *  Function:     stopWatch_init
 *  Description:  This function initializes the stop watch module by configuring the LCD and SysTick timer.
 *  Parameters:   None
 *  Return Value: None
 ***************************************************************************************************/
void stopWatch_init(void)
{
    // Initialize LCD
    lcd_init(&lcd2);
    lcd_send_string(&lcd2, "SW1 to start,   SW2 to stop ");
    delay (3000);
    // Initialize and configure the SysTick timer
    SYSTICK_Init(SYSTIC_Config);
    SYSTIC_voidSetIntervalPeriodic(1000, SYSTICK_Handler_app);
}

/***************************************************************************************************
 *  Function:     stopWatch_HandleMain
 *
 *  Description:  This function is the main handler for the stop watch functionality. It handles button inputs
 *                   and updates the time display on the LCD.
 *  Parameters:   None
 *  Return Value: None
 **********************************************************************************************************/
void stopWatch_HandleMain(void)
{
    if (stop_watch_flag == 1)
    {
        handle_buttons();

        if (start_flag == 1)
        {
            show_time();
        }
        else if ((stop_flag == 1) && (start_flag == 0))
        {
            stop_time();
        }
        else if (reset_flag == 1)
        {
          reset_time ();
        }
        else
        {
            lcd_send_command(&lcd2, _LCD_CLEAR);
        }

        stop_watch_flag = 0;
    }
}

/***************************************************************************************************
 *  Function:     SYSTICK_Handler_app
 *  Description:  This function is the SysTick timer interrupt handler that triggers the stop watch updates.
 *  Parameters:   None
 *  Return Value: None
 ***************************************************************************************************/
void SYSTICK_Handler_app(void)
{
    stop_watch_flag = 1;
}

/***************************************************************************************************
 *  Function:     show_time
 *  Description:  This function displays the current time on the LCD. It handles seconds and minutes display
 *                  logic.
 *  Parameters:   None
 *  Return Value: None
 ***************************************************************************************************/
void show_time(void)
{
    if (sec_num < 60)
    {
        lcd_send_chr_pos(&lcd2, ':', ROW0, COL2);
        if (sec_num < 10)
        {
            lcd_send_number_pos(&lcd2, sec_num, ROW0, COL4);
            sec_num++;
        }
        else
        {
            lcd_send_number_pos(&lcd2, sec_num, ROW0, COL3);
            lcd_send_chr_pos(&lcd2, ':', ROW0, COL2);
            sec_num++;
        }
    }
    else
    {
        if (min_num < 10)
        {
            sec_num = 0;
            lcd_send_number_pos(&lcd2, ++min_num, ROW0, COL1);
            lcd_send_chr_pos(&lcd2, ':', ROW0, COL2);
            lcd_send_number_pos(&lcd2, 0, ROW0, COL3);
            lcd_send_number_pos(&lcd2, 0, ROW0, COL4);
        }
        else
        {
            lcd_send_number_pos(&lcd2, min_num, ROW0, COL0);
            lcd_send_chr_pos(&lcd2, ':', ROW0, COL2);
            min_num++;
            lcd_send_number_pos(&lcd2, 0, ROW0, COL3);
            lcd_send_number_pos(&lcd2, 0, ROW0, COL4);
        }
    }
}

/***************************************************************************************************
 *  Function:     handle_buttons
 *  Description:  This function handles button inputs to control the start and stop of the stop watch.
 *  Parameter:    None
 *  Return Value: None
 ***************************************************************************************************/
void handle_buttons(void)
{
    if (DIO_ReadChannel(PIN_F4) == LOW)
    {
        start_flag = 1;
        stop_flag  = 0;
        reset_flag = 0;
    }
    else if ((DIO_ReadChannel(PIN_F0) == LOW)&&(stop_flag == 0))
    {
        start_flag = 0;
        stop_flag  = 1;
        reset_flag = 0;
    }
    else if ((DIO_ReadChannel(PIN_F0) == LOW)&&(stop_flag == 1))
    {
        start_flag = 0;
        stop_flag  = 0;
        reset_flag = 1;
    }
}

/***************************************************************************************************
 *  Function:     stop_time
 *  Description:  This function displays the stopped time on the LCD when the stop flag is set.
 *  Parameters:   None
 *  Return Value: None
 ***************************************************************************************************/
void stop_time(void)
{
    lcd_send_chr_pos(&lcd2, ':', ROW0, COL2);
    lcd_send_chr_pos(&lcd2, ':', ROW1, COL2);

    if (sec_num < 10)
    {
        lcd_send_number_pos(&lcd2, sec_num, ROW0, COL4);
        lcd_send_number_pos(&lcd2, sec_num, ROW1, COL4);

    }
    else
    {
        lcd_send_number_pos(&lcd2, sec_num, ROW0, COL3);
        lcd_send_number_pos(&lcd2, sec_num, ROW1, COL3);

    }

    if (min_num < 10)
    {
        lcd_send_number_pos(&lcd2, min_num, ROW0, COL1);
        lcd_send_number_pos(&lcd2, min_num, ROW1, COL1);

    }
    else
    {
        lcd_send_number_pos(&lcd2, min_num, ROW0, COL0);
        lcd_send_number_pos(&lcd2, min_num, ROW1, COL0);

    }
}

void reset_time(void)
{
    min_num = 0;
    sec_num = 0;
    lcd_send_command(&lcd2, _LCD_CLEAR);
    lcd_send_chr_pos(&lcd2, '.', ROW0, COL2);
    lcd_send_number_pos(&lcd2, 0, ROW0, COL0);
    lcd_send_number_pos(&lcd2, 0, ROW0, COL1);
    lcd_send_number_pos(&lcd2, 0, ROW0, COL3);
    lcd_send_number_pos(&lcd2, 0, ROW0, COL4);

}
