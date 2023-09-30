/*
 * main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Abdu
 */

#include "freeRTOS_files/FreeRTOS.h"
#include "freeRTOS_files/task.h"

#include "app/app.h"


#define FIRST_STACK 128


int main(void){
    app_init();

    TaskHandle_t First_handle;


    xTaskCreate(LCD_Task, "lcd", FIRST_STACK, NULL, 1, &First_handle);
    xTaskCreate(SmokeTask, "smoke", FIRST_STACK, NULL, 1, &First_handle);
    xTaskCreate(WaterTask, "water", FIRST_STACK, NULL, 1, &First_handle);
    xTaskCreate(TemperatureTask, "temp", FIRST_STACK, NULL, 1, &First_handle);
    xTaskCreate(Task1_blinking, "blink", FIRST_STACK, NULL, 1, &First_handle);
    
    
    vTaskStartScheduler();
    while(1);
}
