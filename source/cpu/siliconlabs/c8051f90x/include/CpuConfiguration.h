/** 
 * Silicon Labs C8051F9x MCUs configuration.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

/**
 * Source clock of CPU oscillator in Hz.
 */      
#define SOURCE_CLOCK (24500000)
  
/**
 * System or CPU clock in Hz.
 */  
#define CPU_CLOCK (24300000)

/**
 * Timer 0/1 divider.
 *
 * The value must equal to 48, 12, 8, 4, or 1.
 */  
#define TIMER_DIVIDER (48)

/**
 * Programmable Counter Array clock source.
 *
 * The value must equal to:
 * 0 - system clock divided by 12.
 * 1 - system clock divided by 4.
 * 2 - timer 0 overflow.
 * 3 - high-to-low transitions on ECI (max rate = system clock divided by 4).
 * 4 - system clock.
 * 5 - external clock divided by 8 (synchronized with the system clock).
 * 6 - SmaRTClock divided by 8 (synchronized with the system clock and only available on F912 and F902 devices).
 */  
#define PCA_CLOCK_SOURCE (4)

#endif /* CPU_CONFIGURATION_H_ */
