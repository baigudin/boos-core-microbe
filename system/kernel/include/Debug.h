/** 
 * Debug module.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018, Sergey Baigudin 
 * @license   http://embedded.team/license/
 */ 
#ifndef DEBUG_H_
#define DEBUG_H_

#include "Types.h"

/**
 * Signals about an action.
 */
extern void Debug_signal(void);

/**
 * Signals about an action by a code value.
 *
 * @param value - a signal value.
 */
extern void Debug_signalCode(int8 value);

#endif /* DEBUG_H_ */
