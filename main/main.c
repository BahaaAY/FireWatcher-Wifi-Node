/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/adc.h"
#include "esp_log.h"

#include "dht.h"

#include <esp_err.h>

#include "sensors_util.h"
#include "wifi_util.h"
static const char *TAG = "MAIN ";



void app_main()
{
    setup_wifi();

    for(;;)
    {
    
        vTaskDelay(1000/portTICK_RATE_MS);
    }
    // setup_wifi();

//    setup_adc();

   
    

    // xTaskCreate(read_sensors, "sensors task", 2048, NULL, 5, NULL);

}
