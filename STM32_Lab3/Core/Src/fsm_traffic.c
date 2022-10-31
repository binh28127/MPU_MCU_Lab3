/*
 * fsm_traffic.c
 *
 *  Created on: Oct 25, 2022
 *      Author: Admin
 */

#include "fsm_traffic.h"

int time_count = 0;

void fsmTrafficRun() {
	switch (mode) {
		case MODE_INIT:
			mode = MODE_1;
			break;

		case MODE_1:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_2;
			}
			break;

		case MODE_2:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_3;
			}
			break;

		case MODE_3:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_4;
			}

			// LEDs blinking
			LEDsBlinking();

			// Update time for 7seg LEDs
			time_count = AMBER_time / 1000;
			updateBufferForIncTime();

			// Increase the AMBER_time when press the 2nd button
			if (isButtonPressed(BUTTON_2)) {
				mode = INC_AMBER;
				time_count++;
			}

			break;

		case MODE_4:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_1;
			}
			break;

		default:
			break;
	}
}
