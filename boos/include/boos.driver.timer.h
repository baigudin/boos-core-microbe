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
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 timerInit(void);

#endif /* BOOS_DRIVER_TIMER_H_ */
