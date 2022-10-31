#include "mFunctions.h"

HAL_StatusTypeDef mPrintf(char* str)
{
	return HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}

void CsSelect(void)
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET); // CS LOW
	return;
}

void CsDeselect(void)
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET); // CS HIGH
	return;
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
	return;
}

void ColorSet(int colorType)
{
	HAL_GPIO_WritePin(GPIOA, S2_Pin | S3_Pin, GPIO_PIN_RESET);
    if (colorType == 0)
    {	// RED
        HAL_GPIO_WritePin(GPIOA, S2_Pin | S3_Pin, GPIO_PIN_RESET);
    }
    else if (colorType == 1)
    {
    	// GREEN
        HAL_GPIO_WritePin(GPIOA, S2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, S3_Pin, GPIO_PIN_SET);
    }
    else if (colorType == 2)
    {
    	// WHITE
        HAL_GPIO_WritePin(GPIOA, S2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, S3_Pin, GPIO_PIN_RESET);
    }
    else if (colorType == 3)
    {
    	// BLUE
        HAL_GPIO_WritePin(GPIOA, S2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, S3_Pin, GPIO_PIN_SET);
    }
	return;
}

void SpeedSet(int speed)
{
	HAL_GPIO_WritePin(GPIOA, S0_Pin | S1_Pin, GPIO_PIN_RESET);

    if(speed == 0)
    {
        HAL_GPIO_WritePin(GPIOA, S0_Pin | S1_Pin, GPIO_PIN_RESET);
    }
    // %2
    else if(speed == 1)
    {
        HAL_GPIO_WritePin(GPIOA, S0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, S1_Pin, GPIO_PIN_SET);
    }
    // %20
    else if(speed == 2)
    {
        HAL_GPIO_WritePin(GPIOA, S0_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, S1_Pin, GPIO_PIN_RESET);
    }
    // %100
    else if(speed == 3)
    {
        HAL_GPIO_WritePin(GPIOA, S0_Pin | S1_Pin, GPIO_PIN_SET);
    }
	return;
}
