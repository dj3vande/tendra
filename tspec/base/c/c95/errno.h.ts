# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.

+IMPLEMENT "c/c89", "errno.h.ts";

# 7.1.4
+SUBSET "i18n" := {
	+CONST int EILSEQ;
};

