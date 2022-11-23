#include "mFunctions.h"

HAL_StatusTypeDef mPrintf(char *str)
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
    uint8_t rbuf = 0;
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
    switch (colorType)
    {
        case RED:
            HAL_GPIO_WritePin(GPIOA, S2_Pin | S3_Pin, GPIO_PIN_RESET);
            break;
        case GREEN:
            HAL_GPIO_WritePin(GPIOA, S2_Pin | S3_Pin, GPIO_PIN_SET);
            break;
        case WHITE:
            HAL_GPIO_WritePin(GPIOA, S2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, S3_Pin, GPIO_PIN_RESET);
            break;
        case BLUE:
            HAL_GPIO_WritePin(GPIOA, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, S3_Pin, GPIO_PIN_SET);
            break;
        default:
            break;
    }
    return;
}

void SpeedSet(int speed)
{
    HAL_GPIO_WritePin(GPIOA, S0_Pin | S1_Pin, GPIO_PIN_RESET);
    switch (speed)
    {
		case POWER_DOWN:
			HAL_GPIO_WritePin(GPIOA, S0_Pin | S1_Pin, GPIO_PIN_RESET);
			break;
		case TWO_PERCENT:
			HAL_GPIO_WritePin(GPIOA, S0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, S1_Pin, GPIO_PIN_SET);
			break;
		case TWENTY_PERCENT:
			HAL_GPIO_WritePin(GPIOA, S0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, S1_Pin, GPIO_PIN_SET);
			break;
		case HUNDRED_PERCENT:
			HAL_GPIO_WritePin(GPIOA, S0_Pin | S1_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
    }
}
