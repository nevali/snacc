## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.4 foreign

# This Makefile is never actually run - it exists to generate a
# template Makefile.in that configure modifies into Makefiles for the
# buffer-type build directories:

lib_LTLIBRARIES = libasn1cbuf.la
BUILT_SOURCES = asn-useful.c asn-useful.h tbl.h tbl.c
libasn1cbuf_la_SOURCES = asn-any.c asn-len.c asn-real.c print.c tbl-enc.c \
	asn-bits.c asn-list.c asn-tag.c tbl-free.c \
	asn-bool.c asn-null.c exp-buf.c str-stk.c tbl-gen.c \
	asn-enum.c asn-octs.c hash.c tbl-dbg.c tbl-print.c \
	asn-int.c asn-oid.c sbuf.c nibble-alloc.c tbl-dec.c tbl-util.c $(BUILT_SOURCES)
cpkgincludedir = $(pkgincludedir)/c
cpkginclude_HEADERS = asn-useful.h tbl.h
INCLUDES = -I$(top_srcdir)/c-lib/inc $(BUFFLAGS)

COMPILERDIR = $(top_srcdir)/compiler
SNACC = $(COMPILERDIR)/core/snacc
ASN1_SRC_DIR = $(top_srcdir)/asn1specs
USEFUL_TYPES = $(ASN1_SRC_DIR)/asn-useful.asn1

# dependency to get the built sources made:
# NB: tbl-enc.lo was chosen because it is the first object referenced
# by libasn1cbuf_la_SOURCES that requires the built sources.
tbl-enc.lo: $(BUILT_SOURCES)

# target to make asn-useful.c and asn-useful.h:
asn-useful.h asn-useful.c: $(SNACC) $(USEFUL_TYPES)
	$(SNACC) -c -l 50 $(USEFUL_TYPES)

# target to make tbl.c and tbl.h:
tbl.h tbl.c: $(SNACC) $(USEFUL_TYPES) $(ASN1_SRC_DIR)/tbl.asn1
	$(SNACC) -u $(USEFUL_TYPES) $(ASN1_SRC_DIR)/tbl.asn1
	@PATCH@ < $(top_srcdir)/c-lib/tbl.h.patch
	echo '#if TTBL' > tbl.c.tmp
	cat tbl.c >> tbl.c.tmp
	echo '#endif /* TTBL */' >> tbl.c.tmp
	mv tbl.c.tmp tbl.c

# target to make remote things:
$(SNACC): force
	cd `dirname $@` && $(MAKE) `basename $@`
force: ;

# target to hook the distribution:
dist-hook:
	cd $(distdir) && rm -rf $(BUILT_SOURCES)
