#ifndef GPIO_BISMAR_H
#define GPIO_BISMAR_H

typedef enum  {
	PORT_A = 0x00020000,
	PORT_B = 0x00040000,
	PORT_C = 0x00080000,
	PORT_D = 0x00100000,
	PORT_F = 0x00400000
} GPIO_PORTS_ENABLE;

typedef enum {
	A = 1,
	B = 2,
	C = 3,
	D = 4,
	E = 5,
	F = 6
} GPIO_PORT;

typedef enum {
	PIN_0 = 0x0001,
	PIN_1 = 0x0002,
	PIN_2 = 0x0004,
	PIN_3 = 0x0008,
	PIN_4 = 0x0010,
	PIN_5 = 0x0020,
	PIN_6 = 0x0040,
	PIN_7 = 0x0080,
	PIN_8 = 0x0100,
	PIN_9 = 0x0200,
	PIN_10 = 0x0400,
	PIN_11 = 0x0800,
	PIN_12 = 0x1000,
	PIN_13 = 0x2000,
	PIN_14 = 0x4000,
	PIN_15 = 0x8000
} PORT_PIN;

typedef enum{
	PIN0 = 0x00000001,
	PIN1 = 0x00000004,
	PIN2 = 0x00000010,
	PIN3 = 0x00000040,
	PIN4 = 0x00000100,
	PIN5 = 0x00000400,
	PIN6 = 0x00001000,
	PIN7 = 0x00004000,
	PIN8 = 0x00010000,
	PIN9 = 0x00040000,
	PIN10 = 0x00100000,
	PIN11 = 0x00400000,
	PIN12 = 0x01000000,
	PIN13 = 0x04000000,
	PIN14 = 0x10000000,
	PIN15 = 0x40000000
} OUTPUT_PINS;

typedef enum {FALSE, TRUE} bool;

typedef enum {
	CENTER, //0
	RIGHT, //1
	LEFT, //2
	UP, //3
	DOWN,
	NULL2
	//NULL
} JOYSTICK_POS;


/*Prototype definitions*/
void enable_PORT(GPIO_PORTS_ENABLE PORT[], int amountofPorts);
void set_asOUTPUT(GPIO_PORT PORT, OUTPUT_PINS PIN[]);
void set_asOUTPUT_singlePIN(GPIO_PORT PORT, OUTPUT_PINS PIN);
void digitalREAD(PORT_PIN PIN, GPIO_PORT PORT, JOYSTICK_POS *POS, bool *PRESSED);
void digitalWrite_HIGH(PORT_PIN PIN[], GPIO_PORT PORT);
void digitalWrite_HIGH_singlePIN(PORT_PIN PIN, GPIO_PORT PORT);
void digitalWrite_LOW(GPIO_PORT PORT);

#endif /*GPIO_BISMAR_H*/
