/*
 * Copyright 2011, The TenDRA Project.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef __HACKED_SYS_SEM_INCLUDED
#define __HACKED_SYS_SEM_INCLUDED

#ifdef __BUILDING_LIBS
#define semop	__semop_wrong
#endif

#include_next <sys/sem.h>

#ifdef __BUILDING_LIBS
#undef semop
#endif

#endif
