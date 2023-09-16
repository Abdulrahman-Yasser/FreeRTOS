

/**
 * main.c
 */

#include "main.h"
void init(void);
void myTask(void* p);

void init(void){
    PLL_Init();
    Port_Init();
}

void myTask(void* p){
    DigitalInterface_Type* myLed;
    myLed = Digital_Interface_Create(DIO_Channel2_F);
    while(1){
        myLed->Write_Toggle(myLed);
        Delay_ms(1000);
    }
}

int main(void)
{
    init();
    TaskHandle_t  First_handle;
    xTaskCreate(myTask, "First",128, NULL,1, &First_handle);
    vTaskStartScheduler();
    while(1){

    }
}
