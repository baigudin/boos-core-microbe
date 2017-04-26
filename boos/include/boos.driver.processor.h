/** 
 * Target processor factory. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_PROCESSOR_H_
#define BOOS_DRIVER_PROCESSOR_H_

#include "boos.types.h"

/**
 * Initializes the driver.
 *
 * @param config the operating system configuration.
 * @return true if no errors have been occurred.
 */   
extern bool processorInit();

/**
 * Deinitializes the driver.
 */
extern void processorDeinit();

#endif // BOOS_DRIVER_PROCESSOR_H_
