/***************************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   *
 *      FFFFFFFFFFFFFFFFFFFFFFEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS       *
 *      F::::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::E SS:::::::::::::::S      *
 *      F::::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::ES:::::SSSSSS::::::S      *
 *      FF::::::FFFFFFFFF::::FEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ES:::::S     SSSSSSS      *
 *        F:::::F       FFFFFF  E:::::E       EEEEEE  E:::::E       EEEEEES:::::S                  *
 *        F:::::F               E:::::E               E:::::E             S:::::S                  *
 *        F::::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE    S::::SSSS               *
 * ----   F:::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E     SS::::::SSSSS     ---- *
 * -::-   F:::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E       SSS::::::::SS   -::- *
 * ----   F::::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE          SSSSSS::::S  ---- *
 *        F:::::F               E:::::E               E:::::E                         S:::::S      *
 *        F:::::F               E:::::E       EEEEEE  E:::::E       EEEEEE            S:::::S      *
 *      FF:::::::FF           EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::ESSSSSSS     S:::::S      *
 *      F::::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES::::::SSSSSS:::::S      *
 *      F::::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES:::::::::::::::SS       *
 *      FFFFFFFFFFF           EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS         *
 *												   *
 *               ____    ___     __      ___    ___    __  ___ __       ___   ___        	   *
 *               |__ |   |__ \_/||__)|   |__    |__ \_/|__)|__ |__)||\/||__ |\ || /\ |    	   *
 *               |   |___|___/ \||__)|___|___   |___/ \|   |___|  \||  ||___| \||/~~\|___ 	   *
 *                         ___     __  ___ __  __  ___ __     __     ________         		   *
 *                        |__ |\/||__)|__ |  \|  \|__ |  \   /__`\ //__`||__ |\/|     		   *
 *                        |___|  ||__)|___|__/|__/|___|__/   .__/ | .__/||___|  |     		   *
 *                                                                                       	   *
 *												   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   *
 *												   *
 *					FEES Project 					           *
 *		    URL: https://github.com/ferrandi/DEIB-DAER-project		                   *
 *				 Politecnico di Milano - DEIB                                      *
 *			    Matteo Franceschini  & Stefano Ampolo	                           *
 *		   ***********************************************************                     *
 *             		Copyright (c) 2018-2019 Politecnico di Milano				   *
 *                                                                                                 *
 *   This file is part of the FEES framework.                                                      *
 *                                                                                                 *
 *   The FEES framework is free software; you can redistribute it and/or modify                    *
 *   it under the terms of the GNU General Public License as published by                          *
 *   the Free Software Foundation; either version 3 of the License, or                             *
 *   (at your option) any later version.                                                           *
 *                                                                                                 *
 *   This program is distributed in the hope that it will be useful,                           	   *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of                                *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                 *
 *   GNU General Public License for more details.                                                  *
 *                                                                                                 *
 *   You should have received a copy of the GNU General Public License                             *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.                         *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
/**
 * @file  main.cc
 * @brief This is the main file
 * @author Stefano Ampolo
 * @author 
 * $Revision$
 * $Date$
 * Last modified by Stefano ampolo
 *
 *
*/
/*  Made by STAMP     */


// 3 Magnetorquers - they are activated by an H bridge - BD6210F-E2
// Each Magn. has his own H-bridge - they are activated by 2 pins : DIR and PWM



//  X - Axis  - DIR X COIL = PE7		PWM_X_COIL = PA0
void Coil_X(int direction, int Duty_Cycle , int time);


//	Y - Axis  - DIR Y COIL = PE8		PWM_X_COIL = PA1
void Coil_Y(int direction, int Duty_Cycle , int time);


//  Z - Axis  - DIR Z COIL = PE9		PWM_X_COIL = PA2
void Coil_Z(int direction, int Duty_Cycle , int time);










https://stm32f4-discovery.net/2014/05/stm32f4-stm32f429-discovery-pwm-tutorial/








//  X - Axis  - DIR X COIL = PE7		PWM_X_COIL = PA0
void Coil_X(int direction, int Duty_Cycle , int time){
	if(direction) {HAL_GPIO_WritePin(GPIOE_BASE, GPIO_PIN_7, GPIO_PIN_SET);}
		else {  HAL_GPIO_WritePin(GPIOE_BASE, GPIO_PIN_7, GPIO_PIN_RESET);}
	//PWM_X_COIL = PA0 --> TIMER2_CH1


	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};
	htim2.Instance = TIM3;
	htim2.Init.Prescaler = -100-1;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  	htim2.Init.Period = 100-1;
  	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK){Error_Handler();}
  	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK){ Error_Handler();}
  	sConfigOC.OCMode = TIM_OCMODE_PWM1;
  	sConfigOC.Pulse = Duty_Cycle-1;
  	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK){ Error_Handler();}
  i++;
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	os_delay(time);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
}	


//	Y - Axis  - DIR Y COIL = PE8		PWM_X_COIL = PA1
void Coil_Y(int direction, int Duty_Cycle , int time){
	if(direction) {HAL_GPIO_WritePin(GPIOE_BASE, GPIO_PIN_8, GPIO_PIN_SET);}
		else {  HAL_GPIO_WritePin(GPIOE_BASE, GPIO_PIN_8, GPIO_PIN_RESET);}
	//PWM_X_COIL = PA0 --> TIMER2_CH2



	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	os_delay(time);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
}


//  Z - Axis  - DIR Z COIL = PE9		PWM_X_COIL = PA2
void Coil_Z(int direction, int Duty_Cycle , int time){
	if(direction) {HAL_GPIO_WritePin(GPIOE_BASE, GPIO_PIN_9, GPIO_PIN_SET);}
		else {  HAL_GPIO_WritePin(GPIOE_BASE, GPIO_PIN_9, GPIO_PIN_RESET);}
	//PWM_X_COIL = PA0 --> TIMER2_CH3



	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	os_delay(time);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
}





















// BLACKBOX
// Here I will create a STUB simulating the black box that will use the three Magnetotorquers.

void BLACKBOX_ADCS (){
	int Duty_Cycle_X= rand() % 100;
	int Duty_Cycle_Y= rand() % 100;
	int Duty_Cycle_Z= rand() % 100;
	int DIR_X = rand() % 1;
	int DIR_Y = rand() % 1;
	int DIR_Z = rand() % 1;

void Coil_X(DIR_X, Duty_Cycle_X, 10);
void Coil_Y(DIR_Y, Duty_Cycle_Y , 10);
void Coil_Z(DIR_Z, Duty_Cycle_Z , 10);

}





