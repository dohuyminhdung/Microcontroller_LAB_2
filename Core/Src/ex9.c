#include "ex9.h"
#define MAX_LED_MATRIX 8
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0xE7 , 0xC3 , 0x99 , 0x99 , 0x81 , 0x81 , 0x99 , 0x99};
//{0xE7 , 0xC3 , 0x99 , 0x99 , 0x81 , 0x81 , 0x99 , 0x99};

void displayMatrixRow(uint8_t i){
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, i & 1);
    HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, i & 2);
    HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, i & 4);
    HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, i & 8);
    HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, i & 16);
    HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, i & 32);
    HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, i & 64);
    HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, i & 128);
}

void updateLEDMatrix(int index){
	switch(index){
	case 0:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 0);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[0]);
        break;
	case 1:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 0);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[1]);
        break;
	case 2:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 0);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[2]);
        break;
	case 3:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 0);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[3]);
        break;
	case 4:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 0);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[4]);
        break;
	case 5:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 0);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[5]);
        break;
	case 6:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 0);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
        displayMatrixRow(matrix_buffer[6]);
        break;
	case 7:
        HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 0);
        displayMatrixRow(matrix_buffer[7]);
        break;
	default: break;
	}
}

int flag9 = 0;
int flag10 = 0;
int counter9 = 4;
int counter10 = 100;
void setTimer9(int time){
	flag9 = 0;
	counter9 = time / TICK;
}
void timerRun9(){
	if(counter9 > 0) {
		counter9--;
		if(counter9 == 0) flag9 = 1;
	}
}
void setTimer10(int time){
	flag10 = 0;
	counter10 = time / TICK;
}
void timerRun10(){
	if(counter10 > 0) {
		counter10--;
		if(counter10 == 0) flag10 = 1;
	}
}
int i = 0;
void ex9(){
	if(flag9 == 1){
		updateLEDMatrix(i);
		if(++i >= 8) i = 0;
		setTimer9(10);
	}
}
void ex10(){
	if(flag9 == 1){
		updateLEDMatrix(i);
		if(++i >= 8) i = 0;
		setTimer9(30);
	}
	if(flag10 == 1){
		setTimer10(800);
		for(int tmp = 0; tmp < 8; ++tmp){
			matrix_buffer[tmp] = (matrix_buffer[tmp] >> 1)
									| ((matrix_buffer[tmp]&1) << 7);
		}
	}
}
