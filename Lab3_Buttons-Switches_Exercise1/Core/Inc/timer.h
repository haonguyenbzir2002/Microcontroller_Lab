/*
 * timer.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Admin
 */
#include "main.h"
#include "input_reading.h"

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timerClock_flag;
extern int timerVerticalTraffic_flag;
extern int timerHorizontalTraffic_flag;
extern int timer7seg_flag;
extern int timerHorizontalTraffic;
extern int timerVerticalTraffic;
extern int timerBlinking2Hz_flag;

void setTimerBlinking2Hz(int duration);
void setTimerClock(int duration);
void setTimerVerticalTraffic(int duration);
void setTimerHorizontalTraffic(int duration);
void setTimer7seg(int duration);
void timerRun();

#endif /* INC_TIMER_H_ */
