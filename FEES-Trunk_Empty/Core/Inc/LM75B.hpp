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
 *                                  Stefano Ampolo                                   *
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
 * LM75B.h
 *
 *  Created on: 15/ott/2018
 *  Author: Stefano Ampolo
 *
 *  Device: LM75B
 *  Company: TexasIstruments
 *
 */
// Libreria per il sensore LM75B - Sensore di Temperatura Digitale I2C.
//        Range da -55C a +125C  - Risoluzione di 0.125 °C
// La Libreria è stata sviluppata per il progetto FEES in ambiente ChibiOS ed è POSIX Compatibile.


#ifndef LM75B_H
#define LM75B_H


//     LM75B INDIRIZZO I2C     // 
#define    LM75B_ADDR        0b1001000

//     LM75B REGISTRI UTILI    //
#define    LM75B_Conf        0x01
#define    LM75B_Temp        0x00
#define    LM75B_Tos         0x03
#define    LM75B_Thyst       0x02

/*
 * I2C frequency - 400 400 khz - FAST I2C  ( CAN ALSO USE 100000  for 100Khz - SLOW I2C )
 */
#define LM75B_I2C_FREQ 400000

/*
 * Using I2CD2
 * I2C2_SDA PB10
 * I2C2_SCL PB11
 */
#define LM75B_BUS_I2C I2CD2



/* Configuration of the the I2C driver ( FOR LM75B ) */
//static const I2CConfig LM75B_i2cconfig = {
//  OPMODE_I2C,
//  LM75B_I2C_FREQ,
//  FAST_DUTY_CYCLE_2,
//};




//  Definizione della classe   //

class LM75B {
public:
// Metodi Costruttore.
  LM75B();
  LM75B(int address);
  
  /*!
  Metodo Distruttore.
  */ 
  ~LM75B();
  
  //

  float getTemp();

  int8_t getI2CAddress() const {
		return I2C_Address;
	}

  void printTemp();

/*
  void shutdown();
  void wakeup();
  bool isShutdown();
*/
  
private:
  
  int8_t I2C_Address;

};

#endif





