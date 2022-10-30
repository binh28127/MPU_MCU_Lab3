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
#include "7seg_display.h"
#include "LEDs_display.h"

// define for timer
// Timer0 for horizontal LEDs, Timer1 for vertical LEDs,
// Timer2 for switching 7seg LEDs, Timer3 for blinking LEDs
#define NO_OF_TIMER		4

// define for button
#define NO_OF_BUTTONS	3

#define BUTTON_1		0
#define BUTTON_2		1
#define BUTTON_3		2

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

// define for traffic mode
#define MODE_INIT		8
#define MODE_1			9
#define MODE_2			10
#define MODE_3			11
#define MODE_4			12

// define for single LEDs
#define LED_ON			GPIO_PIN_SET
#define LED_OFF			GPIO_PIN_RESET

#define AUTO_INIT		16
#define AUTO_RED		17
#define AUTO_GREEN		18
#define AUTO_AMBER		19

// define for 7seg LEDs
#define SEG_ON			GPIO_PIN_RESET
#define SEG_OFF			GPIO_PIN_SET

#define horizontalRoad	0
#define verticalRoad	1

// global variables
extern int timerCycle;
extern int timerForKeyPress;

extern int mode;

extern int RED_time;
extern int GREEN_time;
extern int AMBER_time;

extern int SEG_switching_time;
extern int LED_blinking_time;

#endif /* INC_GLOBAL_H_ */
