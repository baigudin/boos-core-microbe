/** 
 * System constants.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef ERROR_H_
#define ERROR_H_

#include "Types.h"

/**
 * The operating system error codes.
 */
enum Error
{
    /**
     * Common error.
     */  
    SYS_OK = 0,
    
    /**
     * Common error.
     */  
    SYS_ERROR = -1

};

#endif /* ERROR_H_ */
