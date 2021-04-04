/*
*
* Created by: Matteo Franceschini
*
*/
#include <iostream>
#include <cstdint>

using namespace std;


/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*/
/*°°°°  MAIN FINITE STATE MACHINE °°°*/
/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*/

enum main_fsm_state
{       rocket_idle, 		//stato in cui il CUBESAT è all'interno del vettore, ed entrambi gli switch sono connessi. La disconnessione dei connettori ci fa cambiare stato
		init_wait, 			//stato in cui il CUBESAT è appena uscito dal launcher, ma dobbiamo stare in silenzio radio: un timer ci farà passare nel prossimo stato
		nominal,   			//stato in cui il CUBESAT è per la maggior parte del tempo, in cui tutto funziona normalmente
		transmission, 		//stato in cui spengo tutto ciò che non è necessario e trasmetto i dati
		safe 				//stato di recupero da una anomalia
};

main_fsm_state current_state=rocket_idle;
main_fsm_state next_state=rocket_idle; 



/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*/
/*°°°°°     MAIN RAM BUFFER      °°°°*/
/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*/

//Struttura di 4 byte (ingrandibile a piacimento) che contiene tutti i flag necessari per l'attivazione delle periferiche e la segnalazione di stati
typedef union
{
    struct
    {
        /*BYTE DI SISTEMA*/
        unsigned detached         :1;  //segnala se siamo stati staccati dal missile,
        unsigned orientation_ok   :1;  //segnala se non c'è bisogno di un cambiamento di orientamento, per allineare i pannelli al sole
        unsigned connection_req   :1;  //segnala che siamo sopra alla ground station e c'è stata una richiesta di connessione
        unsigned system_nominal   :1;  //segnala che tutto è ok, se questo bit si muove a zero, il sistema va in safe mode.
        unsigned watchdog_reset   :1;  //segnala che è passato un intervallo sufficientemente lungo da richiedere un reset del watchdog esterno
        unsigned battery_charging :1;  //segnala che la batteria è in fase di caricamento
        unsigned antenna_deployed :1;  //segnala che l'antenna è stata fatta uscire
        unsigned                  :1;  //indefinito, non ancora utilizzato
	//unsigned system_state :2 - Al posto di system_nominal e del bit non utilizzato , usare 2 bit di sistema per gestire 4 stati: Nominal - Trasmission - Safe ed Extra (DA IMPLEMENTARE)		:1  - Proposta STAMP
	   
        /*BYTE DEI SENSORI*/
        unsigned imu1_to_sample     :1; //segnala che la imu1 è da campionare appena possibile
        unsigned imu2_to_sample     :1; //segnala che la imu2 è da campionare appena possibile
        unsigned gps_to_sample      :1; //segnala che il gps è da campionare appena possibile
        unsigned temps_to_sample    :1; //segnala che i sensori di temperatura sono da campionare appena possibile
        unsigned photo_to_sample    :1; //segnala che i sensori di sole (matrice) sono da campionare appena possibile
        unsigned                    :3; //indefiniti, non ancora utilizzati
         
        /*BYTE ENABLE DEI PAYLOAD*/
        unsigned iridium_en         :1; //segnala che il payload iridium è abilitato
        unsigned raspberry_en       :1; //segnala che il payload raspberry è abilitato
        unsigned radex_en           :1; //segnala che il payload radex è abilitato
	    
        /*EXTRA BYTE (da definire)*/
        unsigned                  :8; //
	//Proposta STAMP
	//unsigned battery_state 	:2 - Con 2 bit possiamo gestire 4 intervalli di carica della batteria 0-25% 25-50% 50-75% 75-100%
	//unsigned 			:6 indefiniti - non ancora utilizzati
		    
    } __attribute__((packed)) bitfield;
    uint8_t flags[4]; //posso leggere lo struct come se fosse un array di 4 byte
    uint32_t flags32; //per leggerli tutti come un numero unico
}flagfield_t;





typedef struct FixedRam
{
    flagfield_t master_flags;   //contiene tutti i flag di sistema
    ImuSample_t Imu1Sample;		//contiene gli ultimi campioni della prima imu
    ImuSample_t Imu2Sample;		//contiene gli ultimi campioni della seconda imu
    


    //aggiungere tutti gli altri ultimi campioni
    
    

}FixedRam_t;


FixedRam_t ram_data;

#define master_bitfield ram_data.master_flags.bitfield  ///> define per semplificare l'uso dei bit e aumentare la leggibilità

/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*/
/*°°°°°       TEST EVENTS        °°°°*/
/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*/

uint8_t event=255;
static const uint8_t detached='0';
static const uint8_t ok_for_nominal='1';
static const uint8_t transmission_needed='2'; //"GroundStationBeaconFound"
static const uint8_t problem_detected='3';
static const uint8_t reboot_needed = '4';



int main(int argc, char** argv)
{
    cout<<"Main started"<<endl;
    cout<<"FLAGS: "<<ram_data.master_flags.flags32<<endl<<endl; //stampo tutti i flag
    uint8_t no_reboot=1;
	while(no_reboot)
	{

		switch(current_state)
		{
            case rocket_idle:
                    if(event==detached)
                    {
                        master_bitfield.detached=true;
                        cout<<"Detaching status:"<<master_bitfield.detached<<endl<<"CHANGING STATUS."<<endl;
                        next_state=init_wait;
                    }
                    else
                    {
                         cout<<"Idle_state"<<endl;
                         cout<<"Detaching status:"<<master_bitfield.detached<<endl;
                         cout<<"press "<<detached<<" to detach\n"<<endl;//doppio a capo per distanziare
                         cin>>event;
                    }
                    break;
	        case init_wait:
                     if(event==ok_for_nominal)
                     {
                         master_bitfield.system_nominal=true;
                         cout<<"SYSTEM_STATUS:"<<master_bitfield.system_nominal<<endl<<"CHANGING STATUS."<<endl;
                         next_state=nominal;
                     }
                     else
                     {
                         cout<<"Init_wait_state"<<endl;
                         cout<<"SYSTEM_STATUS:"<<master_bitfield.system_nominal<<endl;
                         cout<<"press "<<ok_for_nominal<<" for nominal state\n"<<endl;//doppio a capo per distanziare
                         cin>>event;
                     }
	                break;
	        case nominal:
			    if(event==transmission_needed) 
				    next_state=transmission;
			     else if(event==problem_detected)
				    next_state=safe;
				 else
				{
					cout<<"Nominal_state"<<endl;
					cout<<"FLAGS:"<<ram_data.master_flags.flags32<<endl;
					cout<<"press "<<problem_detected<<" to safe mode or "<<transmission_needed<<" to transmit\n"<<endl;//doppio a capo per distanziare
					cin>>event;
				}
	       break;
            case transmission:
                    	if(event==ok_for_nominal)
                        	next_state=nominal;
                    	else if(event==problem_detected)
                        	next_state=safe;
                   	else
                    	{
                    		cout<<"Transmission_state"<<endl;
                    		cout<<"press "<<ok_for_nominal<<" for nominal state\n"<<endl;//doppio a capo per distanziare
                    		cin>>event;
                    	}
	        break;
            case safe:
                    	if(event==ok_for_nominal)
                        	next_state=nominal;
                   	else if(event==reboot_needed)
                        	no_reboot=0;
			else
                    	{
                    		cout<<"Safe_state"<<endl;
                    	  	cout<<"press "<<ok_for_nominal<<" for nominal state or "<<reboot_needed<<" to reboot\n"<<endl;//doppio a capo per distanziare
                      		cin>>event;
                    	}

	        break;
	    default: ///ATTENZIONE: RISCHIO DI BOOTLOOP! @fixme
			next_state=safe;
			event=reboot_needed;
	       break;
	       }
	   current_state=next_state;

	}


 //SystemReboot();
return 0;
}
