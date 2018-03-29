/** 
 * The operating system error codes.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef ERROR_H_
#define ERROR_H_

/**
 * The operating system error codes.
 * 
 * The enumeration has to contain only negative values of errors, as 
 * negative error codes are used with the system, and positive error 
 * codes would be used with drivers and programs of the operating system.
 */
enum Error
{
    /**
     * No errors have been occurred.
     */  
    ERROR_OK = 0,
    
    /**
     * An undefined error has been occurred.
     */  
    ERROR_UNDEFINED = -1

};

#endif /* ERROR_H_ */
