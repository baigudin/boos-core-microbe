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
 * CPU clock in Hz.
 */  
#define CPU_CLOCK (24300000)

/**
 * Timer 0/1 divider.
 *
 * The value must equal to 48, 12, 8, 4, or 1.
 */  
#define TIMER_DIVIDER (48)

/**
 * Timer 0/1 clock in Hz.
 */  
#define TIMER_CLOCK (CPU_CLOCK / TIMER_DIVIDER)

#endif /* CPU_CONFIGURATION_H_ */
