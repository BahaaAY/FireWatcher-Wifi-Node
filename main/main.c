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
static const char *TAG = "adc ";

#define DHT_GPIO 4 // D2 pin

static void adc_task()
{
    int x;
    uint16_t adc_data[100];

    while (1) {
        if (ESP_OK == adc_read(&adc_data[0])) {
            //convert 10-bit adc value to 12 bit
            adc_data[0] = adc_data[0] << 2;
            ESP_LOGI(TAG, "adc read: %d\r\n", adc_data[0]);
        }

        vTaskDelay(1000 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);

}
void temperature_task(void *arg)
{
    while (1)
    {
        int16_t humidity = 0;
        int16_t temperature = 0;
        if (dht_read_data(DHT_TYPE_DHT11, DHT_GPIO, &humidity, &temperature) == ESP_OK) {
             humidity = humidity / 10;
            temperature = temperature / 10;
            printf("Humidity: %d Temperature: %d\n", humidity, temperature);
        } else {
            printf("Fail to get dht temperature data\n");
        }
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}



void app_main()
{

     // 1. init adc
    adc_config_t adc_config;

    // Depend on menuconfig->Component config->PHY->vdd33_const value
    // When measuring system voltage(ADC_READ_VDD_MODE), vdd33_const must be set to 255.
    adc_config.mode = ADC_READ_TOUT_MODE;
    adc_config.clk_div = 8; // ADC sample collection clock = 80MHz/clk_div = 10MHz
    ESP_ERROR_CHECK(adc_init(&adc_config));

    // 2. Create a adc task to read adc value
    xTaskCreate(adc_task, "adc_task", 1024, NULL, 5, NULL);

    xTaskCreate(temperature_task, "temperature task", 2048, NULL, 5, NULL);

}
