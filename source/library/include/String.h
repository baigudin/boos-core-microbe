/** 
 * Functions to manipulate C-strings.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef STRING_H_
#define STRING_H_

#include "Types.h"


/** 
 * Gets a string length.
 *
 * @param str pointer to C-string.
 * @return the length of string.
 */
extern size_t String_getLength(const cstring* str);

/** 
 * Copies a string.
 *
 * @param dst pointer to the destination array where the content is to be copied.
 * @param src C-string to be copied.     
 * @return destination is returned.     
 */
extern cstring* String_copy(cstring* dst, const cstring* src);

/** 
 * Concatenates strings.
 *
 * @param dst pointer to the destination array, which should contain a C string, 
 *            and be large enough to contain the concatenated resulting string.
 * @param src C-string to be appended. This should not overlap destination.
 * @return destination is returned.     
 */
extern cstring* String_concatenate(cstring* dst, const cstring* src);

/** 
 * Compares two strings.
 *
 * @param str1 C-string to be compared.
 * @param str2 C-string to be compared.
 * @return a value indicating the relationship between the strings.
 */
extern int32 String_compare(const cstring* str1, const cstring* str2);

#endif /* STRING_H_ */
