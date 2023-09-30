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
    TaskHandle_t second_handle;


    xTaskCreate(Task1_sender, "First", FIRST_STACK, NULL, 1, &First_handle);
    xTaskCreate(Task2_receiver, "Second", FIRST_STACK, NULL, 1, &second_handle);
    
    
    vTaskStartScheduler();
    while(1);
}
