#include "ex3.h"
#define MAX_LED 4

int count3_1 = 50;
int flag3_1 = 0;
int index_led = 0;
int led_buffer[4] = {1 , 2 , 3 , 4};
int count3_2 = 100;
int flag3_2 = 0;
void update7SEG(int index){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7SEG(led_buffer[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7SEG(led_buffer[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7SEG(led_buffer[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		display7SEG(led_buffer[3]);
		break;
	default: break;
	}
}
void setTimer3_1(int time){
	count3_1 = time / TICK;
	flag3_1 = 0;
}
void timerRun3_1(){
	if(count3_1 > 0){
		count3_1--;
		if(count3_1 <= 0){
			flag3_1 = 1;
		}
	}
}
void setTimer3_2(int time){
	count3_2 = time / TICK;
	flag3_2 = 0;
}
void timerRun3_2(){
	if(count3_2 > 0){
		count3_2--;
		if(count3_2 <= 0){
			flag3_2 = 1;
		}
	}
}
void ex3(){
	if(flag3_1 == 1){
		setTimer3_1(500);
		update7SEG(index_led++);
		if(index_led >= MAX_LED){
			index_led = 0;
		}
	}
	if(flag3_2 == 1){
		setTimer3_2(1000);
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
}

void ex4(){
	if(flag3_1 == 1){
		setTimer3_1(250);
		update7SEG(index_led++);
		if(index_led >= MAX_LED){
			index_led = 0;
		}
	}
	if(flag3_2 == 1){
		setTimer3_2(1000);
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
}
