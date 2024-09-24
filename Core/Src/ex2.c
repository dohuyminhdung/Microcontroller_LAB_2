#include "ex2.h"

int timer1_flag = 0;
int timer2_flag = 0;
int counter1 = 50;
int counter2 = 100;

void setTimer2_1(int time){
	counter1 = time / TICK;
	timer1_flag = 0;
}
void setTimer2_2(int time){
	counter2 = time / TICK;
	timer2_flag = 0;
}
void timerRun2_1(){
	if(counter1 > 0){
		counter1--;
		if(counter1 <= 0){
			timer1_flag = 1;
		}
	}
}
void timerRun2_2(){
	if(counter2 > 0){
		counter2--;
		if(counter2 <= 0){
			timer2_flag = 1;
		}
	}
}


int state2 = 0;
void ex2(){
	if(timer1_flag == 1){
		setTimer2_1(500);
		switch(state2){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(1);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(2);
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(3);
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			display7SEG(0);
			break;
		default: break;
		}
		state2++;
		if(state2 >= 4){
			state2 = 0;
		}
	}
	if(timer2_flag == 1){
		setTimer2_2(1000);
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
}
