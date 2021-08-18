#include "gpio_bismar.h"
#include "main.h"
#include "gpio.h"

void HAL_getPRESSED(GPIO_PORT PORT, JOYSTICK_POS *selection){
	JOYSTICK_POS selectedItem = NULL2;
	bool pressedFLAG = FALSE;
	if(PORT == B){
		digitalREAD(PIN_5, PORT, &selectedItem, &pressedFLAG);
		if(pressedFLAG == FALSE){
			digitalREAD(PIN_0, PORT, &selectedItem, &pressedFLAG);
		}
	}
	if(PORT == C){
		digitalREAD(PIN_0, C, &selectedItem, &pressedFLAG);
		if(pressedFLAG == FALSE){
			digitalREAD(PIN_1, C, &selectedItem, &pressedFLAG);
		}
	}
	if(PORT == A){
		digitalREAD(PIN_4, A, &selectedItem, &pressedFLAG);
	}
	*selection = selectedItem;


}

void HAL_startGPIO(){
	MX_GPIO_Init();
	/*Shut down rgb leds*/
	LL_GPIO_WriteOutputPort(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_WriteOutputPort(GPIOA, LL_GPIO_PIN_9);
	LL_GPIO_WriteOutputPort(GPIOC, LL_GPIO_PIN_7);
}
