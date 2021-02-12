while (1)
  {
  /* USER CODE END WHILE */

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);
    HAL_Delay(10);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0);
    HAL_Delay(10);


         // PWM_ CONTROL
    pintoggle('c',8);  // PWM_HEATER - BATTERY

    pintoggle('a',0);  // PWM_HEATER - BATTERY
    pintoggle('a',1);  // PWM_HEATER - BATTERY
    pintoggle('a',2);  // PWM_HEATER - BATTERY

         // GPIO DI DIREZIONE
    pintoggle('e',7); // Dir_X
    pintoggle('e',8); // Dir_Y
    pintoggle('e',9); // Dir_Z

      //GPIO DI CONTROLLO
    pintoggle('b',5); // WATCHDOG
    pintoggle('d',12);  // TMTC_WD
    pintoggle('e',0); // ANA_PWR_ON
    pintoggle('e',1); // RAD_PWR_ON
    pintoggle('e',3); // SBD_PWR_ON
    pintoggle('e',2); // GPS_PWR_ON
    pintoggle('e',6); // RSBY_PWR_ON
    pintoggle('b',0); // RSBY_KEEP_EN

         // GPIO DI DIREZIONE
    pintoggle('b',1); // EX_GPIO1
    pintoggle('b',12);  // EX_GPIO2
    pintoggle('a',3); // EX_GPIO3
    pintoggle('a',10);  // EX_GPIO4


         //CS_SPI_SENSORI
    pintoggle('e',5);   // CS_NAND
    pintoggle('e',4);   // CS_LORA
    pintoggle('a',4); // CS_RADFET
    pintoggle('e',11);  // EN_ADC1
    pintoggle('e',13);  // EN_ADC2
    pintoggle('e',12);  // EN_ADC3
    pintoggle('c',9);   // EXT_SPI_EN
    pintoggle('d',10);  // CS_EEPROM
    pintoggle('d',11);  // CS_FRAM
    pintoggle('c',4);   // CS_PSD1_AMP
    pintoggle('c',5);   // CS_PSD2_AMP
    pintoggle('e',10);  // CS_GYRO
    pintoggle('d',14);  // CS_GYRO2




    uint8_t BufferPrint1[20]={"UNOOOO 1!\n"};
    uint8_t BufferPrint2[20]={"DOS! 2!\n"};
    uint8_t BufferPrint3[20]={"TREs!  3!\n"};
    uint8_t BufferPrint6[20]={"666 666 666\n"};

    HAL_UART_Transmit(&huart1, BufferPrint1, 20, 100);
    HAL_Delay(10);

    HAL_UART_Transmit(&huart2, BufferPrint2, 20, 100);
    HAL_Delay(10);

    HAL_UART_Transmit(&huart3, BufferPrint3, 20, 100);
    HAL_Delay(10);

    HAL_UART_Transmit(&huart6, BufferPrint6, 20, 100);
    HAL_Delay(10);



    uint8_t Buffer[10]={ 0x0099, 0x0056, 0x0104,0x4255,0x0045,0x0043,0x0043,0x0043,0x0043,0x0055};

    HAL_I2C_Init(&hi2c1);
    HAL_I2C_Init(&hi2c2);

    HAL_I2C_Master_Transmit(&hi2c1, 0x0123, Buffer, 10, 100);
    HAL_Delay(10);
    HAL_I2C_Master_Transmit(&hi2c2, 0x0123, Buffer, 10, 100);
    HAL_Delay(10);

    HAL_SPI_Init(&hspi1);
    HAL_SPI_Init(&hspi2);
    HAL_SPI_Init(&hspi3);


    HAL_SPI_Transmit(&hspi1, Buffer, 10, 100);
    HAL_Delay(10);
    HAL_SPI_Transmit(&hspi2, Buffer, 10, 100);
    HAL_Delay(10);
    HAL_SPI_Transmit(&hspi3, Buffer, 10, 100);
    HAL_Delay(10);







//      // Communication busses pins
//                 // UART _ BUS
//    pintoggle('b',6);  // UART_1_TX GPS
//    pintoggle('b',7);  // UART_1_RX
//
//    pintoggle('d',5);  // UART_2_TX SBD
//    pintoggle('d',6);  // UART_2_RX
//
//    pintoggle('d',8);  // UART_3_TX CONSOLE SERIALE
//    pintoggle('d',9);  // UART_3_RX
//
//    pintoggle('c',6);  // UART_6_TX SDR
//    pintoggle('c',7);  // UART_6_RX
//
//        // SPI  BUSSES
//          // SPI_1
//    pintoggle('a',6);  // SPI_1_MISO
//    pintoggle('a',7);  // SPI_1_MOSI
//    pintoggle('a',5);  // SPI_1_SCK
//          // SPI_2
//    pintoggle('b',14);  // SPI_2_MISO
//    pintoggle('b',15);  // SPI_2_MOSI
//    pintoggle('b',13);  // SPI_2_SCK
//          // SPI_3
//    pintoggle('c',11);  // SPI_3_MISO
//    pintoggle('c',12);  // SPI_3_MOSI
//    pintoggle('c',10);  // SPI_3_SCK
//
//
//        // I2C  BUSSES
//          // I2C_1
//    pintoggle('b',10);  // SCL
//    pintoggle('b',11);  // SDA
//          // I2C_2
//    pintoggle('b',8);  // SCL2
//    pintoggle('b',9);  // SDA2


      /* USER CODE BEGIN 3 */
    }
      /* USER CODE END 3 */
}
