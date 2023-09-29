

/**
 * main.c
 */
#include "app.h"
static char* task_1_name = "First";

void Task1_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel2_F);
    xLastWakeTime = xTaskGetTickCount();
    while(1){
        myLed_1->Write_Toggle(myLed_1);
//        vTaskDelay(1000);
        vTaskDelayUntil(&xLastWakeTime, 1000);
    }
}

void app_init(void)
{
    PLL_Init();
    Port_Init();
}
