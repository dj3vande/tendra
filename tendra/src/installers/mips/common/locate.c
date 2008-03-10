/*
 * Copyright (c) 2002, The Tendra Project <http://www.ten15.org/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *    		 Crown Copyright (c) 1997
 *
 *    This TenDRA(r) Computer Program is subject to Copyright
 *    owned by the United Kingdom Secretary of State for Defence
 *    acting through the Defence Evaluation and Research Agency
 *    (DERA).  It is made available to Recipients with a
 *    royalty-free licence for its use, reproduction, transfer
 *    to other parties and amendment for any purpose not excluding
 *    product development provided that any such use et cetera
 *    shall be deemed to be acceptance of the following conditions:-
 *
 *        (1) Its Recipients shall ensure that this Notice is
 *        reproduced upon any copies or amended versions of it;
 *
 *        (2) Any amended version of it shall be clearly marked to
 *        show both the nature of and the organisation responsible
 *        for the relevant amendment or amendments;
 *
 *        (3) Its onward transfer from a recipient to another
 *        party shall be deemed to be that party's acceptance of
 *        these conditions;
 *
 *        (4) DERA gives no warranty or assurance as to its
 *        quality or suitability for any purpose and DERA accepts
 *        no liability whatsoever in relation to any use to which
 *        it may be put.
 *
 * $TenDRA$
 */


/* locate.c
 *     discovers "where" an "exp" is;
 *     The where coding of an address tells one whether the result of
 *      evaluating an exp is in a register or directly or literally in store,
 */


#include "config.h"
#include "addrtypes.h"
#include "tags.h"
#include "inst_fmt.h"
#include "mips_ins.h"
#include "bitsmacs.h"
#include "exp.h"
#include "procrectypes.h"
#include "guard.h"
#include "eval.h"
#include "regexps.h"
#include "shapemacs.h"
#include "psu_ops.h"
#include "getregs.h"
#include "move.h"
#include "handle_sregs.h"
#include "common_types.h"
#include "frames.h"
#include "code_here.h"
#include "locate.h"
#include "basicread.h"

extern  FILE * as_file;

long  locals_offset;		/* the offset in bits of start of current
							 *				   locals */
long  frame_size;		/* the size of the current stack frame in
						 *				   bits */


baseoff
boff(exp id)
{		/* decodes id to give a baseoff suitable
		 *				   for ls_ins etc */
	baseoff an;
	if (isglob (id)) {		/* globals */
		dec * gl = brog(id);
		long sno = gl->dec_u.dec_val.sym_number;
		an.base = -(sno + 1);
		an.offset = 0;
	}
	else {
		int   x = no (id);
		int   b = x & 0x3f;
		if (name(son(id))==caller_name_tag) {
			an.base = 29;
			an.offset = (x-b)>>4;
			/* caller tags */
		}
		else
			if (b == 29) {
				an.base = 29;
				an.offset = ((x - b) >> 4) + (locals_offset >> 3);
				/* locally declared things accessed by sp*/
			}
			else
				if ((b==30 && Has_fp)) {
					an.base = b;
					an.offset = (((x - b)) >> 4) + (locals_offset >> 3)
						- ((frame_size+callee_size)>>3);
					/* locally declared things accessed by fp  */
				}
				else
					if ((b == local_reg && Has_vcallees)) {
						an.base = b;
						an.offset = (((x - b)) >> 4) + (locals_offset >> 3)
							- (frame_size>>3);
						/* locally declared things accessed by local_reg */
					}
					else
						if (b <= 31) {
							an.base = b;
							an.offset = ((x - b) >> 4);
							/* other base offsets */
						}
						else
							if (b == 32) {
								an.base = -((x - b) >> 6);
								an.offset = 0;
								/* global names  */
							}
							else
								if (b == 33) {
									an.base = (x - b) >> 6;
									an.offset = 0;
									/* global anonymous */
								}
								else {
									failer ("not a baseoff in boff ");
								}
	}
	return an;
}

where locate(exp e, space sp, shape s, int dreg);
/* locate differs from locate1 only in that it looks to see e has already
 *    been evaluated somehow */

where
locate1(exp e, space sp, shape s, int dreg)
{
	/* finds the address of e using shape s;
	 *				   sp gives available t-regs for any inner
	 *				   evaluation. dreg is historical. */
	ash a;
	ans aa;
	where wans;
	a = ashof (s);
	
/*  while (name (e) == diag_tag || name (e) == fscope_tag
 *      || name (e) == cscope_tag) {
 *    e = son (e);
 *  }
 */
	switch (name (e)) {
    case name_tag:
	{
		exp decx = son (e);
		bool var = isvar (decx);
		/* this a locally declared name ... */
		if (props (decx) & defer_bit) {
			/* ... it has been identified with a
			 *				   simple expression which is better
			 *				   evaluated every time */
			where w;
			w = locate (son (decx), sp, sh (son (decx)), dreg);
			
			if (no (e) == 0) {
				aa = w.answhere;
			}
			else {
				instore is;
				switch (w.answhere.discrim) {
				case notinreg:
				{
					is = insalt (w.answhere);
					is.b.offset += (no (e) / 8);
					break;
				}
				default:
					failer ("NOT deferable");
				}
				
				setinsalt (aa, is);
			}
		}
		else
			if (props (decx) & inreg_bits) {
				/* ... it has been allocated in a fixed
				 *				   point reg */
				if (var) {
					setregalt (aa, no (decx));
				}
				else {
					instore b;
					b.b.base = no (decx);
					b.b.offset = 0;
					b.adval = 1;
					setinsalt (aa, b);
				}
			}
			else
				if (props (decx) & infreg_bits) {
					/* ... it has been allocated in a floating
					 *				   point reg */
					freg fr;
					fr.fr = no (decx);
					fr.dble = (a.ashsize == 64) ? 1 : 0;
					setfregalt (aa, fr);
				}
				else {		/* ... it is in memory */
					instore is;
					if (var || (name (sh (e)) == SH_PROC &&
								(son (decx) == nilexp || name (son (decx)) == proc_tag
								 || name (son (decx)) == general_proc_tag))) {
						is.adval = 1;
					}
					else {
						is.adval = 0;
					}
					is.b = boff (decx);
					is.b.offset += (no (e) / 8);
					setinsalt (aa, is);
				}
		wans.answhere = aa;
		wans.ashwhere = a;
		return wans;
	}
	
    case addptr_tag:
	{
		exp sum = son (e);
		where wsum;
		int   addend;
		space nsp;
		int   reg;
		int   ind;
		instore is;
		ans asum;
		wsum = locate (sum, sp, sh (sum), 0);
		asum = wsum.answhere;
		/* answer is going to be wsum displaced by integer result of
		 *	   evaluating bro(sum) */
		
		switch (asum.discrim) {
		case notinreg:
	    {
			is = insalt (asum);
			if (is.adval) {	/* wsum is a literal address in store ...
							 */
				baseoff b;
				b = is.b;
				if (b.base < 0 || b.base > 31) {
					/* ... it is not a base-offset , so make
					 *				   it one */
					reg = getreg (sp.fixed);
					ls_ins (i_la, reg, b);
					keepreg (sum, reg);
					b.base = reg;
					b.offset = 0;
				}
				nsp = guardreg (b.base, sp);
				
				addend = reg_operand (bro (sum), nsp);
				/* evaluate the displacement ... */
				if (dreg == 0)
					dreg = getreg (nsp.fixed);
				rrr_ins (i_addu, dreg, b.base, addend);
				/* ... add it to the base register into new reg */
				b.base = dreg;
				is.b = b;
				setinsalt (aa, is);
				wans.answhere = aa;
				wans.ashwhere = a;
				/* ...and use it as base a literal base-offset result */
				keepexp (e, aa);
				return wans;
			}
			else {		/* wsum represents an actual pointer in
						 *				   store... */
				ind = getreg (sp.fixed);
				ls_ins (i_lw, ind, is.b);
				/* ... so load it into a good register */
			}
			goto breakpt;
			/* should be break - thought there was cc error */
			
	    }			/* end notinreg */
		
		case inreg:
			/* wsum is already in reg */
	    {
			ind = regalt (asum);
			goto breakpt;
	    }
		
		default: {
			failer ("Locate ? reg");
	    }
		}			/* end case */
		
	  breakpt: 			/* register ind contains the evaluation of
						 *				   1st operand of addptr */
		nsp = guardreg (ind, sp);
		if (name(bro(sum)) == env_offset_tag
			|| name(bro(sum)) == general_env_offset_tag) {
			is.b.base = ind;
			is.b.offset = frame_offset(son(bro(sum)));
		}
		else {
			addend = reg_operand (bro (sum), nsp);
			/* evaluate displacement .... */
			if (dreg == 0)
				dreg = getreg (nsp.fixed);
			rrr_ins (i_addu, dreg, ind, addend);
			/* ... add it to ind in new reg */
			is.b.base = dreg;
			is.b.offset = 0;
        }
		is.adval = 1;
		setinsalt (aa, is);
		wans.answhere = aa;
		wans.ashwhere = a;
		/* ... and deliver literal base_offset */
		keepexp (e, aa);
		return wans;
	}				/* end add_ptr */
	
    case subptr_tag: 		/* this is nugatory - previous transforms
							 *				   make it into addptr or reff */
	{
		exp sum = son (e);
		int   ind = reg_operand (sum, sp);
		instore isa;
		isa.adval = 1;
		sum = bro (sum);
		if (name (sum) == val_tag) {
			instore isa;
			isa.b.base = ind;
			isa.b.offset = -no (e);
			setinsalt (aa, isa);
		}
		else {
			if (dreg == 0)
				dreg = getreg (sp.fixed);
			rrr_ins (i_subu, dreg, ind,
					 reg_operand (sum, guardreg (ind, sp)));
			isa.b.base = dreg;
			isa.b.offset = 0;
		}
		setinsalt (aa, isa);
		wans.answhere = aa;
		wans.ashwhere = a;
		keepexp (e, aa);
		return wans;
	}				/* end subptr */
	
    case reff_tag: {
		instore isa;
		
		wans = locate (son (e), sp, sh (son (e)), 0);
		/* answer is going to be wans displaced by no(e) */
		
		switch (wans.answhere.discrim) {
		case notinreg: {
			
			isa = insalt (wans.answhere);
			if (!isa.adval) {
				/* wans is an actual pointer  in store, so make it into a
				 *		   literal address.... */
				int   reg = getreg (sp.fixed);
				ls_ins (i_lw, reg, isa.b);
				isa.b.offset = 0;
				isa.b.base = reg;
				isa.adval = 1;
			}
			/* ... and add appropriate displacement to give result */
			isa.b.offset += no (e) / 8;
			setinsalt (wans.answhere, isa);
			keepexp (e, wans.answhere);
			break;
	    }
		case inreg: {
			/* wans is a pointer in a register */
			isa.b.base = regalt (wans.answhere);
			isa.adval = 1;
			isa.b.offset = no (e) / 8;
			setinsalt (wans.answhere, isa);
			break;
	    }
		default: {
			failer ("Locate ? reg ");
	    }
		}
		wans.ashwhere = a;
		return wans;
		
	}				/* end reff */
		
    case cont_tag:
    case contvol_tag:
	{
		exp s = son (e);
		ans ason;
		instore isa;
		int   reg;
		where fc;
		fc = locate (s, sp, sh (e), 0);
		ason = fc.answhere;
		/* answer is going to be the contents of address represented by fc
		 */
		
		switch (ason.discrim) {
		case notinreg:
	    {
			isa = insalt (ason);
			if (isa.adval) {	/* fc is a literal store address, so make
								 *				   it into a direct one */
				isa.adval = 0;
				setinsalt (aa, isa);
			}
			else {		/* fc is an actual pointer in store ....
						 */
				reg = getreg (sp.fixed);
				ls_ins (i_lw, reg, isa.b);
				/* .... so load it into reg and deliver direct base-offset
				 *		   (reg,0) */
				isa.b.base = reg;
				isa.b.offset = 0;
				setinsalt (aa, isa);
				if (name (e) != contvol_tag && fc.ashwhere.ashalign != 1)
					keepexp (e, aa);
			}
			goto breakson;
			
	    }			/* end notinrg */
		
		case inreg:
			/* this one is fraught - it depends on only being used in
			 *	       lh-value positions from vars- take care */
	    {
			isa.b.base = regalt (ason);
			isa.b.offset = 0;
			isa.adval = 1;
			setinsalt (aa, isa);
			/* fc is in register, so deliver literal(!?) base-offset */
			goto breakson;
	    }
		
		case infreg: 		/* ditto caveat above */
	    {
			aa = ason;
			goto breakson;
	    }
		
		default: {
			failer ("Locate ? reg");
	    }
		}
	  breakson:
		wans.answhere = aa;
		wans.ashwhere = a;
		return wans;
		
	}				/* end cont */
	
    case top_tag: 		/* does this ever happen ? */
	{
		setregalt (aa, 0);
		wans.answhere = aa;
		wans.ashwhere = a;
		return wans;
	}				/* end top */
	
	
	
    case field_tag: {
		instore isa;
		wans = locate (son (e), sp, sh (son (e)), 0);
		/* answer is wans displace literally by no(e); it should always be
		 *	   a literal store address */
		
		switch (wans.answhere.discrim) {
		case notinreg: {
			
			isa = insalt (wans.answhere);
			isa.b.offset += no (e) / 8;
			setinsalt (wans.answhere, isa);
			break;
	    }
		default:
			failer (" field should be transformed ");
		}
		wans.ashwhere = a;
		return wans;
	}				/* end field */
		
		
		
		
		
		
		
    default:
		/* general catch all; evaluate e into register and deliver it as a
		 *         literal store address */
	{
		int   r = reg_operand (e, sp);
		instore is;
		if (r == 2) {		/* guard possible result from proc - can
							 *				   do better */
			r = getreg (sp.fixed);
			mon_ins (i_move, r, 2);
		}
		is.b.base = r;
		is.b.offset = 0;
		is.adval = 1;
		setinsalt (aa, is);
		wans.answhere = aa;
		wans.ashwhere = a;
		return wans;
	}
	
	}
}

where
locate(exp e, space sp, shape s, int dreg)
{
	ans ak;
	where w;
	ak = iskept (e);
	if (ak.discrim == inreg && (regalt (ak) == 0)) {
		where w;
		w = locate1 (e, sp, s, dreg);
		return w;
	}
	else {			/* e has been evaluated into a register */
		w.answhere = ak;
		w.ashwhere = ashof (s);
	}
	return w;
}