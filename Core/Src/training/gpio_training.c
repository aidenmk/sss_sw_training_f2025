/*
 * gpio.c
 *
 * FOR SSS SOFTWARE FALL 2025 TRAINING
 *
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

// write out configure mode, then high then low, then gpio set
#include "gpio_training.h"

void gpio_high(GPIO_TypeDef *port, int pin) {
	port->ODR |= 1<<pin;
}

void gpio_low(GPIO_TypeDef *port, int pin) {
	port->ODR &= ~(1<<pin);
}

void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {

}

void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode) {
	//modify the 21st bit to one, 20th bit to zero
	//output mode max speed 2mhz
	port->CRH = (port->CRH & ~(1 << 20)) | (1 << 21);

	//bit 23 to 0 and 22 to 0
	// output mode to general purpose push pull
	port->CRH = (port->CRH & ~(1 << 23) | (1 << 22));
}

/*
 * Pls don't modify cause I will be sad D:
 */
void rcc_enable(RCC_SELECT reg) {
	RCC->APB2ENR |= reg;
}

