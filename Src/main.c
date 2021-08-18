/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include "HAL_LCD.h"
#include "HAL_RTC.h"
#include "HAL_GPIO.h"
#include "HAL_Pot.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);

  /* System interrupt init*/

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  HAL_LCD_Init();
  MX_RTC_Init();
  HAL_Pot_Available();
  //HAL_startGPIO();


  //Display Welcome Message
  uint8_t message[7] = {'W', 'e', 'l', 'c', 'o', 'm','e'};
  HAL_LCD_print(message, 1, 42, 7);
  LL_mDelay(2000);
  HAL_LCD_Clear();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //Display Time
	 	  HAL_RTC_Time2LCD(HHMMSS_DEFAULT_PAGE, HHMMSS_DEFAULT_COL, HAL_RTC_FORMAT_HHMMSS);

	 	  	JOYSTICK_POS t1 = NULL2;
	 	  	  HAL_getPRESSED(B, &t1);
	 	  	  if(t1==CENTER){
	 	  		HAL_LCD_Clear();
	 	  		uint8_t message[5] = {'E', 'n', 't', 'e', 'r'};
	 	  		HAL_LCD_print(message, 2, 49, 5);
	 	  		LL_mDelay(200);
	 	  	  }
	 	  	  //}
	 	  	  if(t1 == DOWN){
	 		  		HAL_LCD_Clear();
	 	  		  	uint8_t message[10] = {'P', 'a', 's', 't', 'i', 'l', 'l', 'a', ' ', '3'};
	 	  			HAL_LCD_print(message, 2, 34, 10);
	 		  		LL_mDelay(200);
	 	  	  }
	 	  	  HAL_getPRESSED(C, &t1);
	 	  	  if(t1==RIGHT){
	 	  		  	HAL_getPRESSED(B, &t1);
	 		  		HAL_LCD_Clear();
	 		  		uint8_t potchanged = 0;
	 		  		uint8_t message[8] = {'S', 'e', 't', ' ', 't', 'i', 'm', 'e'};
	 		  		HAL_LCD_print(message, 2, 40, 8);
	 		  		LL_mDelay(800);

	 		  		while(t1 != CENTER){
	 		  			HAL_getPRESSED(B, &t1);
	 		  			HAL_LCD_printPotUpdate();

	 		  		}
	 		  		potchanged = 1;
	 		  		if(potchanged == 1){
	 		  			HAL_RTC_SetTimePot();
	 		  			HAL_LCD_Clear();
	 		  		}
	 	  	  }
	 	  	  if(t1 == LEFT){
	 		  		HAL_LCD_Clear();
	 	  		  	uint8_t message[10] = {'P', 'a', 's', 't', 'i', 'l', 'l', 'a', ' ', '2'};
	 	  			HAL_LCD_print(message, 2, 34, 10);
	 		  		LL_mDelay(200);
	 	  	  }
	 	  	  HAL_getPRESSED(A, &t1);
	 	  	  if(t1 == UP){
	 		  		HAL_LCD_Clear();
	 	  		  	uint8_t message[10] = {'P', 'a', 's', 't', 'i', 'l', 'l', 'a', ' ', '1'};
	 	  			HAL_LCD_print(message, 2, 34, 10);
	 		  		LL_mDelay(200);
	 	  	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_PWR_EnableBkUpAccess();
  if(LL_RCC_GetRTCClockSource() != LL_RCC_RTC_CLKSOURCE_LSE)
  {
    LL_RCC_ForceBackupDomainReset();
    LL_RCC_ReleaseBackupDomainReset();
  }
  LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_LOW);
  LL_RCC_LSE_Enable();

   /* Wait till LSE is ready */
  while(LL_RCC_LSE_IsReady() != 1)
  {

  }
  if(LL_RCC_GetRTCClockSource() != LL_RCC_RTC_CLKSOURCE_LSE)
  {
    LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSE);
  }
  LL_RCC_EnableRTC();
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_4);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }
  LL_Init1msTick(2000000);
  LL_SetSystemCoreClock(2000000);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
