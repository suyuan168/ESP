#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// 电源管理配置
#define AXP192_POWER_MANAGEMENT
#define AXP192_GPIO_SDA GPIO_NUM_21
#define AXP192_GPIO_SCL GPIO_NUM_22
#define AXP192_CHARGE_CURRENT 0x45 // 488mA充电电流
#define AXP192_CHG_CUTOFF_CURRENT 0x02 // 66mA截止电流
#define AXP192_RECHARGE_CURRENT 0x20 // 181mA再充电电流
#define AXP192_CHG_VOL_4_2V
#define AXP192_CHG_CTRL_ENABLE

// 麦克风接口定义
#define MIC_CLK_PIN      GPIO_NUM_0
#define MIC_DATA_PIN     GPIO_NUM_34
#define MIC_SAMPLE_RATE  16000

// GROVE接口定义
#define GROVE_I2C_SCL    GPIO_NUM_33
#define GROVE_I2C_SDA    GPIO_NUM_32
#define GROVE_VCC_PIN    GPIO_NUM_NC

// HAT SPK音频接口定义
#define I2S_DATA_PIN      0  // GPIO0 对应HAT SPK的SD
#define I2S_BCK_PIN      26  // GPIO26
#define I2S_WS_PIN       25  // GPIO25

// 红外发射管
#define IR_TX_PIN      GPIO_NUM_9
// 功放控制引脚
#define PAM8303_EN_PIN   19

// 传感器配置
#define MPU6886_GYROSCOPE
#define MPU6886_GPIO_SDA GPIO_NUM_21
#define MPU6886_GPIO_SCL GPIO_NUM_22
#define BM8563_RTC
#define BM8563_GPIO_IRQ GPIO_NUM_35

// TFT显示配置
#define ST7735_DRIVER
#define TFT_WIDTH 80
#define TFT_HEIGHT 160
#define TFT_MOSI_PIN GPIO_NUM_15
#define TFT_CLK_PIN  GPIO_NUM_13
#define TFT_CS_PIN   GPIO_NUM_5
#define TFT_DC_PIN   GPIO_NUM_23
#define TFT_RST_PIN  GPIO_NUM_18
#define DISPLAY_SWAP_XY true
#define DISPLAY_MIRROR_X false
#define TFT_ROTATION 3
#define TFT_INVERT_COLORS true

// 背光控制
#define TFT_BL_PIN   GPIO_NUM_9
#define TFT_BL_ON    HIGH

// 基础硬件配置
#define BUILTIN_LED_GPIO GPIO_NUM_10
#define BOOT_BUTTON_GPIO GPIO_NUM_37
#define BUTTON_A_GPIO GPIO_NUM_37
#define BUTTON_B_GPIO GPIO_NUM_39

// WiFi天线配置
#define WIFI_ANTENNA_EXTERNAL
#define RF_TX_POWER 20

#endif // _BOARD_CONFIG_H_