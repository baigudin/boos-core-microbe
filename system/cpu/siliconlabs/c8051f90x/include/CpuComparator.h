/** 
 * Silicon Labs C8051F9x MCUs comparator driver.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_COMPARATOR_H_
#define CPU_COMPARATOR_H_

#include "Types.h"
#include "Error.h"

/**
 * Returns an comparator resource.
 *
 * @param handler - an interrupt handler function. 
 * @param index -an available comparator index.
 * @param neg - a negative input channel value.
 * @param pos - a positive input channel value.
 * @return the comparator resource, or zero if error has been occurred.
 */
extern int8 CpuComparator_create(void(*handler)(), int8 index, int8 neg, int8 pos);

/**
 * Deletes the comparator resource.
 *
 * @param res - the comparator resource.
 */
extern void CpuComparator_delete(int8 res);

/**
 * Locks the comparator interrupt source.
 *
 * @param res - the comparator resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
extern int8 CpuComparator_disableInterrupt(int8 res);
    
/**
 * Unlocks the comparator interrupt source.
 *
 * @param res - the comparator resource. 
 * @param status - status returned by lock function.
 */
extern void CpuComparator_enableInterrupt(int8 res, int8 status);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuComparator_initialize(void);

#endif /* CPU_COMPARATOR_H_ */
