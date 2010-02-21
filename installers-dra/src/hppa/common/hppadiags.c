/*
 * Copyright (c) 2002-2005 The TenDRA Project <http://www.tendra.org/>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of The TenDRA Project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific, prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
/*
    		 Crown Copyright (c) 1997

    This TenDRA(r) Computer Program is subject to Copyright
    owned by the United Kingdom Secretary of State for Defence
    acting through the Defence Evaluation and Research Agency
    (DERA).  It is made available to Recipients with a
    royalty-free licence for its use, reproduction, transfer
    to other parties and amendment for any purpose not excluding
    product development provided that any such use et cetera
    shall be deemed to be acceptance of the following conditions:-

	(1) Its Recipients shall ensure that this Notice is
	reproduced upon any copies or amended versions of it;

	(2) Any amended version of it shall be clearly marked to
	show both the nature of and the organisation responsible
	for the relevant amendment or amendments;

	(3) Its onward transfer from a recipient to another
	party shall be deemed to be that party's acceptance of
	these conditions;

	(4) DERA gives no warranty or assurance as to its
	quality or suitability for any purpose and DERA accepts
	no liability whatsoever in relation to any use to which
	it may be put.
*/


/*
			    VERSION INFORMATION
			    ===================

--------------------------------------------------------------------------
$Header: /u/g/release/CVSROOT/Source/src/installers/hppa/common/hppadiags.c,v 1.1.1.1 1998/01/17 15:56:02 release Exp $
--------------------------------------------------------------------------
$Log: hppadiags.c,v $
 * Revision 1.1.1.1  1998/01/17  15:56:02  release
 * First version to be checked into rolling release.
 *
 * Revision 1.4  1996/08/06  10:50:06  wfs
 * bug fixes to pic code, enum diagnostics enabled.
 *
 * Revision 1.3  1996/03/28  10:53:09  wfs
 * Bug fixes to scan(), peephole optimisations in proc.c, and enum diagnostics.
 *
 * Revision 1.2  1995/12/18  13:11:30  wfs
 * Put hppatrans uder cvs control. Major Changes made since last release
 * include:
 * (i) PIC code generation.
 * (ii) Profiling.
 * (iii) Dynamic Initialization.
 * (iv) Debugging of Exception Handling and Diagnostics.
 *
 * Revision 5.11  1995/11/08  10:23:50  wfs
 * Minor changes for compatability with original "hpux_symtab.h" file +
 * extra warning messages.
 *
 * Revision 5.10  1995/11/03  13:24:28  wfs
 * Reset "typeno" after each call of " pos_of_dnttpos_of_dnttpointer". Cosmetic
 * changes.
 *
 * Revision 5.9  1995/10/30  12:58:57  wfs
 * Standardized the format of the warning messages.
 *
 * Revision 5.8  1995/10/25  14:30:42  wfs
 * Incorrect identifier for proc name was being output (in stab_proc()).
 *
 * Revision 5.7  1995/10/24  15:17:57  wfs
 * Fixed a bug in "pos_of_dnttpointer()".
 *
 * Revision 5.6  1995/10/20  13:53:51  wfs
 * Changes for gcc compilation.
 *
 * Revision 5.5  1995/10/09  13:13:46  wfs
 * Added an "SLT_EXIT" entry when closing functions - without this XDB
 * cannot properly trace return's. Cosmetic changes.
 *
 * Revision 5.4  1995/09/26  12:44:52  wfs
 * Moved "SLT_EXIT" in a case statement.
 *
 * Revision 5.3  1995/09/26  08:17:49  wfs
 * Added missing "#ifdef _SYMTAB_INCLUDED"'s.
 *
 * Revision 5.2  1995/09/25  11:46:04  wfs
 *    Added "#ifdef _SYMTAB_INCLUDED" provisios around any code which refers
 * to "hpux-symtab.h". We cannot legally distribute this header file.
 *    Added a procedure which will calculate where in the DNTT table a
 * struct typedef is to be entered without actually emitting the entry.
 * This is required whenever we have a struct typedef with a field being
 * a pointer to a struct of the type in question.
 *
 * Revision 5.1  1995/09/15  12:25:21  wfs
 * Numerous minor changes made to stop gcc complaining.
 *
 * Revision 5.0  1995/08/25  13:42:58  wfs
 * Preperation for August 25 Glue release
 *
 * Revision 3.4  1995/08/25  09:32:55  wfs
 * A major revision. XDB stuff added.
 *
 * Revision 3.4  1995/08/25  09:32:55  wfs
 * A major revision. XDB stuff added.
 *
 * Revision 3.1  95/04/10  16:26:44  16:26:44  wfs (William Simmonds)
 * Apr95 tape version.
 *
 * Revision 3.0  95/03/30  11:17:22  11:17:22  wfs (William Simmonds)
 * Mar95 tape version with CRCR95_178 bug fix.
 *
 * Revision 2.0  95/03/15  15:27:08  15:27:08  wfs (William Simmonds)
 * spec 3.1 changes implemented, tests outstanding.
 *
 * Revision 1.7  1995/01/11  16:40:35  john
 * Fixed bug in diagnostics (for change request CR95_40)
 *
 * Revision 1.6  1995/01/11  09:59:32  john
 * Fixed bug in diagnostics (for change request CR94_224)
 *
 * Revision 1.5  1994/07/07  16:11:33  djch
 * Jul94 tape
 *
 * Revision 1.4  1994/07/04  08:29:06  djch
 * added extra parameter to stab_scope_open

d (section number). -ve values used to control
 * not putting out stabd (sometimes) in solaris; line #s go in the stabs.
 * added assert(0) to catch uninitialized items.
 *
 * Revision 1.3  1994/06/22  09:48:33  djch
 * Changes for solaris - line #s in functions are relative to start of fns,
 * global decls have line # in the stabs, and no stabn, and local labels are .LL,
 * not LL
 *
 * Revision 1.2  1994/05/13  13:08:39  djch
 * Incorporates improvements from expt version
 * changed format strings to remove longs..
 *
 * Revision 1.1  1994/05/03  14:49:53  djch
 * Initial revision
 *
 * Revision 1.6  93/09/27  14:55:15  14:55:15  ra (Robert Andrews)
 * Only whitespace.
 *
 * Revision 1.5  93/08/27  11:37:55  11:37:55  ra (Robert Andrews)
 * A couple of lint-like changes.
 *
 * Revision 1.4  93/08/13  14:45:51  14:45:51  ra (Robert Andrews)
 * Allow the stabs for long double to vary depending on DOUBLE_SZ.
 *
 * Revision 1.3  93/07/05  18:26:29  18:26:29  ra (Robert Andrews)
 * A couple of minor corrections.  Introduced stab_ptrs to avoid duplication
 * of basic pointer types.
 *
 * Revision 1.2  93/06/29  14:32:54  14:32:54  ra (Robert Andrews)
 * Fairly major rewrite and reformat.  There were a number of errors which
 * meant that the diagnostics were not previously working.
 *
 * Revision 1.1  93/06/24  14:59:22  14:59:22  ra (Robert Andrews)
 * Initial revision
 *
--------------------------------------------------------------------------
*/


#define HPPATRANS_CODE
#include "config.h"
#if FS_STDARG
#include <stdarg.h>
#else
#include <varargs.h>
#endif
#include "addrtypes.h"
#include "frames.h"
#include "exptypes.h"
#include "shapemacs.h"
#include "expmacs.h"
#include "codetypes.h"
#include "installtypes.h"
#include "toktypes.h"
#include "exp.h"
#include "exptypes.h"
#include "proctypes.h"
#include "procrec.h"
#include "tags.h"
#include "bitsmacs.h"
#include "diagtypes.h"
#include "xalloc.h"
#include "diag_fns.h"
#include "locate.h"
#include "diagglob.h"
#include "mark_scope.h"
#include "xalloc.h"
#include "comment.h"
#include "myassert.h"
#include "translat.h"
#include "machine.h"
#include "szs_als.h"
#include "install_fns.h"
#include "installglob.h"
#include "externs.h"
#include "out.h"
#include "hppadiags.h"

#ifdef _SYMTAB_INCLUDED
#undef _SYMTAB_INCLUDED
#include "hpux-symtab.h"
#endif



extern bool last_param(exp);


/*
    FORWARD DECLARATIONS
*/

static void stab_scope_open(long);
static void stab_scope_close(long);

#ifdef _SYMTAB_INCLUDED
static int last_lno = 0;
#endif

/*
    ARRAY OF DIAGNOSTIC SCOPES
*/

#define MAX_LEX_LEVEL 256
static long bracket_level = 1;
static long BB_id = 0;
static long BE_id = 0;
static int last_LBRAC_stab = 0;

/*
    DIAGNOSTICS FILE
*/

static FILE *dg_file;
static char dg_file_name[L_tmpnam];


/*
    BASIC TYPE NUMBERS
*/

#define STAB_SCHAR	4
#define STAB_UCHAR	6
#define STAB_SSHRT	2
#define STAB_USHRT	3
#define STAB_SLONG	1
#define STAB_ULONG	8
#define STAB_FLOAT	10
#define STAB_DBL	11
#define STAB_LDBL	12
#define STAB_VOID	13
#define NO_STABS	14


/*
    BASIC POINTERS
*/

static long stab_ptrs[NO_STABS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


/*
    CURRENT TYPE NUMBER
*/

static long typeno = NO_STABS;


/*
    SIZE OF LAST STAB TYPE OUTPUT
*/

static long last_type_sz = 0;


/*
    CURRENT LINE NUMBER AND FILE NUMBER
*/

long currentlno = -1;
long currentfile = -1;

#ifndef _SYMTAB_INCLUDED

typedef int DNTTPOINTER;

#endif

static DNTTPOINTER NIL;

/*
    ARRAY OF TYPE SIZES
*/


/* Information about previously defined types. */

typedef struct { int sz; DNTTPOINTER p; } type_info_t;

static type_info_t *type_info;
static int no_type_info = 0;


/*
    SETTING AND GETTING TYPE SIZES
*/

#define set_stab_size(i)	type_info[(i)].sz = last_type_sz
#define get_stab_size(i)	(type_info[(i)].sz)


/*
    GET THE NEXT TYPE NUMBER
*/

static long next_typen
(void)
{
    if (typeno >= no_type_info) {
	int i, n = no_type_info, m = n + 100;
	type_info = (type_info_t*)xrealloc(type_info, m * sizeof(type_info_t));
	for (i = n; i < m; i++)type_info[i].sz = 0;
	no_type_info = m;
    }
    return(typeno++);
}


/*
    ARRAY OF FILE DESCRIPTORS
*/

static filename *fds = null;
static int szfds = 0;
static int nofds = 0;


/* tdfstring -> nul terminated C string (char *) */
#define CSTRING(tdfstring)	((tdfstring).ints.chars)

/* tdf exp -> C int */
#define EXPINT(exp)		(assert(name(exp) == val_tag), no(exp))

/* tdf nat -> C int */
#define NATINT(n)		((n).nat_val.small_nat)



#ifdef _SYMTAB_INCLUDED
/******************************   XDB stuff  *********************************/

static FILE *VT_,*SLT_,*LNTT_,*GNTT_;

static char   VT_name[L_tmpnam],  SLT_name[L_tmpnam],
	      LNTT_name[L_tmpnam], GNTT_name[L_tmpnam];

static DNTTPOINTER DNTT_BEGIN_entry[1024];

static int level_of_DNTT_BEGINs = -1;

#define last_DNTT_BEGIN_entry() DNTT_BEGIN_entry[level_of_DNTT_BEGINs]
#define LNTT 1
#define GNTT 0

static DNTTPOINTER lntt_next;
static DNTTPOINTER gntt_next;
static SLTPOINTER  slt_next = 0;
static VTPOINTER   vt_next = VTNIL;

struct vt_entry_t { long findex;
		    VTPOINTER vtp;
		    struct vt_entry_t *prev; };

typedef struct vt_entry_t *vt_entry;

vt_entry last_vt_entry = (vt_entry)0;

VTPOINTER is_vt_entry
(long findex)
{
   vt_entry current = last_vt_entry;
   while (current != (vt_entry)0)
   {
      if (current->findex == findex)
	 return current->vtp;
      else
	 current = current->prev;
   }
   return VTNIL;
}

#define EXTENSION_BIT(p)((p) & (1<<31))

void output_LNTT
(union dnttentry e)
{
   KINDTYPE kind = e.dfunc.kind;
   if (kind==K_SVAR)
   {
      fprintf(LNTT_,"\t.WORD\t%lu,%lu,%s",e.dgeneric.word[0], e.dgeneric.word[1],(char*)e.dgeneric.word[2]);
   }
   else
   {
      fprintf(LNTT_,"\t.WORD\t%lu,%lu,%lu",e.dgeneric.word[0], e.dgeneric.word[1], e.dgeneric.word[2]);
   }

   switch (kind)
   {
      case K_MODULE:
      case K_WITH:
      case K_FPARAM:
      case K_SVAR:
      case K_DVAR:
      case K_CONST:
      case K_MEMENUM:
      case K_SUBRANGE:
      case K_ARRAY:
      case K_STRUCT:
      case K_FIELD:
      case K_VARIANT:
      case K_FILE:
      case K_FUNCTYPE:
      {
	 if (EXTENSION_BIT(e.dgeneric.word[3]) ==0)
	 {
	    fprintf(stderr,"hppatrans warning: trans made an error whilst compiling XDB diagnostics tables (extension bit not set)\n");
	 }
	 else
	 {
	    fprintf(LNTT_,",%lu,%lu,%lu",e.dgeneric.word[3],e.dgeneric.word[4], e.dgeneric.word[5]);
	 }
	 break;
      }
      case K_FUNCTION:
      case K_ENTRY:
      case K_BLOCKDATA:
      case K_COBSTRUCT:
      {
	 if (EXTENSION_BIT(e.dgeneric.word[3]) ==0)
	 {
	    fprintf(stderr,"hppatrans warning: trans made an error whilst compiling XDB diagnostics tables (extension bit not set)\n");
	    break;
	 }
	 else
	 {
	    fprintf(LNTT_,",%lu,%lu,%s",e.dgeneric.word[3],e.dgeneric.word[4],(char*)e.dgeneric.word[5]);
	 }
	 if (EXTENSION_BIT(e.dgeneric.word[6]) ==0)
	 {
	    fprintf(stderr,"hppatrans warning: trans made an error whilst compiling XDB diagnostics tables (extension bit not set)\n");
	 }
	 else
	 {
	    fprintf(LNTT_,",%lu,%s,%s",e.dgeneric.word[6],(char*)e.dgeneric.word[7],(char*)e.dgeneric.word[8]);
	 }
      }
      default:
      break;
   }
   fprintf(LNTT_,"\n");
}


void output_GNTT
(union dnttentry e)
{
   KINDTYPE kind = e.dfunc.kind;
   if (kind==K_SVAR)
   {
      fprintf(GNTT_,"\t.WORD\t%lu,%lu,%s",e.dgeneric.word[0], e.dgeneric.word[1],(char*)e.dgeneric.word[2]);
      if (EXTENSION_BIT(e.dgeneric.word[3]) ==0)
      {
	 fprintf(stderr,"hppatrans warning: trans made an error whilst compiling XDB diagnostics tables (extension bit not set)\n");
      }
      else
      {
	 fprintf(GNTT_,",%lu,%lu,%lu",e.dgeneric.word[3],e.dgeneric.word[4], e.dgeneric.word[5]);
      }
   }
   else
   {
      fprintf(GNTT_,"\t.WORD\t%lu,%lu,%lu",e.dgeneric.word[0], e.dgeneric.word[1], e.dgeneric.word[2]);
   }
   if (e.dgeneric.word[6] & (1<<31))
   {
      fprintf(GNTT_,",%lu,%lu,%lu",e.dgeneric.word[6],e.dgeneric.word[7], e.dgeneric.word[8]);
   }
   fprintf(GNTT_,"\n");
}


DNTTPOINTER make_DNTTP_IMMEDIATE
(BASETYPE type, ...)
{
   DNTTPOINTER p;
   va_list ap;
#if FS_STDARG
   va_start(ap,type);
#else
   BASETYPE type;
   va_start(ap);
   type = va_arg(ap, BASETYPE);
#endif
   p.dntti.extension = 1;
   p.dntti.immediate = 1;
   p.dntti.global = 0;
   p.dntti.type = type;
   switch (type)
     {
     case T_UNDEFINED:
       {
	  p.dntti.bitlength = 32;
	  break;
       }
     case T_BOOLEAN:
       {
	  p.dntti.bitlength = 1;
	  break;
       }
     case T_CHAR:
     case T_INT:
     case T_UNS_INT:
     case T_LONG:
     case T_UNS_LONG:
     case T_REAL:
     case T_COMPLEX:
       {
	  p.dntti.bitlength = va_arg(ap,BITS);
	  break;
       }
     }
   return p;
}


void make_vtentry
((e, record, findex))
(char *e, int record, long findex)
{
   int len = 0;
   fprintf(VT_,   while (e[len++])
   {
      fprintf(VT_,"%c",e[len-1]);
   }
   if (record)
   {
      vt_entry next = (vt_entry)malloc(sizeof(struct vt_entry_t));
      if (last_vt_entry == (vt_entry)0)
      {
	 last_vt_entry = next;
	 last_vt_entry->prev = (vt_entry)0;
      }
      else
      {
	 next->prev = last_vt_entry;
	 last_vt_entry = next;
      }
      next->findex = findex;
      next->vtp = vt_next;
   }
   vt_next+=len;
   fprintf(VT_,"\"\n");
}


void make_sltentry
(SLTTYPE sltdesc, ...)
{
   va_list ap;
   union sltentry e;
#if FS_STDARG
   va_start(ap,sltdesc);
#else
   SLTTYPE sltdesc;
   va_start(ap);
   sltdesc = va_arg(ap, SLTTYPE);
#endif
   e.sgeneric.word[0] = 0;
   e.sgeneric.word[1] = 0;
   switch (sltdesc)
   {
   case SLT_SRCFILE:
   case SLT_MODULE:
   case SLT_FUNCTION:
   case SLT_ENTRY:
   case SLT_BEGIN:
   case SLT_END:
   case SLT_WITH:
   case SLT_MARKER:
     {
	/*  A "special" entry  */
	e.sspec.sltdesc = sltdesc;
	e.sspec.line = va_arg(ap,BITS);
	e.sspec.backptr = va_arg(ap,DNTTPOINTER);
	fprintf(SLT_,"\t.WORD\t%lu,%lu\n",e.sgeneric.word[0], e.sgeneric.word[1]);
	break;
     }
   case SLT_EXIT:
   case SLT_NORMAL:
     {
	/*  A "normal" entry  */
	e.snorm.sltdesc = SLT_NORMAL;
	e.snorm.line = va_arg(ap,BITS);
	e.snorm.address = va_arg(ap,ADDRESS);
	fprintf(SLT_,"\t.WORD\t%lu,%s\n",e.sgeneric.word[0],(char*)e.sgeneric.word[1]);
	break;
     }
   case SLT_ASSIST:
     {
	/*  An "assist" entry  */
	e.sasst.sltdesc = SLT_ASSIST;
	e.sasst.unused = 0;
	e.sasst.address = va_arg(ap,ADDRESS);
	fprintf(SLT_,"\t.WORD\t%lu,%lu\n",e.sgeneric.word[0], e.sgeneric.word[1]);
	break;
     }
   }
   slt_next++;
}


DNTTPOINTER make_dnttentry
(KINDTYPE kind, ...)
{
   va_list ap;
   union dnttentry e;
   DNTTPOINTER dnttpointer;
#if FS_STDARG
   va_start(ap,kind);
#else
   KINDTYPE kind;
   va_start(ap);
   kind = va_arg(ap, KINDTYPE);
#endif
   e.dsfile.extension = 0;
   e.dsfile.kind = K_SRCFILE;
   e.dsfile.language = 0;
   dnttpointer = lntt_next;
   switch (kind)
   {
   case K_SRCFILE:
     {
	e.dsfile.extension = 0;
	e.dsfile.kind = K_SRCFILE;
	e.dsfile.language = va_arg(ap,LANGTYPE);
	e.dsfile.unused = 0;
	e.dsfile.name = va_arg(ap,VTPOINTER);
	e.dsfile.address = va_arg(ap,SLTPOINTER);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_MODULE:
     {
	DNTT_BEGIN_entry[++level_of_DNTT_BEGINs] = lntt_next;
	e.dmodule.extension = 0;
	e.dmodule.kind = K_MODULE;
	e.dmodule.unused = 0;
	e.dmodule.name = va_arg(ap,VTPOINTER);
	e.dmodule.alias = va_arg(ap,VTPOINTER);
	e.dmodule.dummy = NIL;
	e.dmodule.address = va_arg(ap,SLTPOINTER);
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_FUNCTION:
   case K_ENTRY:
   case K_BLOCKDATA:
     {
	if (kind==K_FUNCTION)
	   DNTT_BEGIN_entry[++level_of_DNTT_BEGINs] = lntt_next;
	e.dfunc.extension = 0;
	e.dfunc.kind = kind;
	e.dfunc.public = va_arg(ap,BITS);
	e.dfunc.language = va_arg(ap,LANGTYPE);
	e.dfunc.level = va_arg(ap,BITS);
	e.dfunc.optimize = va_arg(ap,BITS);
	e.dfunc.varargs = va_arg(ap,BITS);
	e.dfunc.info = va_arg(ap,BITS);
	e.dfunc.unused = 0;
	e.dfunc.name = va_arg(ap,VTPOINTER);
	e.dfunc.alias = va_arg(ap,VTPOINTER);
	e.dfunc.firstparam = va_arg(ap,DNTTPOINTER);
	e.dfunc.address = va_arg(ap,SLTPOINTER);
	e.dfunc.entryaddr = va_arg(ap,ADDRESS);
	e.dfunc.retval = va_arg(ap,DNTTPOINTER);
	e.dfunc.lowaddr = va_arg(ap,ADDRESS);
	e.dfunc.hiaddr = va_arg(ap,ADDRESS);
	output_LNTT(e);
	lntt_next.word+=3;
	break;
     }
   case K_BEGIN:
     {
	DNTT_BEGIN_entry[++level_of_DNTT_BEGINs] = lntt_next;
	e.dbegin.extension = 0;
	e.dbegin.kind = K_BEGIN;
	e.dbegin.unused = 0;
	e.dbegin.address = va_arg(ap,SLTPOINTER);
	e.dgeneric.word[2] = 0;
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_END:
     {
	e.dend.extension = 0;
	e.dend.kind = K_END;
	e.dend.endkind = va_arg(ap,KINDTYPE);
	e.dend.unused = 0;
	e.dend.address = va_arg(ap,SLTPOINTER);
	e.dend.beginscope = va_arg(ap,DNTTPOINTER);
	output_LNTT(e);
	lntt_next.word++;
	level_of_DNTT_BEGINs--;
	break;
     }
   case K_IMPORT:
     {
	e.dimport.extension = 0;
	e.dimport.kind = K_IMPORT;
	e.dimport.explicit = va_arg(ap,BITS);
	e.dimport.unused = 0;
	e.dimport.module = va_arg(ap,VTPOINTER);
	e.dimport.item = va_arg(ap,VTPOINTER);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_LABEL:
     {
	e.dlabel.extension = 0;
	e.dlabel.kind = K_LABEL;
	e.dlabel.unused = 0;
	e.dlabel.name = va_arg(ap,VTPOINTER);
	e.dlabel.address = va_arg(ap,SLTPOINTER);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_WITH:
     {
	e.dwith.extension = 0;
	e.dwith.kind = K_WITH;
	e.dwith.addrtype = va_arg(ap,BITS);
	e.dwith.indirect = va_arg(ap,BITS);
	e.dwith.longaddr = va_arg(ap,BITS);
	e.dwith.nestlevel = va_arg(ap,BITS);
	e.dwith.unused = 0;
	e.dwith.location = va_arg(ap,long);
	e.dwith.address = va_arg(ap,SLTPOINTER);
	e.dwith.type = va_arg(ap,DNTTPOINTER);
	e.dwith.name = va_arg(ap,VTPOINTER);
	e.dwith.offset = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_COMMON:
     {
	e.dcommon.extension = 0;
	e.dcommon.kind = K_COMMON;
	e.dcommon.unused = 0;
	e.dcommon.name = va_arg(ap,VTPOINTER);
	e.dcommon.alias = va_arg(ap,VTPOINTER);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_FPARAM:
     {
	e.dfparam.extension = 0;
	e.dfparam.kind = K_FPARAM;
	e.dfparam.regparam = va_arg(ap,BITS);
	e.dfparam.indirect = va_arg(ap,BITS);
	e.dfparam.longaddr = va_arg(ap,BITS);
	e.dfparam.copyparam = va_arg(ap,BITS);
	e.dfparam.unused = 0;
	e.dfparam.name = va_arg(ap,VTPOINTER);
	e.dfparam.location = va_arg(ap,DYNTYPE);
	e.dfparam.type = va_arg(ap,DNTTPOINTER);
	e.dfparam.nextparam = va_arg(ap,DNTTPOINTER);
	e.dfparam.misc = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_SVAR:
     {
	int which_table;
	e.dsvar.extension = 0;
	e.dsvar.kind = K_SVAR;
	e.dsvar.public = va_arg(ap,BITS);
	e.dsvar.indirect = va_arg(ap,BITS);
	e.dsvar.longaddr = va_arg(ap,BITS);
	e.dsvar.unused = 0;
	e.dsvar.name = va_arg(ap,VTPOINTER);
	e.dsvar.location = va_arg(ap,STATTYPE);
	e.dsvar.type = va_arg(ap,DNTTPOINTER);
	e.dsvar.offset = va_arg(ap,unsigned long);
	e.dsvar.displacement = va_arg(ap,unsigned long);
	which_table = va_arg(ap,int);
	if (which_table==LNTT)
	{
	   output_LNTT(e);
	   lntt_next.word+=2;
	}
	else
	{
	   dnttpointer = gntt_next;
	   output_GNTT(e);
	   gntt_next.word+=2;
	}
	break;
     }
   case K_DVAR:
     {
	e.ddvar.extension = 0;
	e.ddvar.kind = K_DVAR;
	e.ddvar.public = va_arg(ap,BITS);
	e.ddvar.indirect = va_arg(ap,BITS);
	e.ddvar.regvar = va_arg(ap,BITS);
	e.ddvar.unused = 0;
	e.ddvar.name = va_arg(ap,VTPOINTER);
	e.ddvar.location = va_arg(ap,DYNTYPE);
	e.ddvar.type = va_arg(ap,DNTTPOINTER);
	e.ddvar.offset = 0;
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_CONST:
     {
	e.dconst.extension = 0;
	e.dconst.kind = K_CONST;
	e.dconst.public = va_arg(ap,BITS);
	e.dconst.indirect = va_arg(ap,BITS);
	e.dconst.locdesc = va_arg(ap,LOCDESCTYPE);
	e.dconst.unused = 0;
	e.dconst.name = va_arg(ap,VTPOINTER);
	e.dconst.location = va_arg(ap,STATTYPE);
	e.dconst.type = va_arg(ap,DNTTPOINTER);
	e.dconst.offset = va_arg(ap,unsigned long);
	e.dconst.displacement = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_TYPEDEF:
   case K_TAGDEF:
     {
	e.dtype.extension = 0;
	e.dtype.kind = kind;
	e.dtype.public = va_arg(ap,BITS);
	e.dtype.typeinfo = va_arg(ap,BITS);
	e.dtype.unused = 0;
	e.dtype.name = va_arg(ap,VTPOINTER);
	e.dtype.type = va_arg(ap,DNTTPOINTER);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_POINTER:
     {
	e.dptr.extension = 0;
	e.dptr.kind = kind;
	e.dptr.unused = 0;
	e.dptr.pointsto = va_arg(ap,DNTTPOINTER);
	e.dptr.bitlength = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_ENUM:
     {
	e.denum.extension = 0;
	e.denum.kind = K_ENUM;
	e.denum.unused = 0;
	e.denum.firstmem = va_arg(ap,DNTTPOINTER);
	e.denum.bitlength = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_MEMENUM:
     {
	e.dmember.extension = 0;
	e.dmember.kind = K_MEMENUM;
	e.dmember.unused = 0;
	e.dmember.name = va_arg(ap,VTPOINTER);
	e.dmember.value = va_arg(ap,unsigned long);
	e.dmember.nextmem = va_arg(ap,DNTTPOINTER);
	e.dgeneric.word[4] = 0;
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_SET:
     {
	e.dset.extension = 0;
	e.dset.kind = K_SET;
	e.dset.declaration = va_arg(ap,BITS);
	e.dset.unused = 0;
	e.dset.subtype = va_arg(ap,DNTTPOINTER);
	e.dset.bitlength = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_SUBRANGE:
     {
	e.dsubr.extension = 0;
	e.dsubr.kind = K_SUBRANGE;
	e.dsubr.dyn_low = va_arg(ap,BITS);
	e.dsubr.dyn_high = va_arg(ap,BITS);
	e.dsubr.unused = 0;
	e.dsubr.lowbound = va_arg(ap,long);
	e.dsubr.highbound = va_arg(ap,long);
	e.dsubr.subtype = va_arg(ap,DNTTPOINTER);
	e.dsubr.bitlength = va_arg(ap,unsigned long);
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_ARRAY:
     {
	e.darray.extension = 0;
	e.darray.kind = K_ARRAY;
	e.darray.declaration = va_arg(ap,BITS);
	e.darray.dyn_low = va_arg(ap,BITS);
	e.darray.dyn_high = va_arg(ap,BITS);
	e.darray.arrayisbytes = va_arg(ap,BITS);
	e.darray.elemisbytes = va_arg(ap,BITS);
	e.darray.elemorder = va_arg(ap,BITS);
	e.darray.justified = va_arg(ap,BITS);
	e.darray.unused = 0;
	e.darray.arraylength = va_arg(ap,unsigned long);
	e.darray.indextype = va_arg(ap,DNTTPOINTER);
	e.darray.elemtype = va_arg(ap,DNTTPOINTER);
	e.darray.elemlength = va_arg(ap,unsigned long);
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_STRUCT:
     {
	e.dstruct.extension = 0;
	e.dstruct.kind = K_STRUCT;
	e.dstruct.declaration = va_arg(ap,BITS);
	e.dstruct.unused = 0;
	e.dstruct.firstfield = va_arg(ap,DNTTPOINTER);
	e.dstruct.vartagfield = va_arg(ap,DNTTPOINTER);
	e.dstruct.varlist = va_arg(ap,DNTTPOINTER);
	e.dstruct.bitlength = va_arg(ap,unsigned long);
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_UNION:
     {
	e.dunion.extension = 0;
	e.dunion.kind = K_UNION;
	e.dunion.unused = 0;
	e.dunion.firstfield = va_arg(ap,DNTTPOINTER);
	e.dunion.bitlength = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_FIELD:
     {
	e.dfield.extension = 0;
	e.dfield.kind = K_FIELD;
	e.dfield.unused = 0;
	e.dfield.name = va_arg(ap,VTPOINTER);
	e.dfield.bitoffset = va_arg(ap,unsigned long);
	e.dfield.type = va_arg(ap,DNTTPOINTER);
	e.dfield.bitlength = va_arg(ap,unsigned long);
	e.dfield.nextfield = va_arg(ap,DNTTPOINTER);
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_VARIANT:
     {
	e.dvariant.extension = 0;
	e.dvariant.kind = K_VARIANT;
	e.dvariant.unused = 0;
	e.dvariant.lowvarvalue = va_arg(ap,long);
	e.dvariant.hivarvalue = va_arg(ap,long);
	e.dvariant.varstruct = va_arg(ap,DNTTPOINTER);
	e.dvariant.bitoffset = va_arg(ap,unsigned long);
	e.dvariant.nextvar = va_arg(ap,DNTTPOINTER);
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_FILE:
     {
	e.dfile.extension = 0;
	e.dfile.kind = K_FILE;
	e.dfile.ispacked = va_arg(ap,BITS);
	e.dfile.unused = 0;
	e.dfile.bitlength = va_arg(ap,unsigned long);
	e.dfile.bitoffset = va_arg(ap,unsigned long);
	e.dfile.elemtype = va_arg(ap,DNTTPOINTER);
	e.dgeneric.word[4] = 0;
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_FUNCTYPE:
     {
	e.dfunctype.extension = 0;
	e.dfunctype.kind = K_FUNCTYPE;
	e.dfunctype.varargs = va_arg(ap,BITS);
	e.dfunctype.info = va_arg(ap,BITS);
	e.dfunctype.unused = 0;
	e.dfunctype.bitlength = va_arg(ap,unsigned long);
	e.dfunctype.firstparam = va_arg(ap,DNTTPOINTER);
	e.dfunctype.retval = va_arg(ap,DNTTPOINTER);
	e.dgeneric.word[4] = 0;
	e.dgeneric.word[5] = 0;
	output_LNTT(e);
	lntt_next.word+=2;
	break;
     }
   case K_COBSTRUCT:
     {
	e.dcobstruct.extension = 0;
	e.dcobstruct.kind = K_COBSTRUCT;
	e.dcobstruct.hasoccurs = va_arg(ap,BITS);
	e.dcobstruct.istable = va_arg(ap,BITS);
	e.dcobstruct.unused = 0;
	e.dcobstruct.parent = va_arg(ap,DNTTPOINTER);
	e.dcobstruct.child = va_arg(ap,DNTTPOINTER);
	e.dcobstruct.sibling = va_arg(ap,DNTTPOINTER);
	e.dcobstruct.synonym = va_arg(ap,DNTTPOINTER);
	e.dcobstruct.catusage = va_arg(ap,BITS);
	e.dcobstruct.unused2 = 0;
	e.dcobstruct.table = va_arg(ap,DNTTPOINTER);
	e.dcobstruct.editpgm = va_arg(ap,VTPOINTER);
	e.dcobstruct.bitlength = va_arg(ap,unsigned long);
	output_LNTT(e);
	lntt_next.word+=3;
	break;
     }
   case K_SA:
     {
	e.dsa.extension = 0;
	e.dsa.kind = K_SA;
	e.dsa.base_kind = va_arg(ap,KINDTYPE);
	e.dsa.unused = 0;
	e.dsa.name = va_arg(ap,VTPOINTER);
	e.dsa.extra = 0;
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   case K_XREF:
     {
	e.dxref.extension = 0;
	e.dxref.kind = K_XREF;
	e.dxref.language = va_arg(ap,LANGTYPE);
	e.dxref.unused = 0;
	e.dxref.xreflist = va_arg(ap,XREFPOINTER);
	e.dxref.extra = 0;
	output_LNTT(e);
	lntt_next.word++;
	break;
     }
   }
   return dnttpointer;
}


void output_DEBUG
(void)
{
    int c;
    FILE *f;
    SLTPOINTER slt_prev = slt_next;
    make_sltentry(SLT_END, currentlno, lntt_next);
    make_dnttentry(K_END, K_MODULE, slt_prev, last_DNTT_BEGIN_entry());
    fclose(VT_);
    fclose(SLT_);
    fclose(LNTT_);
    fclose(GNTT_);
    f = fopen(VT_name, "r");
    if (f == NULL) {
	fail("Can't open temporary diagnostics file");
	exit(EXIT_FAILURE);
    }
    while (c = fgetc(f), c != EOF) outc(c);
    outnl();
    fclose(VT_);
    remove(VT_name);
    f = fopen(SLT_name, "r");
    if (f == NULL) {
	fail("Can't open temporary diagnostics file");
	exit(EXIT_FAILURE);
    }
    while (c = fgetc(f), c != EOF) outc(c);
    outnl();
    fclose(SLT_);
    remove(SLT_name);
    f = fopen(LNTT_name, "r");
    if (f == NULL) {
	fail("Can't open temporary diagnostics file");
	exit(EXIT_FAILURE);
    }
    while (c = fgetc(f), c != EOF) outc(c);
    outnl();
    fclose(LNTT_);
    remove(LNTT_name);
    f = fopen(GNTT_name, "r");
    if (f == NULL) {
	fail("Can't open temporary diagnostics file");
	exit(EXIT_FAILURE);
    }
    while (c = fgetc(f), c != EOF) outc(c);
    fclose(GNTT_);
    remove(GNTT_name);

    fprintf(outf,"\n\t.SPACE\t$DEBUG$\n");
    fprintf(outf,"\t.SUBSPA\t$HEADER$\n");
#if USE_XT
    fprintf(outf,"\t.WORD\t%ld\n",(gntt_next.word * DNTTBLOCKSIZE) |
	     		       extension_header);	/* MSB indicates XT */
#else
    fprintf(outf,"\t.WORD\t%ld\n",(gntt_next.word * DNTTBLOCKSIZE) | 0);
	     		                        	/* MSB indicates XT */
#endif
    fprintf(outf,"\t.WORD\t%ld\n",lntt_next.word * DNTTBLOCKSIZE);
    fprintf(outf,"\t.WORD\t%ld\n",slt_next * SLTBLOCKSIZE);
    fprintf(outf,"\t.WORD\t%ld\n",vt_next);
#if USE_XT
    fprintf(outf,"\t.WORD\t%ld\n",xt_next * XTBLOCKSIZE);
#endif
    return;
}

/*****************************************************************************/
#endif

/*
    ADD A NEW FILE TO THE ARRAY OF FILE DESCRIPTORS
*/

void stab_collect_files
(filename f)
{
    if (fds == null) {
	szfds += 10;
	fds = (filename *)xmalloc(szfds * sizeof(filename));
    } else if (nofds >= szfds) {
	szfds += 10;
	fds = (filename *)xrealloc(fds, szfds * sizeof(filename));
    }
    fds[nofds++] = f;
    return;
}


/*
    FIND THE FILE DESCRIPTOR CORRESPONDING TO A FILE NAME
*/

static long find_file
(char * f)
{
    long i;
    for (i = 0; i < nofds; i++) {
	if (strcmp(f, fds[i] ->file.ints.chars) == 0) return(i);
    }
    return(0);
}


static char *last_proc_lab = "<<No Proc>>";

/*
    OUTPUT A FILE POSITION CONSTRUCT
*/

#define N_SLINE  0x44
#define N_DSLINE 0x46
#define N_BSLINE 0x48
#define N_LBRAC  0xc0
#define N_RBRAC  0xe0

void stabd
(long findex, long lno, int seg)
{
   long i;
   if (findex == currentfile && lno == currentlno) return;
   stab_file(findex, 1);
   if (seg != 0)		/* 0 suppresses always */
   {
      if (seg > 0)		/* -ve line nos are put out in the stabs */
      {
	i = next_lab();
	if (xdb)
	{
#ifdef _SYMTAB_INCLUDED
	   char address[128];
	   sprintf(address,"L$M%ld-%s",i,last_proc_lab);
	   make_sltentry(SLT_NORMAL, lno,(ADDRESS)address);
	   last_lno = lno;
#endif
	}
	else  /*  gdb  */
	{
  	   fprintf(dg_file,"\t.stabn\t0x%x,0,%ld,L$M%ld-%s\n",seg,
		   lno,i,last_proc_lab);
	}
	fprintf(dg_file,"L$M%ld\n",i);
      }
   }
   currentlno = lno;
   return;
}


/*
    OUTPUT INITIAL DIAGNOSTICS FOR A DIAGNOSE_TAG
*/

/* ARGSUSED */ void stab_begin
(diag_info * d, int proc_no, exp e)
{
    exp x;

    if (d->key == DIAG_INFO_SOURCE) {
	sourcemark *s = &d->data.source.beg;
	long f = find_file(s->file->file.ints.chars);
	stabd(f,(long)s->line_no.nat_val.small_nat ,N_SLINE);
	return;
    }

    if (d->key != DIAG_INFO_ID) {
	/* not implemented */
	return;
    }

    x = d->data.id_scope.access;
    /* MIPS */
    if (isglob(son(x)) || no(son(x)) == 1) return;

    mark_scope(e);

    if (props(e) & 0x80) {
	stab_scope_open(currentfile);
	stabd(currentfile,(long)(currentlno + 1), N_SLINE);
    }

    stab_local(d->data.id_scope.nme.ints.chars, d->data.id_scope.typ,
		 x, 0, currentfile);

    if (last_param(son(x))) {
	stabd(currentfile,(long)(currentlno + 1),N_SLINE);
    }
    return;
}


/*
    OUTPUT FINAL DIAGNOSTICS FOR A DIAGNOSE_TAG
*/

void stab_end
(diag_info * d, exp e)
{
    if (d->key == DIAG_INFO_SOURCE) {
	sourcemark *s = &d->data.source.end;
	long f = find_file(s->file->file.ints.chars);
	long lno = s->line_no.nat_val.small_nat;
	stabd(f,lno,N_SLINE);
	return;
    }
    if (d->key == DIAG_INFO_ID && props(e) & 0x80) {
	stab_scope_close(currentfile);
	return;
    }
    return;
}


/*
    INITIALISE DIAGNOSTICS
*/

void init_stab
(void)
{
    tmpnam(dg_file_name);
    dg_file = fopen(dg_file_name, "w+");
    if (dg_file == NULL) {
	fail("Can't open temporary diagnostics file");
	exit(EXIT_FAILURE);
    }
#ifdef _SYMTAB_INCLUDED
    NIL.word = -1;
#else
    NIL = 0;
#endif
    if (xdb)
    {
#ifdef _SYMTAB_INCLUDED
       stab_types();
       tmpnam(VT_name);
       VT_ = fopen(VT_name, "w+");
       if (VT_ == NULL)
       {
	  fail("Can't open temporary diagnostics file");
	  exit(EXIT_FAILURE);
       }
       tmpnam(SLT_name);
       SLT_ = fopen(SLT_name, "w+");
       if (SLT_ == NULL)
       {
	  fail("Can't open temporary diagnostics file");
	  exit(EXIT_FAILURE);
       }
       tmpnam(LNTT_name);
       LNTT_ = fopen(LNTT_name, "w+");
       if (LNTT_ == NULL)
       {
	  fail("Can't open temporary diagnostics file");
	  exit(EXIT_FAILURE);
       }
       tmpnam(GNTT_name);
       GNTT_ = fopen(GNTT_name, "w+");
       if (GNTT_ == NULL)
       {
	  fail("Can't open temporary diagnostics file");
	  exit(EXIT_FAILURE);
       }
       fprintf(VT_,"\t.SPACE\t$DEBUG$\n");
       fprintf(VT_,"\t.SUBSPA\t$VT$\n");
       fprintf(SLT_,"\t.SPACE\t$DEBUG$\n");
       fprintf(SLT_,"\t.SUBSPA\t$SLT$\n");
       fprintf(LNTT_,"\t.SPACE\t$DEBUG$\n");
       fprintf(LNTT_,"\t.SUBSPA\t$LNTT$\n");
       fprintf(GNTT_,"\t.SPACE\t$DEBUG$\n");
       fprintf(GNTT_,"\t.SUBSPA\t$GNTT$\n");
       make_vtentry("",0,0);
       lntt_next.word = 1<<31;  /* initialise .word field */
       gntt_next.word = 1<<31;  /* initialise .word field */
       NIL.word = -1;
#endif
    }
    return;
}


/*
    INITIALIZE DIAGNOSTICS
*/

void init_stab_aux
(void)
{
    int c;
    FILE *f;
    int i, j = 0;
    for (i = 0; i < nofds; i++) {
	char *s = fds[i] ->file.ints.chars;
	int n = (int)strlen(s);
	if (n && s[n - 1]!= 'h')j = i;
    }
    fclose(dg_file);
    dg_file = outf;
    stab_file((long)j, 0);
    if (gdb)
    {
       stab_types();
    }
    f = fopen(dg_file_name, "r");
    if (f == NULL) {
	fail("Can't open temporary diagnostics file");
	exit(EXIT_FAILURE);
    }
    while (c = fgetc(f), c != EOF)outc(c);
    fclose(f);
    remove(dg_file_name);
    return;
}


/*
    FIND THE DIAGNOSTICS CORRESPONDING TO THE CURRENT DECLARATION
*/

/* ARGSUSED */ static diag_descriptor *find_dd
(exp e)
{
    if (diag_def == NULL) return(NULL);
    return(diag_def->dec_u.dec_val.diag_info);
}


/*
    OUTPUT DIAGNOSTICS DIRECTIVE FOR A FILE
*/

void stab_file
(long findex, bool internal)
{
    static long i = 0;
    if (findex == currentfile || findex < 0 || findex >= szfds) {
	return;
    }

    if (gdb)
       fprintf(dg_file,"\t.file\t\"%s\"\n",fds[findex] ->file.ints.chars);
    if (internal)
    {
       /* included file */
       if (xdb)
       {
#ifdef _SYMTAB_INCLUDED
	  SLTPOINTER slt_prev = slt_next;
	  VTPOINTER entry = is_vt_entry(findex);
	  make_sltentry(SLT_SRCFILE, currentlno, lntt_next);
	  make_dnttentry(K_SRCFILE, LANG_C,(entry==VTNIL ? vt_next : entry), slt_prev);
	  if (entry==VTNIL)
	     make_vtentry(fds[findex] ->file.ints.chars,1,findex);
#endif
       }
       else
	  fprintf(dg_file,"\t.stabs\t\"%s\",0x84,0,0,L$M%ld\n",
		     fds[findex] ->file.ints.chars, i);
    }
    else
    {
       /* source file */
       i = next_lab();
       if (xdb)
       {
#ifdef _SYMTAB_INCLUDED
	  SLTPOINTER slt_prev = slt_next;
	  VTPOINTER entry = is_vt_entry(findex);
	  make_sltentry(SLT_SRCFILE, currentlno, lntt_next);
	  make_dnttentry(K_SRCFILE, LANG_C,(entry==VTNIL ? vt_next : entry), slt_prev);
	  slt_prev =  slt_next;
	  make_sltentry(SLT_MODULE, 1, lntt_next);
	  make_dnttentry(K_MODULE, VTNIL, VTNIL, slt_prev);
	  if (entry==VTNIL)
	     make_vtentry(fds[findex] ->file.ints.chars,1,findex);
#endif
       }
       else  /*  gdb  */
       {
	  fprintf(dg_file, "\t.stabs\t\"%s\",0x64,0,0,L$M%ld\n",
       	     fds[findex] ->file.ints.chars, i);
       }
       fprintf(dg_file, "L$M%ld\n", i);
    }
    currentfile = findex;
    return;
}


/*********************  START OF A DIAGNOSTICS SCOPE  ************************/

static void stab_scope_open
(long findex)
{
   stab_file(findex,1);
   /* nb. don't need to output bracket level */
   if (xdb)
   {
#ifdef _SYMTAB_INCLUDED
      SLTPOINTER slt_prev = slt_next;
      make_sltentry(SLT_BEGIN,(BITS)currentlno, lntt_next);
      make_dnttentry(K_BEGIN, slt_prev);
#endif
   }
   else  /*  gdb  */
   {
      if (last_LBRAC_stab==BB_id-1)
      {
	 fprintf(dg_file,"\t.stabn\t0x%x,0,0,L$BB%ld-%s\n",N_LBRAC,BB_id,
		 last_proc_lab);
	 last_LBRAC_stab=BB_id;
      }
      BB_id++;
      fprintf(dg_file,"L$BB%ld\n",BB_id);
   }
   bracket_level++;
}


/**********************  END OF A DIAGNOSTICS SCOPE  *************************/

static void stab_scope_close
(long findex)
{
   bracket_level--;
   if (bracket_level>MAX_LEX_LEVEL)
      return;
   /* nb. don't need to output bracket level */
   if (xdb)
   {
#ifdef _SYMTAB_INCLUDED
      SLTPOINTER slt_prev = slt_next;
      make_sltentry(SLT_END, currentlno, lntt_next);
      make_dnttentry(K_END, K_BEGIN, slt_prev, last_DNTT_BEGIN_entry());
#endif
   }
   else  /*  gdb  */
   {
      if (last_LBRAC_stab==BB_id-1)
      {
	 fprintf(dg_file,"\t.stabn\t0x%x,0,0,L$BB%ld-%s\n",N_LBRAC,BB_id,
	      last_proc_lab);
	 last_LBRAC_stab = BB_id;
      }
      BE_id++;
      fprintf(dg_file,"\t.stabn\t0x%x,0,0,L$BE%ld-%s\n",N_RBRAC,BE_id,
		    last_proc_lab);
      fprintf(dg_file,"L$BE%ld\n",BE_id);
   }
   return;
}


/*
    DEPTH COUNT FOR STAB TYPES
*/

/* static int max_depth = 64 ; */
static int depth_now = 0;


/***************  OUTPUT THE DIAGNOSTICS FOR A SIMPLE SHAPE  *****************/

static long out_sh_type
(shape s)
{
    last_type_sz = shape_size(s);
    switch (name(s))
      {
      case scharhd: return(STAB_SCHAR);
      case ucharhd: return(STAB_UCHAR);
      case swordhd: return(STAB_SSHRT);
      case uwordhd: return(STAB_USHRT);
      case slonghd: return(STAB_SLONG);
      case ulonghd: return(STAB_ULONG);
      case shrealhd: return(STAB_FLOAT);
      case realhd: return(STAB_DBL);
      case doublehd: return(STAB_LDBL);
      }
    return(STAB_VOID);
}


/***********************  OUTPUT A DIAGNOSTICS TYPE  *************************/


#ifdef _SYMTAB_INCLUDED


struct outed_t { diag_type dt; struct outed_t *prev; };
typedef struct outed_t *outed;

static outed uo;
static DNTTPOINTER pos;


void undo_outed
(diag_type dt)
{
   outed p = (outed)malloc(sizeof(struct outed_t));
   uo->prev = p;
   p->dt = dt;
   p->prev = (struct outed_t*)0;
   uo = p;
}


static DNTTPOINTER traverse_diag_type
(diag_type dt)
{
    if (dt->been_outed)
    {
       last_type_sz = get_stab_size(dt->been_outed);
       return pos;
    }

#if 0
    if (depth_now >= max_depth)
    {
       return NIL;
    }
    depth_now++;
#endif

    switch (dt->key)
      {
      case DIAG_TYPE_PTR:
	{
	   long non;
	   diag_type pdt = dt->data.ptr.object;
	   if (pdt->key == DIAG_TYPE_VARIETY)
	   {
	      long pn = out_sh_type(f_integer(pdt->data.var));
	      non = stab_ptrs[pn];
	      if (non==0)
	      {
		 non = next_typen();
		 stab_ptrs[pn] = -non;
		 pos.word++;
	      }
	   }
	   else
	   {
	      non = next_typen();
	      traverse_diag_type(pdt);
	      pos.word++;
	   }
	   dt->been_outed = non;
	   undo_outed(dt);
	   last_type_sz = 32;
	   set_stab_size(non);
	   return pos;
	}

      case DIAG_TYPE_ARRAY:
	{
	   long lwb = no(dt->data.array.lower_b);
	   long upb = no(dt->data.array.upper_b);
	   diag_type index_type = dt->data.array.index_type;
	   diag_type element_type = dt->data.array.element_type;
	   long non = next_typen();
	   dt->been_outed = non;
	   undo_outed(dt);
	   traverse_diag_type(index_type);
	   pos.word+=2;
	   traverse_diag_type(element_type);
	   pos.word+=2;
	   last_type_sz *= (upb-lwb+1);
	   set_stab_size(non);
	   return pos;
	   break;
	}

      case DIAG_TYPE_STRUCT:
      case DIAG_TYPE_UNION:
	{
	   int i;
	   shape s;
	   long non = next_typen();
	   diag_field_list fields;
	   dt->been_outed = non;
	   undo_outed(dt);
	   if (dt->key == DIAG_TYPE_STRUCT)
	   {
	      fields = dt->data.t_struct.fields;
	      s = dt->data.t_struct.tdf_shape;
	   }
	   else
	   {
	      fields = dt->data.t_union.fields;
	      s = dt->data.t_union.tdf_shape;
	   }
	   for (i=0;i<fields->lastused;i++)
	   {
	      diag_field f = (fields->array)[i];
	      traverse_diag_type(f->field_type);
	      pos.word+=2;
	   }
	   if (dt->key == DIAG_TYPE_STRUCT)
	   {
	      pos.word+=2;
	   }
	   else
	   {
	      pos.word++;
	   }
	   last_type_sz = shape_size(s);
	   set_stab_size(non);
	   return pos;
	}

	case DIAG_TYPE_FLOAT:
	case DIAG_TYPE_VARIETY:
	  {
	     shape sha;
	     if (dt->key==DIAG_TYPE_VARIETY)
	     {
		sha = f_integer(dt->data.var);
	     }
	     else
	     {
		sha = f_floating(dt->data.f_var);
	     }
	     dt->been_outed = out_sh_type(sha);
	     return pos;
	  }

	case DIAG_TYPE_PROC:
	  {
	     diag_type result_type = dt->data.proc.result_type;
	     long non1 = next_typen();
	     long non2 = next_typen();
	     dt->been_outed = non1;
	     undo_outed(dt);
	     pos.word++;
	     traverse_diag_type(result_type);
	     last_type_sz = 32;
	     set_stab_size(non1);
	     set_stab_size(non2);
	     return pos;
	  }

	case DIAG_TYPE_LOC:
	  {
	     return traverse_diag_type(dt->data.loc.object);
	  }

	case DIAG_TYPE_NULL:
	  {
	     last_type_sz = 0;
	     return pos;
	  }

	case DIAG_TYPE_BITFIELD:
	  {
	     long sz = dt->data.bitfield.no_of_bits.nat_val.small_nat;
	     last_type_sz = sz;
	     return pos;
	  }

	case DIAG_TYPE_ENUM:
	{
	   traverse_diag_type(dt->data.t_enum.base_type);
	   return pos;
	}

	default:
	{
	   last_type_sz = 0;
	   return pos;
	}
    }
}


DNTTPOINTER pos_of_dnttpointer
(diag_type dt)
{
   outed p,f;
   int s;
   int t = typeno;
   pos = lntt_next;
   uo = (struct outed_t*)malloc(sizeof(struct outed_t));
   uo->prev = (struct outed_t*)0;
   f = uo;
   traverse_diag_type(dt);
   while (f->prev)
   {
      p = f->prev;
      free(f);
      p->dt->been_outed = 0;
      f = p;
   }
   free(f);
   for (s=0;s<NO_STABS;s++)
      if (stab_ptrs[s] <0)
	 stab_ptrs[s] = 0;
   typeno = t;
   return pos;
}


#endif


#define OUT_DT_SHAPE(dt)	out_dt_shape((depth_now = 0, dt))

static DNTTPOINTER out_dt_shape
(diag_type dt)
{
    if (dt->been_outed)
    {
       last_type_sz = get_stab_size(dt->been_outed);
       if (xdb)
       {
#ifdef _SYMTAB_INCLUDED
	  return type_info[dt->been_outed].p;
#endif
       }
       else
       {
	  fprintf(dg_file,"%d",(int)dt->been_outed);
       }
       return NIL;
    }

#if 0
    if (depth_now >= max_depth)
    {
       if (gdb)
	  fprintf(dg_file, "%d", STAB_SLONG);
       return NIL;
    }
    depth_now++;
#endif

    switch (dt->key)
      {
      case DIAG_TYPE_PTR:
	{
	   DNTTPOINTER p = NIL;
	   long non;
	   diag_type pdt = dt->data.ptr.object;
	   if (pdt->key == DIAG_TYPE_VARIETY)
	   {
	      long pn = out_sh_type(f_integer(pdt->data.var));
	      non = stab_ptrs[pn];
	      if (non==0)
	      {
		 non = next_typen();
		 stab_ptrs[pn] = non;
		 if (xdb)
		 {
#ifdef _SYMTAB_INCLUDED
		    p = make_dnttentry(K_POINTER, type_info[pn].p, 32);
#endif
		 }
		 else
		 {
		    fprintf(dg_file,"%ld=*%ld",non,pn);
		 }
	      }
	      else
	      {
		 if (xdb)
		 {
#ifdef _SYMTAB_INCLUDED
		    p = type_info[non].p;
#endif
		 }
		 else
		 {
		    fprintf(dg_file,"%ld",non);
		 }
	      }
	   }
	   else
	   {
	      non = next_typen();
	      if (xdb)
	      {
#ifdef _SYMTAB_INCLUDED
		 p = make_dnttentry(K_POINTER, out_dt_shape(dt->data.ptr.object), 32);
#endif
	      }
	      else
	      {
		 fprintf(dg_file,"%ld=*",non);
		 out_dt_shape(dt->data.ptr.object);
	      }
	   }
	   dt->been_outed = non;
#ifdef _SYMTAB_INCLUDED
	   type_info[non].p = p;
#endif
	   last_type_sz = 32;
	   set_stab_size(non);
	   return p;
	}

      case DIAG_TYPE_ARRAY:
	{
	   DNTTPOINTER indextype,elemtype,p=NIL;
#if 0
	   long str = no(dt->data.array.stride);
#endif
	   long lwb = no(dt->data.array.lower_b);
	   long upb = no(dt->data.array.upper_b);
	   diag_type index_type = dt->data.array.index_type;
	   diag_type element_type = dt->data.array.element_type;
	   long non = next_typen();
	   dt->been_outed = non;
	   if (gdb)
	   {
	      fprintf(dg_file,"%ld=ar",non);
	      out_dt_shape(index_type);
  	      fprintf(dg_file,";%ld;%ld;",lwb,upb);
	   }
	   else
	   {
#ifdef _SYMTAB_INCLUDED
	      indextype = make_dnttentry(K_SUBRANGE, 0, 0, lwb, upb, out_dt_shape(index_type),
				         last_type_sz);
#endif
	   }
	   elemtype = out_dt_shape(element_type);
	   if (xdb)
	   {
#ifdef _SYMTAB_INCLUDED
	      unsigned long arraylength = (upb-lwb+1) <<2;
	      unsigned long elemlength = last_type_sz>>3;
	      p = make_dnttentry(K_ARRAY, 0, 0, 0, 1, 1, 0, 0, arraylength, indextype, elemtype, elemlength);
	      type_info[non].p = p;
#endif
	   }
	   last_type_sz *= (upb-lwb+1);
	   set_stab_size(non);
	   return p;
	   break;
	}

      case DIAG_TYPE_STRUCT:
      case DIAG_TYPE_UNION:
	{
	   DNTTPOINTER p = NIL;
	   int i;
	   char su;
	   shape s;
	   long non = next_typen();
	   diag_field_list fields;
#ifdef _SYMTAB_INCLUDED
	   if (xdb)
	      p = pos_of_dnttpointer(dt);
#endif
	   dt->been_outed = non;
	   if (dt->key == DIAG_TYPE_STRUCT)
	   {
	      fields = dt->data.t_struct.fields;
	      s = dt->data.t_struct.tdf_shape;
	      su = 's';
#ifdef _SYMTAB_INCLUDED
	      p.word-=2;
#endif
	   }
	   else
	   {
	      fields = dt->data.t_union.fields;
	      s = dt->data.t_union.tdf_shape;
	      su = 'u';
#ifdef _SYMTAB_INCLUDED
	      p.word--;
#endif
	   }
	   if (xdb)
	   {
#ifdef _SYMTAB_INCLUDED
	      DNTTPOINTER lastfield = NIL;
	      type_info[non].p = p;
	      for (i=0;i<fields->lastused;i++)
	      {
		 diag_field f = (fields->array)[i];
		 unsigned long bitoffset = no(f->where);
		 DNTTPOINTER type = out_dt_shape(f->field_type);
		 lastfield = make_dnttentry(K_FIELD, vt_next, bitoffset, type, last_type_sz, lastfield);
		 make_vtentry(f->field_name.ints.chars,0,0);
	      }

	      if (lntt_next.word != p.word)
	      {
		 fprintf(stderr,"hppatrans warning: trans made an error whilst compiling XDB diagnostics tables\n");
	      }

 	      if (dt->key == DIAG_TYPE_STRUCT)
	      {
		 make_dnttentry(K_STRUCT, 0, lastfield, NIL, NIL, shape_size(s));
	      }
	      else
	      {
		 make_dnttentry(K_UNION, lastfield, shape_size(s));
	      }
#endif
	   }
	   else
	   {
 	      fprintf(dg_file,"%ld=%c%d",non,su,shape_size(s) /8);
  	      for (i=fields->lastused-1;i>=0;i--)
	      {
		 diag_field sf = (fields->array)[i];
		 unsigned long offset = no(sf->where);
#if 0
       	         if (depth_now >= max_depth)
		   return NIL;
		 depth_now++;
#endif
		 fprintf(dg_file,"%s:",sf->field_name.ints.chars);
		 out_dt_shape(sf->field_type);
		 fprintf(dg_file,",%ld,%ld;",offset,last_type_sz);
	      }
	      fprintf(dg_file,";");
	   }
	   last_type_sz = shape_size(s);
	   set_stab_size(non);
	   return p;
	}

	case DIAG_TYPE_FLOAT:
	case DIAG_TYPE_VARIETY:
	  {
	     shape sha;
	     if (dt->key==DIAG_TYPE_VARIETY)
	     {
		sha = f_integer(dt->data.var);
	     }
	     else
	     {
		sha = f_floating(dt->data.f_var);
	     }
	     dt->been_outed = out_sh_type(sha);
	     if (xdb)
	     {
#ifdef _SYMTAB_INCLUDED
		return type_info[dt->been_outed].p;
#endif
	     }
	     else
	     {
		fprintf(dg_file,"%ld",dt->been_outed);
	     }
	     return NIL;
	  }

	case DIAG_TYPE_PROC:
	  {
	     diag_type result_type = dt->data.proc.result_type;
	     long non1 = next_typen();
	     long non2 = next_typen();
	     DNTTPOINTER p = NIL;
	     dt->been_outed = non1;
	     if (xdb)
	     {
#ifdef _SYMTAB_INCLUDED
		p = make_dnttentry(K_POINTER, make_DNTTP_IMMEDIATE(T_FLABEL), 32);
		type_info[non1].p = p;
#endif
	     }
	     else
	     {
 	        fprintf(dg_file, "%ld=*%ld=f", non1, non2);
	     }
	     out_dt_shape(result_type);
	     last_type_sz = 32;
	     set_stab_size(non1);
	     set_stab_size(non2);
	     return p;
	  }

	case DIAG_TYPE_LOC:
	  {
	     /* +++ use qualifier which gives "const"/"volatile" */
	     return out_dt_shape(dt->data.loc.object);
	  }

	case DIAG_TYPE_NULL:
	  {
	     if (gdb)
		fprintf(dg_file,"%d",STAB_VOID);
	     last_type_sz = 0;
	     return NIL;
	  }

	case DIAG_TYPE_BITFIELD:
	  {
	     long sz = dt->data.bitfield.no_of_bits.nat_val.small_nat;
	     last_type_sz = sz;
	     if (xdb)
	     {
#ifdef _SYMTAB_INCLUDED

		return type_info[STAB_SLONG].p;
#endif
	     }
	     else
	     {
		fprintf(dg_file,"%d",STAB_SLONG);
	     }
	     return NIL;
	  }

	case DIAG_TYPE_ENUM:
	{
#if 1
	   /*  Currently tdfc (August 95) does not generate DIAG_TYPE_ENUM.
	       Enable and test this when DIAG_TYPE_ENUM is generated.  */

      /*
       * TypeDef:	e EnumList ;		"Enumerated type (default size, 32 bits)"
       * EnumList:	Enum | EnumList Enum
       * Enum:		NAME : OrdValue ,	"Enumerated scalar description"
       * OrdValue:	INTEGER			"Associated numeric value"
       */
	   enum_values_list enumvals = dt->data.t_enum.values;
	   enum_values *enumarr = (enumvals->array);
	   int nvals = enumvals->len;
	   char *nm = dt->data.t_enum.nme.ints.chars;
	   int i;
	   DNTTPOINTER p = NIL;
	   long non;
	   if (xdb)
	   {
#ifdef _SYMTAB_INCLUDED
	      DNTTPOINTER firstmem;
	      if (nvals>0)
	      {
		 firstmem = lntt_next;
		 firstmem.word+=2;
	      }
	      else
	      {
		 firstmem = NIL;
	      }
	      make_dnttentry(K_TAGDEF,(BITS)1,(BITS)1,vt_next,lntt_next);
	      make_vtentry(nm,0,0);
	      p = make_dnttentry(K_ENUM, firstmem, 32);
	      for (i=0;i<nvals;i++)
	      {
		 DNTTPOINTER nextmem;
		 if (i==nvals-1)
		 {
		    nextmem = NIL;
		 }
		 else
		 {
		    nextmem = lntt_next;
		    nextmem.word+=2;
		 }
		 make_dnttentry(K_MEMENUM, vt_next, EXPINT(enumarr[i] ->val), nextmem);
		 make_vtentry(CSTRING(enumarr[i] ->nme),0,0);
	      }
#endif
	   }
	   else
	   {
	      fprintf(dg_file,"e");
	      for (i=0;i<nvals;i++)
	      {
		 fprintf(dg_file,"%s:%d,",CSTRING(enumarr[i] ->nme), EXPINT(enumarr[i] ->val));
	      }
	      fprintf(dg_file,";");
	   }
	   non = next_typen();
	   dt->been_outed = non;
	   type_info[non].p = p;
	   last_type_sz = 32;
	   set_stab_size(non);
	   return p;
#else
	   /* For now, simply output the base integer type */
	   out_dt_shape(dt->data.t_enum.base_type);
	   last_type_sz = 32;
#endif
	   break;
	}

	default:
	{
	   if (gdb)
	      fprintf(dg_file,"%d",STAB_VOID);
	   last_type_sz = 0;
	   return NIL;
	}
    }
    return NIL;
}


/*
    OUTPUT DIAGNOSTICS FOR A GLOBAL VARIABLE
*/

void stab_global
(exp global, char * id, bool ext)
{
  char *nm;
  diag_descriptor *dd = find_dd(global);

  if (dd==NULL)
     return;
  nm = dd->data.id.nme.ints.chars;
  stabd(find_file(dd->data.id.whence.file->file.ints.chars),
	(long)dd->data.id.whence.line_no.nat_val.small_nat
	 , -N_DSLINE);
  if (xdb)
  {
#ifdef _SYMTAB_INCLUDED
     if (ext)
	make_dnttentry(K_SVAR, 1, 0, 0, vt_next,(STATTYPE)nm, OUT_DT_SHAPE(dd->data.id.new_type), 0, 0, GNTT);
      else
	 make_dnttentry(K_SVAR, 0, 0, 0, vt_next,(STATTYPE)id, OUT_DT_SHAPE(dd->data.id.new_type), 0, 0, LNTT);
      make_vtentry(nm,0,0);
#endif
  }
  else
  {
     fprintf(dg_file,"\t.stabs\t\"%s:%c", nm,(ext ? 'G' : 'S'));
     OUT_DT_SHAPE(dd->data.id.new_type);
     fprintf(dg_file,"\",%#x,0,%d,%s\n",(ext ? 0x24 :((no(global)!=0)?0x26:0x28)),
	   dd->data.id.whence.line_no.nat_val.small_nat /*0*/,
	   id
	  );
  }
  return;
}


/*
    OUTPUT DIAGNOSTICS FOR A PROCEDURE
*/

void stab_proc
(exp proc, char * id, bool public)
{
   char *nm;
   diag_descriptor *dd = find_dd(proc);
   if (dd == NULL)
      return;
   stabd(find_file(dd->data.id.whence.file->file.ints.chars)	,
	(long)dd->data.id.whence.line_no.nat_val.small_nat
	 ,0);
   nm = id;
   if (gdb)
      fprintf(dg_file, "\t.stabs\t\"%s:%c",nm,(public ? 'F' : 'f'));
   OUT_DT_SHAPE(dd->data.id.new_type->data.proc.result_type);

   if (gdb)
      fprintf(dg_file,"\",0x24,0,%ld,%s\n",currentlno,id);

   last_proc_lab = id;		/* id is passed from translate_capsule,
				 so stays in scope while needed */
   if (xdb)
   {
#ifdef _SYMTAB_INCLUDED
      DNTTPOINTER retval;
      SLTPOINTER slt_prev;
      BITS varargs;
      VTPOINTER entry = is_vt_entry(currentfile);
      slt_prev = slt_next;
      make_sltentry(SLT_SRCFILE, 1, lntt_next);
      make_dnttentry(K_SRCFILE, LANG_C,(entry==VTNIL ? vt_next : entry), slt_prev);
      if (entry==VTNIL)
	 make_vtentry(fds[currentfile] ->file.ints.chars,1,currentfile);

      slt_prev = slt_next;
      make_sltentry(SLT_FUNCTION, currentlno, lntt_next);
      retval = make_DNTTP_IMMEDIATE(T_INT);
      varargs = (BITS)dd->data.id.new_type->data.proc.opt_args;
      if (strcmp(nm,"main") ==0)
      {
	 make_dnttentry(K_FUNCTION,(BITS)public, LANG_C,(BITS)0,(BITS)0,
			varargs,(BITS)0, vt_next, vt_next+5, NIL, slt_prev,
			(ADDRESS)"main", retval,(ADDRESS)"main",
			(ADDRESS)"_main_end_");
	 make_vtentry("main",0,0);
	 make_vtentry("_MAIN_",0,0);
      }
      else
      {
	 char *address = nm, *lowaddr = nm, hiaddr[128];
	 sprintf(hiaddr,"_%s_end_",address);
	 make_dnttentry(K_FUNCTION,(BITS)public, LANG_C,(BITS)0,(BITS)0,
			varargs,(BITS)0, vt_next, VTNIL, NIL, slt_prev,
			(ADDRESS)address, retval,(ADDRESS)lowaddr,
			(ADDRESS)hiaddr);
	 make_vtentry(nm,0,0);
      }

      slt_prev = slt_next;
      make_sltentry(SLT_BEGIN,(BITS)currentlno, lntt_next);
      make_dnttentry(K_BEGIN, slt_prev);
#endif
   }

   return;
}

#ifdef _SYMTAB_INCLUDED
void close_function_scope
(int res_label)
{
   SLTPOINTER slt_prev = slt_next;
   char address[128];
   sprintf(address,"L$$%d-%s",res_label,last_proc_lab);
   make_sltentry(SLT_EXIT, last_lno,(ADDRESS)address);
   make_sltentry(SLT_END, last_lno, lntt_next);
   make_dnttentry(K_END, K_BEGIN, slt_prev, last_DNTT_BEGIN_entry());
   slt_prev = slt_next;
   make_sltentry(SLT_END, last_lno, lntt_next);
   make_dnttentry(K_END, K_FUNCTION, slt_prev, last_DNTT_BEGIN_entry());
}
#endif

/*
    OUTPUT DIAGNOSTICS FOR A LOCAL VARIABLE
*/

/* ARGSUSED */ void stab_local
(char *nm, diag_type dt, exp ldid, long disp, long findex)
{
    exp id = son(ldid);
    disp += boff(id).offset;
    again:
    if (name(id) == ident_tag)
    {
       if ((props(id) & defer_bit) == 0)
       {
	  /* +++ add assembler comment to say which reg is being used */
	  if (isparam(id))
	  {
	     if (xdb)
	     {
#ifdef _SYMTAB_INCLUDED
		/* Seems as if parameters are treated like locals by xdb  */
#if 0
		make_dnttentry(K_FPARAM, 0, 0, 0, 0, vt_next, disp, OUT_DT_SHAPE(dt), NIL);
#endif
		make_dnttentry(K_DVAR, 0, 0, 0, vt_next, disp, OUT_DT_SHAPE(dt), 0);
		make_vtentry(nm,0,0);
#endif
	     }
	     else
	     {
		fprintf(dg_file, "\t.stabs\t\"%s:p", nm);
		OUT_DT_SHAPE(dt);
		fprintf(dg_file, "\",0xa0,0,%d,%ld\n",
#if 0
			 shape_size(sh(son(id))) / 8,
#else
			 0,
#endif
			 disp+ (frame_sz>>3));
	     }
	     return;
	  }
	  else
	  {
	     if (xdb)
	     {
#ifdef _SYMTAB_INCLUDED
		make_dnttentry(K_DVAR, 0, 0, 0, vt_next, disp,
			       OUT_DT_SHAPE(dt),
			       0);
		make_vtentry(nm,0,0);
#endif
	     }
	     else
	     {
		fprintf(dg_file, "\t.stabs\t\"%s:", nm);
		OUT_DT_SHAPE(dt);
		fprintf(dg_file,"\",0x80,0,%ld,%ld\n",currentlno,disp+ (frame_sz>>3));
	     }
	     return;
	  }
       }
       else
       {
	  exp sn = son(id);
	  long d = disp;
	  while (sn != nilexp)
	  {
	     switch (name(sn))
	     {
		case name_tag:
		{
		   disp = d + no(sn);
		   id = son(sn);
		   if (isvar(id))
		      dt = dt->data.ptr.object;
		   goto again;
		}
		case reff_tag:
		{
		   d += no(sn);
		   sn = son(sn);
		   break;
		}
		case cont_tag:
		{
		   sn = son(sn);
		   break;
		}
		default:
		{
		   return;
		}
	     }
	  }
       }
    }
    return;
}


/*
    DEAL WITH BASIC TYPES
*/

void stab_types
(void)
{
    no_type_info = NO_STABS;
    type_info = (type_info_t *)xmalloc(NO_STABS * sizeof(type_info_t));
    if (xdb)
    {
#ifdef _SYMTAB_INCLUDED
       type_info[STAB_SCHAR].p = make_DNTTP_IMMEDIATE(T_CHAR, 8);
       type_info[STAB_UCHAR].p = make_DNTTP_IMMEDIATE(T_UNS_INT, 8);
       type_info[STAB_SSHRT].p = make_DNTTP_IMMEDIATE(T_INT, 16);
       type_info[STAB_USHRT].p = make_DNTTP_IMMEDIATE(T_UNS_INT, 16);
       type_info[STAB_SLONG].p = make_DNTTP_IMMEDIATE(T_LONG, 32);
       type_info[STAB_ULONG].p = make_DNTTP_IMMEDIATE(T_UNS_LONG, 32);
       type_info[STAB_FLOAT].p = make_DNTTP_IMMEDIATE(T_REAL, 32);
       type_info[STAB_DBL].p   = make_DNTTP_IMMEDIATE(T_REAL, 64);
       type_info[STAB_LDBL].p  = make_DNTTP_IMMEDIATE(T_REAL, 128);
#endif
    }
    else
    {
       fputs("\t.stabs\t\"int:t1=r1;-2147483648;2147483647;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"short int:t2=r1;-32768;32767;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"short unsigned int:t3=r1;0;65535;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"char:t4=r4;0;127;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"signed char:t5=r1;-128;127;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"unsigned char:t6=r1;0;255;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"long int:t7=r1;-2147483648;2147483647;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"unsigned int:t8=r1;0;-1;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"long unsigned int:t9=r1;0;-1;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"float:t10=r1;4;0;\",0x80,0,0,0\n",
	    dg_file);
       fputs("\t.stabs\t\"double:t11=r1;8;0;\",0x80,0,0,0\n",
	    dg_file);
       fprintf(dg_file,"\t.stabs\t\"long double:t12=r1;8;0;\",0x80,0,0,0\n");
       fputs("\t.stabs\t\"void:t13=13\",0x80,0,0,0\n",
	    dg_file);
    }
    type_info[0].sz = 0;
    type_info[1].sz = 32;
    type_info[2].sz = 16;
    type_info[3].sz = 16;
    type_info[4].sz = 8;
    type_info[5].sz = 8;
    type_info[6].sz = 8;
    type_info[7].sz = 32;
    type_info[8].sz = 32;
    type_info[9].sz = 32;
    type_info[10].sz = 32;
    type_info[11].sz = 64;
    type_info[12].sz = DOUBLE_SZ;
    type_info[13].sz = 0;
    return;
}


/*
    DEAL WITH STRUCTURE AND UNION TAGS
*/

void stab_tagdefs
(void)
{
    diag_tagdef **di = unit_ind_diagtags;
    unsigned int n = unit_no_of_diagtags;
    int i;

    for (i = 0; i < n; i++)
    {
	diag_type d = di[i] ->d_type;
	switch (d->key)
	{
	    case DIAG_TYPE_STRUCT:
	    case DIAG_TYPE_UNION:
	    {
		char *nme;
		if (d->key == DIAG_TYPE_STRUCT) {
		    nme = d->data.t_struct.nme.ints.chars;
		} else {
		    nme = d->data.t_union.nme.ints.chars;
		}

		if (nme && *nme)
		{
		    if (gdb)
		       fprintf(dg_file, "\t.stabs\t\"%s:", nme);
		}
		else
		if (d->key == DIAG_TYPE_STRUCT)
		{
/*		   static int s_count = 0 ; gcc complains */
		   if (gdb)
		      fprintf(dg_file, "\t.stabs\t\"s:");
		}
		else
		{
/*		   static int u_count = 0 ; gcc complains */
		   if (gdb)
  		      fprintf(dg_file, "\t.stabs\t\"u:");
		}
		if (d->been_outed && 0)
		{
		   if (gdb)
		      fprintf(dg_file, "%d",(int)d->been_outed);
		}
		else
		{
		   if (gdb)
		      fprintf(dg_file, "T");
		   OUT_DT_SHAPE(d);
		}
		if (gdb)
		   fprintf(dg_file, "\",0x80,0,0,0\n");
		break;
	    }
	    case DIAG_TYPE_UNINIT:
	    case DIAG_TYPE_INITED:
		assert(0);
	    default:
		break;
	}
    }
    return;
}


/*
    DEAL WITH TYPEDEFS
*/

void stab_typedefs
(void)
{
    diag_descriptor *di = unit_diagvar_tab.array;
    int i, n = unit_diagvar_tab.lastused;
    for (i = 0; i < n; i++) {
	if (di[i].key == DIAG_TYPEDEF_KEY)
	{
	    long non = next_typen();
	    if (gdb)
	       fprintf(dg_file, "\t.stabs\t\"%s:t%ld=",
		      di[i].data.typ.nme.ints.chars, non);
	    OUT_DT_SHAPE(di[i].data.typ.new_type);
	    if (gdb)
	       fprintf(dg_file, "\",0x80,0,0,0\n");
	}
    }
    return;
}