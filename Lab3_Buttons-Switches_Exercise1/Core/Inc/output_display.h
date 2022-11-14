/*
 * output_display.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Admin
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#include "global.h"
#include "main.h"
#include "fsm_traffic-light.h"

extern int index_led;

void updateClockBuffer(int first, int second);
void clearAllLeds();
void output_display();

#endif /* INC_OUTPUT_DISPLAY_H_ */
