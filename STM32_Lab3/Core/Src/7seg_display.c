/*
 * 7seg_display.c
 *
 *  Created on: 29 Oct 2022
 *      Author: Admin
 */

#ifndef SRC_7SEG_DISPLAY_C_
#define SRC_7SEG_DISPLAY_C_

#include "7seg_display.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

void display7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, 0B0111111, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B1000000, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, 0B0000110, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B1111001, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, 0B1011011, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B0100100, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, 0B1001111, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B0110000, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, 0B1100110, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B0011001, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, 0B1101101, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B0010010, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, 0B1111101, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B0000010, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, 0B0000111, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B1111000, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, 0B1111111, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, 0B1101111, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, 0B0010000, GPIO_PIN_SET);
			break;
		default:
			HAL_GPIO_WritePin(GPIOB, 0B1111111, GPIO_PIN_SET);
			break;
	}
}

void update7SEG(int index){
    switch (index){
        case 0:
            //Display the first 7SEG with led_buffer[0]
            display7SEG(led_buffer[0]);
            break;
        case 1:
            //Display the second 7SEG with led_buffer[1]
            display7SEG(led_buffer[1]);
            break;
        case 2:
            //Display the third 7SEG with led_buffer[2]
            display7SEG(led_buffer[2]);
            break;
        case 3:
            //Display the forth 7SEG with led_buffer[3]
            display7SEG(led_buffer[3]);
            break;
        default:
            break;
    }
}

void updateBufferForMode1() {
	led_buffer[0] = currentCounter(0) / 1000;
	led_buffer[1] = (currentCounter(0) / 100) % 10;
	led_buffer[2] = currentCounter(1) / 1000;
	led_buffer[3] = (currentCounter(1) / 100) % 10;
}

void updateBufferForIncTime() {
	// 2 7seg LEDs to display the value
	led_buffer[0] = time_count / 10;
	led_buffer[1] = time_count % 10;

	// 2 7seg LEDs to display the mode
	led_buffer[2] = 0;
	switch (mode) {
		case MODE_2:
			led_buffer[3] = 2;
			break;
		case MODE_3:
			led_buffer[3] = 3;
			break;
		case MODE_4:
			led_buffer[3] = 4;
			break;
		case INC_RED:
			led_buffer[3] = 2;
			break;
		case INC_AMBER:
			led_buffer[3] = 3;
			break;
		case INC_GREEN:
			led_buffer[3] = 4;
			break;
		default:
			break;
	}
}

#endif /* SRC_7SEG_DISPLAY_C_ */
