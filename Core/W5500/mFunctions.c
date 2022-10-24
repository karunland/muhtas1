
#include "mFunctions.h"


HAL_StatusTypeDef mPrintf(char* str)
{
	return HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}

void CsSelect(void)
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET); // CS LOW
}

void CsDeselect(void)
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET); // CS HIGH
}

uint8_t SpiRb(void)
{
	uint8_t rbuf=0;
	HAL_SPI_Receive(&hspi1, &rbuf, 1, HAL_MAX_DELAY);
	return rbuf;
}

void SpiWb(uint8_t b)
{
	HAL_SPI_Transmit(&hspi1, &b, 1, HAL_MAX_DELAY);
}
