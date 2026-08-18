#include "stm32f10x.h"                  // Device header

void LED_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_1 | GPIO_Pin_5);
	
}	

void LED1_Set(unsigned char c){
	switch (c){
		case 1:GPIO_ResetBits(GPIOA,GPIO_Pin_1);break;
		case 0:GPIO_SetBits(GPIOA,GPIO_Pin_1);break;
	}
}	

void LED2_Set(unsigned char c){
	switch (c){
		case 1:GPIO_ResetBits(GPIOA,GPIO_Pin_5);break;
		case 0:GPIO_SetBits(GPIOA,GPIO_Pin_5);break;
	}
}	


void LED_Turn(unsigned char c){
	switch (c){
		case 1:
			if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)GPIO_SetBits(GPIOA,GPIO_Pin_1);
			else GPIO_ResetBits(GPIOA,GPIO_Pin_1);
			break;
		case 2:
			if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5)==0)GPIO_SetBits(GPIOA,GPIO_Pin_5);
			else GPIO_ResetBits(GPIOA,GPIO_Pin_5);break;
			break;
	}
}	