/***************************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   												   *
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
 *												   												   *
 *                  __    __     __     __   __    __  __ __       __    ___                       *
 *                 |_ |  |_ \_/||__)|  |_   |_ \_/|__)|_ |__)||\/||_ |\ | |  /\ |                  *
 *                 |  |__|__/ \||__)|__|__  |__/ \|   |__| \ ||  ||__| \| | /--\|__                *
 *                    __     __  __ __  __  __ __    __   ___ __       ___ __                      *
 *                   |_ |\/||__)|_ |  \|  \|_ |  \  (_  /\ | |_ |  |  | | |_                       *
 *                   |__|  ||__)|__|__/|__/|__|__/  __)/--\| |__|__|__| | |__                      *
 *                                                                                                 *
 *												    											   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   												   *
 *											FEES Project			 					           *
 *		    			URL: https://github.com/ferrandi/DEIB-DAER-project		                   *
 *				 					Politecnico di Milano - DEIB                                   *
 *			    						   Stefano Ampolo	    			                       *
 *		 			  ***********************************************************                  *
 *        		 	   		Copyright (c) 2018-2019 Politecnico di Milano				   		   *
 *                                                                                                 *
 *     This file is part of the FEES framework.                                                    *
 *                                                                                                 *
 *     The FEES framework is free software; you can redistribute it and/or modify                  *
 *     it under the terms of the GNU General Public License as published by                        *
 *     the Free Software Foundation; either version 3 of the License, or                           *
 *     (at your option) any later version.                                                         *
 *                                                                                                 *
 *     This program is distributed in the hope that it will be useful,                             *
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of                              *
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                               *
 *     GNU General Public License for more details.                                                *
 *                                                                                                 *
 *     You should have received a copy of the GNU General Public License                           *
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.                       *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 */

//============================================================================
// Name        : GpioMapper.h
// Author      : Stefano Ampolo
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : this file is needed to link The Schematics to the GPIO system
//
// DA MODIFICARE IL FILE HWDEFINITION di ARDUPILOT.
//============================================================================



#ifndef MAPPER_H
#define MAPPER_H

// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI

#define		UHF_RESET		0
#define		GPS_PWR_ON		1
#define		ANALOG_PWR_ON	2
#define		RASPY_ON		3
#define		RASPY_KEEP		4
#define		RAD_PWR_ON		5
#define		RAD_RESET		6

#define		PSD_0	7
#define		PSD_1	8
#define		PSD_2	9
#define		PSD_3	10


// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54

#define		PWM_X			PWM(1)
#define		PWM_X_GPIO		11

#define		PWM_Y			PWM(2)
#define		PWM_Y_GPIO		12

#define		PWM_Z			PWM(3)
#define		PWM_Z_GPIO		13

#define	BATTERY_HEATER_PWM		PWM(4)
#define	BATTERY_HEATER_GPIO 	14

#define		DIR_X		15
#define		DIR_Y		16
#define		DIR_Z		17


#define		RADFET_OWB		18

#define		LED		19


#define WATCHDOG	20


// IRIDIUM - SDB (GPIO 60-68)

#define		SDB_0	21		// DCD
#define		SDB_1	22		// DSR
#define		SDB_2	23		// DTR
#define		SDB_3	24		// CTS
#define		SDB_4	25		// RTS
#define		SDB_5	26	// on-off?
#define		SDB_6	27		// RI
#define		SDB_7	28		// NET
#define		SDB_PWR_ON	29  // Iridium Pwr On


#define EX_GPIO_1	30
#define	EX_GPIO_2	31
#define	EX_GPIO_3	32
#define	EX_GPIO_4	33



// POWER "INPUTS"
//	PGOOD -
// 	VUSB  - ADC INTERNO + Termocoppia

//ADC ESTERNO
// I_ X,Y,Z COIL
// BATT_TEMP
// I_CELL_ +X,+Y,+Z,-X
// V_CELL_ +X,+Y+Z,-X
// V_CELL_ +Y_1



#endif // MAPPER_H
