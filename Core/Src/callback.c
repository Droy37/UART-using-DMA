

#include "usart.h"

extern uint8_t rx_buff[100];

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
  if (huart == &huart6) {
    HAL_UART_Transmit_DMA(huart, rx_buff, Size);
    HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_buff, sizeof(rx_buff));
  }
}
