/***********************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                             *
 *    FFFFFFFFFFFFFFFFFFFFFEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS      *
 *    F:::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::E SS:::::::::::::::S     *
 *    F:::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::ES:::::SSSSSS::::::S     *
 *    FF:::::FFFFFFFFF::::FEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ES:::::S     SSSSSSS     *
 *      F::::F       FFFFFF  E:::::E       EEEEEE  E:::::E       EEEEEES:::::S                 *
 *      F::::F               E:::::E               E:::::E             S:::::S                 *
 *      F:::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE    S::::SSSS              *
 * ---- F::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E     SS::::::SSSSS    ---- *
 * -::- F::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E       SSS::::::::SS  -::- *
 * ---- F:::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE          SSSSSS::::S ---- *
 *      F::::F               E:::::E               E:::::E                         S:::::S     *
 *      F::::F               E:::::E       EEEEEE  E:::::E       EEEEEE            S:::::S     *
 *    FF::::::FF           EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::ESSSSSSS     S:::::S     *
 *    F:::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES::::::SSSSSS:::::S     *
 *    F:::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES:::::::::::::::SS      *
 *    FFFFFFFFFF           EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS        *
 *                                                                                             *
 *             ____    ___     __      ___    ___    __  ___ __       ___   ___                *
 *             |__ |   |__ \_/||__)|   |__    |__ \_/|__)|__ |__)||\/||__ |\ || /\ |           *
 *             |   |___|___/ \||__)|___|___   |___/ \|   |___|  \||  ||___| \||/~~\|___        *
 *                      ___     __  ___ __  __  ___ __     __     ________                     *
 *                      |__ |\/||__)|__ |  \|  \|__ |  \   /__`\ //__`||__ |\/|                *
 *                      |___|  ||__)|___|__/|__/|___|__/   .__/ | .__/||___|  |                *
 *                                                                                             *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                              *                                              *
 *                                        FEES Project                                         *
 *                      URL: https://github.com/ferrandi/DEIB-DAER-project                     *
 *                               Politecnico di Milano - DEIB                                  *
 *                          				Stefano Ampolo                             		   *
 *         ************************************************************************            *
 *                  Copyright (c) 2018-2019 Politecnico di Milano                              *
 *                                                                                             *
 *          This file is part of the FEES framework.                                           *
 *                                                                                             *
 *          The FEES framework is free software; you can redistribute it and/or modify         *
 *          it under the terms of the GNU General Public License as published by               *
 *          the Free Software Foundation; either version 3 of the License, or                  *
 *          (at your option) any later version.                                                *
 *                                                                                             *
 *          This program is distributed in the hope that it will be useful,                    *
 *          but WITHOUT ANY WARRANTY; without even the implied warranty of                     *
 *          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                      *
 *          GNU General Public License for more details.                                       *
 *                                                                                             *
 *          You should have received a copy of the GNU General Public License                  *
 *          along with this program.  If not, see <http://www.gnu.org/licenses/>.              *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
/**
 * @file    ADC12b_SPI_Driver.h
 * @brief   ADC12bit library header.
 *
 * @addtogroup ADC12bit
 * @ingroup EX_ADC
 * @{
 *
 *  Created on: 20/ott/2018
 *  Author: Stefano Ampolo
 *
 *  Device: ADC128S022
 *  Company: TexasIstruments
 *
 */

#ifndef ADC12B_SPI_DRIVER
#define ADC12B_SPI_DRIVER

#include "hal_spi.h"
#include "hal_spi_lld.h"

//FUNZIONI UTILI
//ADC12_PrintRAW();
//ADC12_PrintVoltage();
//ADC12_PrintALL();
//ADC12_PrintALLExtended();
//ADC12_Print(e,a);

/*
Register Maps
Table 1. Control Register Bits
Bit 7 Bit 6 Bit 5 Bit 4 Bit 3 Bit 2 Bit 1 Bit 0
DONTC DONTC ADD2  ADD1  ADD0  DONTC DONTC DONTC
*/

/*
INVIA 16 Bit		0 0 ADD1  ADD2 	-	 ADD3 0    0   0    -	0   0   0  	0    -	0   0   0   0
Ricevi 16 bit 		0 0 0     0		-	 DB11 DB10 DB9 DB8 	-	DB7 DB6 DB5 DB4  -	DB3 DB2 DB1 DB0

DB11==> MSB

CPOL= HIGH;
CPHA= HIGH;

INPUT - SAMPLE in RISING edge
OUTPUT - SAMPLE in FALLING edge

Digital clock input. The specified performance range of frequencies for this input
is 0.8 MHz SCLK 16 Digital I/O to 3.2 MHz. This clock directly controls the conversion
and readout processes.
*/
/*
 * ADC12b_SPI 1-2-3 configuration (3MHz, CPOL=1, CPHA=1,  MSB first).
 *
 * SPI AT 6MHZ!
 */

const SPIConfig ADC1_SPI_config = {
  FALSE,
  NULL,
  GPIOE,			//GPIOE
  GPIOE_CS_ADC1,	//pin 11  - E11 - GPIOE_EN_ADC1
  SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0 | SPI_CR1_CPOL | SPI_CR1_CPHA,
  0
};

const SPIConfig ADC2_SPI_config = {
  FALSE,
  NULL,
  GPIOE,			//GPIOE
  GPIOE_CS_ADC2,	//pin 13  - E13
  SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0 | SPI_CR1_CPOL | SPI_CR1_CPHA,
  0
};

const SPIConfig ADC3_SPI_config = {
  FALSE,
  NULL,
  GPIOE,			//GPIOE
  GPIOE_CS_ADC3,	//pin 12  - E12
  SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0 | SPI_CR1_CPOL | SPI_CR1_CPHA,
  0
};

/*
 * SPI_CR1 Register Bit Definition for STM32F107 as "guide"
 *
 * Bit 0 SPI_CR1_CPHA: Clock phase
 *  0: The first clock transition is the first data capture edge
 *  1: The second clock transition is the first data capture edge
 * Bit 1 SPI_CR1_CPOL: Clock polarity
 *  0: CK to 0 when idle
 *  1: CK to 1 when idle
 * Bits 5:3 SPI_CR1_BR[2:0]: Baud rate control
 *  000: f_PCLK/2		100: f_PCLK/32
 *  001: f_PCLK/4		101: f_PCLK/64
 *  010: f_PCLK/8		110: f_PCLK/128
 *  011: f_PCLK/16		111: f_PCLK/256
 * Bit 7 SPI_CR1_LSBFIRST: Frame format
 *  0: MSB transmitted first
 *  1: LSB transmitted first
 * Bit 8 SPI_CR1_SSI: Internal slave select
 * This bit has an effect only when the SSM bit is set. The value of this bit
 *  is forced onto the NSS pin and the IO value of the NSS pin is ignored.
 * Bit 9 SPI_CR1_SSM: Software slave management
 *  When SSM is set, the NSS pin input is replaced with the SSI bit value.
 *  0: Software slave management disabled
 *  1: Software slave management enabled
 * Bit 10 SPI_CR1_RXONLY: Receive only
 * Bit 11 SPI_CR1_DFF: Data frame format
 *  0: 8-bit data frame format is selected for transmission/reception
 *  1: 16-bit data frame format is selected for transmission/reception
 * Bit 12 SPI_CR1_CRCNEXT: CRC transfer next
 * Bit 13 SPI_CR1_CRCEN: Hardware CRC calculation enable
 * Bit 14 SPI_CR1_BIDIOE: Output enable in bidirectional mode
 *  Combined with the BIDImode, this bit selects the direction of transfer
 *  0: Output disabled (receive-only mode)
 *  1: Output enabled (transmit-only mode)
 * Bit 15 SPI_CR1_BIDIMODE: Bidirectional data mode enable
 *  0: 2-line unidirectional data mode selected
 *  1: 1-line bidirectional data mode selected
 */



///////////// Library //////////////////

#define ADC_SPI_Driver	SPID1

uint16_t FULLSCALE_12BIT = 0b0000111111111111; // 4095 in decimale

//ADC1	ENABLE 1 ---> PE11
#define		VANA_SENSE		0U
#define		VREF ADC 2.5	1U
#define		VBAT_SENSE		2U
#define		VSOL_SENSE		3U
#define		ILOAD			4U
#define		ICHARGER		5U
#define		PSD1OUT			6U
#define		PSD2OUT			7U

//ADC2	ENABLE 2 ---> PE13
#define		V_piuX			0U
#define		I_piuX			1U
#define		V_menoX			2U
#define		I_menoX			3U
#define		V_piuY			4U
#define		I_piuY			5U
#define		V_piuZ			6U
#define		I_piuZ			7U

//ADC3	ENABLE 3 ---> PE12
#define		VCELL_piuX_1	0U
#define		IXCOIL			1U
#define		IYCOIL			2U
#define		IZCOIL			3U
#define		BATT_TEMP		4U
#define		EXADC1			5U
#define		EXADC2			6U
#define		EXADC3			7U



uint16_t Adc12DataRAW[3][8];
float Adc12DataNormalized[3][8];
float Adc12DataVoltage[3][8];


char Adc12_Channel_Name[3][8][15]{
	{"V Analog SENSE" ,	"VREF ADC 2.5" ,"VBAT SENSE" , "VSOL SENSE" ,"ILOAD" , "ICHARGER" ,	"PSD1OUT",	"PSD2OUT"},
	{"V piu X", "I piu X", "V meno X", "I meno X", "V piu Y", "I piu Y", "V piu Z", "I piu Z"},
	{"VCELL piu X 1", "IXCOIL", "IYCOIL", "IZCOIL", "BATT TEMP",	"EX ADC1", "EX ADC2","EX ADC3"}
};


/* Array 2D di Stringhe , 3D di Char

Adc12_Channel_Name[0][8][15]{
	"VANA_SENSE" ,
	"VREF ADC 2.5" ,
	"VBAT_SENSE" ,
	"VSOL_SENSE" ,
	"ILOAD \t" ,
	"ICHARGER" ,
	"PSD1OUT" ,
	"PSD2OUT"
}
Adc12_Channel_Name[1][8][15]{
	"V_piuX",
	"I_piuX",
	"V_menoX",
	"I_menoX",
	"V_piuY",
	"I_piuY",
	"V_piuZ",
	"I_piuZ"
}
Adc12_Channel_Name[2][8][15]{
	"VCELL_piuX_1",
	"IXCOIL \t",
	"IYCOIL \t",
	"IZCOIL \t",
	"BATT_TEMP",
	"EXADC1",
	"EXADC2",
	"EXADC3"
}
*/

/*
 * Methods Declaration all pretty self explainatory
 */
/*

static void ADC12_ReadALL();
static void ADC12_PrintRAW();
static void ADC12_PrintNormalized();
static void ADC12_PrintVoltage();
static void ADC12_PrintALL();
static void ADC12_PrintALLShort();
static void ADC12_PrintALLExtended();
static void ADC12_Print(uint8_t adc_number, uint8_t channel);
*/




#endif /* ADC12B_SPI_DRIVER */
