/*
  WatchDog "driver"
*/
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "WatchDog.h"

#include <AP_HAL/AP_HAL.h>
#include "ch.h"
 


WatchDog::WatchDog(){
    hal.gpio->pinMode(0, HAL_GPIO_OUTPUT);
    on(false);
}

WatchDog::WatchDog(int a){
    hal.gpio->pinMode(a, HAL_GPIO_OUTPUT);
    on(false);
    this->_pin=a;
}


WatchDog::WatchDog(int a , bool b){
    hal.gpio->pinMode(a, HAL_GPIO_OUTPUT);
    on(b);
    this->_pin=a;
    this->_state=b;
}


void WatchDog::update(void){
  
  hal.gpio->write(WatchDogPin, 0 );
  /* Delay of 250 milliseconds.*/
  chThdSleepMilliseconds(250);
  hal.gpio->write(WatchDogPin, 1 );
  /* Delay of 250 milliseconds.*/
  chThdSleepMilliseconds(250);
}


void WatchDog::toggle(void){
  if(this->_state==1){
    hal.gpio->write(WatchDogPin, 0 );
  }
  else{
    hal.gpio->write(WatchDogPin, 1 );
  }
}