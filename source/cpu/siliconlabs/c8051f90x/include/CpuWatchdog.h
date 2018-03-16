/** 
 * Silicon Labs C8051F9x MCUs watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_WATCHDOG_H_
#define CPU_WATCHDOG_H_

#include "Error.h"

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuWatchdog_initialize(void);

#endif /* CPU_WATCHDOG_H_ */
