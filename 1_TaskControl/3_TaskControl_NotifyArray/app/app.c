

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

void Task1_resumer(void* pvParameter){
    TaskHandle_t task2;
    TickType_t xLastWakeTime;
    uint8 i = 0;
    task2 = xTaskGetHandle(task_2_name);
    while(task2 == NULL){
    	vTaskDelay(100);
	    task2 = xTaskGetHandle(task_2_name);
    }
    xLastWakeTime = xTaskGetTickCount();
    while(1){
        vTaskDelayUntil(&xLastWakeTime, 500);
        /* Notify index 1 of the notification array */ 
    	xTaskNotify(task2, 0, eIncrement);
		if(i == 0){
			i = 1;
	        /* Notify index 2 of the notification array.
	           which will be each 1 second */ 
	    	xTaskNotify(task2, 1<<18, eSetBits);
		}
		i = 0;
    }
}

// task will wait for a notification every 4 seconds
void Task2_blinking(void* pvParameter){
    TickType_t xLastWakeTime;
    DigitalInterface_Type* myLed = Digital_Interface_Create(DIO_Channel2_F);
    DigitalInterface_Type* myLed_2 = Digital_Interface_Create(DIO_Channel1_F);
    uint32 myNotificationValue_0_Index = 0, myNotificationValue_1_Index = 0;
    xLastWakeTime = xTaskGetTickCount();
    while(1){
    	xTaskNotifyWait(0, 0, &myNotificationValue_0_Index, 1 );

	    switch(myNotificationValue_0_Index){
	    case 6:
		    myLed->Write_Toggle(myLed);
			break;
		case 8:
		    myLed->Write_Toggle(myLed);
		    ulTaskNotifyValueClear(NULL, 0xffffffff);
			break;
	    }
	    
	    if(myNotificationValue_0_Index && (1 << 18) ){
		    ulTaskNotifyValueClear(NULL, 1 << 18);
		    myLed_2->Write_Toggle(myLed_2);
	    }

    }
}


void app_init(void)
{
    PLL_Init();
    Port_Init();
}
