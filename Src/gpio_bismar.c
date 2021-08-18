#include "gpio_bismar.h"
#include "main.h"


/*Function definitions*/
void enable_PORT(GPIO_PORTS_ENABLE PORT[], int amountofPorts){
	/*enble_PORT takes an array of the desired
	 * PORTS that should be enabled and generates the
	 * hexadecimal value in order to send that to the
	 * RCC_AHBENR register
	 */
	//int array_length = sizeof(PORT)/sizeof(PORT[0]);
	uint32_t portEnable_value = 0;
	for(int i = 0; i<=amountofPorts-1; i++){
		portEnable_value = portEnable_value | PORT[i];
	}

	RCC->AHBENR = portEnable_value;
}

void set_asOUTPUT(GPIO_PORT PORT, OUTPUT_PINS PIN[]){
	/*Rest of pins are set to INPUT*/
	int array_length = sizeof(PIN);
	uint32_t pinOUTPUT_value = 0;
	for(int i = 0; i<array_length-1; i++){
		pinOUTPUT_value = pinOUTPUT_value | PIN[i];
	}
	switch(PORT){
		case 1:
			GPIOA->MODER = pinOUTPUT_value;
			break;
		case 2:
			GPIOB->MODER = pinOUTPUT_value;
			break;
		case 3:
			GPIOC->MODER = pinOUTPUT_value;
			break;
		case 4:
			GPIOD->MODER = pinOUTPUT_value;
			break;
		case 5:
			break;
		case 6:
			GPIOF->MODER = pinOUTPUT_value;
			break;
	}
}

void digitalREAD (PORT_PIN PIN, GPIO_PORT PORT, JOYSTICK_POS *POS, bool *PRESSED){
	/*CENTER, 0
	RIGHT, 1
	LEFT, 2
	UP, 3
	DOWN 4*/

	*PRESSED = FALSE;
	switch(PORT){
		case A:
			if((GPIOA->IDR & PIN)==PIN) {
				*PRESSED = TRUE;
				if(PIN == PIN_4){
					*POS = UP;
				}
			}
			break;
		case B:
			if((GPIOB->IDR & PIN)==PIN) {
				*PRESSED = TRUE;
				if (PIN==PIN_5) {
					*POS = CENTER;
				}
				if (PIN==PIN_0) {
					*POS = DOWN;
				}
			}
			break;
		case C:
			if((GPIOC->IDR & PIN)==PIN) {
				*PRESSED = TRUE;
				if(PIN == PIN_0){
					*POS = RIGHT;
				}
				if(PIN == PIN_1){
					*POS = LEFT;
				}
			}
			break;
		case D:
			if((GPIOD->IDR & PIN)==PIN)
			{
				*PRESSED = TRUE;
			}

			break;
		case E:
			break;
		case F:
			if((GPIOF->IDR & PIN)==PIN) *PRESSED = TRUE;
			break;
		default:
			*PRESSED = FALSE;
			break;
	}
}


void set_asOUTPUT_singlePIN(GPIO_PORT PORT, OUTPUT_PINS PIN){
	/*Rest of pins are set to INPUT*/
	switch(PORT){
			case 1:
				GPIOA->MODER = PIN;
				break;
			case 2:
				GPIOB->MODER = PIN;
				break;
			case 3:
				GPIOC->MODER = PIN;
				break;
			case 4:
				GPIOD->MODER = PIN;
				break;
			case 5:
				break;
			case 6:
				GPIOF->MODER = PIN;
				break;
		}
}



void digitalWrite_HIGH(PORT_PIN PIN[], GPIO_PORT PORT){
	int array_length = sizeof(PIN);
	uint16_t set_HIGH_pinValue = 0;
	for(int i = 0; i<array_length-1; i++){
		set_HIGH_pinValue = set_HIGH_pinValue | PIN[i];
		}
	switch(PORT){
	case 1:
		GPIOA->ODR = set_HIGH_pinValue;
		break;
	case 2:
		GPIOB->ODR = set_HIGH_pinValue;
		break;
	case 3:
		GPIOC->ODR = set_HIGH_pinValue;
		break;
	case 4:
		GPIOD->ODR = set_HIGH_pinValue;
		break;
	case 5:
		break;
	case 6:
		GPIOF->ODR = set_HIGH_pinValue;
		break;
	}
}

void digitalWrite_HIGH_singlePIN(PORT_PIN PIN, GPIO_PORT PORT){
	switch(PORT){
		case 1:
			GPIOA->ODR = PIN;
			break;
		case 2:
			GPIOB->ODR = PIN;
			break;
		case 3:
			GPIOC->ODR = PIN;
			break;
		case 4:
			GPIOD->ODR = PIN;
			break;
		case 5:
			break;
		case 6:
			GPIOF->ODR = PIN;
			break;
		}
}

void digitalWrite_LOW(GPIO_PORT PORT){
	switch(PORT){
			case 1:
				GPIOA->ODR = 0x0000;
				break;
			case 2:
				GPIOB->ODR = 0x0000;
				break;
			case 3:
				GPIOC->ODR = 0x0000;
				break;
			case 4:
				GPIOD->ODR = 0x0000;
				break;
			case 5:
				break;
			case 6:
				GPIOF->ODR = 0x0000;
				break;
			}
}
