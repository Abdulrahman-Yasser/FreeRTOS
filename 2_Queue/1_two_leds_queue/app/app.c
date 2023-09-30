

/**
 * main.c
 */
#include "app.h"


static char* task_1_name = "First";
static char* task_2_name = "Second";

QueueHandle_t myQueue_1 ;


/* task will wait for a notification every 4 seconds
 * then it will put the resuming task in ready state*/

void Task1_sender(void* pvParameter){
    TickType_t xLastWakeTime;
    
    char my_send_value;
    do{
	    myQueue_1 = xQueueCreate(3, sizeof(char) );
	    vTaskDelay(100);
	}while(myQueue_1 == NULL);

    xLastWakeTime = xTaskGetTickCount();
    while(1){
	    my_send_value = 1;
	    xQueueSend( myQueue_1, (void*)&my_send_value, (TickType_t)0);
	    vTaskDelay(100);
	    my_send_value = 2;
	    xQueueSend( myQueue_1, (void*)&my_send_value, (TickType_t)0);
	    vTaskDelay(100);
	    my_send_value = 3;
	    xQueueSend( myQueue_1, (void*)&my_send_value, (TickType_t)0);
	    vTaskDelay(100);
        /* Notify index 1 of the notification array */ 
    }
}

// task will wait for a notification every 4 seconds
void Task2_receiver(void* pvParameter){
    TickType_t xLastWakeTime;
    DigitalInterface_Type* myLed_1 = Digital_Interface_Create(DIO_Channel1_F);
    DigitalInterface_Type* myLed_2 = Digital_Interface_Create(DIO_Channel2_F);
    DigitalInterface_Type* myLed_3 = Digital_Interface_Create(DIO_Channel3_F);
    xLastWakeTime = xTaskGetTickCount();
    char receivedData ;

	while(myQueue_1 == NULL){
		myLed_1->Write_High(myLed_1);
		vTaskDelay(2000);
		myLed_1->Write_Low(myLed_1);
		vTaskDelay(2000);
	}
    while(1){
    	while( xQueueReceive( myQueue_1, (void*)&receivedData, (TickType_t)15) == pdFALSE){
			vTaskDelay(100);
    	}
    	switch(receivedData){
		case 1:
			myLed_1->Write_High(myLed_1);
			myLed_2->Write_Low(myLed_2);
			myLed_3->Write_Low(myLed_3);
			break;
		case 2:
			myLed_1->Write_Low(myLed_1);
			myLed_2->Write_Low(myLed_2);
			myLed_3->Write_High(myLed_3);
			break;
		case 3:
			myLed_1->Write_Low(myLed_1);
			myLed_2->Write_High(myLed_2);
			myLed_3->Write_Low(myLed_3);
			break;
		default:
			break;
			myLed_1->Write_High(myLed_1);
			myLed_2->Write_High(myLed_2);
			myLed_3->Write_High(myLed_3);
    	}
    	receivedData = 0;
    }
}


void app_init(void)
{
    PLL_Init();
    Port_Init();
}
