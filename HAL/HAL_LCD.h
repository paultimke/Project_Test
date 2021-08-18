/*
 * HAL_LCD.h
 *
 *  Created on: Aug 6, 2021
 *      Author: Paul Timke
 */

#ifndef HAL_HAL_LCD_H_
#define HAL_HAL_LCD_H_

/*Includes--------------------*/
#include "main.h"
#include "spi.h"
#include "images.h"
#include "font.h"
#include "HAL_Pot.h"


/*Macros----------------------*/

#define HAL_LCD_HEIGHT 						(32)
#define HAL_LCD_WIDTH						(128)
#define HAL_DISPLAY_MAX_PAGE				(4)
#define HAL_DISPLAY_BITS					(8)

#define DISPLAY_ON							(0xAF)
#define DISPLAY_OFF							(0XAE)


#define COG_CMD_START_LINE(line)			(0x40 | (line & 0x01))
#define COG_CMD_PAGE_SET(page)				(0xB0 | (page & 0x0F))
#define COG_CMD_COLUMN_MSB(c)				(0x10 | ((c >> 4) & 0x0F))
#define COG_CMD_COLUMN_LSB(c)				(0x00 | (c & 0x0F))

#define COG_COMMON_NORMAL 					(0x00)
#define COG_COMMON_REVERSE					(0x08)
#define COG_CMD_COMMON_OUTPUT(dir)			(0xC0 | (dir & 0x0F))

#define COG_LCD_BIAS_0						(0x00)
#define COG_LCD_BIAS_1						(0x01)
#define COG_CMD_LCD_BIAS(ratio)				(0xA0 | (ratio & 0x01))


/*Prototypes-------------------*/
void HAL_LCD_dataWrite(uint8_t data);				//Write commands
void HAL_LCD_cmdWrite(uint8_t data);				//Write data to display
void HAL_LCD_Clear(void);							//Clears Display
void HAL_LCD_Init(void);							//Initialize LCD settings

void HAL_LCD_dispImage(uint8_t *image, uint8_t width, uint8_t height, uint8_t page_start, uint8_t column_start);		//Displays Image
void HAL_LCD_printletter(uint8_t string, uint8_t pag, uint8_t col);														//Print single letter
void HAL_LCD_print(uint8_t *word, uint8_t start_page, uint8_t start_column, uint8_t size);								//Print array
void HAL_LCD_printPotUpdate(void);



#endif /* HAL_HAL_LCD_H_ */



