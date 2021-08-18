/*
 * HAL_Pot.c
 *
 *  Created on: 09/08/2021
 *      Author: Marys
 */


/* Includes ------------------------------------------------------------------*/
#include "HAL_Pot.h"
#include "stdio.h"
#include "adc.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/**
  * @brief Configuration of the Pots with the ADC channels
  */
void HAL_Pot_Available(void)
{
	MX_ADC1_Init();
	MX_ADC1_Calibration();
	MX_ADC1_Enable();
  }


/**
  * @brief This function handles Memory management fault.
  */
uint16_t HAL_PotValue(ADC_CHANNEL Ch)

{
	uint16_t adc_Result = 0;
	MX_ADC1_SetChannel(Ch);
	MX_ADC1_StartConvertion();
	adc_Result = MX_ADC1_Value();
	return adc_Result;

}

uint16_t HAL_PotResult1(void){
	  uint16_t vp1=0;
	  vp1 = HAL_PotValue(POT1_CHANNEL);
	  return vp1;
}


uint16_t HAL_PotResult2(void){
	  uint16_t vp2 = 0;
	  vp2 = HAL_PotValue(POT2_CHANNEL);
	  return vp2;
}

uint8_t HAL_getHR(uint16_t hr){
	uint32_t hr1 = 0;
	  if(hr >= 0 && hr <= 42){
	  		  //printf("\n\rHora: 1 \n\r");
	  		  hr1=1;
	  	  }
	  	  else if( hr >= 43 &&  hr <= 85){
	  		  //printf("\n\rHora: 2 \n\r");
	  		  hr1=2;
	  	  }
	  	  else if( hr >= 86 && hr <= 128){
	  		  //printf("\n\rHora: 3 \n\r");
	  		  hr1=3;
	  	  }
	  	  else if (hr >= 129 && hr <= 171){
	  		  //printf("\n\rHora: 4 \n\r");
	  		  hr1=4;
	  	  }
	  	  else if (hr >= 172 && hr <= 214){
	  		  //printf("\n\rHora: 5 \n\r");
	  		  hr1=5;
	  	  }
	  	  else if (hr >= 215 && hr <= 257){
	  		  //printf("\n\rHora: 6 \n\r");
	  		  hr1=6;
	  	  }
	  	  else if (hr >= 258 && hr <= 300){
	  		 // printf("\n\rHora: 7 \n\r");
	  		  hr1=7;
	  	  }
	  	  else if (hr >= 301 && hr <= 343){
	  		  //printf("\n\rHora: 8 \n\r");
	  		  hr1=8;
	  	  }
	  	  else if (hr >= 344 && hr <= 386){
	  		  //printf("\n\rHora: 9 \n\r");
	  		  hr1=9;
	  	  }
	  	  else if (hr >= 387 && hr <= 429){
	  		  //printf("\n\rHora: 10 \n\r");
	  		  hr1=10;
	  	  }
	  	  else if (hr >= 430 && hr <= 472){
	  		 // printf("\n\rHora: 11 \n\r");
	  		  hr1=11;
	  	  }
	  	  else if (hr >= 473 && hr <= 515){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=12;
	  	  }
	  	  else if (hr >= 516 && hr <= 558){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=13;
	  	  }
	  	  else if (hr >= 559 && hr <= 601){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=14;
	  	  }
	  	  else if (hr >= 602 && hr <= 644){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=15;
	  	  }
	  	  else if (hr >= 645 && hr <= 687){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=16;
	  	  }
	  	  else if (hr >= 689 && hr <= 730){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=17;
	  	  }
	  	  else if (hr >= 731 && hr <= 773){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=18;
	  	  }
	  	  else if (hr >= 774 && hr <= 816){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=19;
	  	  }
	  	  else if (hr >= 817 && hr <= 859){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=20;
	  	  }
	  	  else if (hr >= 860 && hr <= 902){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=21;
	  	  }
	  	  else if (hr >= 903 && hr <= 945){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=22;
	  	  }
	  	  else if (hr >= 946 && hr <= 1024){
	  		  //printf("\n\rHora: 12 \n\r");
	  		  hr1=23;
	  	  }
	  return hr1;
}

uint8_t HAL_getMin(uint16_t min){
	uint32_t min1 =0;
	if(min >= 0 && min <= 17){
		  		  //printf("Minuto: 0 \n\r");
		  		  min1=0;
		  	  }
		  	  else if( min >= 18 &&  min <= 34){
		  		  //printf("Minuto: 1 \n\r");
		  		  min1=1;
		  	  }
		  	  else if( min >= 35 && min <= 51){
		  		  //printf("Minuto: 2 \n\r");
		  		  min1=2;
		  	  }
		  	  else if (min >= 52 && min <= 68){
		  		  //printf("Minuto: 3 \n\r");
		  		  min1=3;
		  	  }
		  	  else if (min >= 69 && min <= 85){
		  		  //printf("Minuto: 4 \n\r");
		  		  min1=4;
		  	  }
		  	  else if (min >= 86 && min <= 102){
		  		  //printf("Minuto: 5 \n\r");
		  		  min1=5;
		  	  }
		  	  else if (min >= 103 && min <= 119){
		  		  //printf("Minuto: 6 \n\r");
		  		  min1=6;
		  	  }
		  	  else if (min >= 120 && min <= 136){
		  		  //printf("Minuto: 7 \n\r");
		  		  min1=7;
		  	  }
		  	  else if (min >= 137 && min <= 153){
		  		  //printf("Minuto: 8 \n\r");
		  		  min1=8;
		  	  }
		  	  else if (min >= 154 && min <= 170){
		  		  //printf("Minuto: 9 \n\r");
		  		  min1=9;
		  	  }
		  	  else if (min>= 171 && min<= 187){
		  		  //printf("Minuto: 10 \n\r");
		  		  min1=10;
		  	  }
		  	  else if (min >= 188 && min <= 204){
				  //printf("Minuto: 11 \n\r");
				  min1=11;
			  }
			  else if (min >= 205 && min <= 221){
				  //printf("Minuto: 12 \n\r");
				  min1=12;
			  }
			  else if (min >= 222 && min <= 238){
				  //printf("Minuto: 13 \n\r");
				  min1=13;
			  }
			  else if (min >= 239 && min <= 255){
				  //printf("Minuto: 14 \n\r");
				  min1=14;
			  }
			  else if (min >= 256 && min <= 272){
				  //printf("Minuto: 15 \n\r");
				  min1=15;
			  }
			  else if (min >= 273 && min <= 289){
				  //printf("Minuto: 16 \n\r");
				  min1=16;
			  }
			  else if (min >= 290 && min <= 306){
				  //printf("Minuto: 17 \n\r");
				  min1=17;
			  }
			  else if (min >= 307 && min <= 323){
				  //printf("Minuto: 18 \n\r");
				  min1=18;
			  }
			  else if (min >= 324 && min <= 340){
				  //printf("Minuto: 19 \n\r");
				  min1=19;
			  }
			  else if (min >= 341 && min <= 357){
				  //printf("Minuto: 20 \n\r");
				  min1=20;
			  }
			  else if (min >= 358 && min <= 374){
				  //printf("Minuto: 21 \n\r");
				  min1=21;
			  }
			  else if (min >= 375 && min <= 391){
				  //printf("Minuto: 22 \n\r");
				  min1=22;
			  }
			  else if (min >= 392 && min <= 408){
				  //printf("Minuto: 23 \n\r");
				  min1=23;
			  }
			  else if (min >= 409 && min <= 425){
				  //printf("Minuto: 24 \n\r");
				  min1=24;
			  }
			  else if (min >= 426 && min <= 442){
				  //printf("Minuto: 25 \n\r");
				  min1=25;
			  }
			  else if (min >= 443 && min <= 459){
				  //printf("Minuto: 26 \n\r");
				  min1=26;
			  }
			  else if (min >= 460 && min <= 476){
				  //printf("Minuto: 27 \n\r");
				  min1=27;
			  }
			  else if (min >= 477 && min <= 493){
				 // printf("Minuto: 28 \n\r");
				  min1=28;
			  }
			  else if (min >= 494 && min <= 510){
				 // printf("Minuto: 29 \n\r");
				  min1=29;
			  }
			  else if (min >= 511 && min <= 527){
				 // printf("Minuto: 30 \n\r");
				  min1=30;
			  }
			  else if (min >= 528 && min <= 544){
				 // printf("Minuto: 31 \n\r");
				  min1=31;
			  }
			  else if (min >= 545 && min <= 561){
				 // printf("Minuto: 32 \n\r");
				  min1=32;
			  }
			  else if (min >= 562 && min <= 578){
				 // printf("Minuto: 33 \n\r");
				  min1=33;
			  }
			  else if (min >= 579 && min <= 595){
				 // printf("Minuto: 34 \n\r");
				  min1=34;
			  }
			  else if (min >= 596 && min <= 612){
				 // printf("Minuto: 35 \n\r");
				  min1=35;
			  }
			  else if (min >= 613 && min <= 629){
				 // printf("Minuto: 36 \n\r");
				  min1=36;
			  }
			  else if (min >= 630 && min <= 646){
				  //printf("Minuto: 37 \n\r");
				  min1=37;
			  }
			  else if (min >= 647 && min <= 663){
				  //printf("Minuto: 38 \n\r");
				  min1=38;
			  }
			  else if (min >= 664 && min <= 680){
				 // printf("Minuto: 39 \n\r");
				  min1=39;
			  }
			  else if (min >= 681 && min <= 697){
				 // printf("Minuto: 40 \n\r");
				  min1=40;
			  }
			  else if (min >= 698 && min <= 714){
				 // printf("Minuto: 41 \n\r");
				  min1=41;
			  }
			  else if (min >= 715 && min <= 731){
				 // printf("Minuto: 42 \n\r");
				  min1=42;
			  }
			  else if (min >= 732 && min <= 748){
				 // printf("Minuto: 43 \n\r");
				  min1=43;
			  }
			  else if (min >= 749 && min <= 765){
				//  printf("Minuto: 44 \n\r");
				  min1=44;
			  }
			  else if (min >= 766 && min <= 782){
				//  printf("Minuto: 45 \n\r");
				  min1=45;
			  }
			  else if (min >= 783 && min <= 799){
				//  printf("Minuto: 46 \n\r");
				  min1=46;
			  }
			  else if (min >= 800 && min <= 816){
				//  printf("Minuto: 47 \n\r");
				  min1=47;
			  }
			  else if (min >= 817 && min <= 833){
				//  printf("Minuto: 48 \n\r");
				  min1=48;
			  }
			  else if (min >= 834 && min <= 850){
				//  printf("Minuto: 49 \n\r");
				  min1=49;
			  }
			  else if (min >= 851 && min <= 867){
				//  printf("Minuto: 50 \n\r");
				  min1=50;
			  }
			  else if (min >= 868 && min <= 884){
				//  printf("Minuto: 51 \n\r");
				  min1=51;
			  }
			  else if (min >= 885 && min <= 901){
				//  printf("Minuto: 52 \n\r");
				  min1=52;
			  }
			  else if (min >= 902 && min <= 918){
				//  printf("Minuto: 53 \n\r");
				  min1=53;
			  }
			  else if (min >= 919 && min <= 935){
				//  printf("Minuto: 54 \n\r");
				  min1=54;
			  }
			  else if (min >= 936 && min <= 952){
				 // printf("Minuto: 55 \n\r");
				  min1=55;
			  }
			  else if (min >= 953 && min <= 969){
				//  printf("Minuto: 56 \n\r");
				  min1=56;
			  }
			  else if (min >= 970 && min <= 986){
				//  printf("Minuto: 57 \n\r");
				  min1=57;
			  }
			  else if (min >= 987 && min <= 1003){
				//  printf("Minuto: 58 \n\r");
				  min1=58;
			  }
			  else if (min >= 1004 && min <= 1024){
				//  printf("Minuto: 59 \n\r");
				  min1=59;
			  }
	return min1;
}
