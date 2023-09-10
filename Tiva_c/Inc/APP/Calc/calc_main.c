#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/HAL/LCD/lcd.h"
#include "Inc/HAL/KEYPAD/keypad.h"
#include "Inc/APP/Calc/calc.h"
#include "Inc/LIB/DELAY.h"
#include <stdlib.h>

// Define messages to be displayed on the LCD
uint8 *hello_msg1 = "Hosseni - Ahmed";
uint8 *hello_msg2 = "Hello To Our Calc";
uint8 val = 0xFF;  // Initialize 'val' to an invalid value
extern int flag;   // External flag variable defined elsewhere

// LCD and keypad configurations
lcd_t lcd1 = {PIN_C7, PIN_C6, {PIN_A2, PIN_A3, PIN_A4, PIN_A6, PIN_B4, PIN_B5, PIN_B6, PIN_B7}, _8_BIT};
keypad_t keypad1 = {{PIN_D6, PIN_F4, PIN_D2, PIN_D3}, {PIN_E0, PIN_E1, PIN_E2, PIN_E3}};

double result;
uint8 expresion[100];
uint8 index = 0;
void calc_init ()
{
    // Initialize the LCD
        lcd_init(&lcd1);

        // Display message 1 and wait
        lcd_send_string(&lcd1, hello_msg1);
        delay(5000);

        // Clear the LCD and display message 2
        lcd_send_command(&lcd1, _LCD_CLEAR);
        lcd_send_string(&lcd1, hello_msg2);
        delay(5000);
        lcd_send_command(&lcd1, _LCD_CLEAR);
}
void calc_main()
{

    // Main loop
    while (1)
    {
        // Get the pressed key from the keypad
        val = keypad_get_value(&keypad1);

        if (val != 0xFF)  // A valid key press
        {
            lcd_send_chr(&lcd1, val);  // Display the pressed character on the LCD

            expresion[index++] = val;  // Store the character in the expression buffer

            if (val == '=')  // If the equal sign was pressed
            {
                expresion[index] = '\0';  // Null-terminate the expression string
                index = 0;  // Reset the index for the next expression

                lcd_set_cursor(&lcd1, ROW1, COL0);  // Move cursor to the second row

                // Evaluate the expression and handle different cases
                result = evaluateInfixExpression(expresion);
                if (flag == 0)
                {
                    if (result < 0)
                    {
                        lcd_send_chr(&lcd1, '-');
                        lcd_sendFloat(&lcd1, (double)result * -1, 3);
                    }
                    else
                    {
                        lcd_sendFloat(&lcd1, (double)result, 3);
                    }
                }
                else if (flag == 1)
                {
                    lcd_send_string(&lcd1, "error");
                    flag = 0;
                }
                else if (flag == 2)
                {
                    lcd_send_string(&lcd1, "div by 0 not allowed");
                }

                lcd_set_cursor(&lcd1, ROW0, COL0);  // Move cursor back to the first row
            }

            if (val == 'D')  // If 'D' key was pressed
            {
                lcd_send_command(&lcd1, _LCD_CLEAR);  // Clear the LCD
            }
        }
    }
}
