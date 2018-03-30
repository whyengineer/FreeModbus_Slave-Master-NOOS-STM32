#include "bsp.h"
#ifdef STEP_TFT
#include "tft.h"
#endif
#ifdef STEP_TOUCH
#include "touch.h"
#endif


uint8_t system_init=0;

void bsp_init(){
      //close led
    HAL_GPIO_WritePin(LED_R_PORT, LED_R_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_G_PORT, LED_G_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_B_PORT, LED_B_PIN, GPIO_PIN_SET);
#ifdef STEP_TFT
    tft_init();
#endif
#ifdef STEP_TOUCH
    touch_init();
#endif
    
    
    system_init=1;
}
