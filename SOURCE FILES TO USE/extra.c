




#define Normal_MODE
//#define UNIT_TESTING



// FOR EXAMPLE  - BATTERY_PID_CONTROL



//                                                -5                  +2
int BATTERY_PID_CONTROL(int actual_temp, int Limit_temp_LOW, int Limit_temp_HIGH) {

#ifdef Normal_MODE
  if(actual_temp<Limit_temp_LOW){
   turn_ON_BatteryPWM;
  }

  if(actual_temp>Limit_temp_HIGH){
   turn_OFF_BatteryPWM;
  }
#endif


#ifdef UNIT_TESTING
  if(actual_temp<Limit_temp_LOW){
   printf("PWM_BATTERY HAS BEEN TURNED ON\n");
  }

  if(actual_temp>Limit_temp_HIGH){
  printf("PWM_BATTERY HAS BEEN TURNED OFF\n");
   }
#endif

}




//main.c

while(1){
  float temp;
    temp= readbatttemp();
    BATTERY_PID_CONTROL( temp , -5 , +2);

    #ifdef UNIT_TESTING
    // here I check if it actually has been turned on

    printf("PWM_BATTERY HAS BEEN TURNED OFF\n");


  #endif

}





// In test_my_sum.c
int main(int argc, char *argv[]) {
  assert(2 == my_sum(1, 1));
  assert(-2 == my_sum(-1, -1));
  assert(0 == my_sum(0, 0));
  // ...
  return(0);
}