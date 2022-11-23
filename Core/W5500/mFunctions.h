#ifndef _mSpiInit_H_
#define _mSpiIni_H_

#include "main.h"
#include <string.h>

extern SPI_HandleTypeDef hspi1;
extern UART_HandleTypeDef huart2;
extern char msg[60];

#define RED 0
#define BLUE 1
#define WHITE 2
#define GREEN 3

#define POWER_DOWN 0
#define TWO_PERCENT 1
#define TWENTY_PERCENT 2
#define HUNDRED_PERCENT 3

// Simply of hal_uart_transmit function. It does nothin more than transmitting data
HAL_StatusTypeDef mPrintf(char *str);
// Below functions are for CallBack Funtions of Wiznet APIs. We are going to need address of them
// Chip select function and deselect funtion
void CsSelect(void);
void CsDeselect(void);
// Spi read and write one byte funtions
uint8_t SpiRb(void);
void SpiWb(uint8_t b);

void ColorSet(int colorType);
void SpeedSet(int speed);

#define NETWORK_MSG "Network configuration:\r\n"
#define IP_MSG "  IP ADDRESS:  %d.%d.%d.%d\r\n"
#define NETMASK_MSG "  NETMASK:     %d.%d.%d.%d\r\n"
#define GW_MSG "  GATEWAY:     %d.%d.%d.%d\r\n"
#define MAC_MSG "  MAC ADDRESS: %x:%x:%x:%x:%x:%x\r\n"

#define PRINT_NETINFO(netInfo)                                                                                             \
  do                                                                                                                       \
  {                                                                                                                        \
    HAL_UART_Transmit(&huart2, (uint8_t *)NETWORK_MSG, strlen(NETWORK_MSG), 100);                                          \
    sprintf(msg, MAC_MSG, netInfo.mac[0], netInfo.mac[1], netInfo.mac[2], netInfo.mac[3], netInfo.mac[4], netInfo.mac[5]); \
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100);                                                          \
    sprintf(msg, IP_MSG, netInfo.ip[0], netInfo.ip[1], netInfo.ip[2], netInfo.ip[3]);                                      \
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100);                                                          \
    sprintf(msg, NETMASK_MSG, netInfo.sn[0], netInfo.sn[1], netInfo.sn[2], netInfo.sn[3]);                                 \
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100);                                                          \
    sprintf(msg, GW_MSG, netInfo.gw[0], netInfo.gw[1], netInfo.gw[2], netInfo.gw[3]);                                      \
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100);                                                          \
  } while (0)

#define PRINT_STR(msg)                                            \
  do                                                              \
  {                                                               \
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100); \
  } while (0)

#endif // _mSpiIni_H_
