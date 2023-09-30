/*
 * main.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Abdu
 */

#ifndef APP_H_
#define APP_H_

#include "MCAL_Layer/PORT/Static/inc/PORT.h"
#include "MCAL_Layer/PLL/Static/inc/PLL.h"
#include "MCAL_Layer/DIO/Static/inc/DIO_Types.h"
#include "HAL_Layer/Digital_Intrface/Static/inc/Digital_Interface.h"

#include "../freeRTOS_files/FreeRTOS.h"
#include "../freeRTOS_files/task.h"
#include "../freeRTOS_files/queue.h"


void app_init(void);

void LCD_Task(void* pvParameter);
void SmokeTask(void* pvParameter);
void WaterTask(void* pvParameter);
void TemperatureTask(void* pvParameter);
void Task1_blinking(void* pvParameter);

#endif /* MAIN_H_ */

