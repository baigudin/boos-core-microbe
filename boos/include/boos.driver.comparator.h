/** 
 * Target processor interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_COMPARATOR_H_
#define BOOS_DRIVER_COMPARATOR_H_

#include "boos.constants.h"

/**
 * Returns an comparator resource.
 *
 * @param index available comparator index.
 * @return the comparator resource, or zero if error has been occurred.
 */
extern int8 comparatorCreate(int8 index);

/**
 * Removes the comparator resource.
 *
 * @param res the comparator resource.
 */
extern void comparatorRemove(int8 res);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 comparatorInit(void);

#endif /* BOOS_DRIVER_COMPARATOR_H_ */
