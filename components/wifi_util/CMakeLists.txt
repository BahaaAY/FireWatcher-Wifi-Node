idf_component_register(SRCS "app_prov_handlers.c" "wifi_util.c"
                       INCLUDE_DIRS "." REQUIRES freertos driver wifi_provisioning nvs_flash esp_wifi ) 