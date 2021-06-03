#include "motor.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "io_task.h"

extern TIM_HandleTypeDef htim1;
extern uint8_t crossing;
extern uint8_t flag;


void motor_init(void)
{
	//All motor stop
	//HAL_GPIO_WritePin(GPIOA, MOTOR_IN1_Pin|MOTOR_IN2_Pin|MOTOR_IN3_Pin|MOTOR_IN4_Pin, GPIO_PIN_RESET); 
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);	//Left motor speed control
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);	//Right motor speed control
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);	
}

void motor_speed_set(unsigned int speed)
{
	if 	(speed == SPEED_VERY_LOW)
	{
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,4000);	//very slow 
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,4000);
	}
	else if(speed == STOP)
	{
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,0);	
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,0);
	}
	else
	{
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,speed*3000);	//20000/5 = 4000 FULL SPEED:20000
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,speed*3000);
	}
}
// range: -30 to 30 
void steer_control(float angle)
{
	int offset = angle*500/45;
	__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,1500 + offset);
}


void motor_control(void)
{
    if(IO_L==0&&IO_ML==0&&IO_MR==0&&IO_R==0)
			steer_control(0);
		else if(IO_L==0&&IO_ML==1&&IO_MR==0&&IO_R==0)
		{steer_control(-60);
			}
		else if(IO_L==1&&IO_MR==0&&IO_R==0)
		{  
			steer_control(-90);
			//motor_speed_set(1);
		 // HAL_Delay(100);
		}
		else if(IO_L==0&&IO_ML==0&&IO_MR==1&&IO_R==0)
		{steer_control(60);
			}
		else if(IO_L==0&&IO_ML==0&&IO_R==1)
		{  
			steer_control(90);
		//	motor_speed_set(1);
		//	HAL_Delay(100);
		}
		else if((IO_L==1&&IO_R==1))
		{
			steer_control(0);
			//motor_speed_set(STOP);
			crossing++;
			flag=1;
		}
}
//||(IO_L==1&&IO_R==1)||(IO_ML==1&&IO_R==1)||(IO_L==1&&IO_MR==1)
