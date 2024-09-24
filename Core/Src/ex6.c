#include "ex6.h"
//NO SIMULATION REQUEST IN THIS EXCERCISE.
#define TIMER_CYCLE 10
int timer0_counter = 0;
int timer0_flag = 0;

 void setTimer6(int duration){
	 timer0_counter = duration / TIMER_CYCLE ;
	 timer0_flag = 0;
 }
 void timer_run6(){
	 if( timer0_counter > 0) {
		 timer0_counter--;
		 if( timer0_counter == 0) timer0_flag = 1;
	 }
 }

 void ex6(){
	 if( timer0_flag == 1) {
		 HAL_GPIO_TogglePin(LED_RED_GPIO_Port , LED_RED_Pin);
		 setTimer6(2000);
	 }
 }

//1 setTimer6(1000);
//2 while (1) {
//3	 if( timer0_flag == 1) {
//4		 HAL_GPIO_TogglePin ( LED_RED_GPIO_Port , LED_RED_Pin ) ;
//5		 setTimer0 (2000) ;
//6	 }
//7 }
//Report 1: if in line 1 of the code above is miss, what happens after that and why?
 //Answer: The timer will never be set, meaning the variable timer0_counter remains at 0.
 //As a result, timer0_flag will never be set to 1, and the LED toggle operation in line 4 will not execute.
//Because The timer_run6() function relies on timer0_counter to decrease from a non-zero value until it
 //reaches 0, which sets timer0_flag to 1. Without calling setTimer6(), timer0_counter stays 0,
 //so the condition in line 3 (timer0_flag == 1) is never satisfied.

///Report 2: if in line 1 of the code above is changed to setTimer0(1), what happens after that and why?
 //Answer: counter is set to 0 (counter = duration/TIMER_CYCLE = 1/10 = 0) lead to timer_flag = 1 in
 //the timer_run function. Timer_flag == 1 lead to the led toggle (turn on) so the led turn on right
 //after run the program.

//Report 3: if in line 1 of the code above is changed to setTimer0(10), what is changed
//compared to 2 first questions and why?
 //Answer: counter is set to 1 (counter = duration/TIMER_CYCLE = 10/10 = 1) lead to timer_flag = 1 in
 //the timer_run function after 10ms. Timer_flag == 1 lead to the led toggle (turn on) so the led turn on
 //almost right after run the program.

