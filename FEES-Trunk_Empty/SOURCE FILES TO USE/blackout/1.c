/* Private defines -----------------------------------------------------------*/
#define GPS_PWR_ON_Pin GPIO_PIN_2
#define GPS_PWR_ON_GPIO_Port GPIOE
#define SBD_PWR_ON_Pin GPIO_PIN_3
#define SBD_PWR_ON_GPIO_Port GPIOE
#define CS_NAND_Pin GPIO_PIN_4
#define CS_NAND_GPIO_Port GPIOE
#define LORA_CS_Pin GPIO_PIN_5
#define LORA_CS_GPIO_Port GPIOE
#define RSBY_ON_Pin GPIO_PIN_6
#define RSBY_ON_GPIO_Port GPIOE
#define UHF_RESET_Pin GPIO_PIN_13
#define UHF_RESET_GPIO_Port GPIOC
#define RADFET_OWB_Pin GPIO_PIN_14
#define RADFET_OWB_GPIO_Port GPIOC
#define RAD_RESET_Pin GPIO_PIN_15
#define RAD_RESET_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define PSD1_SEL1_Pin GPIO_PIN_0
#define PSD1_SEL1_GPIO_Port GPIOC
#define PSD1_SEL0_Pin GPIO_PIN_1
#define PSD1_SEL0_GPIO_Port GPIOC
#define PSD2_SEL1_Pin GPIO_PIN_2
#define PSD2_SEL1_GPIO_Port GPIOC
#define PSD2_SEL0_Pin GPIO_PIN_3
#define PSD2_SEL0_GPIO_Port GPIOC
#define PWM_X_COIL_Pin GPIO_PIN_0
#define PWM_X_COIL_GPIO_Port GPIOA
#define PWM_Y_COIL_Pin GPIO_PIN_1
#define PWM_Y_COIL_GPIO_Port GPIOA
#define PWM_Z_COIL_Pin GPIO_PIN_2
#define PWM_Z_COIL_GPIO_Port GPIOA
#define EX_GPIO3_Pin GPIO_PIN_3
#define EX_GPIO3_GPIO_Port GPIOA
#define CS_RADFET_Pin GPIO_PIN_4
#define CS_RADFET_GPIO_Port GPIOA
#define PSD1_AMP_CS_Pin GPIO_PIN_4
#define PSD1_AMP_CS_GPIO_Port GPIOC
#define PSD2_AMP_CS_Pin GPIO_PIN_5
#define PSD2_AMP_CS_GPIO_Port GPIOC
#define RSBY_KEEP_EN_Pin GPIO_PIN_0
#define RSBY_KEEP_EN_GPIO_Port GPIOB
#define EX_GPIO1_Pin GPIO_PIN_1
#define EX_GPIO1_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define DIR_X_COIL_Pin GPIO_PIN_7
#define DIR_X_COIL_GPIO_Port GPIOE
#define DIR_Y_COIL_Pin GPIO_PIN_8
#define DIR_Y_COIL_GPIO_Port GPIOE
#define DIR_Z_COIL_Pin GPIO_PIN_9
#define DIR_Z_COIL_GPIO_Port GPIOE
#define CS_GYRO_Pin GPIO_PIN_10
#define CS_GYRO_GPIO_Port GPIOE
#define EN_ADC1_Pin GPIO_PIN_11
#define EN_ADC1_GPIO_Port GPIOE
#define EN_ADC3_Pin GPIO_PIN_12
#define EN_ADC3_GPIO_Port GPIOE
#define EN_ADC2_Pin GPIO_PIN_13
#define EN_ADC2_GPIO_Port GPIOE
#define SBD_SER_SI_Pin GPIO_PIN_14
#define SBD_SER_SI_GPIO_Port GPIOE
#define SBD_SER_NET_Pin GPIO_PIN_15
#define SBD_SER_NET_GPIO_Port GPIOE
#define EX_GPIO2_Pin GPIO_PIN_12
#define EX_GPIO2_GPIO_Port GPIOB
#define CS_EEPROM_Pin GPIO_PIN_10
#define CS_EEPROM_GPIO_Port GPIOD
#define CS_FRAM_Pin GPIO_PIN_11
#define CS_FRAM_GPIO_Port GPIOD
#define TMTC_MCU_WD_Pin GPIO_PIN_12
#define TMTC_MCU_WD_GPIO_Port GPIOD
#define INT_GYRO_Pin GPIO_PIN_13
#define INT_GYRO_GPIO_Port GPIOD
#define CS_GYRO2_Pin GPIO_PIN_14
#define CS_GYRO2_GPIO_Port GPIOD
#define INT_GYRO2_Pin GPIO_PIN_15
#define INT_GYRO2_GPIO_Port GPIOD
#define PWM_HEATER_Pin GPIO_PIN_8
#define PWM_HEATER_GPIO_Port GPIOC
#define EX_SPI_EN_Pin GPIO_PIN_9
#define EX_SPI_EN_GPIO_Port GPIOC
#define PGOOD_Pin GPIO_PIN_8
#define PGOOD_GPIO_Port GPIOA
#define VBUS_FS_Pin GPIO_PIN_9
#define VBUS_FS_GPIO_Port GPIOA
#define OTG_FS_ID_Pin GPIO_PIN_10
#define OTG_FS_ID_GPIO_Port GPIOA
#define OTG_FS_DM_Pin GPIO_PIN_11
#define OTG_FS_DM_GPIO_Port GPIOA
#define OTG_FS_DP_Pin GPIO_PIN_12
#define OTG_FS_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SBD_SER_DCD_Pin GPIO_PIN_0
#define SBD_SER_DCD_GPIO_Port GPIOD
#define SBD_SER_DSR_Pin GPIO_PIN_1
#define SBD_SER_DSR_GPIO_Port GPIOD
#define SBD_SER_DTR_Pin GPIO_PIN_2
#define SBD_SER_DTR_GPIO_Port GPIOD
#define SBD_ON_OFF_Pin GPIO_PIN_7
#define SBD_ON_OFF_GPIO_Port GPIOD
#define WATCHDOG_Pin GPIO_PIN_5
#define WATCHDOG_GPIO_Port GPIOB
#define ANA_PWR_ON_Pin GPIO_PIN_0
#define ANA_PWR_ON_GPIO_Port GPIOE
#define RAD_PWR_ON_Pin GPIO_PIN_1
#define RAD_PWR_ON_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */


// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI

#define    UHF_RESET    0
#define    GPS_PWR_ON    1
#define    ANA_PWR_ON    2
#define    RSBY_ON      3
#define    RSBY_KEEP_EN  4
#define    RAD_PWR_ON    5
#define    RAD_RESET    6

#define    PSD1_SEL0  7
#define    PSD1_SEL1  8
#define    PSD2_SEL0  9
#define    PSD2_SEL1  10

// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54

#define    PWM_X      PWM(1)
#define    PWM_X_COIL    11

#define    PWM_Y      PWM(2)
#define    PWM_Y_COIL    12

#define    PWM_Z      PWM(3)
#define    PWM_Z_COIL    13

#define    PWM_HEATER    PWM(4)
#define    PWM_HEATER     14

#define    DIR_X_COIL    15
#define    DIR_Y_COIL    16
#define    DIR_Z_COIL    17


#define    RADFET_OWB    18

#define    LED        19
#define    TMTC_MCU_WD    19

#define   WATCHDOG    20


// IRIDIUM - SBD (GPIO 60-68)

#define    SBD_PWR_ON    21  // Iridium Pwr On

#define    SBD_SER_DCD    22    // DCD
#define    SBD_SER_DSR    23    // DSR
#define    SBD_SER_DTR    24    // DTR
#define    SBD_SER_CTS   25    // CTS
#define    SBD_SER_RTS   26    // RTS
#define    SBD_SER_ON_OFF  27    // ON_OFF
#define    SBD_SER_RI    28    // RI
#define    SBD_SER_NET   29    // NET


#define EX_GPIO1  30
#define  EX_GPIO2  31
#define  EX_GPIO3  32
#define  EX_GPIO4  33



// POWER "INPUTS"
//  PGOOD -
//   VUSB  - ADC INTERNO + Termocoppia

//ADC ESTERNO
// I_ X,Y,Z COIL
// BATT_TEMP
// I_CELL_ +X,+Y,+Z,-X
// V_CELL_ +X,+Y+Z,-X
// V_CELL_ +Y_1


// Here Will come the definitions of the sensor drivers.

