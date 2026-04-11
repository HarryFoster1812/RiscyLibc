/* Copyright (C) 1997,1998,1999,2000,2001,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *        ISO C99: 7.18 Integer types <stdint.h>
 */

#ifndef _STDINT_H
#define _STDINT_H        1


/* Signed.  */

/* There is some amount of overlap with <sys/types.h> as known by inet code */
typedef signed char           int8_t;
typedef short int             int16_t;
typedef int                   int32_t;
typedef long int							int64_t;

/* Unsigned.  */
typedef unsigned char                uint8_t;
typedef unsigned short int        uint16_t;
typedef unsigned int                uint32_t;
typedef unsigned long int        uint64_t;





/* Types for `void *' pointers.  */
typedef int                        intptr_t;
typedef unsigned int                uintptr_t;


/* Limits of integral types.  */

/* Minimum of signed integral types.  */
# define INT8_MIN                (-128)
# define INT16_MIN                (-32767-1)
# define INT32_MIN                (-2147483647-1)
# define INT64_MIN                (-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types.  */
# define INT8_MAX                (127)
# define INT16_MAX                (32767)
# define INT32_MAX                (2147483647)
# define INT64_MAX                (__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types.  */
# define UINT8_MAX                (255)
# define UINT16_MAX                (65535)
# define UINT32_MAX                (4294967295U)
# define UINT64_MAX                (__UINT64_C(18446744073709551615))

#endif /* stdint.h */

