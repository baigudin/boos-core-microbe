/** 
 * Functions to manipulate memory.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_UTIL_MEMORY_H_
#define BOOS_UTIL_MEMORY_H_

#include "boos.Types.h"

/** 
 * Copies a block of memory.
 *
 * @param dst pointer to the destination array where the content is to be copied, 
 *            type-casted to a pointer of type void*.
 * @param src pointer to the source of data to be copied, type-casted to a pointer of type const void*.
 * @param len number of bytes to copy.
 * @return destination is returned.
 */
extern void* memoryCopy(void* dst, const void* src, size_t len);

/** 
 * Fills a block of memory.
 *
 * @param dst pointer to the destination block of memory to fill.
 * @param val value to be set. The value is passed as an int, but the function fills 
 *            the block of memory using the unsigned char conversion of this value.
 * @param len Number of bytes to be set to the value.
 * @return destination is returned.
 */
extern void* memorySet(void* dst, cell val, size_t len);

/** 
 * Gets a string length.
 *
 * @param str pointer to C-string.
 * @return the length of string.
 */
extern size_t memoryStrlen(const cstring* str);

/** 
 * Copies a string.
 *
 * @param dst pointer to the destination array where the content is to be copied.
 * @param src C-string to be copied.     
 * @return destination is returned.     
 */
extern cstring* memoryStrcpy(cstring* dst, const cstring* src);

/** 
 * Concatenates strings.
 *
 * @param dst pointer to the destination array, which should contain a C string, 
 *            and be large enough to contain the concatenated resulting string.
 * @param src C-string to be appended. This should not overlap destination.
 * @return destination is returned.     
 */
extern cstring* memoryStrcat(cstring* dst, const cstring* src);

/** 
 * Compares two strings.
 *
 * @param str1 C-string to be compared.
 * @param str2 C-string to be compared.
 * @return a value indicating the relationship between the strings.
 */
extern int32 memoryStrcmp(const cstring* str1, const cstring* str2);

#endif /* BOOS_UTIL_MEMORY_H_ */

