/* 
 * File:   keypad.h
 * Author: Mohamed Abosreea
 *
 * Created on April 12, 2023, 11:14 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/* Section : Includes */
#include "keypad_cfg.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/LIB/STD_TYPES.h"
#include "../../../Inc/LIB/BIT_MATH.h"
/*  Section : Macro declarations */
#define KEYPAD_ROWS   4
#define KEYPAD_COLS   4

/*  Section : Macro Functions declarations */

/*  Section : Data types declarations */
typedef struct 
{
    DIO_ChannelType keypad_rows[KEYPAD_ROWS];
    DIO_ChannelType keypad_cols[KEYPAD_COLS];
}keypad_t;
/*  Section : Functions declarations */

/**
 * This function is used to initialize a keypad
 * @param keypad [keypad_rows , keypad_cols]
 * @return OK if function success , N_OK if function fails
 */
Err_check_t keypad_init(const keypad_t *keypad );
/**
 * This function is used to get value of a keypad button
 * @param keypad [keypad_rows , keypad_cols]
 * @param value [return value of pressed key]
 * @return OK if function success , N_OK if function fails
 */
char keypad_get_value(const keypad_t *keypad );
        
#endif	/* KEYPAD_H */

