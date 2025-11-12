#pragma once

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "freertos/event_groups.h"

class CWiFi {
public:
    static void Init(const char* ssid, const char* password);
    static bool IsConnected();

private:
    static void EventHandler(void* arg, esp_event_base_t event_base,
                             int32_t event_id, void* event_data);

    static inline EventGroupHandle_t s_wifi_event_group = nullptr;
    static inline const int WIFI_CONNECTED_BIT = BIT0;
    static inline const char* TAG = "WiFi";
};
