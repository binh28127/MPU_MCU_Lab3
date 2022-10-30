/*
 * fsm_traffic.c
 *
 *  Created on: Oct 25, 2022
 *      Author: Admin
 */

#include "fsm_traffic.h"

void fsmTrafficRun() {
	switch (mode) {
		case MODE_INIT:
			mode = MODE_1;
			break;

		case MODE_1:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_2;
			}

			// Run traffic single LEDs normally
			LEDsDisplay();

			// Update time for 7seg LEDs
			updateBufferForMode1();

			break;

		case MODE_2:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_3;
			}

			// LEDs blinking
			LEDsBlinking();

			break;

		case MODE_3:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_4;
			}

			// LEDs blinking
			LEDsBlinking();

			break;

		case MODE_4:
			if (isButtonPressed(BUTTON_1)) {
				mode = MODE_1;
			}

			// LEDs blinking
			LEDsBlinking();

			break;

		default:
			break;
	}
}
