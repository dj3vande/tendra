/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef _STDARG_H
#define _STDARG_H


#include <ansi_compat.h>

/*
    DEFINITION OF VA_LIST

    The definition of va_list is copied from the system header.
*/

#ifndef _VA_LIST_
#define _VA_LIST_
typedef char *va_list ;
#endif


#include <proxy/include/stdarg.h>


/*
    DEFINITION OF VA_START

    How va_start is defined in terms of __va_start depends on whether
    this is stdarg.h or varargs.h.
*/
#ifndef __BUILDING_TDF_C89_STDARG_H_VA_ARGS
#pragma TenDRA ident ... allow
#ifdef __HACKED_VARARGS
#define va_alist		...
#define va_dcl
#undef va_start
#define va_start( l )		( ( void ) ( l = __va_start ( ... ) ) )
#endif
#endif


#endif /* _STDARG_H */