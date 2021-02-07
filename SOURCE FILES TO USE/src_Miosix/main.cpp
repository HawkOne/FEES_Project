#include <cstdio>
#include <miosix.h>
#include <pthread.h>
#include "arch/cortexM4_stm32f4/stm32f407vg_fees/interfaces-impl/hwmapping.h"
#include <iostream>
#include <string>
#include "Headers/BasicFunctions.h"


//#include "src/USB VIRTUAL COM LIBRARY ST/tm_stm32f4_usb_vcp.h"
//#include "mxusb-master/usb.h"
//#include "mxusb-master/config/usb_config.h"
//#include "mxusb-master/config/usb_gpio.h"


using namespace std;
using namespace miosix;


bool PowerVector[10];
bool CSVector[10];


int main() {
    
    //  USB_OTG_SPEED::USB_SPEED_FULL;
    

    printf("\n FEES - StarSystem - Booting Up! \n \n");
    lowPowerMask();
    buzzerStartup();
    
    
    gpios::led_blue::low();
    usleep(500000);
    gpios::led_blue::high();
   
    pthread_t ThreadWatchdog;
    pthread_create(&ThreadWatchdog,NULL,watchdogHandler,NULL);
    
    //  pthread_t ThreadBuzzer;
    //  pthread_create(&ThreadBuzzer,NULL,buzzer,NULL);

    //  pthread_t ThreadSeriale;
    //  pthread_create(&ThreadSeriale, NULL, seriale3Test, NULL);
    

    while (1) {
        menu();
    }
}
