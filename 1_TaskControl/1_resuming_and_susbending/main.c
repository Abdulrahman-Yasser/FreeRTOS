/*
 * main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Abdu
 */

#include "freeRTOS_files/FreeRTOS.h"
#include "freeRTOS_files/task.h"

#include "myApp/app.h"


#define FIRST_STACK 128


int main(void){
    app_init();

    TaskHandle_t First_handle;
    TaskHandle_t second_handle;
    TaskHandle_t third_handle;
    TaskHandle_t resumer_handle;


    xTaskCreate(Task1_blinking, "First", FIRST_STACK, NULL, 1, &First_handle);
    xTaskCreate(Task2_blinking, "Second", FIRST_STACK, NULL, 1, &second_handle);
    xTaskCreate(Task3_blinking, "Third", FIRST_STACK, NULL, 1, &third_handle);
    xTaskCreate(Task4_ResumingAll, "The saver", FIRST_STACK, NULL, 1, &resumer_handle);

    vTaskStartScheduler();
    while(1);
}
