/*
 * fsm_trafic-light.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Admin
 */
#include "fsm_traffic-light.h"

int horizontalTrafficState = AUTO_RED;
int verticalTrafficState = AUTO_GREEN;

void initState(){
	index_led = 0;
	setTimer7seg(20);
	setTimerClock(10);
	horizontalTrafficState = AUTO_RED;
	verticalTrafficState = AUTO_GREEN;
	setTimerHorizontalTraffic(RED_TIME);
	setTimerVerticalTraffic(GREEN_TIME);
}

/*void setRed(GPIO_TypeDef* red, uint16_t redPin
		, GPIO_TypeDef* yellow, uint16_t yellowPin
		, GPIO_TypeDef* green, uint16_t greenPin){
	HAL_GPIO_WritePin(red, redPin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(green, greenPin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green, greenPin, GPIO_PIN_SET);
}

void setYellow(GPIO_TypeDef* red, uint16_t redPin
		, GPIO_TypeDef* yellow, uint16_t yellowPin
		, GPIO_TypeDef* green, uint16_t greenPin){
	HAL_GPIO_WritePin(red, redPin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green, greenPin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(green, greenPin, GPIO_PIN_SET);
}

void setGreen(GPIO_TypeDef* red, uint16_t redPin
		, GPIO_TypeDef* yellow, uint16_t yellowPin
		, GPIO_TypeDef* green, uint16_t greenPin){
	HAL_GPIO_WritePin(red, redPin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green, greenPin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green, greenPin, GPIO_PIN_RESET);
}*/

void fsm_for_automatic_traffic_light(){
	switch (horizontalTrafficState){
	case AUTO_RED:
		HAL_GPIO_WritePin(HORIZONTAL_RED_GPIO_Port, HORIZONTAL_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(HORIZONTAL_GREEN_GPIO_Port, HORIZONTAL_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(HORIZONTAL_YELLOW_GPIO_Port, HORIZONTAL_YELLOW_Pin, GPIO_PIN_RESET);
		if (timerHorizontalTraffic_flag == 1){
			horizontalTrafficState = AUTO_GREEN;
			setTimerHorizontalTraffic(GREEN_TIME);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(HORIZONTAL_RED_GPIO_Port, HORIZONTAL_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(HORIZONTAL_GREEN_GPIO_Port, HORIZONTAL_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(HORIZONTAL_YELLOW_GPIO_Port, HORIZONTAL_YELLOW_Pin, GPIO_PIN_RESET);
		if (timerHorizontalTraffic_flag == 1){
			horizontalTrafficState = AUTO_YELLOW;
			setTimerHorizontalTraffic(YELLOW_TIME);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(HORIZONTAL_RED_GPIO_Port, HORIZONTAL_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(HORIZONTAL_GREEN_GPIO_Port, HORIZONTAL_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(HORIZONTAL_YELLOW_GPIO_Port, HORIZONTAL_YELLOW_Pin, GPIO_PIN_SET);
		if (timerHorizontalTraffic_flag == 1){
			horizontalTrafficState = AUTO_RED;
			setTimerHorizontalTraffic(RED_TIME);
		}
		break;
	default:
		break;
	}

	switch (verticalTrafficState){
	case AUTO_RED:
		HAL_GPIO_WritePin(VERTICAL_RED_GPIO_Port, VERTICAL_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VERTICAL_GREEN_GPIO_Port, VERTICAL_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VERTICAL_YELLOW_GPIO_Port, VERTICAL_YELLOW_Pin, GPIO_PIN_RESET);
		if (timerVerticalTraffic_flag == 1){
			verticalTrafficState = AUTO_GREEN;
			setTimerVerticalTraffic(GREEN_TIME);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(VERTICAL_RED_GPIO_Port, VERTICAL_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VERTICAL_GREEN_GPIO_Port, VERTICAL_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VERTICAL_YELLOW_GPIO_Port, VERTICAL_YELLOW_Pin, GPIO_PIN_RESET);
		if (timerVerticalTraffic_flag == 1){
			verticalTrafficState = AUTO_YELLOW;
			setTimerVerticalTraffic(YELLOW_TIME);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(VERTICAL_RED_GPIO_Port, VERTICAL_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VERTICAL_GREEN_GPIO_Port, VERTICAL_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VERTICAL_YELLOW_GPIO_Port, VERTICAL_YELLOW_Pin, GPIO_PIN_SET);
		if (timerVerticalTraffic_flag == 1){
			verticalTrafficState = AUTO_RED;
			setTimerVerticalTraffic(RED_TIME);
		}
		break;
	default:
		break;
	}
}
