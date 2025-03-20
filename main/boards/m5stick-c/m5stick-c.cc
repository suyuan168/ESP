#include "m5stick-c.h"
#include "axp192.h"
#include "esp_wifi.h"
#include "driver/gpio.h"

#define PAM8303_EN_GPIO 19

static void enable_pam8303(bool enable) {
  gpio_set_level((gpio_num_t)PAM8303_EN_GPIO, enable ? 1 : 0);
}

void setup_power_management() {
  AXP192::begin(AXP192_GPIO_SDA, AXP192_GPIO_SCL);
  AXP192::setChargeCurrent(CURRENT_100MA);
  AXP192::enableCharge(true);
  AXP192::setLDO3Voltage(3300);  // 设置LDO3输出3.3V
  AXP192::enableLDO3(true);      // 启用LDO3为PAM8303供电
}

#include "driver/i2s.h"

#define I2S_BCK_GPIO 26
#define I2S_WS_GPIO  25
#define I2S_DATA_GPIO 0

typedef struct {
    int sample_rate;
    i2s_bits_per_sample_t bits_per_sample;
    i2s_channel_t channels;
} i2s_cfg_t;

static void i2s_init() {
    i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX,
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .dma_buf_count = 6,
        .dma_buf_len = 512,
        .use_apll = false
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_BCK_GPIO,
        .ws_io_num = I2S_WS_GPIO,
        .data_out_num = I2S_DATA_GPIO,
        .data_in_num = I2S_PIN_NO_CHANGE
    };

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
}

void init_audio() {
  // 初始化PAM8303使能引脚
  gpio_config_t io_conf = {};
  io_conf.pin_bit_mask = (1ULL << PAM8303_EN_GPIO);
  io_conf.mode = GPIO_MODE_OUTPUT;
  gpio_config(&io_conf);
  enable_pam8303(true);
  i2s_init();
}

void init_display() {
  M5Display::begin();
  M5Display::setRotation(1);
  M5Display::fillScreen(BLACK);
  M5Display::setTextSize(1);
  M5Display::setCursor(0, 0);
}

void configure_wifi_rf() {
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init(&cfg);
  esp_wifi_set_max_tx_power(84);  // 20dBm
}

void check_charge_status() {
  if(AXP192::isCharging()) {
    M5Display::print("CHG: ");
    M5Display::println(AXP192::getBatteryLevel());
  }
}