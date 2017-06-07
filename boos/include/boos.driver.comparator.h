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
 * @param handler an interrupt handler function. 
 * @param index   an available comparator index.
 * @return the comparator resource, or zero if error has been occurred.
 */
extern int8 comparatorCreate(void(*handler)(), int8 index);

/**
 * Removes the comparator resource.
 *
 * @param res the comparator resource.
 */
extern void comparatorRemove(int8 res);

/**
 * Selects the comparator input channels.
 *
 * @param res the comparator resource.
 * @param neg a negative input channel value.  
 * @param pos a positive input channel value. 
 */
extern void comparatorSetInput(int8 res, int8 neg, int8 pos);

/**
 * Locks the comparator interrupt source.
 *
 * @param res the comparator resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
extern int8 comparatorIntDisable(int8 res);
    
/**
 * Unlocks the comparator interrupt source.
 *
 * @param res    the comparator resource. 
 * @param status status returned by lock function.
 */
extern void comparatorIntEnable(int8 res, int8 status);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 comparatorInit(void);

#endif /* BOOS_DRIVER_COMPARATOR_H_ */
