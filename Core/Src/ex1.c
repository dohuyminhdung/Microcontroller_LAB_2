#include "ex1.h"

int timer_flag = 0;
int timer_counter = 50;

void setTimer1(int time){
	timer_flag = 0;
	timer_counter = time / TICK;
}

void timerRun1(){
	if(timer_counter > 0){
		timer_counter--;
		if(timer_counter <= 0){
			timer_flag = 1;
		}
	}
}

int state = 1;
void ex1(){
	if(timer_flag == 1){
		setTimer1(500);
		switch(state){
			case 1:
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
				display7SEG(1);
				break;
			case 2:
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
				display7SEG(2);
				break;
			default: break;
		}
		state = 3 - state;
//		HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
//		HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
	}
}
