# TenDRA C and C++ Producers

This directory contains the source for the TenDRA C to TDF and C++ to TDF
producers.  Most of the source is shared between the producers and is
defined in the common directory.  The language dependent components
for the C and C++ producers are defined in the c and cpp directories
respectively.  The primary language dependent component is the sid
grammar for each language which determines which features of the common
section can be accessed.  Each language dependent directory also contains
a header, language.h, which defines macros:

    LANGUAGE_C and LANGUAGE_CPP

which are used in the common source to select behaviour where the languages
differ, and to comment out sections which are not used by a particular
language.
