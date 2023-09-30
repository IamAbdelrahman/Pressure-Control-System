/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.h
 * 
 * This header file Header is containing frequently used macros and functions
 * for GPIO (General Purpose Input/Output) configuration.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "../../Utilities/Macros.h"

// Enumeration to represent different GPIO states
typedef enum {
    GPIO_STATE_ENABLE_CLOCK,   // Enable clock for GPIO
    GPIO_STATE_INIT,   // GPIO initialization
    GPIO_STATE_WRITE,  // GPIO write operation
    GPIO_STATE_ERROR   // GPIO error
} GPIO_STATE_t;

// Base addresses for GPIO and RCC (Reset and Clock Control)
#define GPIO_PORTA   0x40010800
#define BASE_RCC     0x40021000

// Register addresses for GPIO configuration
#define APB2ENR      *(volatile uint32_t *)(BASE_RCC + 0x18)
#define GPIOA_CRL    *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH    *(volatile uint32_t *)(GPIO_PORTA + 0x04)
#define GPIOA_IDR    *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

// Function prototypes
GPIO_STATE_t enableClk(void);                           // Enable clock for GPIO
GPIO_STATE_t gpioInit(void);                            // Initialize GPIO
GPIO_STATE_t gpioWritePin(vuint8_t, vuint8_t, vuint8_t);  // Write to a GPIO pin

#endif // !GPIO_H_
