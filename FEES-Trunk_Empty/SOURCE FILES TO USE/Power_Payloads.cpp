/*  In this file a list of Basic Funcions for Powering the payloads is defined.
*
*   Made by Stefano Ampolo (STAMP in Art)
*/


void System_Reboot()
{
/* Da scrivere qui una routine che spenga prima tutti i devices-Payloads,
*  Salvi in memoria FeRam (statica) tutto il buffer-ram e poi faccia un restart della STM32.
*/

	Analog_PowerOff();
	GPS_PowerOff();
	Lora_PowerOff();
	Iridium_PowerOff();
	Radex_PowerOff();

// DA AGGIUNGERE:
//--> Memory Save --> RamBuffer
//Watchdog (?)
	return 0;
}



/*********************************** Analog_DEVICES-PAYLOAD ***********(PE0)*********************/

void Analog_PowerOn()
{	
	ANOLOG_POWER_ON::high();	//Da alimentazione ai sensori Analogici		(PE0=1)
}

void Analog_PowerOff()
{	
	ANALOG_POWER_ON::low():		//Toglie l'alimentazione ai S.Analogici   	(PE0=0)	
}

void Analog_Reset()
{	
	Analog_PowerOff();
	Thread::sleep(2000);  		//wait 2 secondi
	Analog_PowerOn();
}


/*********************************** GPS DEVICE-PAYLOAD ***********(PE2)*********************/

void GPS_PowerOn()
{
	GPS_POWER_ON::high():		//Da alimentazione al modulo GPS 			(PE2=1)	
}

void GPS_PowerOff()
{	
	GPS_POWER_ON::low()			//Toglie l'alimentazione al modulo GPS   	(PE2=0)			
}

void GPS_Reset()
{	GPS_PowerOff();
	Thread::sleep(2000);  		//wait 2 secondi
	GPS_PowerOn();
}

/*********************************** LORA DEVICE-PAYLOAD *********(PC13)********************/
void Lora_PowerOn()
{	
	UHF_RESET::high();			//Da alimentazione al modulo TMTC-LORA  	(PC13=1)
}

void Lora_PowerOff()
{	
	UHF_RESET::low():			//Toglie l'alimentazione al modulo TMTC  	(PC13=0)
}

void Lora_Reset()
{	
	Lora_PowerOff():
	Thread::sleep(2000);  		//wait 2 secondi
	Lora_PowerOn();
}


/********************************* Iridium Trasmitter PAYLOAD *********(PE3)***************/
void Iridium_PowerOn()
{
	SBD_POWER_ON::high();		//Da alimentazione al modulo IRIDIUM  		(PE3=1)
}

void Iridium_PowerOff()
{
	SBD_POWER_ON::high();		//Toglie l'alimentazione al modulo IRIDIUM  (PE3=0)
}

void Iridium_Reset()
{
	Iridium_PowerOff():
	Thread::sleep(2000);  		//wait 2 secondi
	Iridium_PowerOn():
}

/*********************************** RAD-Experiment PAYLOAD ***********(PE1)***************/
void Radex_PowerOn()
{
	RAD_POWER_ON::high();  		//Da alimentazione al RADEX 				(PE1 =1)
	RADFET_RESET::high();		//Fa partire l'ADC 32bit del RADEX 			(PC15=1)
}

void Radex_PowerOff()
{
	RAD_POWER_ON::low();		//Spegne alimentazione al RADEX 			(PE1 =0)
	RADFET_RESET::low();		//Spegne l' ADC 32bit del RADEX 			(PC15=0)

}

void Radex_Reset()
{
	Radex_PowerOff();			// (PE1=0) e (PC15=0)
	Thread::sleep(2000);
	Radex_PowerOn();			// (PE1=1) e (PC15=1)
}
