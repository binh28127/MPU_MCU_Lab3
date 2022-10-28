/*
 * global.h
 *
 *  Created on: Oct 25, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button_reading.h"
#include "software_timer.h"
#include "fsm_traffic.h"

#define NO_OF_BUTTONS	3

#define BUTTON_1		0
#define BUTTON_2		1
#define BUTTON_3		2

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

#define MODE_INIT		8
#define MODE_1			9
#define MODE_2			10
#define MODE_3			11
#define MODE_4			12

#define LED_ON			GPIO_PIN_SET
#define LED_OFF			GPIO_PIN_RESET

extern int timerCycle;
extern int timerForKeyPress;
extern int mode;

#endif /* INC_GLOBAL_H_ */
