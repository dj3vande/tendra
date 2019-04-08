/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/*
   This file contains d_X procedures, where X is a TDF non-primitive
   SORT; when used with readstreams.c, the d_ procedures will give a
   diagnostic print of TDF in the above stream format.
*/

#ifndef DECODINGS_INCLUDED
#define DECODINGS_INCLUDED

@use all
@loop sort
@if !sort.builtin
extern unsigned int d_%SN(int);
@endif
@end

#endif
