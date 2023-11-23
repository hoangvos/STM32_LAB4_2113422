/*
 * led.c
 *
 *  Created on: Nov 23, 2023
 *      Author: hoang
 */

#include "led.h"

int time_stamp = 0;
void get_time(void){
	time_stamp++;
}

void LedInit(void){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 1);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, 1);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, 1);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 1);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, 1);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, 1);
}
void toggle_led_1(){
	char show_time[50] = {"Task 1: "};
	char time_stamp_str[30];
	itoa(time_stamp*10, time_stamp_str, 10);
	strcat(show_time, time_stamp_str);
	strcat (show_time , "ms\r\n");
	HAL_UART_Transmit(&huart2 , (char*)show_time , strlen(show_time), 100);
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}
void toggle_led_2(){
	char show_time[50] = {"Task 2: "};
	char time_stamp_str[30];
	itoa(time_stamp*10, time_stamp_str, 10);
	strcat(show_time, time_stamp_str);
	strcat (show_time , "ms\r\n");
	HAL_UART_Transmit(&huart2 , (char*)show_time , strlen(show_time), 100);
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}
void toggle_led_3(){
	char show_time[50] = {"Task 3: "};
	char time_stamp_str[30];
	itoa(time_stamp*10, time_stamp_str, 10);
	strcat(show_time, time_stamp_str);
	strcat (show_time , "ms\r\n");
	HAL_UART_Transmit(&huart2 , (char*)show_time , strlen(show_time), 100);
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}
void toggle_led_4(){
	char show_time[50] = {"Task 4: "};
	char time_stamp_str[30];
	itoa(time_stamp*10, time_stamp_str, 10);
	strcat(show_time, time_stamp_str);
	strcat (show_time , "ms\r\n");
	HAL_UART_Transmit(&huart2 , (char*)show_time , strlen(show_time), 100);
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
}
void toggle_led_5(){
	char show_time[50] = {"Task 5: "};
	char time_stamp_str[30];
	itoa(time_stamp*10, time_stamp_str, 10);
	strcat(show_time, time_stamp_str);
	strcat (show_time , "ms\r\n");
	HAL_UART_Transmit(&huart2 , (char*)show_time , strlen(show_time), 100);
	HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
}
void toggle_led_6(){
	char show_time[50] = {"Task 6: "};
	char time_stamp_str[30];
	itoa(time_stamp*10, time_stamp_str, 10);
	strcat(show_time, time_stamp_str);
	strcat (show_time , "ms\r\n");
	HAL_UART_Transmit(&huart2 , (char*)show_time , strlen(show_time), 100);
	HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
}

