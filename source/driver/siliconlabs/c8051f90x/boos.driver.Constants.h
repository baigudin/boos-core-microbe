/** 
 * System driver constants.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_CONSTANTS_H_
#define BOOS_DRIVER_CONSTANTS_H_

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

#endif /* BOOS_DRIVER_CONSTANTS_H_ */
