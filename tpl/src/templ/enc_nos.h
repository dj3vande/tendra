/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


#ifndef ENC_NOS_INCLUDED
#define ENC_NOS_INCLUDED


/* AUTOMATICALLY GENERATED BY %ZX VERSION %ZV FROM TDF %VA.%VB */

@use all
#define major_version	%48t%VA
#define minor_version	%48t%VB

#define s_tdfint	%48t%u
#define s_tdfbool	%48t%u
#define s_tdfstring	%48t%u
#define s_bitstream	%48t%u
#define s_tdfident	%48t%u
#define s_bytestream	%48t%u
@loop sort
@if sort.simple

#define s_%SN	%48t%u
@if sort.basic
@loop sort.cons
#define e_%CN	%48t%CE
@end
@endif
@endif
@end


#endif
