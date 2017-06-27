/** 
 * Target processor interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_INTERRUPT_LL_H_
#define BOOS_DRIVER_INTERRUPT_LL_H_

#include "boos.Types.h"

/**
 * HW interrupt handle routing.
 *
 * @param index index of HW interrupt vector
 */
extern void interruptHandler(uint8 index);

#endif /* BOOS_DRIVER_INTERRUPT_LL_H_ */
