## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.4 foreign

# This Makefile is never actually run - it exists to generate a
# template Makefile.in that configure modifies into Makefiles for the
# c++ and tcl build directories:

lib_LTLIBRARIES = libasn1cxxtcl.la
BUILT_SOURCES = asn-useful.C asn-useful.h
libasn1cxxtcl_la_SOURCES = asn-any.C asn-bits.C asn-bool.C asn-enum.C \
	asn-int.C asn-len.C asn-list.C asn-null.C asn-octs.C asn-oid.C \
	asn-real.C asn-tag.C asn-type.C hash.C meta.C print.C \
	tcl-if.C str-stk.C tkAppInit.c $(BUILT_SOURCES)
cxxpkgincludedir = $(pkgincludedir)/c++
cxxpkginclude_HEADERS = asn-useful.h
INCLUDES = -I$(top_srcdir)/c++-lib/inc $(BUFFLAGS)

ASN1_SRC_DIR = $(top_srcdir)/asn1specs
COMPILERDIR = $(top_srcdir)/compiler/core
SNACC = $(COMPILERDIR)/snacc
USEFUL_TYPES = $(ASN1_SRC_DIR)/asn-useful.asn1

# dependency to get the built sources made:
# NB: meta.lo was chosen because it is the first object referenced
# by libasn1cxxtcl_la_SOURCES that requires the built sources.
meta.lo: $(BUILT_SOURCES)

# target to make asn-useful.h and asn-useful.C:
$(BUILT_SOURCES): $(SNACC) $(USEFUL_TYPES)
	if test "x$(BUFFLAGS)" = x-DTCL; then \
	  $(SNACC) -C @SNACC_NOVOLAT@ -l 50 -tcl "" $(USEFUL_TYPES); \
	  rm modules.C; \
	else \
	  $(SNACC) -C @SNACC_NOVOLAT@ -l 50 $(USEFUL_TYPES); \
	fi

# target to make remote things:
$(SNACC): force
	cd `dirname $@` && $(MAKE) `basename $@`
force: ;

# target to hook the distribution:
dist-hook:
	for built in $(BUILT_SOURCES); do rm -f $(distdir)/$build; done

