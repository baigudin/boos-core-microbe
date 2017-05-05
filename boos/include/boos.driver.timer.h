/** 
 * Target processor timer driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_TIMER_H_
#define BOOS_DRIVER_TIMER_H_

#include "boos.constants.h"

/**
 * Returns an timer resource.
 *
 * @param index an available timer index.
 * @return the timer resource, or zero if error has been occurred.
 */
extern int8 timerCreate(int8 index);

/**
 * Removes the timer resource.
 *
 * @param res the timer resource.
 */
extern void timerRemove(int8 res);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 timerInit(void);

#endif /* BOOS_DRIVER_TIMER_H_ */
