/**
 Defines that the accessory contains a security system.

 Required Characteristics:
 - SECURITY_SYSTEM_CURRENT_STATE*
 - SECURITY_SYSTEM_TARGET_STATE*

 Optional Characteristics:
 - NAME
 - STATUS_FAULT
 - STATUS_TAMPERED
 - SECURITY_SYSTEM_ALARM_TYPE
 **/
#define HOMEKIT_SERVICE_SECURITY_SYSTEM HOMEKIT_APPLE_UUID2("7E")





#define HOMEKIT_CHARACTERISTIC_SECURITY_SYSTEM_CURRENT_STATE HOMEKIT_APPLE_UUID2("66")
#define HOMEKIT_DECLARE_CHARACTERISTIC_SECURITY_SYSTEM_CURRENT_STATE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_SECURITY_SYSTEM_CURRENT_STATE, \
    .description = "Security System Current State", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
                 | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {4}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
        .count = 5, \
        .values = (uint8_t[]) { 0, 1, 2, 3, 4 }, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_SECURITY_SYSTEM_TARGET_STATE HOMEKIT_APPLE_UUID2("67")
#define HOMEKIT_DECLARE_CHARACTERISTIC_SECURITY_SYSTEM_TARGET_STATE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_SECURITY_SYSTEM_TARGET_STATE, \
    .description = "Security System Target State", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
                 | homekit_permissions_paired_write \
                 | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
        .count = 4, \
        .values = (uint8_t[]) { 0, 1, 2, 3 }, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_NAME HOMEKIT_APPLE_UUID2("23")
#define HOMEKIT_DECLARE_CHARACTERISTIC_NAME(name, ...) \
    .type = HOMEKIT_CHARACTERISTIC_NAME, \
    .description = "Name", \
    .format = homekit_format_string, \
    .permissions = homekit_permissions_paired_read, \
    .value = HOMEKIT_STRING_(name), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_STATUS_FAULT HOMEKIT_APPLE_UUID2("77")
#define HOMEKIT_DECLARE_CHARACTERISTIC_STATUS_FAULT(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_STATUS_FAULT, \
    .description = "Status Fault", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
                 | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {1}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
        .count = 2, \
        .values = (uint8_t[]) { 0, 1 }, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__


#define HOMEKIT_CHARACTERISTIC_STATUS_TAMPERED HOMEKIT_APPLE_UUID2("7A")
#define HOMEKIT_DECLARE_CHARACTERISTIC_STATUS_TAMPERED(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_STATUS_TAMPERED, \
    .description = "Status Tampered", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
                 | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {1}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
        .count = 2, \
        .values = (uint8_t[]) { 0, 1 }, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_SECURITY_SYSTEM_ALARM_TYPE HOMEKIT_APPLE_UUID2("8E")
#define HOMEKIT_DECLARE_CHARACTERISTIC_SECURITY_SYSTEM_ALARM_TYPE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_SECURITY_SYSTEM_ALARM_TYPE, \
    .description = "Security System Alarm Type", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
                 | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {1}, \
    .min_step = (float[]) {1}, \
   .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__
