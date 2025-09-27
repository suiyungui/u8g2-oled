#ifndef __OLED_APP_H__
#define __OLED_APP_H__

#include "mydefine.h"

uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8g2_gpio_and_delay_stm32(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
void u8g2_init(void);
void draw(u8g2_t *u8g2);
void oled_task(void);
#endif

