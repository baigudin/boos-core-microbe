/** 
 * Silicon Labs C8051F9x MCUs watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_WATCHDOG_H_
#define CPU_WATCHDOG_H_

#include "Types.h"
#include "Error.h"

/**
 * Returns an watchdog resource.
 *
 * @param index - any value.
 * @return the watchdog resource, or zero if error has been occurred.
 */
extern int8 CpuWatchdog_create(int8 index);

/**
 * Deletes the watchdog resource.
 *
 * @param res - the watchdog resource.
 */
extern void CpuWatchdog_delete(int8 res);

/**
 * Enables the watchdog.
 *
 * @param res - the watchdog resource. 
 */      
extern void CpuWatchdog_start(int8 res);

/**
 * Disables the watchdog.
 *
 * @param res - the watchdog resource. 
 */      
extern void CpuWatchdog_stop(int8 res);

/**
 * Restarts the watchdog counting.
 *
 * @param res - the watchdog resource. 
 */      
extern void CpuWatchdog_restart(int8 res);

/**
 * This partially guards from calling these functions by a user program.
 */
#ifdef BOOS_SYSTEM_MODE

/**
 * Plugs the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuWatchdog_plug(void);

#endif /* BOOS_SYSTEM_MODE */

#endif /* CPU_WATCHDOG_H_ */
