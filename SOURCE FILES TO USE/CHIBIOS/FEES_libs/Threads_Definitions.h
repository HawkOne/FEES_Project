/*
 * Threads_Definitions.h
 *
 *  Created on: 19/ott/2018
 *      Author: Stefano
 */

#ifndef THREADS_DEFINITIONS_H_
#define THREADS_DEFINITIONS_H_

/* This is a periodic thread that flashes the LED. */
static THD_WORKING_AREA(Blinker_wa, 128);
static THD_FUNCTION(Blinker, arg)
{
  (void)arg;
  chRegSetThreadName("Blinker");
  while (1)
  	  {
	  palToggleLine(LINE_LED_BLUE);
	  chThdSleepMilliseconds(500);
      palToggleLine(LINE_LED_BLUE);
	  chThdSleepMilliseconds(500);
  	  }
}
/*====================================================*/

/* This is a periodic thread Updates the Watchdog (every 30 seconds) DefaultHigh */
static THD_WORKING_AREA(WatchdogUpdater_wa, 128);
static THD_FUNCTION(WatchdogUpdater, arg)
{
  (void)arg;
  chRegSetThreadName("WatchdogUpdater");
  while (1)
  	  {
	  palSetLine(PAL_LINE(GPIOB, GPIOB_WATCHDOG));
	  chThdSleepMilliseconds(30000);
	  palClearLine(PAL_LINE(GPIOB, GPIOB_WATCHDOG));
	  chThdSleepMilliseconds(1);
  	  }
}
/*====================================================*/






/////////////////////// TEST THREADS ////////////////////////
/* This is a thread for the buzzer. // GPIO 3 - FUNZIONA */
static THD_WORKING_AREA(TestBuzzer_wa, 128);
static THD_FUNCTION(TestBuzzer, arg)
{
  (void)arg;
  chRegSetThreadName("TestBuzzer");
  while (1)
  	  {
	  palToggleLine(PAL_LINE(GPIOA, GPIOA_EX_GPIO3));
	  chThdSleepMilliseconds(2);
	  palToggleLine(PAL_LINE(GPIOA, GPIOA_EX_GPIO3));
	  chThdSleepMilliseconds(2);
  	  }
}
//////////////////////////////////////////////////////////////

/* This is a thread that flashes the EX_GPIO1 */
static THD_WORKING_AREA(Blink_ex_GPIO123_wa, 128);
static THD_FUNCTION(Blink_ex_GPIO123, arg)
{
  (void)arg;
  chRegSetThreadName("Blink_ex_GPIO123");
  while (1)
  	  {
	  palToggleLine(PAL_LINE(GPIOB, GPIOB_EX_GPIO1));
	  palToggleLine(PAL_LINE(GPIOB, GPIOB_EX_GPIO2));
	  palToggleLine(PAL_LINE(GPIOA, GPIOA_EX_GPIO3));


	  chThdSleepMilliseconds(2);

	  palToggleLine(PAL_LINE(GPIOB, GPIOB_EX_GPIO1));
	  palToggleLine(PAL_LINE(GPIOB, GPIOB_EX_GPIO2));
	  palToggleLine(PAL_LINE(GPIOA, GPIOA_EX_GPIO3));


	  chThdSleepMilliseconds(2);
  	  }
}
////////////////////////////////////////////////////////////





#endif /* THREADS_DEFINITIONS_H_ */
