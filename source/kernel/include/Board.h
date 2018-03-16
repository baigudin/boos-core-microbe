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

/**
 * Initializes a processor board.
 *
 * @return error code or else zero if no errors have been occurred.
 */ 
extern int8 Board_initialize(void);

#endif /* BOARD_H_ */
