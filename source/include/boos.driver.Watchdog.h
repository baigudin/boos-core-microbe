/** 
 * Target processor watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_WATCHDOG_H_
#define BOOS_DRIVER_WATCHDOG_H_

#include "boos.Constants.h"

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 watchdogInit(void);

#endif /* BOOS_DRIVER_WATCHDOG_H_ */
