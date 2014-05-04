/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#pragma TenDRA begin
#pragma TenDRA directive include_next allow
#pragma TenDRA longlong type allow
#pragma TenDRA no external declaration allow

#define __WRONG_C_C89_LOCALE_H

#ifndef __NO_BUILTIN_ASSERTIONS
#assert machine(i386)
#assert cpu(i386)
#assert system(unix)
#assert system(DragonFly)
#unassert lint
#endif

#define unix		1
#define i386		1
#define __unix		1
#define __i386		1
#define __unix__	1
#define __i386__	1
#define __DragonFly__	2

#ifndef __inline
#pragma TenDRA keyword __inline for inline
#endif

#ifndef __signed
#define __signed	signed
#endif
