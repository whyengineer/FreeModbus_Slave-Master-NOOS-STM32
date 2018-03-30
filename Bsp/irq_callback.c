#include "stm32f1xx_hal.h"
#include "mbport.h"
#include "mb_m.h"




void HAL_SYSTICK_Callback(void){
#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
  eMBMasterPoll();
#endif
#if MB_SLAVE_RTU_ENABLED>0 || MB_SLAVE_ASCII_ENABLED>0 
  eMBPoll();
#endif
}
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
//#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
//  pxMBMasterFrameCBTransmitterEmpty();
//#endif
//#if MB_SLAVE_RTU_ENABLED>0 || MB_SLAVE_ASCII_ENABLED>0 
//  pxMBFrameCBTransmitterEmpty();
//#endif
//  
//}
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
//  
//#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0 
//  pxMBMasterFrameCBByteReceived();
//#endif
//  
//#if MB_SLAVE_RTU_ENABLED>0 || MB_SLAVE_ASCII_ENABLED>0 
//  pxMBFrameCBByteReceived();
//#endif
//  
//}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0   
  (void) pxMBMasterPortCBTimerExpired();
#endif
#if MB_SLAVE_RTU_ENABLED>0 || MB_SLAVE_ASCII_ENABLED>0   
   (void )pxMBPortCBTimerExpired(  );
#endif
}