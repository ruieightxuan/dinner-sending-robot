#include "uwb.h"
#include "FreeRTOS.h"
#include "main.h"
#include "cmsis_os.h"
#include "motor.h"

uint8_t USART_RX_BUF[USART_REC_LEN];
uint16_t USART_RX_STA=0;       //����״̬���	
uint8_t aRxBuffer[RXBUFFERSIZE];//HAL��ʹ�õĴ��ڽ��ջ���



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==USART1)//����Ǵ���1
	{
		if((USART_RX_STA&0x8000)==0)//����δ���
		{
			if(USART_RX_STA&0x4000)//���յ���0x0d
			{
				if(aRxBuffer[0]!=0x0a)USART_RX_STA=0;//���մ���,���¿�ʼ
				else USART_RX_STA|=0x8000;	//��������� 
			}
			else //��û�յ�0X0D
			{	
				if(aRxBuffer[0]==0x0d)USART_RX_STA|=0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=aRxBuffer[0] ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}

	}
}


void uwb_task(void *argument)
{
  /* USER CODE BEGIN uwb_task */
  /* Infinite loop */
  for(;;)
  {
   if(USART_RX_STA&0x8000)
		{					   
			length=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			uwb_index=0;
			uwb_index1=0;
			distl=0;
			distr=0;
			memcpy(uwb_dist,USART_RX_BUF,20*sizeof(uint8_t));
			for(int i=0;i<length;i++)
			{
			  if(uwb_dist[i]==','&&uwb_index==0)
				{
				uwb_index=i;
				}
				else if(uwb_dist[i]==','&&uwb_index!=0)
				{
				uwb_index1=i;
				}			
			}
			for(int i=uwb_index+1;i<uwb_index1;i++)
			{
			distl=distl*10+(uwb_dist[i]-'0');		//��߾���
			}
			for(int i=uwb_index1+1;i<length;i++)
			{
			distr=distr*10+(uwb_dist[i]-'0');   //�ұ߾���
			}
			USART_RX_STA=0;
		}
		
		osDelay(10);
  }
  /* USER CODE END uwb_task */
}

