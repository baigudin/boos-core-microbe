/** 
 * Silicon Labs C8051F9x MCUs timer driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_TIMER_H_
#define CPU_TIMER_H_

#include "Types.h"
#include "Error.h"

/**
 * Returns an timer resource.
 *
 * @param index - an available timer index.
 * @return the timer resource, or zero if error has been occurred.
 */
extern int8 CpuTimer_create(int8 index);

/**
 * Deletes the timer resource.
 *
 * @param res - the timer resource.
 */
extern void CpuTimer_delete(int8 res);

/**
 * Sets the timer period.
 *
 * @param res - the timer resource. 
 * @param time - timer period in microseconds, zero value sets a period to maximum value.
 */      
extern void CpuTimer_setPeriod(int8 res, int16 us);

/**
 * Starts the timer count.
 *
 * @param res - the timer resource. 
 */      
extern void CpuTimer_start(int8 res);

/**
 * Stops the timer count.
 *
 * @param res - the timer resource. 
 */      
extern void CpuTimer_stop(int8 res);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuTimer_initialize(void);

#endif /* CPU_TIMER_H_ */
