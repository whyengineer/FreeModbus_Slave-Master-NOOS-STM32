#ifndef STEP_BOARD_H
#define STEP_BOARD_H

#include "stm32f1xx_hal.h"


#define LED_R_PORT GPIOB
#define LED_R_PIN GPIO_PIN_3

#define LED_G_PORT GPIOB
#define LED_G_PIN GPIO_PIN_4

#define LED_B_PORT GPIOA
#define LED_B_PIN GPIO_PIN_15

#define M485_EN_PORT GPIOA
#define M485_EN_PIN GPIO_PIN_8

#ifdef STEP_TFT

#define TFT_CS_PORT GPIOA
#define TFT_CS_PIN GPIO_PIN_0

#define TFT_RST_PORT GPIOA
#define TFT_RST_PIN GPIO_PIN_1

#define TFT_DC_PORT GPIOB
#define TFT_DC_PIN GPIO_PIN_0

#endif

#ifdef STEP_TOUCH


#define TOUCH_CS_PORT GPIOB
#define TOUCH_CS_PIN GPIO_PIN_1

#define TOUCH_BUSY_PORT GPIOB
#define TOUCH_BUSY_PIN GPIO_PIN_13

#define TOUCH_IRQ_PORT  GPIOB
#define TOUCH_IRQ_PIN GPIO_PIN_14


#endif






#endif
