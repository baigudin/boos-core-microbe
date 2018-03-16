/** 
 * Functions to manipulate C-strings.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "String.h"

/** 
 * Gets a string length.
 *
 * @param str pointer to C-string.
 * @return the length of string.
 */
size_t String_getLength(const cstring* str)
{
    register size_t len = 0;
    while(*str++) 
    {
        len++;
    }
    return len;
}

/** 
 * Copies a string.
 *
 * @param dst pointer to the destination array where the content is to be copied.
 * @param src C-string to be copied.     
 * @return destination is returned.     
 */
cstring* String_copy(cstring* dst, const cstring* src)
{
    register cstring* d = dst - 1;     
    register const cstring* s = src  - 1;     
    while( (*++d = *++s) != 0 ){}
    return dst;
}

/** 
 * Concatenates strings.
 *
 * @param dst pointer to the destination array, which should contain a C string, 
 *            and be large enough to contain the concatenated resulting string.
 * @param src C-string to be appended. This should not overlap destination.
 * @return destination is returned.     
 */
cstring* String_concatenate(cstring* dst, const cstring* src)
{
    register cstring* d = dst - 1;
    register const cstring* s = src - 1;
    while( *++d ){}
    d--;
    while( (*++d = *++s) != 0 ){}
    return dst;
}

/** 
 * Compares two strings.
 *
 * @param str1 C-string to be compared.
 * @param str2 C-string to be compared.
 * @return a value indicating the relationship between the strings.
 */
int32 String_compare(const cstring* str1, const cstring* str2)
{
    register int32 c1, res;
    while(1)
    {
        c1 = *str1++;
        res = c1 - *str2++;
        if(c1 == 0 || res != 0)
        { 
            break; 
        }
    }
    return res;
}
