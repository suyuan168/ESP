#ifndef _M5STICK_C_H_
#define _M5STICK_C_H_

#include <Arduino.h>
#include <M5Display.h>
#include "driver/i2s.h"

typedef struct {
    int sample_rate;
    i2s_bits_per_sample_t bits_per_sample;
    i2s_channel_t channels;
} i2s_cfg_t;

void init_audio();

void setup_power_management();
void init_display();
void configure_wifi_rf();
void check_charge_status();

extern const int I2S_BCK_GPIO;
extern const int I2S_WS_GPIO;
extern const int I2S_DATA_GPIO;

#endif // _M5STICK_C_H_