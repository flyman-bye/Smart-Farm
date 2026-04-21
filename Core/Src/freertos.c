/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
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
#include "farm_state.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
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
/* Definitions for SensorTask */
osThreadId_t SensorTaskHandle;
const osThreadAttr_t SensorTask_attributes = {
  .name = "SensorTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for InputTask */
osThreadId_t InputTaskHandle;
const osThreadAttr_t InputTask_attributes = {
  .name = "InputTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for ScreenTask */
osThreadId_t ScreenTaskHandle;
const osThreadAttr_t ScreenTask_attributes = {
  .name = "ScreenTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal5,
};
/* Definitions for MQTTTask */
osThreadId_t MQTTTaskHandle;
const osThreadAttr_t MQTTTask_attributes = {
  .name = "MQTTTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for MQTTQueue */
osMessageQueueId_t MQTTQueueHandle;
const osMessageQueueAttr_t MQTTQueue_attributes = {
  .name = "MQTTQueue"
};
/* Definitions for BeepTimer */
osTimerId_t BeepTimerHandle;
const osTimerAttr_t BeepTimer_attributes = {
  .name = "BeepTimer"
};
/* Definitions for i2CMutex */
osMutexId_t i2CMutexHandle;
const osMutexAttr_t i2CMutex_attributes = {
  .name = "i2CMutex"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartSensorTask(void *argument);
extern void StartInputTask(void *argument);
extern void StartScreenTask(void *argument);
extern void StartMQTTTask(void *argument);
extern void BeepTimerCallback(void *argument);

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
  /* Create the mutex(es) */
  /* creation of i2CMutex */
  i2CMutexHandle = osMutexNew(&i2CMutex_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of BeepTimer */
  BeepTimerHandle = osTimerNew(BeepTimerCallback, osTimerPeriodic, NULL, &BeepTimer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of MQTTQueue */
  MQTTQueueHandle = osMessageQueueNew (16, sizeof(FarmState), &MQTTQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of SensorTask */
  SensorTaskHandle = osThreadNew(StartSensorTask, NULL, &SensorTask_attributes);

  /* creation of InputTask */
  InputTaskHandle = osThreadNew(StartInputTask, NULL, &InputTask_attributes);

  /* creation of ScreenTask */
  ScreenTaskHandle = osThreadNew(StartScreenTask, NULL, &ScreenTask_attributes);

  /* creation of MQTTTask */
  MQTTTaskHandle = osThreadNew(StartMQTTTask, NULL, &MQTTTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartSensorTask */
/**
  * @brief  Function implementing the SensorTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartSensorTask */
__weak void StartSensorTask(void *argument)
{
  /* USER CODE BEGIN StartSensorTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartSensorTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

