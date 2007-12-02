/*
 * Copyright (c) 2002-2006 The TenDRA Project <http://www.tendra.org/>.
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


/**** nstring-list.c --- String list ADT.
 *
 ** Author: Steve Folkes <smf@hermes.mod.uk>
 *
 **** Commentary:
 *
 * This file implements the string list facility specified in the file
 * "nstring-list.h".  See that file for more details.
 *
 **** Change Log:
 * $Log: nstring-list.c,v $
 * Revision 1.1.1.1  1998/01/17  15:57:17  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1994/12/12  11:44:47  smf
 * Performing changes for 'CR94_178.sid+tld-update' - bringing in line with
 * OSSG C Coding Standards.
 *
 * Revision 1.1.1.1  1994/07/25  16:05:52  smf
 * Initial import of library shared files.
 *
**/

/****************************************************************************/

#include "nstring-list.h"

/*--------------------------------------------------------------------------*/

void
nstring_list_init(NStringListP list)
{
    list->head = NIL(NStringListEntryP);
    list->tail = & (list->head);
}

void
nstring_list_append(NStringListP list,			     NStringP     string)
{
    NStringListEntryP entry = ALLOCATE(NStringListEntryT);

    entry->next   = NIL(NStringListEntryP);
    nstring_assign(& (entry->string), string);
    *(list->tail) = entry;
    list->tail    = & (entry->next);
}

NStringListEntryP
nstring_list_head(NStringListP list)
{
    return(list->head);
}

NStringP
nstring_list_entry_string(NStringListEntryP entry)
{
    return(& (entry->string));
}

NStringListEntryP
nstring_list_entry_deallocate(NStringListEntryP entry)
{
    NStringListEntryP next = entry->next;

    DEALLOCATE(entry);
    return(next);
}

/*
 * Local variables(smf):
 * eval: (include::add-path-entry "../os-interface" "../generated")
 * end:
**/