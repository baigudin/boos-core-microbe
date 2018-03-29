/** 
 * Silicon Labs C8051F9x MCUs phase-locked loop driver.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_PLL_H_
#define CPU_PLL_H_

#include "Types.h"
#include "Error.h"

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuPll_initialize(void);

#endif /* CPU_PLL_H_ */
