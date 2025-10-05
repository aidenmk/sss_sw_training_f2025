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

	int count = 0;

	/* Infinite loop */
	while (1)
	{
	  HAL_Delay(1000);
	  printMsg("Hello #%d\r\n", count++);
	}
}

