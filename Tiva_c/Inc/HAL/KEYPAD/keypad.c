#include "Inc/HAL/KEYPAD/keypad.h"
#define ARM_DELAY(d)   do{unsigned long int i=(d * 5000); while(i--){asm(" nop ");}}while(0)

// Keypad values for each button
static const uint8 keypad_val[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3', '/'},
    {'4', '5', '6', '*'},
    {'7', '8', '9', '-'},
    {'D', '0', '=', '+'}
};

#if ENABLE_KEYPAD_APIS == ENABLE_KEYPAD

/***************************************************************************************************
 *  Function: keypad_get_value
 *  Description:
 *      This function scans the keypad rows and columns to detect which button is pressed and
 *      returns the corresponding character value. It utilizes the keypad configuration provided
 *      in the keypad_t structure.
 *  Parameters:
 *      keypad: Pointer to a keypad_t structure containing keypad pin configurations.
 *  Return Value:
 *      char: Character value of the pressed button. Returns 0xFF if no button is pressed.
 ***************************************************************************************************/
char keypad_get_value(const keypad_t *keypad)
{
    DIO_LevelType state;
    uint8 count;
    uint8 row;
    uint8 col;
    uint8 value = 0xFF;

    for (row = 0; row < KEYPAD_ROWS; row++)
    {
        // Disable all rows
        for (count = 0; count < KEYPAD_ROWS; count++)
        {
            DIO_WriteChannel((keypad->keypad_rows[count]), LOW);
        }

        // Enable the current row
        DIO_WriteChannel((keypad->keypad_rows[row]), HIGH);

        // Check each column for button press
        for (col = 0; col < KEYPAD_COLS; col++)
        {
            state = DIO_ReadChannel((keypad->keypad_cols[col]));

            if (HIGH == state)
            {
                // Button pressed, get its value
                value = keypad_val[row][col];

                // Wait until button is released
                while (HIGH == DIO_ReadChannel((keypad->keypad_cols[col])));

                // Introduce a delay to avoid button debouncing
                ARM_DELAY(20);
            }
        }

        // Disable the current row
        DIO_WriteChannel((keypad->keypad_rows[row]), LOW);
    }

    return value;
}
#endif
