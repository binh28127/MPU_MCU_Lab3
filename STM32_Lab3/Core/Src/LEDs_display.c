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
