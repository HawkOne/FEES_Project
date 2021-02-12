/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasicFunctions.h
 * Author: Stefano
 *
 * Created on April 20, 2018, 9:59 PM
 */

#ifndef BASICFUNCTIONS_H
#define BASICFUNCTIONS_H


#include <cstdio>
#include <miosix.h>
#include <pthread.h>
#include "arch/cortexM4_stm32f4/stm32f407vg_fees/interfaces-impl/hwmapping.h"
#include <iostream>
#include <string>
#include "Headers/BasicFunctions.h"

using namespace std;
using namespace miosix;
using namespace gpios;


void SOS_Morse();
void* ledRapido(void*);
void* ledLento(void*);

void* seriale3Test(void*);
void watchdogUpdate();
void* watchdogHandler(void*);
void lowPowerMask();
void buzzerStartup();
void buzzerWatchdogUpdate();
void menu();
void esperimentoPowerAnalog();

void spiSend(unsigned char byte) {
    SPI1->DR = byte;
    while ((SPI1->SR & SPI_SR_RXNE) == 0); //Wait
    byte = SPI1->DR; // DummyREAD
}

unsigned char spiRecive() {
    SPI1->DR = 0;
    while ((SPI1->SR & SPI_SR_RXNE) == 0); // Wait
    return SPI1->DR;
}

void menu() {
    char a[1];
    printf("\n"
            "*********************************************************** \n"
            "*** *** *** - Benvenuto nel Menu di testing! -* *** *** *** \n"
            "*********************************************************** \n"
            "*** *** Quale test vuoi avviare? ** *** *** *** *** *** *** \n"
            "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** \n"
            "*** ***  --> I test disponibili sono:   *** *** *** *** *** \n"
            "*********************************************************** \n"
            "*** - 0 -    Analog Power Test    - 0 -                 *** \n"
            "*** - 1 -    Watchdog             - 1 -                 *** \n"
            "*** - 2 -    Test Imu-SPI         - 2 -                 *** \n"
            "*** - 3 -    BOOT THE BOOTLOADER  - 3 -                 *** \n"
            "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** \n"
            "*********************************************************** \n"
            );
    cin>>a;
    switch (a[0]) {
        case '0':
            printf(" Welcome to : Esperimento Power Analog! \n");
            esperimentoPowerAnalog();
            break;

        case '1':
            printf(" Esperimento non ancora disponibile \n");
            break;

        case '2':
            printf(" Il Test Imu-SPI sarà implementato a breve! \n");
            break;

        case '3':
            printf(" Loading Bootloader! \n");
            bootLoader();
            break;

        default:
            printf(" La scelta inserita non e' corretta. \n");
            break;
    }
}

void bootLoader() {
    goto 0x1FFF77DE;
}

void reboot(){
	goto 0x08000000;
}

void esperimentoPowerAnalog() {
    char a[1];
    while (1) {
        printf(" Cosa vuoi fare? a - Accendi , s - Spegni , e - Esci , r - REBOOT\n");
        scanf("%s", a);
        //cin>>a;

        switch (a[0]) {
            case 'a':
                powersave::analog::en::high(); //Accendo l'Analog
                gpios::led_blue::low();
                printf(" Analog Power ON! \n");
                break;

            case's':
                powersave::analog::en::low(); //Spengo l'Analog
                gpios::led_blue::high();
                printf(" Analog Power OFF! \n");
                break;

            case 'e':
                printf(" Uscita dall'esperimento, ritorno al menu. \n");
                return;

            case 'r':
                printf(" Reboooooooooooooting! \n");
				reboot();
				return;

            default:
                printf("Non e' stato inserito nulla di corretto! \n"
                        "I comandi disponibili sono: - a , s , e -\n");
                break;

        }
    }
}

void* seriale3Test(void*) {
    while (1) {
        printf("Acceso da: %llu ticks \n ", getTick());
        usleep(1000000); // wait 1 secondo.
    }
}

/*
void SOS_Morse() {
    led::low();
    usleep(100000);
    led::high();
    usleep(100000);
    led::low();
    usleep(100000);
    led::high();
    usleep(100000);
    led::low();
    usleep(100000);
    led::high();

    usleep(100000);
    led::low();
    usleep(300000);
    led::high();
    usleep(100000);
    led::low();
    usleep(300000);
    led::high();
    usleep(100000);
    led::low();
    usleep(300000);
    led::high();
    usleep(100000);


    led::low();
    usleep(100000);
    led::high();
    usleep(100000);
    led::low();
    usleep(100000);
    led::high();
    usleep(100000);
    led::low();
    usleep(100000);
    led::high();
    usleep(3000000);

}
 */

void watchdogUpdate() {

    actuators::watchdog::watchdog::high();
    usleep(10000);
    actuators::watchdog::watchdog::low();
    sleep(10000);
    actuators::watchdog::watchdog::high();
    printf("\n  WatchDog Update - Fatto! \n");
    buzzerWatchdogUpdate();

}

void* watchdogHandler(void*) {
    while (1) {
        watchdogUpdate();
        Thread::sleep(60000);
    }
}

void* ledRapido(void*) {
    for (;;) {
        gpios::led_blue::low();
        usleep(100000);
        gpios::led_blue::high();
        usleep(100000);
    }

}

void* ledLento(void*) {
    for (;;) {
        gpios::led_blue::low();
        usleep(500000);
        gpios::led_blue::high();
        usleep(500000);
    }

}

void buzzerStartup() {
    for (int i = 0; i < 500; i++) {
        gpios::gpio1::high();
        usleep(5000);
        gpios::gpio1::low();
        usleep(5000);
    }
}

void buzzerWatchdogUpdate() {
    for (int i = 0; i < 500; i++) {
        gpios::gpio1::high();
        usleep(500);
        gpios::gpio1::low();
        usleep(500);
    }
}

void lowPowerMask() {

    /*******************************************************************************
     * lowPowerPinMask e' la Maschera standard che l'STM32F407vgt6 deve assumere   *
     * nell'ambito del progetto FEES per fare in modo che il consumo di corrente   *
     * sia il minimo possibile, essa infatti rappresenta una situazione standard   *
     * in cui il microcontrollore spegne effettivamente tutto, e imposta i segnali *
     * sui chip select e sui bus in modo che le resistenze di pull-up/down dei bus *
     * siano alla stessa tensione in modo da avere zero corrente passante.         *
     *                                                                             *
     ******************************************************************************/

    using namespace sensors;
    external_device::cs::high();

    using namespace powersave;
    //analog::en::low(); //spengo l'analogica
    analog::en::high(); //Provo ad accendere l'analog  -->TEST


    gps::en::low(); //spengo il gps
    iridium::en::low(); //spengo l'iridium
    raspberry::en::low(); //spengo il raspberry
    lora::en::low(); //spengo il lora
    radiation::en::low(); //spengo il sensore di radiazioni

    using namespace interfaces;
    // imposto i chip select di tutti i device sulla SPI ALTI.
    sck1::low();
    miso1::low();
    mosi1::low();

    sck2::low();
    miso2::low();
    mosi2::low();

    sck3::low();
    miso3::low();
    mosi3::low();

    u6tx::low();
    u6rx::low();

    using namespace memories;

    eeprom::cs::high();
    fram::cs::high();
    nand::cs::high();

    using namespace sensors;

    external_device::cs::high();
    radfet::cs::high();
    radfet::reset::low(); // Spengo l'adc 32 bit
    mpu1::cs::high();
    mpu2::cs::high();
    temperature::t_radiation::low();


    adc::cs1::high();
    adc::cs2::high();
    adc::cs3::high();

    sda1::mode(Mode::OUTPUT);
    scl1::mode(Mode::OUTPUT);

    sda2::mode(Mode::OUTPUT);
    scl2::mode(Mode::OUTPUT);

    sda1::high();
    scl1::high();

    sda2::high();
    scl2::high();

    using namespace gpios;

    gpio1::low();
    gpio2::low();
    gpio3::low();
    gpio4::low();
    gpios::led_blue::high(); // Led acceso basso!

    printf(" - BootMask LOW POWER impostata - \n");

}


#endif /* BASICFUNCTIONS_H */

