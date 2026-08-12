#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
#include "Buzzer.h" 
#include "LightSenser.h" 

int main(){
	Buzzer_Init();
	LightSenser_Init();
	while(1){
		if(LightSenser_Get()==0)Buzzer_Set(1);
		else Buzzer_Set(0);
	}
	
}
