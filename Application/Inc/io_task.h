#ifndef __IO_TASK__H
#define __IO_TASK__H
#include "main.h"


#define IO_L HAL_GPIO_ReadPin(DETECT_0_GPIO_Port,DETECT_0_Pin)
#define IO_ML HAL_GPIO_ReadPin(DETECT_1_GPIO_Port,DETECT_1_Pin)
#define IO_MR HAL_GPIO_ReadPin(DETECT_2_GPIO_Port,DETECT_2_Pin)
#define IO_R HAL_GPIO_ReadPin(DETECT_3_GPIO_Port,DETECT_3_Pin)

#define KEY_0 HAL_GPIO_ReadPin(KEY_0_GPIO_Port,KEY_0_Pin)
#define KEY_1 HAL_GPIO_ReadPin(KEY_1_GPIO_Port,KEY_1_Pin)
#define ROAD1 HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_12)
#define ROAD2 HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11)

#endif
