/** 
 * Silicon Labs C8051F9x MCUs interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_INTERRUPT_H_
#define CPU_INTERRUPT_H_

#include "Error.h"

/**
 * Returns an interrupt resource.
 *
 * @param handler - an interrupt handler function.
 * @param source - an available interrupt source number.
 * @return the interrupt resource, or zero if error has been occurred.
 */
extern int8 CpuInterrupt_create(void(*handler)(), int8 source);

/**
 * Deletes the interrupt resource.
 *
 * @param res - the interrupt resource.
 */
extern void CpuInterrupt_delete(int8 res);

/**
 * Locks the interrupt source.
 *
 * @param res - the interrupt resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
extern int8 CpuInterrupt_disable(int8 res);
    
/**
 * Unlocks this interrupt source.
 *
 * @param res - the interrupt resource. 
 * @param status - status returned by lock function.
 */
extern void CpuInterrupt_enable(int8 res, int8 status);

/**
 * Tests if this interrupt source can be polarized.
 *
 * @param res - the interrupt resource.  
 * @return true if this source is polarizing.
 */  
extern int8 CpuInterrupt_isPolarized(int8 res);

/**
 * Disables all maskable interrupts.
 *
 * @return global interrupts enable bit value before function was called.
 */
extern int8 CpuInterrupt_disableAll(void);

/**
 * Enables all maskable interrupts.
 *
 * The true passed argument directly turns all maskable interrupts on, 
 * and the false does nothing, the interrupts stay in the current state.     
 *
 * @param status - the returned status by disable function.
 */
extern void CpuInterrupt_enableAll(int8 status);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuInterrupt_initialize(void);

#endif /* CPU_INTERRUPT_H_ */
