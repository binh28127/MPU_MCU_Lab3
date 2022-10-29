/*
 * button.c
 *
 *  Created on: Oct 25, 2022
 *      Author: Admin
 */

#include "button_reading.h"

int button_flag[NO_OF_BUTTONS];
int button_flag_1s[NO_OF_BUTTONS];
GPIO_PinState key_reg[NO_OF_BUTTONS][4];
int counterForKeyPress[NO_OF_BUTTONS];

int isButtonPressed(int button) {
	if (button_flag[button]) {
		button_flag[button] = 0;
		return 1;
	}
	else return 0;
}

int isButtonPressed1s(int button) {
	return (button_flag_1s[button] == 1);
}

void getKeyInput() {
	for (int button = 0; button < NO_OF_BUTTONS; button++) {
		key_reg[button][0] = key_reg[button][1];
		key_reg[button][1] = key_reg[button][2];
		switch (button) {
			case BUTTON_1:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
				break;
			case BUTTON_2:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
				break;
			case BUTTON_3:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
				break;
			default:
				break;
		}

		if ((key_reg[button][0] == key_reg[button][1]) && (key_reg[button][1] == key_reg[button][2])) {

			// Press button, then release
			if (key_reg[button][3] != key_reg[button][2]) {
				key_reg[button][3] = key_reg[button][2];
				button_flag_1s[button] = 0;

				if (key_reg[button][2] == PRESSED_STATE) {
					button_flag[button] = 1;
					counterForKeyPress[button] = timerForKeyPress / timerCycle;
				}
			}
			// Press and hold button
			else {
				counterForKeyPress[button]--;
				if (!counterForKeyPress[button]) {
					if (key_reg[button][2] == PRESSED_STATE) {
						button_flag[button] = 1;
						button_flag_1s[button] = 1;
					}
					counterForKeyPress[button] = timerForKeyPress / timerCycle;
				}
			}
		}
	}
}
