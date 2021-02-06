/***************************************************************************
 *   Copyright (C) 2018 by Terraneo Federico                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#ifndef HWMAPPING_H
#define	HWMAPPING_H

#include "interfaces/gpio.h"

namespace miosix {

namespace gpios{

	using gpio1 = Gpio<GPIOB_BASE,1>;                        //
	using gpio2 = Gpio<GPIOB_BASE,12>;                        //
	using gpio3 = Gpio<GPIOA_BASE,3>;                        //
	using gpio4 = Gpio<GPIOA_BASE,10>;                        //
	using led_blue = Gpio<GPIOD_BASE,12>;					//pin del led blu, usato anche per whatchdog TMTC
	//using tms= Gpio<GPIOA_BASE,13>;                 // not used, just programming
	//using tck= Gpio<GPIOA_BASE,14>;                 // not used, just programming
	//using = Gpio<GPIOA_BASE,15>;              UNCONNECTED
	//using = Gpio<GPIOB_BASE,3> ;              UNCONNECTED
	//using = Gpio<GPIOB_BASE,4> ;              UNCONNECTED
}//gpios

namespace interfaces{

	//shared SPIs
	using sck1 = Gpio<GPIOA_BASE,5>;                 // ( MPU1-9250)
	using miso1 = Gpio<GPIOA_BASE,6>;                // ( MPU1-9250)
	using mosi1 = Gpio<GPIOA_BASE,7>;                // ( MPU1-9250)

	using sck2 = Gpio<GPIOB_BASE,13>;                 //MPU2-9250
	using miso2 = Gpio<GPIOB_BASE,14>;                //MPU2-9250
	using mosi2 = Gpio<GPIOB_BASE,15>;                //MPU2-9250

	using sck3 = Gpio<GPIOC_BASE,10>;                 //EEPROM2 SPI3       
	using miso3 = Gpio<GPIOC_BASE,11>;                //EEPROM2 SPI3       
	using mosi3 = Gpio<GPIOC_BASE,12>;                //EEPROM2 SPI3

	//SHARED I2Cs
	using scl1= Gpio<GPIOB_BASE,8>;                 //LORA    (Negli schematici I2C2)
	using sda1= Gpio<GPIOB_BASE,9>;                 //LORA
	using scl2= Gpio<GPIOB_BASE,10>;                 //EEPROM1  (Negli schematici I2C1)
	using sda2= Gpio<GPIOB_BASE,11> ;                 //EEPROM1

	//USB 
	using vbus = Gpio<GPIOA_BASE,9>;
	using usbm = Gpio<GPIOA_BASE,11>;
	using usbp = Gpio<GPIOA_BASE,12>;

	//UART 6
	using u6tx = Gpio<GPIOC_BASE,6>;                 // SDR
	using u6rx = Gpio<GPIOC_BASE,7>;                 // SDR
	//using u1tx= Gpio<GPIOB_BASE,6>;                 //GPS
	//using u1rx= Gpio<GPIOB_BASE,7>;                 //GPS
	//using u2tx= Gpio<GPIOD_BASE,5>;     //PD5 (USART2_TX) IRIDIUM TX
	//using u2rx= Gpio<GPIOD_BASE,6>;     //PD6 (USART2_RX)  IRIDIUM RX
	//using u3tx= Gpio<GPIOD_BASE,8>;               //
	//using u3rx= Gpio<GPIOD_BASE,9>;               //
        

} //namespace interfaces



namespace memories{

	namespace eeprom{
		using cs = Gpio<GPIOD_BASE,10>;
	}//namespace eeprom

	namespace fram{
		using cs = Gpio<GPIOD_BASE,11>;
	}//namespace fram

	namespace nand{
		using cs = Gpio<GPIOE_BASE,4>;
	}//namespace nand


}//namespace memories


namespace sensors{


	namespace external_device
	{
		using cs = Gpio<GPIOC_BASE,9>; //SPI external enable
	}//namespace external device

	namespace radfet
	{
		using cs = Gpio<GPIOA_BASE,4>; 
		using reset = Gpio<GPIOC_BASE,15>;
	}//namespace radfet

	namespace psd1{
		using cs = Gpio<GPIOC_BASE,4>;
		using addr0 = Gpio<GPIOC_BASE,0>;           //
		using addr1 = Gpio<GPIOC_BASE,1>;           //
	}//namespace psd1

	namespace psd2{
		using cs = Gpio<GPIOC_BASE,5>;
		using addr0 = Gpio<GPIOC_BASE,2>;           //
		using addr1 = Gpio<GPIOC_BASE,3>;           //
	}//namespace psd2

	namespace mpu1{
		using cs =  Gpio<GPIOD_BASE,14>;
		using interrupt = Gpio<GPIOD_BASE,15>;
	}//namespace mpu1

	namespace mpu2{
		using cs =  Gpio<GPIOE_BASE,10>;
		using interrupt = Gpio<GPIOD_BASE,13>;

	}//namespace mpu2

	namespace temperature{
		using t_radiation = Gpio<GPIOC_BASE,14>; //il sensore di temperatura vicino a quello di radiazioni 
	}

	namespace battery{
		using power_good = Gpio<GPIOA_BASE,8>;
	}

	namespace adc{
		using cs1 = Gpio<GPIOE_BASE,11>;
		using cs2 = Gpio<GPIOE_BASE,13>;
		using cs3 = Gpio<GPIOE_BASE,12>;
	}

	

}//namespace  sensors

namespace powersave{

	namespace analog{
		using en = Gpio<GPIOE_BASE,0>;
	}//namespace analog

	namespace gps{
		using en = Gpio<GPIOE_BASE,2>;
	}//namespace gps

	namespace iridium{
		using en = Gpio<GPIOE_BASE,3>;
	}//namespace iridium

	namespace raspberry{
		using en = Gpio<GPIOE_BASE,6>;
		using keep_en = Gpio<GPIOB_BASE,0>;
	}//namespace raspberry

	namespace lora{
		using en = Gpio<GPIOC_BASE,13>;
	}//namespace lora

	namespace radiation{
		using en = Gpio<GPIOE_BASE,1>;
	}
}//namespace powersave

namespace actuators{

	namespace magnetorquer{
		using x = Gpio<GPIOA_BASE,0>;
		using xdir = Gpio<GPIOE_BASE,7>;
		using y = Gpio<GPIOA_BASE,1>;
		using ydir =Gpio<GPIOE_BASE,8>;
		using z = Gpio<GPIOA_BASE,2>;
		using zdir = Gpio<GPIOE_BASE,9>;
	}//namespace magnetorquer

	namespace heater{
		using battery = Gpio<GPIOC_BASE,8>;
	}//namespace heater

	namespace watchdog{
		using watchdog = Gpio<GPIOB_BASE,5>;
		using watchdog_TMTC = Gpio<GPIOD_BASE,12>;
	}//namespace watchdog

	namespace iridium{
	using cts2 = Gpio<GPIOD_BASE,3>;    // CLEAR TO SEND
	using rts2 = Gpio<GPIOD_BASE,4>;    // REQUEST TO SEND
	using dcd = Gpio<GPIOD_BASE,0>;     // SBD DCD- CAN1?
	using dsr = Gpio<GPIOD_BASE,1>;     // SBD DSR- CAN1?
	using dtr = Gpio<GPIOD_BASE,2>;     // SBD DTR?
	using onOff = Gpio<GPIOD_BASE,7>;	//SBD ON/OFF
	using ri = Gpio<GPIOE_BASE,14>;     //
	using net = Gpio<GPIOE_BASE,15>;    //
	}//namespace iridium

	namespace lora
	{
		using cs = Gpio<GPIOE_BASE,5>;
	}//namespace lora
	
}//namespace actuators


} //namespace miosix

#endif //HWMAPPING_H
