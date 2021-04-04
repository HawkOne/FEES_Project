

//------- COMPILING SETTINGS ----------//

//#define WINDOWS
//#define LINUX

//#define ARDUPILOT
//#define FREERTOS
//#define CHIBIOS

#define BAREMETAL  //ST's HAL LIBRARIES
#define FREERTOS

//#define UNIT_TESTING

//------- ------- ------- ------ ----- //

  #ifdef WINDOWS
  #endif // WINDOWS
  #ifdef LINUX
  #endif // LINUX
  #ifdef ARDUPILOT
  #endif // ARDUPILOT
  #ifdef FREERTOS
  #endif // FREERTOS
  #ifdef CHIBIOS
  #endif // CHIBIOS
  #ifdef BAREMETAL
  #endif // BAREMETAL
  #ifdef UNIT_TESTING
  #endif // UNIT_TESTING




void FEES_print(int a , uint8_t PrintBuffer[20] ){

  switch(a){
  case default:   HAL_UART_Transmit(&huart2, PrintBuffer, 20, 100);
        break;
        case 1:  HAL_UART_Transmit(&huart1, PrintBuffer, 20, 100);
        break;
        case 2:  HAL_UART_Transmit(&huart2, PrintBuffer, 20, 100);
        break;
        case 3:  HAL_UART_Transmit(&huart3, PrintBuffer, 20, 100);
        break;
        case 4:  HAL_UART_Transmit(&huart6, PrintBuffer, 20, 100);
        break;
        case 6:  HAL_UART_Transmit(&huart6, PrintBuffer, 20, 100);
        break;
    }
}





void FEES_print(2 , " Stocazzo " );



void FEES_Delay( int a){
  #ifdef WINDOWS
  std::this_thread::sleep_for(std::chrono::milliseconds(a));
  #endif // WINDOWS

  #ifdef FREERTOS
  osDelay(a);
  #endif // FREERTOS
}






  FEES_print( 2 ,  "\n ");
