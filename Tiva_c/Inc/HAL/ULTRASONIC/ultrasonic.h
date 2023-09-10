/*********************************************
 * ultrasonic_sensor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal
 *********************************************/

#ifndef HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPT/GPT_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

typedef struct
{
    DIO_ChannelType ultrasonicEchoPin;
    DIO_ChannelType ultrasonicTriggerPin;
}ultraSonic_t;

/*This function is used to initialize the ultrasonic sensor
 * param sensor [port , echo pin , trigger pin]
 * return
 * */
void ultarsonicSensorInit(ultraSonic_t *sensor);

/*This function is used to get the ultrasonic sensor reading value
 * param sensor [port , echo pin , trigger pin]
 * return distance in cm
 * */
uint32 ultarsonicSensorReadValue(ultraSonic_t *sensor);

#endif /* HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_ */
