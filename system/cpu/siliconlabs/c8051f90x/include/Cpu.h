/** 
 * Silicon Labs C8051F9x MCUs driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018 Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_H_
#define CPU_H_

#include "Types.h"
#include "Error.h"

/**
 * This partially guards from calling these functions by a user program.
 */
#ifdef BOOS_SYSTEM_MODE

/**
 * Plugs the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 Cpu_plug(void);

#endif /* BOOS_SYSTEM_MODE */

#endif /* CPU_H_ */
