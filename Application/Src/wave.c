#include "wave.h"
#include "FreeRTOS.h"
#include "main.h"
#include "cmsis_os.h"
uint8_t  TIM2CH3_CAPTURE_STA=0;							//���벶��״̬		    				
uint8_t  TIM3CH3_CAPTURE_STA=0;							//���벶��״̬		    				
uint8_t  TIM4CH3_CAPTURE_STA=0;							//���벶��״̬		    				

uint16_t	TIM2CH3_CAPTURE_VAL;							  //���벶��ֵ(TIM3��16λ)
uint16_t	TIM3CH3_CAPTURE_VAL;							  //���벶��ֵ(TIM3��16λ)
uint16_t	TIM4CH3_CAPTURE_VAL;							  //���벶��ֵ(TIM3��16λ)


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//�����жϣ����������ʱִ��
{
	if((TIM3CH3_CAPTURE_STA&0X80)==0)				//��δ�ɹ�����������
	{
		if(TIM3CH3_CAPTURE_STA&0X40)				//�Ѿ����񵽸ߵ�ƽ��
		{
			if((TIM3CH3_CAPTURE_STA&0X3F)==0X3F)	//�ߵ�ƽ̫����
			{
				TIM3CH3_CAPTURE_STA|=0X80;			//��ǳɹ�������һ��
				TIM3CH3_CAPTURE_VAL=0XFFFF;
			}else TIM3CH3_CAPTURE_STA++;
		}	 
	}		
	if((TIM2CH3_CAPTURE_STA&0X80)==0)				//��δ�ɹ�����������
	{
		if(TIM2CH3_CAPTURE_STA&0X40)				//�Ѿ����񵽸ߵ�ƽ��
		{
			if((TIM2CH3_CAPTURE_STA&0X3F)==0X3F)	//�ߵ�ƽ̫����
			{
				TIM2CH3_CAPTURE_STA|=0X80;			//��ǳɹ�������һ��
				TIM2CH3_CAPTURE_VAL=0XFFFF;
			}else TIM2CH3_CAPTURE_STA++;
		}	 
	}		
	if((TIM4CH3_CAPTURE_STA&0X80)==0)				//��δ�ɹ�����������
	{
		if(TIM4CH3_CAPTURE_STA&0X40)				//�Ѿ����񵽸ߵ�ƽ��
		{
			if((TIM4CH3_CAPTURE_STA&0X3F)==0X3F)	//�ߵ�ƽ̫����
			{
				TIM4CH3_CAPTURE_STA|=0X80;			//��ǳɹ�������һ��
				TIM4CH3_CAPTURE_VAL=0XFFFF;
			}else TIM4CH3_CAPTURE_STA++;
		}	 
	}		
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)//�����жϷ���ʱִ��
{
	if((TIM3CH3_CAPTURE_STA&0X80)==0)				//��δ�ɹ�����
	{
		if(TIM3CH3_CAPTURE_STA&0X40)				//����һ���½��� 		
		{	  			
			TIM3CH3_CAPTURE_STA|=0X80;				//��ǳɹ�����һ�θߵ�ƽ����
            TIM3CH3_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(&htim3,TIM_CHANNEL_3);//��ȡ��ǰ�Ĳ���ֵ.
			TIM_RESET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
            TIM_SET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3,TIM_ICPOLARITY_RISING);//����TIM3ͨ��3�����ز���
		}else  										//��δ��ʼ,��һ�β���������
		{
			TIM3CH3_CAPTURE_STA=0;					//���
			TIM3CH3_CAPTURE_VAL=0;
			TIM3CH3_CAPTURE_STA|=0X40;				//��ǲ�����������
			__HAL_TIM_DISABLE(&htim3);      	//�رն�ʱ��3
			__HAL_TIM_SET_COUNTER(&htim3,0);
			TIM_RESET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
			TIM_SET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3,TIM_ICPOLARITY_FALLING);//��ʱ��3ͨ��3����Ϊ�½��ز���
			__HAL_TIM_ENABLE(&htim3);		//ʹ�ܶ�ʱ��3
		}		    
	}		
	if((TIM2CH3_CAPTURE_STA&0X80)==0)				//��δ�ɹ�����
	{
		if(TIM2CH3_CAPTURE_STA&0X40)				//����һ���½��� 		
		{	  			
			TIM2CH3_CAPTURE_STA|=0X80;				//��ǳɹ�����һ�θߵ�ƽ����
            TIM2CH3_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(&htim2,TIM_CHANNEL_3);//��ȡ��ǰ�Ĳ���ֵ.
			TIM_RESET_CAPTUREPOLARITY(&htim2,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
            TIM_SET_CAPTUREPOLARITY(&htim2,TIM_CHANNEL_3,TIM_ICPOLARITY_RISING);//����TIM3ͨ��3�����ز���
		}else  										//��δ��ʼ,��һ�β���������
		{
			TIM2CH3_CAPTURE_STA=0;					//���
			TIM2CH3_CAPTURE_VAL=0;
			TIM2CH3_CAPTURE_STA|=0X40;				//��ǲ�����������
			__HAL_TIM_DISABLE(&htim2);      	//�رն�ʱ��3
			__HAL_TIM_SET_COUNTER(&htim2,0);
			TIM_RESET_CAPTUREPOLARITY(&htim2,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
			TIM_SET_CAPTUREPOLARITY(&htim2,TIM_CHANNEL_3,TIM_ICPOLARITY_FALLING);//��ʱ��3ͨ��3����Ϊ�½��ز���
			__HAL_TIM_ENABLE(&htim2);		//ʹ�ܶ�ʱ��3
		}		    
	}		
	if((TIM4CH3_CAPTURE_STA&0X80)==0)				//��δ�ɹ�����
	{
		if(TIM4CH3_CAPTURE_STA&0X40)				//����һ���½��� 		
		{	  			
			TIM4CH3_CAPTURE_STA|=0X80;				//��ǳɹ�����һ�θߵ�ƽ����
            TIM4CH3_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(&htim4,TIM_CHANNEL_3);//��ȡ��ǰ�Ĳ���ֵ.
			TIM_RESET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
            TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_3,TIM_ICPOLARITY_RISING);//����TIM3ͨ��3�����ز���
		}else  										//��δ��ʼ,��һ�β���������
		{
			TIM4CH3_CAPTURE_STA=0;					//���
			TIM4CH3_CAPTURE_VAL=0;
			TIM4CH3_CAPTURE_STA|=0X40;				//��ǲ�����������
			__HAL_TIM_DISABLE(&htim4);      	//�رն�ʱ��3
			__HAL_TIM_SET_COUNTER(&htim4,0);
			TIM_RESET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
			TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_3,TIM_ICPOLARITY_FALLING);//��ʱ��3ͨ��3����Ϊ�½��ز���
			__HAL_TIM_ENABLE(&htim4);		//ʹ�ܶ�ʱ��3
		}		    
	}		
}






void Trig_Init(void)
{
	HAL_GPIO_WritePin(GPIOB,WAVE_TRIGGER_LEFT_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,WAVE_TRIGGER_MID_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,WAVE_TRIGGER_RIGHT_Pin,GPIO_PIN_RESET);
}

void ch1_capture(void)
{    
			TRIG1h;
			delay_us(20);
			TRIG1l;
	    timeL=0;
	    
}
void ch2_capture(void)
{    
			TRIG2h;
			delay_us(20);
			TRIG2l;
	    timeM=0;
	   
}
void ch3_capture(void)
{    
			TRIG3h;
			delay_us(20);
			TRIG3l;
	    timeR=0;

}

void delay_us(uint32_t udelay)
{
  uint32_t startval,tickn,delays,wait;
 
  startval = SysTick->VAL;
  tickn = HAL_GetTick();
  //sysc = 72000;  //SystemCoreClock / (1000U / uwTickFreq);
  delays =udelay * 72; //sysc / 1000 * udelay;
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

void wave_task(void *argument)
{
  /* USER CODE BEGIN wave_task */
  /* Infinite loop */
  for(;;)
  {
//    ch2_capture();  
//		if(TIM3CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
//		{
//			timeM=TIM3CH3_CAPTURE_STA&0X3F; 
//			timeM*=65536;		 	    	        //���ʱ���ܺ�
//			timeM+=TIM3CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
//			lenM=timeM*1.7;
//			TIM3CH3_CAPTURE_STA=0;          //������һ�β���
//		}
		ch1_capture();  
		if(TIM2CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
		{
			timeL=TIM2CH3_CAPTURE_STA&0X3F; 
			timeL*=65536;		 	    	        //���ʱ���ܺ�
			timeL+=TIM2CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
			lenL=timeL*1.7;
			if(lenL<7) lenL=170;
			TIM2CH3_CAPTURE_STA=0;          //������һ�β���
		}
//		ch3_capture();  
//		if(TIM4CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
//		{
//			timeR=TIM4CH3_CAPTURE_STA&0X3F; 
//			timeR*=65536;		 	    	        //���ʱ���ܺ�
//			timeR+=TIM4CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
//			lenR=timeR*1.7;
//			TIM4CH3_CAPTURE_STA=0;          //������һ�β���
//		}
		osDelay(10);
  }
  /* USER CODE END wave_task */
}

void wavem_task(void *argument)
{
  /* USER CODE BEGIN wave_task */
  /* Infinite loop */
  for(;;)
  {
    ch2_capture();  
		if(TIM3CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
		{
			timeM=TIM3CH3_CAPTURE_STA&0X3F; 
			timeM*=65536;		 	    	        //���ʱ���ܺ�
			timeM+=TIM3CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
			lenM=timeM*1.7;
			if(lenM<7) lenM=170;
			TIM3CH3_CAPTURE_STA=0;          //������һ�β���
		}
//		ch1_capture();  
//		if(TIM2CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
//		{
//			timeL=TIM2CH3_CAPTURE_STA&0X3F; 
//			timeL*=65536;		 	    	        //���ʱ���ܺ�
//			timeL+=TIM2CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
//			lenL=timeL*1.7;
//			TIM2CH3_CAPTURE_STA=0;          //������һ�β���
//		}
//		ch3_capture();  
//		if(TIM4CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
//		{
//			timeR=TIM4CH3_CAPTURE_STA&0X3F; 
//			timeR*=65536;		 	    	        //���ʱ���ܺ�
//			timeR+=TIM4CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
//			lenR=timeR*1.7;
//			TIM4CH3_CAPTURE_STA=0;          //������һ�β���
//		}
		osDelay(10);
  }
  /* USER CODE END wave_task */
}

void waver_task(void *argument)
{
  /* USER CODE BEGIN wave_task */
  /* Infinite loop */
  for(;;)
  {
//    ch2_capture();  
//		if(TIM3CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
//		{
//			timeM=TIM3CH3_CAPTURE_STA&0X3F; 
//			timeM*=65536;		 	    	        //���ʱ���ܺ�
//			timeM+=TIM3CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
//			lenM=timeM*1.7;
//			TIM3CH3_CAPTURE_STA=0;          //������һ�β���
//		}
//		ch1_capture();  
//		if(TIM2CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
//		{
//			timeL=TIM2CH3_CAPTURE_STA&0X3F; 
//			timeL*=65536;		 	    	        //���ʱ���ܺ�
//			timeL+=TIM2CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
//			lenL=timeL*1.7;
//			TIM2CH3_CAPTURE_STA=0;          //������һ�β���
//		}
		ch3_capture();  
		if(TIM4CH3_CAPTURE_STA&0X80)           //�ɹ�������һ�θߵ�ƽ
		{
			timeR=TIM4CH3_CAPTURE_STA&0X3F; 
			timeR*=65536;		 	    	        //���ʱ���ܺ�
			timeR+=TIM4CH3_CAPTURE_VAL; 			//�õ��ܵĸߵ�ƽʱ��
			lenR=timeR*1.7;
			if(lenR<7) lenR=170;
			TIM4CH3_CAPTURE_STA=0;          //������һ�β���
		}
		osDelay(10);
  }
  /* USER CODE END wave_task */
}














