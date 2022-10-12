/*
 * global.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"

#define AUTO_RED 11
#define AUTO_YELLOW 12
#define AUTO_GREEN 13

#define AUTOMATIC 1
#define MANUAL_RED 2
#define MANUAL_YELLOW 3
#define MANUAL_GREEN 4

extern int RED_TIME;
extern int YELLOW_TIME;
extern int GREEN_TIME;
extern int newTimer;

extern int MODE;

#endif /* INC_GLOBAL_H_ */
