/*
 * fsm_traffic-light.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_TRAFFIC_LIGHT_H_
#define INC_FSM_TRAFFIC_LIGHT_H_

#include "global.h"
#include "timer.h"
#include "main.h"
#include "input_reading.h"
#include "output_display.h"

extern int horizontalTrafficState;
extern int verticalTrafficState;

/*void setRed(GPIO_TypeDef* red, uint16_t redPin
		, GPIO_TypeDef* yellow, uint16_t yellowPin
		, GPIO_TypeDef* green, uint16_t greenPin);
void setYellow(GPIO_TypeDef* red, uint16_t redPin
		, GPIO_TypeDef* yellow, uint16_t yellowPin
		, GPIO_TypeDef* green, uint16_t greenPin);
void setGreen(GPIO_TypeDef* red, uint16_t redPin
		, GPIO_TypeDef* yellow, uint16_t yellowPin
		, GPIO_TypeDef* green, uint16_t greenPin);*/
void initState();
void fsm_for_automatic_traffic_light();

#endif /* INC_FSM_TRAFFIC_LIGHT_H_ */
