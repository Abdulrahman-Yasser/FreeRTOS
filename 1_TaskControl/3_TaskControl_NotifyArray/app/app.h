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

void app_init(void);

void Task1_resumer(void* pvParameter);
void Task2_blinking(void* pvParameter);

#endif /* MAIN_H_ */

