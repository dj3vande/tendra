# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.


+IMPLEMENT "c/c89", "stdarg.h.ts", "va_args" ;

+DEFINE va_alist	%% ... %% ;
+DEFINE va_dcl		%% %% ;
+DEFINE va_start.1 (l)	%% ( ( void ) ( l = __va_start ( ... ) ) ) %% ;
