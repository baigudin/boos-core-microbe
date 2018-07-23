/** 
 * Processor board initialization.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef BOARD_H_
#define BOARD_H_

#include "Types.h"
#include "Error.h"

/**
 * This partially guards from calling these functions by a user program.
 */
#ifdef BOOS_SYSTEM_MODE

/**
 * Plugs a processor board.
 *
 * @return error code or else zero if no errors have been occurred.
 */ 
extern int8 Board_plug(void);

#endif /* BOOS_SYSTEM_MODE */

#endif /* BOARD_H_ */
