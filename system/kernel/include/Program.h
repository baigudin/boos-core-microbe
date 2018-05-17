/** 
 * User program entry.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "Types.h"
#include "Error.h"

/**
 * User function which will be stated as first.
 *
 * @return error code or zero.
 */
extern int8 Program_start(void);

#endif /* PROGRAM_H_ */
