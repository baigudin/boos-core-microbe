/** 
 * System types.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_TYPES_H_
#define BOOS_TYPES_H_

#ifdef __cplusplus
#error "The source file must be compiled by C compiler"
#endif

/* LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit) */
#ifdef BOOS_TYPE_WIDTH_LP32
typedef signed   int        int16;
typedef unsigned int        uint16;
typedef signed   long       int32;
typedef unsigned long       uint32;
#endif 
/* ILP32 or 4/4/4 (int, long, and pointer are 32-bit) */
#ifdef BOOS_TYPE_WIDTH_ILP32
typedef signed   short      int16;
typedef unsigned short      uint16;
typedef signed   int        int32;
typedef unsigned int        uint32;
#endif 
/* LLP64 or 4/4/8 (int and long are 32-bit, pointer is 64-bit) */
#ifdef BOOS_TYPE_WIDTH_LLP64
typedef signed   short      int16;
typedef unsigned short      uint16;
typedef signed   int        int32;
typedef unsigned int        uint32;
#endif 
/* LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit) */
#ifdef BOOS_TYPE_WIDTH_LP64
typedef signed   short      int16;
typedef unsigned short      uint16;
typedef signed   int        int32;
typedef unsigned int        uint32;
#endif 
/* C standard */
#ifdef BOOS_TYPE_C_STANDARD
typedef signed   short      int16;
typedef unsigned short      uint16;
typedef signed   long       int32;
typedef unsigned long       uint32;
#endif 
/* Floating point types */
typedef float               float32;
typedef long double         float64;
/* The type returned by sizeof */
typedef uint32              size_t;
/* Minimal addressable memory cell */
typedef signed char         cell;
typedef unsigned char       ucell;
/* Byte types of byte addressing */
typedef signed char         int8;
typedef unsigned char       uint8;
/* C-string type */
typedef char                cstring;

#endif /* BOOS_TYPES_H_ */
