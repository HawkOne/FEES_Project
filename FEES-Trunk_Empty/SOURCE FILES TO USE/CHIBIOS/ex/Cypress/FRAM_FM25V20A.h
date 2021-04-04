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
/*
 * FRAM.h
 *
 *  Created on: 25/ott/2018
 *  Author: Stefano
 *
 *  Device: FM25V20A-G
 *  Company: Cypress
 *
 */

#ifndef FRAM_H_
#define FRAM_H_


#define USED_SPI_DRIVER_FRAM SPID2


static const SPIConfig FERAM_SPI_Config ={
			FALSE,
			NULL,
			GPIOD,			//GPIOD
			GPIOD_CS_FRAM,	//pin 11  - D11 - GPIOD_CS_FRAM
			!SPI_CR1_BR_2 | !SPI_CR1_BR_1 | !SPI_CR1_BR_0 | SPI_CR1_CPOL | SPI_CR1_CPHA,
			0 };
/*
 * Bits 5:3 SPI_CR1_BR[2:0]: Baud rate control
 *  000: f_PCLK/2		100: f_PCLK/32
 *  001: f_PCLK/4		101: f_PCLK/64
 *  010: f_PCLK/8		110: f_PCLK/128
 *  011: f_PCLK/16		111: f_PCLK/256
 */

// OPCODES DEFINITION //
static const uint8_t FRAM_WRITE_ENABLE 			= 0b00000110 ;
static const uint8_t FRAM_WRITE_DISABLE 		= 0b00000100 ;
static const uint8_t FRAM_STATUS_REGISTER_READ 	= 0b00000101 ;
static const uint8_t FRAM_STATUS_REGISTER_WRITE = 0b00000001 ;
static const uint8_t FRAM_READ 					= 0b00000011 ;
static const uint8_t FRAM_FASTREAD				= 0b00001011 ;
static const uint8_t FRAM_WRITE 				= 0b00000010 ;
static const uint8_t FRAM_SLEEP					= 0b10111001 ;
static const uint8_t FRAM_READ_ID   			= 0b10011111 ;

// Function Definition //
static void FRAM_PrintSR();
static void FRAM_PrintID();
static void FRAM_WriteEnable();
static void FRAM_Read1byte(uint32_t address);
static void FRAM_Write(uint8_t *data , uint8_t size , uint32_t address);
static uint8_t FRAM_SPI_Ex1Byte(uint8_t OPCODE);
static uint8_t FRAM_SPI_Read1byte( uint32_t address);
static void FRAM_PrintNbyte(uint8_t N, uint32_t address);
static void FRAM_TestWriteSingleCell(uint8_t quante_volte , uint32_t quale_indirizzo);
void FRAM_TestWriteIncremental(uint8_t quante_volte , uint32_t quale_indirizzo);
void FRAM_PrintTest(int num_celle);


/*
La memoria dispone di una protezione “software” alla scrittura:
un bit del status register deve essere messo a 1 invece che a zero
prima di ogni operazione di scrittura. Cioè, dopo ogni comando “write”
(che sia nella memoria stessa o nel registro), questo bit si resetta
 automaticamente a “0” e blocca ogni nuova operazione di scrittura.

Il “status register” è composto cosi:

Bit7: WPEN, non usato;
Bits 6,5,4 e 0: non usati;
Bit 3 = BP(1), block protection;
Bit 2 = BP(0);
Bit 1 = WEL, il famoso bit che dice se puoi scrivere o meno.

*/

/*
La struttura della comunicazione con la memoria è:

CS low → al primo “rising” di SCK si manda l’ OPCODE (byte) che da il comando,
poi gli argomenti se necessario.

Gli OPCODE (in MSB) disponibili sono:

WREN: 0b00000110 = “enable writing”.
Questo cambia il bit WEL da 0 a 1, per permettere la scrittura.
Questo comando va mandato prima di ogni scrittura!
Dopo WREN, il CS va messo in high, e poi low prima di fare la scrittura.

WRDI: 0b00000100 = “disable writing”,
cambia WEL da 1 a 0

RDSR: 0b00000101 = “read status register”,
rimanda gli 8 bits del SR;

WRSR: 0b00000001 = “write status register”.
Per usare questo commando, il WEL deve essere a 1,
quindi va usato dopo WREN!

READ: 0b00000011 = “read memory”,
va seguito dall’indirizzo fisico della memoria;

FSTR: 0b00001011 = “fast read”,
fa la stessa cosa di read, ma manda prima
un dummy byte in uscita, prima dei data;

WRITE:0b00000010 = “write memory”,
va seguito dall’indirizzo, e dai byte da scrivere;

SLEEP:0b10111001 = “sleep mode”,
per ridurre il consumo. La memoria si risveglia
dopo il prossimo “falling edge” del CS, dopo un delay di 1 ms;

RDID: 0b10011111 = “read id”,
per leggere l’ID della memoria…

*/


/*
L’indirizzo fisico della memoria è composto cosi: 3 byte. I primi 6 bits sono “non-care”,
da mettere a 0. Gli ultimi 18 sono l’indirizzo MSB.
3byte = 24 bits --> 18 bits  ( MSB FIRST )

Block protection bits: BP(1) e BP(0). Sono una protezione software contro la scrittura.
PB1	PB0
0	0	NONE
0	1	UPPER 1/4		0x30000 fino a 0x3FFFF
1	0	UPPER 1/2		0x20000 fino a 0x3FFFF
1	1	ALL THE MEMORY	0x00000 fino a 0x3FFFF

Vanno settati a piacere.

Per settarli:
CS low
Opcode WREN;
CS high;
CS low;
Opcode WRSR;
Bits da scrivere nel status register. D7 D6  D5 D4 BP(1) BP(0) D1 D0; (BP1<<4)|(BP0<<3)
CS high.


Per scivere sulla memoria:

CS low
Opcode WREN;
CS high;

CS low;
Opcode WRITE;
Address MSB;
Bytes da scrivere (incremento automatico finché si mandano dati) in MSB;
CS high quando finito.
Non c’è bisogno di fare data polling! La scrittura è immediata.


Per leggere:

CS low
Opcode READ;
Address;
Lasciare CS low e mandare il clock finché si vuole leggere (incremento auto):
CS high.
 */






#endif /* FRAM_H_ */
