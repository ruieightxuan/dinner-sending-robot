#ifndef __UWB__H
#define __UWB__H

#include "main.h"



#define USART_REC_LEN  			20  		//�����������ֽ��� 200
#define EN_USART1_RX 			1			//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern uint8_t  USART_RX_BUF[USART_REC_LEN]; 	//���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern uint16_t USART_RX_STA;         			//����״̬���	
//extern UART_HandleTypeDef UART1_Handler; 	//UART���

#define RXBUFFERSIZE   1 					//�����С
extern uint8_t aRxBuffer[RXBUFFERSIZE];			//HAL��USART����Buffer



#endif
