

/**
 * main.c
 */
#include "app.h"
#include "APP_Layer/TemperatureDriver_WeatherStation/TempratureDriver_WeatherStation.h"

extern QueueHandle_t myQueue_1 ;

void TemperatureTask(void* pvParameter){
    TickType_t xLastWakeTime;
	uint32 my_temperature;
	TempDriver_WeatherStation_Init();

    xLastWakeTime = xTaskGetTickCount();

	while(myQueue_1 == NULL){
        vTaskDelayUntil(&xLastWakeTime, 1000);
	}

    while(1){
		my_temperature = TempDriver_WeatherStation_Read();
	    xQueueSend( myQueue_1, (void*)&my_temperature, (TickType_t)0);
        vTaskDelayUntil(&xLastWakeTime, 1000);
    }
}


void app_init(void)
{
    PLL_Init();
    Port_Init();
}
