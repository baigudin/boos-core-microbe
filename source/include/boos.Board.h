/** 
 * Processor board initialization.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_BOARD_H_
#define BOOS_BOARD_H_

#include "boos.Types.h"

/**
 * Initializes a processor board.
 *
 * @return error code or else zero if no errors have been occurred.
 */ 
extern int8 boardInit(void);

#endif /* BOOS_BOARD_H_ */
