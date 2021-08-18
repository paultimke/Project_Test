/*
 * HAL_RTC.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Paul Timke
 */

#include "HAL_RTC.h"

void HAL_RTC_SetTimePot(void)
{
	uint8_t hh, mm;

	hh = HAL_getHR(HAL_PotValue(POT1_CHANNEL));
	mm = HAL_getMin(HAL_PotValue(POT2_CHANNEL));

	MX_RTC_SetTime(hh, mm);
	return;
}

/*HAL_RTC_Time2LCD: User can decide whether to use a hh:mm or hh:mm:ss format.
 *Also, it is possible to move the digits around the display or set them
 *as DEFAULT, which will align the digits to the upper left corner*/
void HAL_RTC_Time2LCD(uint8_t page, uint8_t col, int HAL_RTC_FORMAT)
{
	uint8_t hour, min, sec;

	MX_RTC_GetTime(&hour, &min, &sec);

	uint8_t sec_small = sec % 10;
	uint8_t sec_big = sec/10;
	uint8_t min_small = min % 10;
	uint8_t min_big = min/10;
	uint8_t hour_small = hour % 10;
	uint8_t hour_big = hour/10;

	/*Build time array, add 48 to units to display the corresponding ascii number*/
	if(HAL_RTC_FORMAT == HAL_RTC_FORMAT_HHMMSS)
	{
		uint8_t lcd_time[8] = {(hour_big+48), (hour_small+48), ':', (min_big+48), (min_small+48), ':', (sec_big+48), (sec_small+48)};
		HAL_LCD_print (lcd_time, page, col, 8);
	}
	if(HAL_RTC_FORMAT == HAL_RTC_FORMAT_HHMM)
	{
		uint8_t lcd_time[5] = {(hour_big+48), (hour_small+48), ':', (min_big+48), (min_small+48)};
		HAL_LCD_print (lcd_time, page, col, 5);
	}

	return;
}
