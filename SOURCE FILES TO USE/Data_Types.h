/* Made by Stamp    */





//*******************************************    DATI IMU  *********************************************

typedef union {         // Struttura ImuSample che contiene i dati Imu.
    struct              // Forse ACDS preferisce avere i quaternioni - c'è da vedere come ottenerli.
    {
        struct accelerometer
        {
            float x;
            float y;
            float z;
        }
        struct gyroscope
        {
            float x;
            float y;
            float z;
        }
        struct magnetometer
        {
            float x;
            float y;
            float z;
        }

        float temperature;

    } 

    float vector[10];       // Secondo modo di indirizzarsi alla stessa struttura: vettore.
                            //3acc,3gyro,3Magn,1Temp


} ImuSample_t;



/************************************************ DATI **********************************************************/


typedef union {    		// Struttura ImuSample che contiene i dati Imu.
	
} GPSSample_t;