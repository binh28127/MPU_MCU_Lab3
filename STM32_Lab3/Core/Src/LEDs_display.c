/*
 * LEDs_display.c
 *
 *  Created on: 30 Oct 2022
 *      Author: Admin
 */

#include "LEDs_display.h"

int horizontalStatus = AUTO_INIT;
int verticalStatus = AUTO_INIT;
GPIO_PinState blinkingStatus = LED_ON;

void fsmHorLEDsRun() {
	switch (horizontalStatus) {
		case AUTO_INIT:
			horizontalStatus = AUTO_RED;
			setTimer(0, RED_time);
			break;

		case AUTO_RED:
			if (isTimerUp(0)) {
				horizontalStatus = AUTO_GREEN;
				setTimer(0, GREEN_time);
			}
			break;

		case AUTO_GREEN:
			if (isTimerUp(0)) {
				horizontalStatus = AUTO_AMBER;
				setTimer(0, AMBER_time);
			}
			break;

		case AUTO_AMBER:
			if (isTimerUp(0)) {
				horizontalStatus = AUTO_RED;
				setTimer(0, RED_time);
			}
			break;

		default:
			break;
	}
}

void fsmVerLEDsRun() {
	switch (verticalStatus) {
		case AUTO_INIT:
			verticalStatus = AUTO_GREEN;
			setTimer(1, GREEN_time);
			break;

		case AUTO_RED:
			if (isTimerUp(1)) {
				verticalStatus = AUTO_GREEN;
				setTimer(1, GREEN_time);
			}
			break;

		case AUTO_GREEN:
			if (isTimerUp(1)) {
				verticalStatus = AUTO_AMBER;
				setTimer(1, AMBER_time);
			}
			break;

		case AUTO_AMBER:
			if (isTimerUp(1)) {
				verticalStatus = AUTO_RED;
				setTimer(1, RED_time);
			}
			break;

		default:
			break;
	}
}

void LEDsDisplay() {
	fsmHorLEDsRun();
	fsmVerLEDsRun();

	switch (horizontalStatus) {
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, LED_OFF);
			break;

		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, LED_OFF);
			break;

		case AUTO_AMBER:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, LED_ON);
			break;

		default:
			break;
	}

	switch (verticalStatus) {
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, LED_OFF);
			break;

		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, LED_OFF);
			break;

		case AUTO_AMBER:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, LED_ON);
			break;

		default:
			break;
	}
}

void LEDsBlinking() {
	if (isTimerUp(3)) {
		blinkingStatus = !blinkingStatus;
		setTimer(3, LED_blinking_time);
	}
	HAL_GPIO_WritePin(GPIOA, 0xFC, blinkingStatus);
}
