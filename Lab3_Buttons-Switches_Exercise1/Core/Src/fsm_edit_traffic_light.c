/*
 * fsm_edit_traffic_light.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Admin
 */
#include "fsm_edit_traffic_light.h"


void modifyTime(int *currentTimer,
			  GPIO_TypeDef* horizontalPort, uint16_t horizontalPin,
			  GPIO_TypeDef* verticalPort, uint16_t verticalPin)
{
	//blinking coresponding color in 2 Hz
	if (timerBlinking2Hz_flag == 1){
		setTimerBlinking2Hz(250);
		HAL_GPIO_TogglePin(horizontalPort, horizontalPin);
		HAL_GPIO_TogglePin(verticalPort, verticalPin);
	}
	//increase newTimer if button 2 is pressed
	if (is_button_pressed(1) == 1){
		newTimer++;
		if (newTimer >= 100)
			newTimer = 1;
	}
	//set newTimer to the current color if button 3 is pressed
	if (is_button_pressed(2)){
		*currentTimer = newTimer * 1000;
	}
}

void fsm_for_customizing_traffic_light(){
	switch (MODE){
	case MANUAL_RED:
		modifyTime(&RED_TIME, HORIZONTAL_RED_GPIO_Port, HORIZONTAL_RED_Pin,
							  VERTICAL_RED_GPIO_Port, VERTICAL_RED_Pin);
		if (is_button_pressed(0) == 1){
			MODE = MANUAL_YELLOW;
			newTimer = 1;
		}
		break;
	case MANUAL_YELLOW:
		modifyTime(&YELLOW_TIME, HORIZONTAL_YELLOW_GPIO_Port, HORIZONTAL_YELLOW_Pin,
							  VERTICAL_YELLOW_GPIO_Port, VERTICAL_YELLOW_Pin);
		if (is_button_pressed(0) == 1){
			MODE = MANUAL_GREEN;
			newTimer = 1;
		}
		break;
	case MANUAL_GREEN:
		modifyTime(&GREEN_TIME, HORIZONTAL_GREEN_GPIO_Port, HORIZONTAL_GREEN_Pin,
							  	 VERTICAL_GREEN_GPIO_Port, VERTICAL_GREEN_Pin);
		if (is_button_pressed(0) == 1){
			MODE = AUTOMATIC;
			newTimer = 1;
		}
		break;
	default:
		break;
	}
}

