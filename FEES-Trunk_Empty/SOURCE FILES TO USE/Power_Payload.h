/*  In This Header File a list of Basic Funcions for Powering the payloads is defined.  (Prototypes)
*
*   Made by Stefano Ampolo (STAMP in Art)
*/

#ifndef Power_Payload
#define Power_Payload


void System_Reboot();  
/* Da scrivere qui una routine che spenga prima tutti i devices-Payloads,
*  Salvi in memoria FeRam (statica) tutto il buffer-ram e poi faccia un restart della STM32.
*  
* Analog_PowerOff();
* GPS_PowerOff();
* Lora_PowerOff();
* Iridium_PowerOff();
* Radex_PowerOff();
*
* -> Memory Save --> RamBuffer
* Watchdog (?)
* return0;
*/


/*********************************** Analog_DEVICES-PAYLOAD ***********(PE0)*********************/

void Analog_PowerOn();
void Analog_PowerOff();
void Analog_Reset();


/*********************************** GPS DEVICE-PAYLOAD ***********(PE2)*********************/
void GPS_Reset();
void GPS_PowerOn();
void GPS_PowerOff();

/*********************************** LORA DEVICE-PAYLOAD *********(PC13)********************/
void Lora_PowerOn(); 
void Lora_PowerOff();
void Lora_Reset();

/********************************* Iridium Trasmitter PAYLOAD *********(PE3)***************/
void Iridium_Reset();
void Iridium_PowerOn();
void Iridium_PowerOff();


/*********************************** RAD-Experiment PAYLOAD ***********(PE1)***************/
void Radex_PowerOff();
void Radex_PowerOn();
void Radex_Reset();


#endif
