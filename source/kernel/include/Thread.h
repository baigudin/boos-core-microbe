/**
 * Thread working procedure.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */ 
#ifndef THREAD_H_
#define THREAD_H_

#include "Types.h"

/**
 * Causes the currently executing thread to sleep.
 *
 * @param millis - a time to sleep in milliseconds.
 */  
extern void Thread_sleep(int16 millis);

#endif /* THREAD_H_ */
