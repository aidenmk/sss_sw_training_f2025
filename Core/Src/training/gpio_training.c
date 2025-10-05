/*
 * gpio.c
 *
 * FOR SSS SOFTWARE FALL 2025 TRAINING
 *
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

#include "gpio_training.h"

void gpio_high(GPIO_TypeDef *port, int pin) {}

void gpio_low(GPIO_TypeDef *port, int pin) {}

void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {}

void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode) {}

/*
 * Pls don't modify cause I will be sad D:
 */
void rcc_enable(RCC_SELECT reg) {
	RCC->APB2ENR |= reg;
}

