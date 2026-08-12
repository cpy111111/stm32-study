#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
int main(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_5 |GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	while(1){
		GPIO_Write(GPIOA,~GPIO_Pin_1);
		Delay_ms(100);
		GPIO_Write(GPIOA,~GPIO_Pin_5);
		Delay_ms(100);
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
		
	}
	
}
