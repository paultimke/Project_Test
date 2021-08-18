/*
 * HAL_RTC.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Paul Timke
 */

#ifndef HAL_RTC_H_
#define HAL_RTC_H_

/*Includes-------------------*/
#include "main.h"
#include "rtc.h"
#include "HAL_LCD.h"
#include "HAL_Pot.h"

/*Macros-------------------*/
#define HAL_RTC_FORMAT_HHMM			(0)
#define HAL_RTC_FORMAT_HHMMSS		(1)

#define HHMMSS_DEFAULT_PAGE			(0)
#define HHMMSS_DEFAULT_COL			(72)
#define HHMM_DEFAULT_PAGE			(0)
#define HHMM_DEFAULT_COL			(92)


/*Prototypes-------------------*/
void HAL_RTC_SetTimePot(void);
void HAL_RTC_Time2LCD(uint8_t page, uint8_t col, int HAL_RTC_FORMAT);

#endif /* HAL_RTC_H_ */
