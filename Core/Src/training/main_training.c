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


/* The task functions prototype*/
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

/* Task parameter to be sent to the task function */
const char *pvTask1  = "Task1 is running.";
const char *pvTask2  = "Task2 is running.";

/* Global semaphore variable */
SemaphoreHandle_t xSemaphore = NULL;

int main(void)
{
	setup_training();

	uint32_t curr_tick = 0;

	uint32_t prev_tick = 0;

	/* Create one of the two tasks. */
	xTaskCreate(vTask1, /* Pointer to the function that implements the task. */
		"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
			configMINIMAL_STACK_SIZE, /* Stack depth in words. */
		(void*)pvTask1,		/* We are not using the task parameter. */
		1,			/* This task will run at priority 1. */
		NULL );		/* We are not using the task handle. */

	/* Create the other task in exactly the same way. */
	xTaskCreate( vTask2, "Task 2", configMINIMAL_STACK_SIZE, (void*)pvTask2, 1, NULL );

	/* Create a binary semaphore */
	xSemaphore = xSemaphoreCreateBinary();
	/* make the semaphore token available for the first time */
	xSemaphoreGive( xSemaphore);
	/* Start the scheduler so our tasks start executing. */
	printMsg("Starting Scheduler\r\n======================");
	vTaskStartScheduler();

  /* Infinite loop */
  while (1)
  {
	  HAL_Delay(1000);

	  curr_tick = HAL_GetTick();

	  printMsg("%ul - %ul = %ul\r\n", curr_tick, prev_tick, curr_tick - prev_tick);


	  prev_tick = curr_tick;
  }
  /* USER CODE END 3 */
}

void vTask1( void *pvParameters )
{
char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Take semaphore */
		xSemaphoreTake(xSemaphore,(TickType_t) portMAX_DELAY);
		/* Print out the name of this task. */
	  	printMsg( "%s\r\n",pcTaskName );
	  	printMsg("Task 1\r\n");

		/* Give semaphore */
		xSemaphoreGive(xSemaphore);
		/* Delay for a period. */
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}
}

void vTask2( void *pvParameters )
{
char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Take semaphore */
		xSemaphoreTake(xSemaphore,(TickType_t) portMAX_DELAY);
		/* Print out the name of this task. */
	  	printMsg( "%s\r\n",pcTaskName );
	  	printMsg("Task 2\r\n");
		/* Give semaphore */
		xSemaphoreGive(xSemaphore);
		/* Delay for a period. */
		vTaskDelay( 2000 / portTICK_PERIOD_MS );
	}
}
