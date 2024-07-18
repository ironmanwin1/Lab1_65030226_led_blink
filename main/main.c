#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


void app_main(void)
{
    gpio_set_direction(5, GPIO_MODE_OUTPUT);
    gpio_set_direction(17, GPIO_MODE_INPUT);
    int button2 = 0;
    while (1) {
        button2 = gpio_get_level(GPIO_NUM_17);
        printf("button 2 = %d\n", button2);
        if(button2 == 1)
        {
            gpio_set_level(5,1);
        }
        else
        {
            gpio_set_level(5,0);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
