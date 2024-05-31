#ifndef SENSOR_UTIL_H
#define SENSOR_UTIL_H
#include "driver/adc.h"
#include "dht.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_err.h>

#define DHT_GPIO 4 // D2 pin

void setup_adc(void);
void read_sensors(void *pvParameters);

#endif