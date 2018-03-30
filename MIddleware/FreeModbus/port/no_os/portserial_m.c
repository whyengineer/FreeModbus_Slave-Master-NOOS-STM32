/*
 * FreeModbus Libary: RT-Thread Port
 * Copyright (C) 2013 Armink <armink.ztl@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: portserial_m.c,v 1.60 2013/08/13 15:07:05 Armink add Master Functions $
 */

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "usart.h"
#include "bsp.h"

#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Defines ------------------------------------------*/
/* serial transmit event */
#define EVENT_SERIAL_TRANS_START    (1<<0)

/* ----------------------- static functions ---------------------------------*/

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBMasterPortSerialInit(UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits,
        eMBParity eParity)
{
    return TRUE;
}

void vMBMasterPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{
    if (xRxEnable) {   
      HAL_GPIO_WritePin(M485_EN_PORT, M485_EN_PIN, GPIO_PIN_RESET);
      __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
    } else{
      __HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
    }
  
  if (xTxEnable) { 
    HAL_GPIO_WritePin(M485_EN_PORT, M485_EN_PIN, GPIO_PIN_SET);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_TXE);
  } else{
     __HAL_UART_DISABLE_IT(&huart1, UART_IT_TXE);
  }
}

void vMBMasterPortClose(void)
{
    
}

BOOL xMBMasterPortSerialPutByte(CHAR ucByte)
{
    
    return (HAL_OK == HAL_UART_Transmit(&huart1, (uint8_t*)&ucByte, 1, 10));
}

BOOL xMBMasterPortSerialGetByte(CHAR * pucByte)
{
    
    *pucByte = (uint8_t)(huart1.Instance->DR & (uint8_t)0x00FF);  
    return TRUE;
}



#endif
