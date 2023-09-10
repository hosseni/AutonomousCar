/*
 * stopWatch.h
 *
 *  Created on: 24/8/2023
 *      Author: HOSSENI
 */

#ifndef INC_APP_STOPWATCH_STOPWATCH_H_
#define INC_APP_STOPWATCH_STOPWATCH_H_

void stopWatch_init(void);
void stopWatch_HandleMain ();
void show_time();
void stop_time();
void reset_time();
void handle_buttons (void);
void SYSTICK_Handler_app ();


#endif /* INC_APP_STOPWATCH_STOPWATCH_H_ */
