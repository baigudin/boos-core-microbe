/** 
 * Functions to manipulate memory.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef MEMORY_H_
#define MEMORY_H_

#include "Types.h"

/** 
 * Copies a block of memory.
 *
 * @param dst pointer to the destination array where the content is to be copied, 
 *            type-casted to a pointer of type void*.
 * @param src pointer to the source of data to be copied, type-casted to a pointer of type const void*.
 * @param len number of bytes to copy.
 * @return destination is returned.
 */
extern void* Memory_copy(void* dst, const void* src, size_t len);

/** 
 * Fills a block of memory.
 *
 * @param dst pointer to the destination block of memory to fill.
 * @param val value to be set. The value is passed as an int, but the function fills 
 *            the block of memory using the unsigned char conversion of this value.
 * @param len Number of bytes to be set to the value.
 * @return destination is returned.
 */
extern void* Memory_set(void* dst, cell val, size_t len);


#endif /* MEMORY_H_ */
