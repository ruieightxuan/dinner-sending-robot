#include "main_control.h"
#include "FreeRTOS.h"
#include "main.h"
#include "cmsis_os.h"
#include "motor.h"
#include "io_task.h"

extern TIM_HandleTypeDef htim1;
uint8_t crossing=0;
uint8_t flag=0;

void delay_ms(uint32_t mdelay)
{
  uint32_t startval,tickn,delays,wait;
 
  startval = SysTick->VAL;
  tickn = HAL_GetTick();
  //sysc = 72000;  //SystemCoreClock / (1000U / uwTickFreq);
  delays =mdelay * 72000; //sysc / 1000 * udelay;
  if(delays > startval)
    {
      while(HAL_GetTick() == tickn)
        {
 
        }
      wait = 72000 + startval - delays;
      while(wait < SysTick->VAL)
        {
				
				}
    }
  else
    {
      wait = startval - delays;
      while(wait < SysTick->VAL && HAL_GetTick() == tickn)
        {
 
        }
    }
}

void main_control_Task(void const * argument)
{
  /* USER CODE BEGIN main_control_Task */
  /* Infinite loop */
  for(;;)
  {
		motor_speed_set(1);
		motor_control();
		while(flag)
		{
			motor_speed_set(0);
			//steer_control(0);
			if(IO_L==0||IO_R==0)
				flag=0;
			if(KEY_1==0)//按键1被按下；没有加连按还是点按
			{
				motor_speed_set(1);
				HAL_Delay(1000);
				//delay_ms(2000);
			}
		}
//		if(crossing==2)
//		motor_speed_set(0);
		
		
	
		
		osDelay(1);
  }
  /* USER CODE END main_control_Task */
}

