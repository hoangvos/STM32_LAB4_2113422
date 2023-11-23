/*
 * led.h
 *
 *  Created on: Nov 23, 2023
 *      Author: hoang
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"
#include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include "scheduler.h"
extern int time_stamp;
UART_HandleTypeDef huart2;

void get_time(void);

void LedInit(void);
void toggle_led_1();
void toggle_led_2();
void toggle_led_3();
void toggle_led_4();
void toggle_led_5();
void toggle_led_6();


#endif /* INC_LED_H_ */
