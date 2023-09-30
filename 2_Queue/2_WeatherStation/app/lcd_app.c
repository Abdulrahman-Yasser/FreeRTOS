#include "app.h"
#include "HAL_Layer/LCD/Static/inc/LCD.h"

QueueHandle_t myQueue_1 ;

void LCD_Task(void* pvParameter){
    TickType_t xLastWakeTime;
	uint32 receivedData;
    xLastWakeTime = xTaskGetTickCount();
	LCD_Handler_Type* myLcd = LCD_Create(LCD_Interface_I2C, 0);

	while(myQueue_1 == NULL){
        vTaskDelayUntil(&xLastWakeTime, 1000);
	}
	
    char *z;
    while(1){
		while( xQueueReceive( myQueue_1, (void*)&receivedData, (TickType_t)15) == pdFALSE){
	        vTaskDelayUntil(&xLastWakeTime, 100);
    	}
		z = int_to_string(receivedData);
		myLcd->LCD_Write_Data(myLcd, z);
		free(z);
    }
}
