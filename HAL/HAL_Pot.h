/*
 * HAL_Pot.h
 *
 *  Created on: 09/08/2021
 *      Author: Marys
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HAL_POT_H__
#define __HAL_POT_H__

#ifdef __cplusplus
extern "C" {
#endif



/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

#define POT1_PORT		PORTA
#define POT1_PIN		0
#define POT1_CHANNEL	ADC_CHANNEL_1
#define POT2_PORT		PORTA
#define POT2_PIN		1
#define POT2_CHANNEL	ADC_CHANNEL_2

#define POT_MAX_VOLTAGE	1023
#define POT_MAX_COUNT	330



/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */

void HAL_Pot_Available(void);
uint16_t HAL_PotValue(ADC_CHANNEL Ch);
uint16_t HAL_PotResult1(void);
uint16_t HAL_PotResult2(void);
uint8_t HAL_getHR(uint16_t hr1);
uint8_t HAL_getMin(uint16_t min);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
