

/**
 * main.c
 */

#include "app.h"
#include "APP_Layer/SmokeDriver_WeatherStation/SmokeDriver_WeatherStation.h"

extern QueueHandle_t myQueue_1 ;

void SmokeTask(void* pvParameter){
    TickType_t xLastWakeTime;
	uint32 my_Smoke;
	SmokeDriver_WeatherStation_Init();

    xLastWakeTime = xTaskGetTickCount();

    do{
	    myQueue_1 = xQueueCreate(9, sizeof(uint32) );
	    vTaskDelay(100);
	}while(myQueue_1 == NULL);

    while(1){
		my_Smoke = SmokeDriver_WeatherStation_Read();
	    xQueueSend( myQueue_1, (void*)&my_Smoke, (TickType_t)0);
        vTaskDelayUntil(&xLastWakeTime, 1000);
    }
}
