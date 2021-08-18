#include "HAL_LCD.h"


void HAL_LCD_dataWrite(uint8_t data)
{
	MX_SPI1_CSlow();
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8);		//A0 pin high
	MX_SPI1_Send(data);
	MX_SPI1_CShigh();
	return;
}


void HAL_LCD_cmdWrite(uint8_t data)
{
	MX_SPI1_CSlow();
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);	//A0 pin low
	MX_SPI1_Send(data);
	MX_SPI1_CShigh();
	return;
}


void HAL_LCD_dispImage(uint8_t *image, uint8_t width, uint8_t height, uint8_t page_start, uint8_t column_start)
{
	uint8_t page;
	uint8_t index;
	uint8_t page_max;
	uint8_t column_max;

	index = 0;

	page_max = page_start + (height-1) / HAL_DISPLAY_BITS;
	if(height % HAL_DISPLAY_BITS > 0)
	{
		page_max++;
	}
	if(page_max >(HAL_DISPLAY_MAX_PAGE-1))
	{
		page_max = HAL_DISPLAY_MAX_PAGE-1;
	}

	column_max = column_start + width -1;
	if(column_max >= HAL_LCD_WIDTH)
	{
		column_max = HAL_LCD_WIDTH -1;
	}


	//HAL_LCD_cmdWrite(DISPLAY_OFF);
	HAL_LCD_cmdWrite(COG_CMD_START_LINE(0));

	for(page = page_start; page <= page_max; page++)
	{
		HAL_LCD_cmdWrite(COG_CMD_PAGE_SET(page));
		for (uint8_t column = column_start; column <= column_max; column++)
		{
			HAL_LCD_cmdWrite(COG_CMD_COLUMN_LSB(column));
			HAL_LCD_cmdWrite(COG_CMD_COLUMN_MSB(column));

			HAL_LCD_dataWrite(image[index++]);
		}
	}
	HAL_LCD_cmdWrite(DISPLAY_ON);
	return;
}


void HAL_LCD_printletter(uint8_t string, uint8_t pag, uint8_t col)
{
	HAL_LCD_dispImage((Font+(string * SMALLFONT_WIDTH)), SMALLFONT_WIDTH, SMALLFONT_HEIGHT, pag, col);
	return;
}



void HAL_LCD_print(uint8_t *word, uint8_t start_page, uint8_t start_column, uint8_t size)
{
	uint8_t letter;
	uint8_t page_update = 0;
	uint8_t column_update = 0;

	for (letter = 0; letter < size; letter++)
	{
		HAL_LCD_printletter(word[letter], start_page+page_update, start_column+column_update);

		column_update = column_update + SMALLFONT_WIDTH + 1;

	}
}

void HAL_LCD_printPotUpdate(void)
{
	uint8_t pothh, potmm;

	pothh = HAL_getHR(HAL_PotValue(POT1_CHANNEL));
	potmm = HAL_getMin(HAL_PotValue(POT2_CHANNEL));

	uint8_t min_small = potmm % 10;
	uint8_t min_big = potmm/10;
	uint8_t hour_small = pothh % 10;
	uint8_t hour_big = pothh/10;

	uint8_t lcd_pot_update[8] = {(hour_big+48), (hour_small+48), ':', (min_big+48), (min_small+48), ':', ('0'), ('0')};
	HAL_LCD_print (lcd_pot_update, 2, 40, 8);
}




void HAL_LCD_Clear(void)
{
	unsigned int i,j;
	unsigned char page = 0xB0;

	HAL_LCD_cmdWrite(0xA4);
	HAL_LCD_cmdWrite(DISPLAY_OFF);
	HAL_LCD_cmdWrite(COG_CMD_START_LINE(0));				//Start Address Line
	for(i=0;i<4;i++){
		HAL_LCD_cmdWrite(COG_CMD_PAGE_SET(i));			//Page Address
		for(j=0;j<128;j++)
		{
			HAL_LCD_cmdWrite(COG_CMD_COLUMN_LSB(j));
			HAL_LCD_cmdWrite(COG_CMD_COLUMN_MSB(j));

			HAL_LCD_dataWrite(0x00);	//Clear
		}
		page++;
	}
	HAL_LCD_cmdWrite(DISPLAY_ON);
	return;
}




void HAL_LCD_Init(void)
{
  MX_SPI1_Init();

  LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);		//Reset Pin low
  LL_mDelay(100);
  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6);		//Reset Pin High
  LL_mDelay(100);

  HAL_LCD_cmdWrite(0xA0);											// ADC select
  HAL_LCD_cmdWrite(DISPLAY_OFF);
  HAL_LCD_cmdWrite(COG_CMD_COMMON_OUTPUT(COG_COMMON_REVERSE));   	// COM direction scan
  HAL_LCD_cmdWrite(COG_CMD_LCD_BIAS(COG_LCD_BIAS_0));  				// LCD bias set
  HAL_LCD_cmdWrite(0x2F);  											// Power Control set
  HAL_LCD_cmdWrite(0x21);  											// Resistor Ratio Set
  HAL_LCD_cmdWrite(0x81);   										// Electronic Volume Command (set contrast) Double Btye: 1 of 2
  HAL_LCD_cmdWrite(0x20);   										// Electronic Volume value (contrast value) Double Byte: 2 of 2
  HAL_LCD_cmdWrite(COG_CMD_START_LINE(0));							// Display Start Line
  HAL_LCD_cmdWrite(0xA4);
  HAL_LCD_cmdWrite(DISPLAY_ON);
  HAL_LCD_Clear();

  return;
}
