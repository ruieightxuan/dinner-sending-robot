/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "main_control.h"
#include "motor.h"
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
osThreadId main_controlHandle;
osThreadId detectHandle;
osThreadId io_judgeHandle;
osThreadId wave_detectHandle;
osThreadId encoderHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void main_control_Task(void const * argument);
void detect_Task(void const * argument);
void io_Task(void const * argument);
void wave_Task(void const * argument);
void encoder_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

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
  /* definition and creation of main_control */
  osThreadDef(main_control, main_control_Task, osPriorityHigh, 0, 128);
  main_controlHandle = osThreadCreate(osThread(main_control), NULL);

  /* definition and creation of detect */
  osThreadDef(detect, detect_Task, osPriorityAboveNormal, 0, 128);
  detectHandle = osThreadCreate(osThread(detect), NULL);

  /* definition and creation of io_judge */
  osThreadDef(io_judge, io_Task, osPriorityNormal, 0, 128);
  io_judgeHandle = osThreadCreate(osThread(io_judge), NULL);

  /* definition and creation of wave_detect */
  osThreadDef(wave_detect, wave_Task, osPriorityNormal, 0, 128);
  wave_detectHandle = osThreadCreate(osThread(wave_detect), NULL);

  /* definition and creation of encoder */
  osThreadDef(encoder, encoder_Task, osPriorityAboveNormal, 0, 128);
  encoderHandle = osThreadCreate(osThread(encoder), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_main_control_Task */
/**
  * @brief  Function implementing the main_control thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_main_control_Task */
//void main_control_Task(void const * argument)
//{
//  /* USER CODE BEGIN main_control_Task */
//////  /* Infinite loop */
//////  for(;;)
//////  {
//////    osDelay(1);
//////  }
//  /* USER CODE END main_control_Task */
//}

/* USER CODE BEGIN Header_detect_Task */
/**
* @brief Function implementing the detect thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_detect_Task */
void detect_Task(void const * argument)
{
  /* USER CODE BEGIN detect_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END detect_Task */
}

/* USER CODE BEGIN Header_io_Task */
/**
* @brief Function implementing the io_judge thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_io_Task */
//void io_Task(void const * argument)
//{
//  /* USER CODE BEGIN io_Task */
//  /* Infinite loop */
//  for(;;)
//  {
//    osDelay(1);
//  }
//  /* USER CODE END io_Task */
//}

/* USER CODE BEGIN Header_wave_Task */
/**
* @brief Function implementing the wave_detect thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_wave_Task */
void wave_Task(void const * argument)
{
  /* USER CODE BEGIN wave_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END wave_Task */
}

/* USER CODE BEGIN Header_encoder_Task */
/**
* @brief Function implementing the encoder thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_encoder_Task */
void encoder_Task(void const * argument)
{
  /* USER CODE BEGIN encoder_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END encoder_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
