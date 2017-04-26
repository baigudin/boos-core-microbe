/** 
 * Target processor interrupts factory.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_INTERRUPT_H_
#define BOOS_DRIVER_INTERRUPT_H_

#include "boos.types.h"

/**
 * Returns the interrupt resource of a target processor.
 *
 * @return target processor interrupt resource.
 */
extern int32 interruptCreate();

/**
 * Initializes the driver.
 *
 * @param config a target processor configuration.
 * @return true if no errors have been occurred.
 */   
extern bool interruptInit();

/**
 * Deinitializes the driver.
 */
extern void interruptDeinit();

#endif // BOOS_DRIVER_INTERRUPT_H_
