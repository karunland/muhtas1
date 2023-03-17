/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define mS2_Pin GPIO_PIN_14
#define mS2_GPIO_Port GPIOC
#define mS3_Pin GPIO_PIN_15
#define mS3_GPIO_Port GPIOC
#define mS0_Pin GPIO_PIN_1
#define mS0_GPIO_Port GPIOA
#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA
#define mS1_Pin GPIO_PIN_8
#define mS1_GPIO_Port GPIOA
#define S0_Pin GPIO_PIN_9
#define S0_GPIO_Port GPIOA
#define S1_Pin GPIO_PIN_10
#define S1_GPIO_Port GPIOA
#define S2_Pin GPIO_PIN_11
#define S2_GPIO_Port GPIOA
#define S3_Pin GPIO_PIN_12
#define S3_GPIO_Port GPIOA
#define Trigger_Pin GPIO_PIN_6
#define Trigger_GPIO_Port GPIOB
#define Echo_Pin GPIO_PIN_7
#define Echo_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
