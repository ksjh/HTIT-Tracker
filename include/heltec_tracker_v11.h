#ifndef HELTEC_TRACKER_V11_H_
#define HELTEC_TRACKER_V11_H_

#include <stdint.h>

/* Heltec Wireless Tracker V1.1 */

//
// TFT data from HT_st7735.h
//
#define ST7735_CS_Pin           38
#define ST7735_REST_Pin         39
#define ST7735_DC_Pin           40
#define ST7735_SCLK_Pin         41
#define ST7735_MOSI_Pin         42
#define ST7735_LED_K_Pin        21
#define ST7735_VTFT_CTRL_Pin    3
#define ST7735_WIDTH            160
#define ST7735_HEIGHT           80
// mini 160x80, rotate left (INITR_MINI160x80_PLUGIN)
#define ST7735_MODEL            INITR_MINI160x80_PLUGIN

//
// SX1262 from esp32/libraries/LoraWan102/src/driver/board-config.h
//
#define BOARD_TCXO_WAKEUP_TIME  5
#define RADIO_DIO_1             14
#define RADIO_NSS               8
#define RADIO_RESET             12
#define RADIO_BUSY              13
#define LORA_CLK                9
#define LORA_MISO               11
#define LORA_MOSI               10

//
// UC6580 GNSS
//
#define VGNSS_CTRL              3
#define GNSS_TX                 33
#define GNSS_RX                 34
#define GNSS_RST                35
#define GNSS_PPS                36
#define GNSS_BAUD               115200UL

//
// misc from schematic
//
#define VEXT_CTRL               3
#define VBAT_READ               1
// VBAT = analogReadMilliVolts(VBAT_READ) * 4.9
#define ADC_CTRL                2
#define USER_KEY                0
#define LED                     18
#define GNSS_BOOT_MODE          47
#define GNSS_D_SEL              48
#define U0RXD                   44
#define U0TXD                   43

#endif // HELTEC_TRACKER_V11_H_