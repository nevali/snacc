## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.3 foreign

noinst_PROGRAMS = snaccC
bin_PROGRAMS = snacc
SNACC_UNBUILT = parse-asn1.y lex-asn1.l \
	asn1module.h define.h dependency.h do-macros.h err-chk.h \
	exports.h gen-tbls.h lex-stuff.h lib-types.h link-types.h \
	link-values.h mem.h meta.h normalize.h oid.h parser.h \
	print.h recursive.h snacc-util.h val-parser.h \
	define.c dependency.c do-macros.c err-chk.c exports.c \
	gen-tbls.c lib-types.c link-types.c link-values.c mem.c \
	meta.c normalize.c oid.c print.c recursive.c snacc.c \
	snacc-util.c val-parser.c 
SNACC_BUILT = tbl.h tbl.c
snacc_SOURCES = $(SNACC_UNBUILT) $(SNACC_BUILT)
snaccC_SOURCES = $(SNACC_UNBUILT) tbl-boot.h tbl-boot.c
YFLAGS = -d
BACKEND_DIR = $(top_srcdir)/compiler/back-ends
ASN1_SRC_DIR = $(top_srcdir)/asn1specs
ASN1_LIB_DIR = $(top_srcdir)/c-lib
ASN1_INC_DIR = $(ASN1_LIB_DIR)/inc
ASN1_BOOT_DIR = $(ASN1_LIB_DIR)/boot
USEFUL_TYPES = $(ASN1_SRC_DIR)/asn-useful.asn1
snacc_DEPENDENCIES = ../back-ends/LIBOBJ $(ASN1_LIB_DIR)/Cebuf/libasn1cCebuf.la 
snacc_LDADD = `cat ../back-ends/LIBOBJ` $(ASN1_LIB_DIR)/Cebuf/libasn1cCebuf.la @LEXLIB@
snaccC_DEPENDENCIES = $(snacc_DEPENDENCIES)
snaccC_LDADD = $(snacc_LDADD)
INCLUDES = -DCOMPILER -DUSE_NIBBLE_MEMORY=0 -DUSE_EXP_BUF \
	-I$(ASN1_INC_DIR) -I$(ASN1_BOOT_DIR) -I$(BACKEND_DIR)
CLEANFILES = $(SNACC_BUILT)
EXTRA_DIST = parse-asn1.h

# target to make tbl.h and tbl.c:
$(SNACC_BUILT): snaccC $(USEFUL_TYPES) $(ASN1_SRC_DIR)/tbl.asn1
	./snaccC -c -t -e -u $(USEFUL_TYPES) $(ASN1_SRC_DIR)/tbl.asn1

# target to make remote things:
$(snacc_DEPENDENCIES): force
	cd `dirname $@` && $(MAKE) `basename $@`
force: ;

# target to capture the distribution:
dist-hook:
	cd $(distdir) && rm -f $(SNACC_BUILT)