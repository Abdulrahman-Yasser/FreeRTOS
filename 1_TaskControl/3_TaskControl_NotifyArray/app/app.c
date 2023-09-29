

/**
 * main.c
 */
#include "app.h"


static char* task_1_name = "First";
static char* task_2_name = "Second";

/*
 *
 */


/* task will wait for a notification every 4 seconds
 * then it will put the resuming task in ready state*/

void Task1_blinking(void* pvParameter){
    TaskHandle_t task2;
    TickType_t xLastWakeTime;
    DigitalInterface_Type* myLed = Digital_Interface_Create(DIO_Channel1_F);
    int i = 0;
    task2 = xTaskGetHandle(task_2_name);
    while(task2 == NULL){
    	vTaskDelay(100);
	    task2 = xTaskGetHandle(task_2_name);
    }
    xLastWakeTime = xTaskGetTickCount();
    while(1){
        myLed->Write_Toggle(myLed);
        vTaskDelayUntil(&xLastWakeTime, 500);
    	xTaskNotify(task2, 0, eIncrement);
    }
}

// task will wait for a notification every 4 seconds
void Task2_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    DigitalInterface_Type* myLed = Digital_Interface_Create(DIO_Channel2_F);
    uint32 myNotificationValue = 0;
    xLastWakeTime = xTaskGetTickCount();
    while(1){
        if(xTaskNotifyWait(0, 0, &myNotificationValue, portMAX_DELAY ) == pdFALSE){
	        vTaskDelayUntil(&xLastWakeTime, 100);
        }else{
		    switch(myNotificationValue){
		    case 6:
			    myLed->Write_Toggle(myLed);
				break;
			case 8:
			    myLed->Write_Toggle(myLed);
			    ulTaskNotifyValueClear(NULL, 0xffffffff);
				break;
		    }
        }
    }
}


void app_init(void)
{
    PLL_Init();
    Port_Init();
}
