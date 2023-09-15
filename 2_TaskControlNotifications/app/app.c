

/**
 * main.c
 */
#include <app/app.h>


static char* task_resumer_name = "resume";
static char* task_1_name = "First";
static char* task_2_name = "Second";
static char* task_3_name = "Third";

/*
 *
 */


/* task will wait for a notification every 4 seconds
 * then it will put the resuming task in ready state*/

void Task1_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel1_F);
    int i = 0;
    while(1){
        myLed_1->Write_Toggle(myLed_1);
        vTaskDelayUntil(xLastWakeTime, 500);
        if(i == 8){
            ulTaskNotifyTake(6, 0);
            vTaskResume(xTaskGetHandle(task_resumer_name));
        }
    }
}

// task will wait for a notification every 4 seconds
void Task2_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel2_F);
    int i = 0;
    while(1){
        myLed_1->Write_Toggle(myLed_1);
        vTaskDelayUntil(xLastWakeTime, 1000);
        if(i == 4){
            ulTaskNotifyTake(6, 0);
        }
    }
}

// task will wait for a notification every 4 seconds
void Task3_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel3_F);
    int i = 0;
    while(1){
        myLed_1->Write_Toggle(myLed_1);
        vTaskDelayUntil(xLastWakeTime, 2000);
        if(i == 2){
            ulTaskNotifyTake(6, 0);
        }
    }
}

// resume every 6 sec
void Task4_ResumingAll(void* pvParameter){
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    TaskHandle_t Task1 = NULL, Task2 = NULL, Task3 = NULL;
    while(Task1 == NULL || Task2 == NULL || Task3 == NULL){
        vTaskDelayUntil(xLastWakeTime, 50);
        Task1 = xTaskGetHandle(task_1_name);
        Task2 = xTaskGetHandle(task_2_name);
        Task3 = xTaskGetHandle(task_3_name);
    }
    while(1){
        vTaskDelayUntil(xLastWakeTime, 1000);
        /* if all the tasks are ready, go to BLOCK state*/
        if(eTaskGetState(Task1) == eTaskGetState(Task2) == eTaskGetState(Task3) == eReady){
            vTaskSuspend(NULL);
        }else if(eTaskGetState(Task1) == eTaskGetState(Task2) == eTaskGetState(Task3)){

        }else{
            vTaskDelayUntil(xLastWakeTime, 50);
        }
        xTaskNotify(Task1);
        xTaskNotify(Task2);
        xTaskNotify(Task3);
    }
}


void app_init(void)
{
    PLL_Init();
    Port_Init();
}
