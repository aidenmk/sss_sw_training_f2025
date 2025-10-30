/*
 * main_training.c
 *
 *  Created on: Sep 22, 2025
 *      Author: dilgill
 */

#include <stdbool.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "main.h"


/* The task functions prototype*/
void vTask1( void *pvParameters );

/* Task parameter to be sent to the task function */
const char *pvTask1  = "Task1 is running.";

/* Global semaphore variable */
int main(void)
{
	setup_training();

	/* Create one of the two tasks. */
	xTaskCreate(vTask1, /* Pointer to the function that implements the task. */
		"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
			configMINIMAL_STACK_SIZE, /* Stack depth in words. */
		(void*)pvTask1,		/* We are not using the task parameter. */
		1,			/* This task will run at priority 1. */
		NULL );		/* We are not using the task handle. */


	/* Start the scheduler so our tasks start executing. */
	printMsg("Starting Scheduler\r\n======================\r\n");
	vTaskStartScheduler();

  /* Infinite loop - If this runs something went wrong*/

  while (1)
  {
	  HAL_Delay(1000);
	  printMsg("Should not run\r\n");
  }
  /* USER CODE END 3 */
}

void vTask1( void *pvParameters )
{
char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
//		HAL_Delay(1100);
		printMsg("Hello from Task 1\r\n");

		/* Delay for a period. */
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}
}
