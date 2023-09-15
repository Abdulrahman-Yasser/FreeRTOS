/*
 * main.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Abdu
 */

#ifndef APP_H_
#define APP_H_

#include "General_Mcal/PORT/Static/inc/PORT.h"
#include "General_Mcal/PLL/Static/inc/PLL.h"
#include "General_Mcal/DIO/Static/inc/DIO_Types.h"
#include "General_HAL/Digital_Intrface/Static/inc/Digital_Interface.h"

#include "../freeRTOS_files/FreeRTOS.h"
#include "../freeRTOS_files/task.h"

void app_init(void);

void Task1_blinking(void* pvParameter);
void Task2_blinking(void* pvParameter);
void Task3_blinking(void* pvParameter);
void Task4_ResumingAll(void* pvParameter);

#endif /* MAIN_H_ */

