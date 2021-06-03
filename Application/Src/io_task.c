#include "main_control.h"
#include "FreeRTOS.h"
#include "main.h"
#include "cmsis_os.h"
#include "motor.h"
#include "io_task.h"




void io_Task(void const * argument)
{
  /* USER CODE BEGIN io_Task */
  /* Infinite loop */
  for(;;)
  {
    
		osDelay(1);
  }
  /* USER CODE END io_Task */
}

