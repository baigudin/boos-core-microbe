/**
 * Thread working procedure.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */ 
#ifndef BOOS_SYSTEM_THREAD_H_
#define BOOS_SYSTEM_THREAD_H_

#include "boos.types.h"

/**
 * Causes the currently executing thread to sleep.
 *
 * @param millis a time to sleep in milliseconds.
 */  
extern void threadSleep(int8 millis);

#endif /* BOOS_SYSTEM_THREAD_H_ */
