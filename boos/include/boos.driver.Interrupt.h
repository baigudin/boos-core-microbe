/** 
 * Target processor interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_INTERRUPT_H_
#define BOOS_DRIVER_INTERRUPT_H_

#include "boos.Constants.h"

/**
 * Returns an interrupt resource.
 *
 * @param handler an interrupt handler function.
 * @param source an available interrupt source number.
 * @return the interrupt resource, or zero if error has been occurred.
 */
extern int8 interruptCreate(void(*handler)(), int8 source);

/**
 * Removes the interrupt resource.
 *
 * @param res the interrupt resource.
 */
extern void interruptRemove(int8 res);

/**
 * Locks the interrupt source.
 *
 * @param res the interrupt resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
extern int8 interruptDisable(int8 res);
    
/**
 * Unlocks this interrupt source.
 *
 * @param res    the interrupt resource. 
 * @param status status returned by lock function.
 */
extern void interruptEnable(int8 res, int8 status);

/**
 * Tests if this interrupt source can be polarized.
 *
 * @param res the interrupt resource.  
 * @return true if this source is polarizing.
 */  
extern int8 interruptIsPolarized(int8 res);

/**
 * Disables all maskable interrupts.
 *
 * @return global interrupts enable bit value before function was called.
 */
extern int8 interruptGlobalDisable(void);

/**
 * Enables all maskable interrupts.
 *
 * The true passed argument directly turns all maskable interrupts on, 
 * and the false does nothing, the interrupts stay in the current state.     
 *
 * @param status the returned status by disable function.
 */
extern void interruptGlobalEnable(int8 status);

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 interruptInit(void);

#endif /* BOOS_DRIVER_INTERRUPT_H_ */
