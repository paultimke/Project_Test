/**
  ******************************************************************************
  * @file    rtc.c
  * @brief   This file provides code for the configuration
  *          of the RTC instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* RTC init function */
void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  LL_RTC_InitTypeDef RTC_InitStruct = {0};

  /* Peripheral clock enable */
  LL_RCC_EnableRTC();

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC and set the Time and Date
  */
  RTC_InitStruct.HourFormat = LL_RTC_HOURFORMAT_24HOUR;
  RTC_InitStruct.AsynchPrescaler = 127;
  RTC_InitStruct.SynchPrescaler = 255;
  LL_RTC_Init(RTC, &RTC_InitStruct);
  LL_RTC_SetAsynchPrescaler(RTC, 127);
  LL_RTC_SetSynchPrescaler(RTC, 255);
  /* USER CODE BEGIN RTC_Init 2 */

  LL_RTC_DateTypeDef RTC_DateStruct = {0};
  LL_RTC_TimeTypeDef RTC_TimeStruct = {0};

  LL_RTC_DATE_StructInit(&RTC_DateStruct);
  LL_RTC_TIME_StructInit(&RTC_TimeStruct);

  LL_RTC_DATE_Init(RTC, LL_RTC_FORMAT_BIN, &RTC_DateStruct);
  LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BIN, &RTC_TimeStruct);

  /* USER CODE END RTC_Init 2 */

}

/* USER CODE BEGIN 1 */

void MX_RTC_Enter_InitMode(void)
{
	LL_RTC_EnableInitMode(RTC);
	while(LL_RTC_IsActiveFlag_INIT(RTC) != 1);

	return;
}

void MX_RTC_Exit_InitMode(void)
{
	LL_RTC_DisableInitMode(RTC);
	LL_RTC_ClearFlag_RS(RTC);
	while(LL_RTC_IsActiveFlag_RS(RTC) != 1);

	return;
}

void MX_RTC_GetTime(uint8_t *hh, uint8_t *mm, uint8_t *ss)
{
	*hh = __LL_RTC_CONVERT_BCD2BIN(LL_RTC_TIME_GetHour(RTC)) ;
	*mm = __LL_RTC_CONVERT_BCD2BIN(LL_RTC_TIME_GetMinute(RTC));
	*ss = __LL_RTC_CONVERT_BCD2BIN(LL_RTC_TIME_GetSecond(RTC));

	return;
}

void MX_RTC_GetDate(uint16_t *yyyy, uint8_t *mm, uint8_t *dd)
{
	*yyyy = 2000 + __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetYear(RTC));
	*mm = __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetMonth(RTC));
	*dd = __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetDay(RTC));

	return;
}

void MX_RTC_SetTime(uint8_t hh, uint8_t mm)
{
	  LL_RTC_InitTypeDef RTC_InitStruct = {0};
	  LL_RCC_EnableRTC();

	  RTC -> CR |= RTC_CR_BYPSHAD;

	  RTC_InitStruct.HourFormat = LL_RTC_HOURFORMAT_24HOUR;
	  RTC_InitStruct.AsynchPrescaler = 127;
	  RTC_InitStruct.SynchPrescaler = 255;
	  LL_RTC_Init(RTC, &RTC_InitStruct);
	  LL_RTC_SetAsynchPrescaler(RTC, 127);
	  LL_RTC_SetSynchPrescaler(RTC, 255);

	  LL_RTC_TimeTypeDef RTC_TimeStruct = {0};

	  Update_TR(&RTC_TimeStruct, hh, mm);

	  LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BIN, &RTC_TimeStruct);

	  return;
}

void Update_TR(LL_RTC_TimeTypeDef *RTC_TimeStruct, uint8_t hour, uint8_t min)
{
	RTC_TimeStruct->TimeFormat = LL_RTC_TIME_FORMAT_AM_OR_24;
	RTC_TimeStruct->Hours = hour;
	RTC_TimeStruct->Minutes = min;
	RTC_TimeStruct->Seconds = 0x00;

	return;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
