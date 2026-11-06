/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define REDN_Pin GPIO_PIN_0
#define REDN_GPIO_Port GPIOA
#define GREENN_Pin GPIO_PIN_1
#define GREENN_GPIO_Port GPIOA
#define YELLOWN_Pin GPIO_PIN_2
#define YELLOWN_GPIO_Port GPIOA
#define REDE_Pin GPIO_PIN_3
#define REDE_GPIO_Port GPIOA
#define GREENE_Pin GPIO_PIN_4
#define GREENE_GPIO_Port GPIOA
#define YELLOWE_Pin GPIO_PIN_5
#define YELLOWE_GPIO_Port GPIOA
#define REDS_Pin GPIO_PIN_6
#define REDS_GPIO_Port GPIOA
#define GREENS_Pin GPIO_PIN_7
#define GREENS_GPIO_Port GPIOA
#define YELLOWS_Pin GPIO_PIN_0
#define YELLOWS_GPIO_Port GPIOB
#define REDW_Pin GPIO_PIN_1
#define REDW_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_10
#define SEG6_GPIO_Port GPIOB
#define BTN_MODE_Pin GPIO_PIN_11
#define BTN_MODE_GPIO_Port GPIOB
#define BTN_INC_Pin GPIO_PIN_12
#define BTN_INC_GPIO_Port GPIOB
#define BTN_SET_Pin GPIO_PIN_13
#define BTN_SET_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_14
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_15
#define EN1_GPIO_Port GPIOB
#define SEG0_Pin GPIO_PIN_8
#define SEG0_GPIO_Port GPIOA
#define SEG1_Pin GPIO_PIN_9
#define SEG1_GPIO_Port GPIOA
#define SEG2_Pin GPIO_PIN_10
#define SEG2_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_11
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_12
#define EN3_GPIO_Port GPIOA
#define GREENW_Pin GPIO_PIN_5
#define GREENW_GPIO_Port GPIOB
#define YELLOWW_Pin GPIO_PIN_6
#define YELLOWW_GPIO_Port GPIOB
#define SEG3_Pin GPIO_PIN_7
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_8
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_9
#define SEG5_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
