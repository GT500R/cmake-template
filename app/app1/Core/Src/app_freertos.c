/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <src/app1Main.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for MainAppTask */
osThreadId_t MainAppTaskHandle;
uint32_t MainAppTaskBuffer[ 4096 ];
osStaticThreadDef_t MainAppTaskControlBlock;
const osThreadAttr_t MainAppTask_attributes = {
  .name = "MainAppTask",
  .stack_mem = &MainAppTaskBuffer[0],
  .stack_size = sizeof(MainAppTaskBuffer),
  .cb_mem = &MainAppTaskControlBlock,
  .cb_size = sizeof(MainAppTaskControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void vMainAppTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of MainAppTask */
  MainAppTaskHandle = osThreadNew(vMainAppTask, NULL, &MainAppTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_vMainAppTask */
/**
  * @brief  Function implementing the MainAppTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_vMainAppTask */
void vMainAppTask(void *argument)
{
  /* USER CODE BEGIN vMainAppTask */
  UNUSED(argument);

  /* Infinite loop */
  app1MainWrapper();
  /* USER CODE END vMainAppTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void APP_setMainTaskPriorityLow()
{
  const osStatus_t status = osThreadSetPriority(MainAppTaskHandle, osPriorityLow);
  UNUSED(status);
}

void APP_taskDelayMs(const uint32_t delayMs)
{
  const osStatus_t status = osDelay(pdMS_TO_TICKS(delayMs));
  UNUSED(status);
}
/* USER CODE END Application */

