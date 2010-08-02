## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.3 foreign

bin_PROGRAMS = mkchdr
mkchdr_SOURCES = mkchdr.c tbl-gen-c-hdr.c
INCLUDES = -I$(top_srcdir)/c-lib/inc -DUSE_SBUF -I$(top_srcdir)/c-lib/tbl
mkchdr_LDADD = ../../c-lib/tbl/libasn1ctbl.la
