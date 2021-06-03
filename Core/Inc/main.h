/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f4xx_hal.h"

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
#define DETECT_0_Pin GPIO_PIN_2
#define DETECT_0_GPIO_Port GPIOE
#define KEY_1_Pin GPIO_PIN_3
#define KEY_1_GPIO_Port GPIOE
#define KEY_0_Pin GPIO_PIN_4
#define KEY_0_GPIO_Port GPIOE
#define DETECT_3_Pin GPIO_PIN_5
#define DETECT_3_GPIO_Port GPIOE
#define OUT_0_Pin GPIO_PIN_0
#define OUT_0_GPIO_Port GPIOC
#define OUT_1_Pin GPIO_PIN_1
#define OUT_1_GPIO_Port GPIOC
#define OUT_2_Pin GPIO_PIN_2
#define OUT_2_GPIO_Port GPIOC
#define OUT_3_Pin GPIO_PIN_3
#define OUT_3_GPIO_Port GPIOC
#define TIANMAO_4_Pin GPIO_PIN_12
#define TIANMAO_4_GPIO_Port GPIOB
#define TIANMAO_5_Pin GPIO_PIN_13
#define TIANMAO_5_GPIO_Port GPIOB
#define TIANMAO_6_Pin GPIO_PIN_14
#define TIANMAO_6_GPIO_Port GPIOB
#define TIANMAO_7_Pin GPIO_PIN_15
#define TIANMAO_7_GPIO_Port GPIOB
#define TIANMAO_0_Pin GPIO_PIN_8
#define TIANMAO_0_GPIO_Port GPIOD
#define TIANMAO_1_Pin GPIO_PIN_9
#define TIANMAO_1_GPIO_Port GPIOD
#define TIANMAO_2_Pin GPIO_PIN_10
#define TIANMAO_2_GPIO_Port GPIOD
#define TIANMAO_3_Pin GPIO_PIN_11
#define TIANMAO_3_GPIO_Port GPIOD
#define OUT_4_Pin GPIO_PIN_0
#define OUT_4_GPIO_Port GPIOD
#define OUT_5_Pin GPIO_PIN_1
#define OUT_5_GPIO_Port GPIOD
#define OUT_6_Pin GPIO_PIN_2
#define OUT_6_GPIO_Port GPIOD
#define OUT_7_Pin GPIO_PIN_3
#define OUT_7_GPIO_Port GPIOD
#define OUT_8_Pin GPIO_PIN_4
#define OUT_8_GPIO_Port GPIOD
#define OUT_9_Pin GPIO_PIN_5
#define OUT_9_GPIO_Port GPIOD
#define DETECT_1_Pin GPIO_PIN_0
#define DETECT_1_GPIO_Port GPIOE
#define DETECT_2_Pin GPIO_PIN_1
#define DETECT_2_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
