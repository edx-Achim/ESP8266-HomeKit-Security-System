/** Copyright 2019 Achim Pieters | StudioPieters®

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

   Build upon: ESP-HomeKit - MIT License - Copyright (c) 2017 Maxim Kulkin
 **/

#include <stdio.h>
#include <espressif/esp_wifi.h>
#include <espressif/esp_sta.h>
#include <espressif/esp_system.h>
#include <esp/uart.h>
#include <esp8266.h>
#include <etstimer.h>
#include <esplibs/libmain.h>
#include <FreeRTOS.h>
#include <task.h>

#include <homekit/homekit.h>
#include <homekit/characteristics.h>
#include <wifi_config.h>

#define LED_INBUILT_GPIO 2  // this is the onboard LED used to show on/off only
bool led_on = false;

void led_write(bool on) {
        gpio_write(LED_INBUILT_GPIO, on ? 0 : 1);
}

void led_init() {
        gpio_enable(LED_INBUILT_GPIO, GPIO_OUTPUT);
        led_write(led_on);
}

void security_system_identify_task(void *_args) {
        for (int i=0; i<3; i++) {
                for (int j=0; j<2; j++) {
                        led_write(true);
                        vTaskDelay(100 / portTICK_PERIOD_MS);
                        led_write(false);
                        vTaskDelay(100 / portTICK_PERIOD_MS);
                }
                vTaskDelay(250 / portTICK_PERIOD_MS);
        }
        led_write(led_on);
        vTaskDelete(NULL);
}

void security_system_identify(homekit_value_t _value) {
        printf("Security System identify\n");
        xTaskCreate(security_system_identify_task, "Security System identify", 128, NULL, 2, NULL);
}


void update_state();

void on_update(homekit_characteristic_t *ch, homekit_value_t value, void *context) {
        update_state();
}
homekit_characteristic_t security_system_current_state = HOMEKIT_CHARACTERISTIC_(SECURITY_SYSTEM_CURRENT_STATE, 0);
homekit_characteristic_t security_system_target_state = HOMEKIT_CHARACTERISTIC_(SECURITY_SYSTEM_TARGET_STATE, 0, .callback=HOMEKIT_CHARACTERISTIC_CALLBACK(on_update));

// 0 ”Stay Arm. The home is occupied and the residents are active. e.g. morning or evenings”
// 1 ”Away Arm. The home is unoccupied”
// 2 ”Night Arm. The home is occupied and the residents are sleeping”
// 3 ”Disarmed”
// 4 ”Alarm Triggered”

void update_state() {
        if (security_system_current_state.value.int_value != 1 && security_system_target_state.value.int_value == 1) {
                        security_system_current_state.value = HOMEKIT_UINT8(1);
                        printf("Security System Away Arm.\n");
                        homekit_characteristic_notify(&security_system_current_state, security_system_current_state.value);
        }
        else if (security_system_current_state.value.int_value != 2 && security_system_target_state.value.int_value == 2) {
                        security_system_current_state.value = HOMEKIT_UINT8(2);
                        printf("Security System Night Arm.\n");
                        homekit_characteristic_notify(&security_system_current_state, security_system_current_state.value);
        }
        else if (security_system_current_state.value.int_value != 2 && security_system_target_state.value.int_value == 3) {
                        security_system_current_state.value = HOMEKIT_UINT8(3);
                        printf("Security System Disarmed.\n");
                        homekit_characteristic_notify(&security_system_current_state, security_system_current_state.value);
        }
        else if (security_system_current_state.value.int_value != 2 && security_system_target_state.value.int_value == 4) {
                        security_system_current_state.value = HOMEKIT_UINT8(4);
                        printf("Security System Alarm Triggered.\n");
                        homekit_characteristic_notify(&security_system_current_state, security_system_current_state.value);
        }
        else if (security_system_current_state.value.int_value != 0 && security_system_target_state.value.int_value == 0) {
                        security_system_current_state.value = HOMEKIT_UINT8(0);
                        printf("Security System Stay Arm.\n");
                        homekit_characteristic_notify(&security_system_current_state, security_system_current_state.value);
        }
      }


homekit_accessory_t *accessories[] = {
        HOMEKIT_ACCESSORY(.id=1, .category=homekit_accessory_category_security_system, .services=(homekit_service_t*[]) {
                HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
                        HOMEKIT_CHARACTERISTIC(NAME, "Security System"),
                        HOMEKIT_CHARACTERISTIC(MANUFACTURER, "StudioPieters®"),
                        HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "C39LDDQZFFD"),
                        HOMEKIT_CHARACTERISTIC(MODEL, "HKSP1SE/C"),
                        HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "0.0.1"),
                        HOMEKIT_CHARACTERISTIC(IDENTIFY, security_system_identify),
                        NULL
                }),
                HOMEKIT_SERVICE(SECURITY_SYSTEM, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
                        HOMEKIT_CHARACTERISTIC(NAME, "Alarm"),
                        &security_system_current_state,
                        &security_system_target_state,

                        NULL
                }),
                NULL
        }),
        NULL
};

homekit_server_config_t config = {
        .accessories = accessories,
        .password = "123-45-678",
        .setupId="1QJ8",
};

void user_init(void) {
        uart_set_baud(0, 115200);
        homekit_server_init(&config);

        led_init();
}
