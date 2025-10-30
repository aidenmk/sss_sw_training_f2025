/*
 * main_training.c
 *
 *  Created on: Sep 22, 2025
 *      Author: dilgill
 */

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "main.h"

#include "gpio_training.h"

#define LED_PORT GPIOC
#define LED_PIN  13

int main(void)
{
	setup_training();
	rcc_enable(GPIO_C_ENABLE);
	gpio_configureMode(LED_PORT, LED_PIN, GPIO_OUTPUT_PUSH_PULL, GPIO_MED_SPEED);

	/* Infinite loop */
	while (1)
	{
	  gpio_low(LED_PORT, LED_PIN);
	  HAL_Delay(1000);
	  gpio_high(LED_PORT, LED_PIN);
	  HAL_Delay(1000);

	}
}

