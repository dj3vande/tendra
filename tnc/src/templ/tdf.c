/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


@special external
@special token
@special tokdec
@special tokdef
@special tagdec
@special tagdef
@special al_tagdef
@special version
@special token_defn
/* AUTOMATICALLY GENERATED BY %ZX VERSION %ZV FROM TDF %VA.%VB */

#include <stddef.h>

#include <shared/bool.h>
#include <shared/check.h>

#include <tdf/magic.h>

#include "types.h"
#include "de_types.h"
#include "enc_types.h"
#include "check.h"
#include "decode.h"
#include "de_capsule.h"
#include "de_unit.h"
#include "encode.h"
#include "node.h"
#include "read.h"
#include "shape.h"
#include "table.h"
#include "tdf.h"
#include "utility.h"


void
init_constructs(void)
{
    sortname s;
@loop sort
@if sort.basic
@if !sort.special

    s = SORT_%SN;
@if sort.eq.sortname
    new_sort(s, %3SM);
@else
    sort_letters[s] = '%SX';
    sort_encoding[s] = %SB;
    sort_extension[s] = %SE;
    sort_decode[s] = de_%SN;
    sort_read[s] = read_%SN;
    new_sort(s, %1SM);
@endif
@loop sort.cons
@if cons.params
@if cons.token
    new_cons("%CN", s, %CE, "!");
    sort_tokens[s] = %CE;
@else
@if cons.eq.identify
    new_cons("%CN", s, %CE, "?[u]t^x{x}");
@else
    new_cons("%CN", s, %CE, "%CX");
@if cons.cond
    sort_conds[s] = %CE;
@endif
@endif
@endif
@else
@if cons.eq.alignment_sort
    new_cons("alignment", s, %CE, NULL);
@else
    new_cons("%CN", s, %CE, NULL);
@endif
@endif
@end
@if sort.eq.sortname
    new_cons("callees", s, %1SM, NULL);
    new_cons("error_code", s, %2SM, NULL);
@endif
@endif
@endif
@end
    return;
}
@special sortname


sortname
find_sort(char c)
{
    sortname s;
    switch (c) {
@loop sort
@if sort.basic
@if !sort.special
	case '%SX': s = SORT_%SN; break;
@endif
@endif
@end
	default : {
	    input_error("Illegal decode letter, %%c", c);
	    s = SORT_unknown;
	    break;
	}
    }
    return s;
}
@loop sort
@if sort.basic


/* DECODE A %ST */

@if sort.special
long
de_%SN_bits(void)
@else
node *
de_%SN(void)
@endif
{
@if sort.extends
    long n = fetch_extn(%SB%1u);
@else
    long n = fetch(%SB%0u);
@endif
@if sort.special
    if (n < %u || n > %SM) {
	input_error("Illegal %SN value, %%ld", n);
    }
    return n;
@else
    char *args;
    node *p = new_node();
    construct *cons = cons_no(SORT_%SN, n);
    p->cons = cons;
    if (n < %u || n > %SM || cons->name == NULL) {
	input_error("Illegal %SN value, %%ld", n);
    }
@if sort.eq.callees
    args = get_char_info(cons);
    if (args) {
	p->son = de_node(args);
    }
@else
@if sort.eq.error_code
    args = get_char_info(cons);
    if (args) {
	p->son = de_node(args);
    }
@else
    switch (n) {
@loop sort.cons
@if cons.token
	case %CE: {
	    IGNORE de_token(p, SORT_%SN);
	    break;
	}
@else
@if cons.cond
	case %CE: {
	    args = get_char_info(cons);
	    p->son = de_node(args);
	    if (do_check) {
		checking = "%CN";
		IGNORE check1(ENC_integer, p->son);
	    }
	    break;
	}
@else
@if cons.edge
	case %CE: {
@if sort.link
	    p->son = de_var_sort(%SN_var);
@else
	    long m = tdf_int();
	    p->son = new_node();
	    p->son->cons = find_%SN(m);
@endif
	    break;
	}
@endif
@endif
@endif
@end
	default : {
	    args = get_char_info(cons);
	    if (args) {
		p->son = de_node(args);
	    }
	    break;
	}
    }
@endif
@endif
#ifdef check_%SN
    check_%SN(p);
#endif
    return p;
@endif
}
@endif
@end
@loop sort
@if sort.basic
@if sort.special


/* ENCODE A %ST */

void
enc_%SN_bits(bitstream *p, int n)
{
@if sort.extends
    enc_bits_extn(p, %SB,(long)n);
@else
    enc_bits(p, %SB,(long)n);
@endif
    return;
}
@else
@if sort.edge


/* ENCODE A %ST */

void
enc_%SN_bits(bitstream *p, int n)
{
@if sort.extends
    enc_bits_extn(p, %SB,(long)n);
@else
    enc_bits(p, %SB,(long)n);
@endif
    return;
}
@endif
@endif
@endif
@end
@special exp sequence
@special signed_nat make_signed_nat
@loop sort
@if sort.basic
@if !sort.special


/* READ A %ST */

node *
read_%SN(long n)
{
    char *args;
    node *p = new_node();
    construct *cons = cons_no(SORT_%SN, n);
    p->cons = cons;
    if (n < 0 || n > %SM || cons->name == NULL) {
	input_error("Illegal %SN value, %%ld", n);
    }
@if sort.eq.callees
    args = get_char_info(cons);
    if (args) {
	p->son = read_node(args);
    }
@else
@if sort.eq.error_code
    args = get_char_info(cons);
    if (args) {
	p->son = read_node(args);
    }
@else
    switch (n) {
@loop sort.cons
@if cons.token
	case %CE: {
	    read_token(p, SORT_%SN);
	    break;
	}
@else
@if cons.cond
	case %CE: {
	    args = get_char_info(cons);
	    p->son = read_node(args);
	    if (do_check) {
		checking = "%CN";
		IGNORE check1(ENC_integer, p->son);
	    }
	    break;
	}
@else
@if cons.edge
	case %CE: {
	    p->son = read_var_sort(SORT_%SN);
	    break;
	}
@else
@if cons.special
	case %CE: {
	    read_%CN(p, get_char_info(cons));
	    break;
	}
@endif
@endif
@endif
@endif
@end
	default : {
	    args = get_char_info(cons);
	    if (args) {
		p->son = read_node(args);
	    }
	    break;
	}
    }
@endif
@endif
#ifdef check_%SN
    check_%SN(p);
#endif
    return p;
}
@endif
@endif
@end
