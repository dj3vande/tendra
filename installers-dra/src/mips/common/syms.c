/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/*  syms.c   - produce symbol numbers for binasm (dense numbers) */

#include <shared/xalloc.h>

#include "cross_config.h"

#ifndef CROSS_INCLUDE
#include <symconst.h>
#else
#include CROSS_INCLUDE/symconst.h>
#endif

#include <reader/basicread.h>

#include <construct/flags.h>
#include <construct/shapemacs.h>
#include <construct/tags.h>

#include "symtab.h"
#include "expmacs.h"
#include "syms.h"
#include "main.h"
#include "diag_out.h"
#include "new_symbol.h"
#include "localtypes.h"

extern long currentfile;

int  *symnos;
int  *tempsnos = (int *) 0;

int   next_temps = 0;
int   no_temps = 0;



int
symnoforext(dec * ex, int filen)
{
				/* produce a symbolno for global given by
				   ex in file filen */
        exp tg = ex -> dec_u.dec_val.dec_exp;
  shape s = ex -> dec_u.dec_val.dec_shape;
  diag_type dt = (diag_type)0;
  short   symtype;
  short   symclass;
  long  v = 0;
  char *id = ex -> dec_u.dec_val.dec_id;
  if (diag != DIAG_NONE) {
    diag_descriptor * t = ex ->dec_u.dec_val.diag_info;
    if (t != (diag_descriptor *) 0) {
      id = t -> data.id.nme.ints.chars;
      dt = t -> data.id.new_type;
      filen = find_file(t ->data.id.whence.file->file.ints.chars);
    }
  }


  if (ex -> dec_u.dec_val.extnamed) {/* it is global */
    if (name (s) == prokhd && !isvar (tg)
		&& (son(tg) == nilexp || name(son(tg))== proc_tag
		|| name(son(tg)) == general_proc_tag))
   {/* a declared procedure */
      if (son (tg) != nilexp) {	/* a defined procedure will be output
				   later with this symbolno */
	return add_dense_no (0, 0);
      }
      else {
      	symtype = stGlobal;
        symclass = scNil;
      }
    }
    else {			/* some other global */
      ash a;
      symtype = stGlobal;
      symclass =
	(son (tg) != nilexp) ?
	((name (son (tg))) != clear_tag ? scData : scCommon)
	: scNil;
      a = ashof (s);
      v = (a.ashsize + 7) >> 3;
    }
    return new_esym_d (id, v, symtype, symclass, dt, filen);
  }
  else {			/* statics */
    if (name (s) == prokhd && !isvar (tg)
		&& (son(tg) == nilexp || name(son(tg))== proc_tag
		|| name(son(tg)) == general_proc_tag))
    {/* a procedure */
      symtype = stStaticProc;
      if (son (tg) != nilexp)
	return add_dense_no (0, 0);
      /* a defined procedure will be output later with this symbolno */
      failer ("Static procs should have bodies ");
      symclass = scNil;
    }
    else {			/* other statics */
      symtype = stStatic;
      symclass = (son(tg)== nilexp || name (son (tg)) != clear_tag)
                     ? scData : scCommon;
    }
    return new_lsym_d (id, v, symtype, symclass, dt, filen);
  }
}

int
symnoforstart(int i, int filen)
{
				/* output symbolno for start of proc */
  dec * ex = main_globals[i];
  short   symtype = (ex -> dec_u.dec_val.extnamed) ? stProc : stStaticProc;
  char *id = ex -> dec_u.dec_val.dec_id;
  diag_type dt = (diag_type)0;
  if (diag != DIAG_NONE) {
    diag_descriptor * t = ex ->dec_u.dec_val.diag_info;
    if (t != (diag_descriptor *) 0) {
      id = t ->data.id.nme.ints.chars;
      dt = t -> data.id.new_type;
      filen = find_file(t ->data.id.whence.file->file.ints.chars);
    }
  }

  return new_lsym (id, symnos[i], symtype, scText, dt, filen);
}

int
symnoforend(dec * ex, int filen)
{
				/* output symbolno for end of proc */
  char *id = ex -> dec_u.dec_val.dec_id;
  diag_type dt = (diag_type)0;
  if (diag != DIAG_NONE) {
    diag_descriptor * t = ex ->dec_u.dec_val.diag_info;
    if (t != (diag_descriptor *) 0) {
      id = t -> data.id.nme.ints.chars;
      dt = t -> data.id.new_type;
      filen = find_file(t -> data.id.whence.file->file.ints.chars);
    }
  }

  return new_lsym_d (id, 0, stEnd, scText, dt, filen);
}

int
symnofordata(int data_lab)
{
				/* output symbol number for data_lab and
				   remember it in tempsnos */
  int   a = data_lab - 32;
  if (a >= no_temps) {
    tempsnos = (int *) xrealloc ((char *) tempsnos, (100 + a) * sizeof (int));
    no_temps = a + 100;
  }

  return tempsnos[a] = add_dense_no (currentfile, 1048575 /* ???? */ );
}
