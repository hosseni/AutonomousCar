/*
 * lcd.c
 *
 *      Author: Hosseni
 */

#include "Inc/HAL/LCD/lcd.h"
#include "Inc/HAL/LCD/lcd_config.h"
#include "Inc/LIB/DELAY.h"

/***************************************************************************************************
 *  Function: lcd_send_command
 *  Description:
 *      This function sends a command to the LCD module. It handles both 4-bit and 8-bit LCD modes.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      command: Command to be sent to the LCD module.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_command (const lcd_t *lcd, uint8 command)
{           uint8 count;
             DIO_WriteChannel((lcd->lcd_rs), LOW);
            if (lcd->lcd_connection == _4_BIT)
            {
               DIO_WriteChannel((lcd->lcd_data_pins[0]), GET_BIT(command, 4));
               DIO_WriteChannel((lcd->lcd_data_pins[1]), GET_BIT(command, 5));
               DIO_WriteChannel((lcd->lcd_data_pins[2]), GET_BIT(command, 6));
               DIO_WriteChannel((lcd->lcd_data_pins[3]), GET_BIT(command, 7));
               DIO_WriteChannel((lcd->lcd_en), HIGH);
                delay(5);
               DIO_WriteChannel((lcd->lcd_en), LOW);
               delay(5);
               DIO_WriteChannel((lcd->lcd_data_pins[0]), GET_BIT((command), 0));
               DIO_WriteChannel((lcd->lcd_data_pins[1]), GET_BIT((command), 1));
               DIO_WriteChannel((lcd->lcd_data_pins[2]), GET_BIT((command), 2));
               DIO_WriteChannel((lcd->lcd_data_pins[3]), GET_BIT((command), 3));
               DIO_WriteChannel((lcd->lcd_en), HIGH);
               delay(5);
               DIO_WriteChannel((lcd->lcd_en), LOW);
               delay(5);
            }
            else if (lcd->lcd_connection == _8_BIT)
            {
                for ( count = 0; count < 8; count++)
                {
                   DIO_WriteChannel((lcd->lcd_data_pins[count]), GET_BIT(command, count));
                }
                DIO_WriteChannel((lcd->lcd_en), HIGH);
                delay(5);
                DIO_WriteChannel((lcd->lcd_en), LOW);
            } else {
                /*Do Nothing*/
            }

}
/***************************************************************************************************
 *  Function: lcd_set_cursor
 *  Description:
 *      This function sets the cursor position on the LCD module based on the specified row and column.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      row: Desired row for the cursor.
 *      col: Desired column for the cursor.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_set_cursor(const lcd_t *lcd, row_t row, col_t col)
{
    switch (row)
    {
    case ROW0:
        lcd_send_command(lcd, (0x80 + col));
        break;
    case ROW1:
        lcd_send_command(lcd, (0xc0 + col));
        break;
    case ROW2:
        lcd_send_command(lcd, (0x94 + col));
        break;
    case ROW3:
        lcd_send_command(lcd, (0xD4 + col));
        break;
    }
}
/***************************************************************************************************
 *  Function: lcd_init
 *  Description:
 *      This function initializes the LCD module based on the provided configuration.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD configuration settings.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_init(const lcd_t *lcd)
{

    if (lcd->lcd_connection == _4_BIT)
    {

        delay(50);
        lcd_send_command(lcd, _LCD_8BIT_2LINE);
        delay(25);
        lcd_send_command(lcd, _LCD_8BIT_2LINE);
        delay(300);
        lcd_send_command(lcd, _LCD_8BIT_2LINE);

        lcd_send_command(lcd, _LCD_RETURN_HOME);
        lcd_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        lcd_send_command(lcd, _LCD_CLEAR);
        lcd_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        lcd_send_command(lcd, _LCD_4BIT_2LINE);
    }
    else if (lcd->lcd_connection == _8_BIT)
    {
        delay(20);
        lcd_send_command(lcd, _LCD_8BIT_2LINE);
        delay(5);
        lcd_send_command(lcd, _LCD_8BIT_2LINE);
        delay(150);
        lcd_send_command(lcd, _LCD_8BIT_2LINE);

        lcd_send_command(lcd, _LCD_CLEAR);
        lcd_send_command(lcd, _LCD_RETURN_HOME);
        lcd_send_command(lcd, _LCD_CURSOR_OFF_DISPLAY_ON);
    }
    else
    {
        /*Do Nothing*/
    }
}
/***************************************************************************************************
 *  Function: lcd_send_chr
 *  Description:
 *      This function sends a character to the LCD module for display. It handles both 4-bit and
 *      8-bit LCD modes.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      character: Character to be displayed on the LCD.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_chr(const lcd_t *lcd, uint8 character)
{
    uint8 count = 0;

    DIO_WriteChannel((lcd->lcd_rs), HIGH);
    if (lcd->lcd_connection == _4_BIT)
    {
        DIO_WriteChannel((lcd->lcd_data_pins[0]), GET_BIT(character, 4));
        DIO_WriteChannel((lcd->lcd_data_pins[1]), GET_BIT(character, 5));
        DIO_WriteChannel((lcd->lcd_data_pins[2]), GET_BIT(character, 6));
        DIO_WriteChannel((lcd->lcd_data_pins[3]), GET_BIT(character, 7));

        DIO_WriteChannel((lcd->lcd_en), HIGH);
        delay(10);
        DIO_WriteChannel((lcd->lcd_en), LOW);

        DIO_WriteChannel((lcd->lcd_data_pins[0]), GET_BIT((character), 0));
        DIO_WriteChannel((lcd->lcd_data_pins[1]), GET_BIT((character), 1));
        DIO_WriteChannel((lcd->lcd_data_pins[2]), GET_BIT((character), 2));
        DIO_WriteChannel((lcd->lcd_data_pins[3]), GET_BIT((character), 3));
        DIO_WriteChannel((lcd->lcd_en), HIGH);
        delay(10);
        DIO_WriteChannel((lcd->lcd_en), LOW);
    }
    else if (lcd->lcd_connection == _8_BIT)
    {
        for (count = 0; count < 8; count++)
        {
            DIO_WriteChannel((lcd->lcd_data_pins[count]), GET_BIT(character, count));
        }
        DIO_WriteChannel((lcd->lcd_en), HIGH);
        delay(10);
        DIO_WriteChannel((lcd->lcd_en), LOW);
    }
    else
    {
        /*Do Nothing*/
    }
}
/***************************************************************************************************
 *  Function: lcd_send_chr_pos
 *  Description:
 *      This function sends a character to the LCD module at the specified row and column position.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      character: Character to be displayed on the LCD.
 *      row: Desired row for displaying the character.
 *      col: Desired column for displaying the character.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_chr_pos(const lcd_t *lcd, uint8 character, row_t row, col_t col)
{
    lcd_set_cursor(lcd, row, col);
    lcd_send_chr(lcd, character);
}
/***************************************************************************************************
 *  Function: lcd_send_string
 *  Description:
 *      This function sends a string of characters to the LCD module for display.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      data: Pointer to the string data to be displayed.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_string(const lcd_t *lcd, uint8 *data)
{
    uint8 index = 0;

    for (index = 0; data[index] != '\0'; index++)
    {
        lcd_send_chr(lcd, data[index]);
    }
}
/***************************************************************************************************
 *  Function: lcd_send_string_pos
 *  Description:
 *      This function sends a string of characters to the LCD module at the specified row and column.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      data: Pointer to the string data to be displayed.
 *      row: Desired row for displaying the string.
 *      col: Desired column for displaying the string.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_string_pos(const lcd_t *lcd, uint8 *data, row_t row, col_t col)
{

    lcd_set_cursor(lcd, row, col);
    lcd_send_string(lcd, data);
}

/***************************************************************************************************
 *  Function: lcd_send_number_pos
 *  Description:
 *      This function sends a number to the LCD module at the specified row and column.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      num: Number to be displayed on the LCD.
 *      row: Desired row for displaying the number.
 *      col: Desired column for displaying the number.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_number_pos(const lcd_t *lcd, uint32 num, row_t row, col_t col)
{
    uint8 data1[6], data2[6];
    uint8 count1 = 0, count2 = 0;
    lcd_set_cursor(lcd, row, col);

    if (num == 0)
        {
            lcd_send_chr(lcd, '0');
        }
        else
        {
            while (num > 0)
            {
                data1[count1] = ((num % 10) + '0');
                num /= 10;
                count1++;
            }
            data1[count1] = '\0';
            for (count2 = 0; count2 < count1; count2++)
            {
                data2[count2] = data1[count1 - count2 - 1];
            }
            data2[count2] = '\0';
            lcd_send_string(lcd, data2);
        }
}
/***************************************************************************************************
 *  Function: lcd_send_number
 *  Description:
 *      This function sends a number to the LCD module for display.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      num: Number to be displayed on the LCD.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_number(const lcd_t *lcd, uint16 num)
{
    uint8 data1[6], data2[6];
    uint8 count1 = 0, count2 = 0;

    if (num == 0)
    {
        lcd_send_chr(lcd, '0');
    }
    else
    {
        while (num > 0)
        {
            data1[count1] = ((num % 10) + '0');
            num /= 10;
            count1++;
        }
        data1[count1] = '\0';
        for (count2 = 0; count2 < count1; count2++)
        {
            data2[count2] = data1[count1 - count2 - 1];
        }
        data2[count2] = '\0';
        lcd_send_string(lcd, data2);
    }
}
/***************************************************************************************************
 *  Function: lcd_send_custome_chr_pos
 *  Description:
 *      This function sends a custom character to the LCD module at the specified row and column.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      arr: Pointer to an array representing the custom character.
 *      mem_pos: Memory position of the custom character (0 to 7).
 *      row: Desired row for displaying the custom character.
 *      col: Desired column for displaying the custom character.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_custome_chr_pos(const lcd_t *lcd, uint8 *arr, uint8 mem_pos, row_t row, col_t col)
{
    uint8 count = 0;

    lcd_send_command(lcd, (_LCD_CGRAM_START + (mem_pos * 8)));
    for (count = 0; count < 8; count++)
    {
        lcd_send_chr(lcd, (uint8)arr[count]);
    }
    lcd_send_chr_pos(lcd, mem_pos, row, col);
}

void lcd_sendFloat(const lcd_t *lcd, double f_num, char n_digits)
{
    uint16 L_u16AfterDigit = 1;
    uint8 L_u8Iterator = 0;

    lcd_send_number(lcd, (uint16)f_num);
    lcd_send_chr(lcd, ',');

    for (L_u8Iterator = 0; L_u8Iterator < n_digits; L_u8Iterator++)
    {
        L_u16AfterDigit = L_u16AfterDigit * 10;
    }

    /** display fraction part */
    lcd_send_number(lcd, (f_num - (uint32)f_num) * L_u16AfterDigit);
}
