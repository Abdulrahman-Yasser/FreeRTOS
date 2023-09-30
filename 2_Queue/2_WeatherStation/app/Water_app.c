/**
 * Sending the smoke value to the lcd
 */


#include "app.h"
#include "APP_Layer/WaterDriver_WeatherStation/WaterDriver_WeatherStation.h"

extern QueueHandle_t myQueue_1 ;

void WaterTask(void* pvParameter){
    TickType_t xLastWakeTime;
	uint32 my_Water;
	WaterDriver_WeatherStation_Init();

    xLastWakeTime = xTaskGetTickCount();

	while(myQueue_1 == NULL){
        vTaskDelayUntil(&xLastWakeTime, 1000);
	}

    while(1){
		my_Water = WaterDriver_WeatherStation_Read();
	    xQueueSend( myQueue_1, (void*)&my_Water, (TickType_t)0);
        vTaskDelayUntil(&xLastWakeTime, 1000);
    }
}
