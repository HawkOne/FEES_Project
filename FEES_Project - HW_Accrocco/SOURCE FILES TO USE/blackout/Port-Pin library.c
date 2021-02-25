
void pintoggle(char port , int pin){

GPIO_TypeDef* PORT__BASE;

switch (port){
	case a: PORT__BASE = GPIOA;
	break;
	case b: PORT__BASE = GPIOB;
	break;
	case c: PORT__BASE = GPIOC;
	break;
	case d: PORT__BASE = GPIOD;
	break;
	case e: PORT__BASE = GPIOE;
	break;

	default: PORT__BASE = GPIOA;
	break;
	}

uint16_t pin_number=0;


switch (pin){
	case 0: pin_number = 0x0001;
	break;
	case 1: pin_number = 0x0002;
	break;
	case 2: pin_number = 0x0004;
	break;
	case 3: pin_number = 0x0008;
	break;
	case 4: pin_number = 0x0010;
	break;
	case 5: pin_number = 0x0020;
	break;
	case 6: pin_number = 0x0040;
	break;
	case 7: pin_number = 0x0080;
	break;
	case 8: pin_number = 0x0100;
	break;
	case 9: pin_number = 0x0200;
	break;
	case 10: pin_number = 0x0400;
	break;
	case 11: pin_number = 0x0800;
	break;
	case 12: pin_number = 0x1000;
	break;
	case 13: pin_number = 0x2000;
	break;
	case 14: pin_number = 0x4000;
	break;
	case 15: pin_number = 0x8000;
	break;


	default:  = in_number = 0x0001;
	break;
	}

	HAL_GPIO_WritePin(PORT__BASE, pin_number, 1);
    HAL_Delay(100);
    HAL_GPIO_WritePin(PORT__BASE, pin_number, 0);
    HAL_Delay(100);

}