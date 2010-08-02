## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.3 foreign

bin_PROGRAMS = ptbl
ptbl_SOURCES = ptbl.c pasn1.c pasn1.h
INCLUDES = -I$(top_srcdir)/c-lib/inc -DUSE_GEN_BUF -I$(top_srcdir)/c-lib/tbl
ptbl_LDADD = ../../c-lib/tbl/libasn1ctbl.la
