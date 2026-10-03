#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX
// 麦克风 I2S：麦SD接到ESP GPIO19
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_22
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_21
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_19

// 功放 I2S：ESP GPIO25输出 → 功放DIN
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_25
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_26
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_27
#else
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_26
#define AUDIO_I2S_GPIO_LRCK GPIO_NUM_27
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_19
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_25
#endif

// ========== 按键配置：GPIO5 按住录音松开停止 ==========
#define BOOT_BUTTON_GPIO        GPIO_NUM_5
#define BOOT_BUTTON_ACTIVE_LEVEL 0
#define BOOT_BUTTON_MODE BUTTON_MODE_HOLD

// LED
#define LED_GPIO_PIN            GPIO_NUM_4
#define LED_ACTIVE_LEVEL        1

// ========== bread_board.cc 必须的GPIO宏 ==========
#define BUILTIN_LED_GPIO        GPIO_NUM_4
#define LAMP_GPIO               GPIO_NUM_NC
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define ASR_BUTTON_GPIO         GPIO_NUM_NC

// ========== OLED屏幕宏（无屏幕，引脚NC，补齐用于编译通过） ==========
#define DISPLAY_SDA_PIN         GPIO_NUM_NC
#define DISPLAY_SCL_PIN         GPIO_NUM_NC
#define DISPLAY_WIDTH           128
#define DISPLAY_HEIGHT          32
#define DISPLAY_MIRROR_X        false
#define DISPLAY_MIRROR_Y        false

// ========== CI强制需要的SH1106宏 ==========
#define CONFIG_OLED_SH1106_128X64 false

// 关闭唤醒词，保留网页配网
#define CONFIG_USE_WAKE_WORD    false
#define CONFIG_WAKE_WORD_ENGINE "none"
#define CONFIG_WEB_PROVISION_ENABLE true

#endif // _BOARD_CONFIG_H_
