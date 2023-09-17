

/**
 * main.c
 */
#include <app/app.h>
static char* task_1_name = "First";
static char* task_2_name = "Second";
static char* task_3_name = "Third";

void Task1_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel1_F);
    TaskHandle_t myTaskSuspender;
    int i = 0;
    while(1){
        myLed_1->Write_Toggle(myLed_1);
        vTaskDelayUntil(xLastWakeTime, 500);
        // suspend task_2 and task_3 every 3 sec
        if(i == 60){
            myTaskSuspender = xTaskGetHandle(task_2_name);
            vTaskSuspend(myTaskSuspender);
            myTaskSuspender = xTaskGetHandle(task_3_name);
            vTaskSuspend(myTaskSuspender);
            i = 0;
        }
        i++;
    }
}

void Task2_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel2_F);
    while(1){
        myLed_1->Write_Toggle(myLed_1);
        vTaskDelayUntil(xLastWakeTime, 1000);
    }
}

void Task3_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel2_F);
    while(1){
        myLed_1->Write_Toggle(myLed_1);
        vTaskDelayUntil(xLastWakeTime, 1500);
    }
}

// resume task_2 and task_3 every 6 sec
void Task4_ResumingAll(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    while(1){
        vTaskDelayUntil(xLastWakeTime, 6000);
        xTaskResumeAll();
    }
}


void app_init(void)
{
    PLL_Init();
    Port_Init();
}
