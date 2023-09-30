/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.c
 *
 * Source file containing GPIO (General Purpose Input/Output)
 * functions' implementations and low-level hardware access for STM32 microcontrollers.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "GPIO.h"


GPIO_STATE_t enableClk(void)
{
	SET_BIT(APB2ENR, 2);
	return GPIO_STATE_ENABLE_CLOCK;
}

GPIO_STATE_t gpioInit(void)
{
	if (enableClk() == GPIO_STATE_ENABLE_CLOCK)
	{
		return GPIO_STATE_INIT;
	}
	else
	{
		return GPIO_STATE_ERROR;
	}
}

GPIO_STATE_t gpioWritePin(vuint8_t portName, vuint8_t pinNumber, vuint8_t value)
{
	switch (portName)
	{
	case 'A':
		if (value == HIGH)
		{
			SET_BIT(GPIOA_ODR, pinNumber);
		}
		else if (value == LOW)
		{
			CLEAR_BIT(GPIOA_ODR, pinNumber);
		}
		else
		{
			return GPIO_STATE_ERROR;
		}
		break;

	default:
		break;
	}
	return GPIO_STATE_WRITE;
}
