#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "encoder.h" 

int16_t num;

int main(){
	OLED_Init();
	encoder_Init();
	
	while(1){
		num += encoder_Get();
		OLED_ShowSignedNum(1, 5, num, 5);
	}
	
}
