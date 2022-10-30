/*
 * software_timer.h
 *
 *  Created on: Oct 25, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

int currentCounter(int timer);
int isTimerUp(int timer);
void setTimer(int timer, int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
