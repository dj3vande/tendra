/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1996, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef XDB_BASICS_INCLUDED
#define XDB_BASICS_INCLUDED

#include <diag3/dg_first.h>
#include <diag3/diaginfo.h>

extern void diag_start(diag_info *, exp);
extern void diag_end(diag_info *, exp);
extern void xdb_diag_proc_begin(diag_descriptor *, exp, char *, long, int);
extern void xdb_diag_proc_return(void);
extern void xdb_diag_proc_end(diag_descriptor *);
extern void xdb_diag_val_begin(diag_descriptor *, char *, long, int);
extern dec *sort_decs(dec *);
extern void xOUTPUT_GLOBALS_TAB(void);
extern void xOUTPUT_DIAG_TAGS(void);
extern void xINSPECT_FILENAME(filename);

#endif
