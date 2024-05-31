#include "sensors_util.h"


void setup_adc(void)
{  // 1. init adc
    adc_config_t adc_config;

    // Depend on menuconfig->Component config->PHY->vdd33_const value
    // When measuring system voltage(ADC_READ_VDD_MODE), vdd33_const must be set to 255.
    adc_config.mode = ADC_READ_TOUT_MODE;
    adc_config.clk_div = 8; // ADC sample collection clock = 80MHz/clk_div = 10MHz
    ESP_ERROR_CHECK(adc_init(&adc_config));


}

void read_sensors(void *pvParameters)
{
    char *TAG = "SENSORS_TASK";
    uint16_t adc_data[100];

    for(;;)
    {
if (ESP_OK == adc_read(&adc_data[0])) {
            //convert 10-bit adc value to 12 bit
            adc_data[0] = adc_data[0] << 2;
            ESP_LOGI(TAG, "adc read: %d\r\n", adc_data[0]);
        }
        int16_t humidity = 0;
        int16_t temperature = 0;
        if (dht_read_data(DHT_TYPE_DHT11, DHT_GPIO, &humidity, &temperature) == ESP_OK) {
             humidity = humidity / 10;
            temperature = temperature / 10;
            printf("Humidity: %d Temperature: %d\n", humidity, temperature);
        } else {
            printf("Fail to get dht temperature data\n");
        }

        vTaskDelay(3000 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}