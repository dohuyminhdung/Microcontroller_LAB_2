#include "ex5.h"
int ledBuffer[4] = {1 , 5 , 0 , 8}, idx = 0;
int hour = 15 , minute = 8 , second = 50;
void updateClockBuffer(){
	ledBuffer[2] = minute / 10;
	ledBuffer[3] = minute % 10;
	ledBuffer[0] = hour/10;
	ledBuffer[1] = hour%10;
}

void update7SEG_2(int index){
	switch (index){
	case 0:
		display7SEG(ledBuffer[0]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);

		break;
	case 1:
		display7SEG(ledBuffer[1]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);

		break;
	case 2:
		display7SEG(ledBuffer[2]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);

		break;
	case 3:
		display7SEG(ledBuffer[3]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);

		break;
	default: break;
	}
}

void ex5(){
	second++;
	if ( second >= 60) {
		second = 0;
		minute++;
	}
	if( minute >= 60) {
		minute = 0;
		hour++;
	}
	if( hour >=24) {
		hour = 0;
	}
	updateClockBuffer();
	update7SEG_2(idx++);
	if(idx >= 4){
		idx = 0;
	}
	HAL_Delay (1000);
}

////////////////////////////   EXERCISE 7   ///////////////////////////////
int flag7_1 = 0;
int counter7_1 = 100;
int flag7_2 = 0;
int counter7_2 = 100;
int flag7_3 = 0;
int counter7_3 = 25;
void setTimer7_1(int time){
	counter7_1 = time / TICK;
	flag7_1 = 0;
}
void setTimer7_2(int time){
	counter7_2 = time / TICK;
	flag7_2 = 0;
}
void setTimer7_3(int time){
	counter7_3 = time / TICK;
	flag7_3 = 0;
}
void timerRun7_1(){
	if(counter7_1 > 0){
		counter7_1--;
		if(counter7_1 <= 0) flag7_1 = 1;
	}
}
void timerRun7_2(){
	if(counter7_2 > 0){
		counter7_2--;
		if(counter7_2 <= 0) flag7_2 = 1;
	}
}
void timerRun7_3(){
	if(counter7_3 > 0){
		counter7_3--;
		if(counter7_3 <= 0) flag7_3 = 1;
	}
}
void ex7(){
	if(flag7_1 == 1){
		setTimer7_1(1000);
		second++;
		if ( second >= 60) {
			second = 0;
			minute++;
		}
		if( minute >= 60) {
			minute = 0;
			hour++;
		}
		if( hour >=24) {
			hour = 0;
		}
		updateClockBuffer();
	}
	if(flag7_2 == 1){
		setTimer7_2(1000);
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	////////////////////////////////// EXERCISE8 ///////////////////////////////////////
	if(flag7_3 == 1){
		setTimer7_3(250);
		update7SEG_2(idx++);
		if(idx >= 4){
			idx = 0;
		}
	}
}
