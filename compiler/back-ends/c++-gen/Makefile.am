## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.4 foreign

noinst_LIBRARIES = libjunk.a
libjunk_a_SOURCES = kwd.h rules.h types.h gen-any.h gen-code.h gen-vals.h \
	kwd.c types.c rules.c gen-code.c gen-vals.c gen-any.c 
CORE_DIR = $(top_srcdir)/compiler/core
BACKEND_DIR = $(top_srcdir)/compiler/back-ends
ASN1_LIB_DIR = $(top_srcdir)/c-lib
ASN1_INC_DIR = $(ASN1_LIB_DIR)/inc
ASN1_BOOT_DIR = $(ASN1_LIB_DIR)/boot
INCLUDES = -DCOMPILER -DUSE_NIBBLE_MEMORY=0 -DUSE_EXP_BUF \
	-I$(ASN1_INC_DIR) -I$(ASN1_BOOT_DIR) -I$(BACKEND_DIR) -I$(CORE_DIR)
CLEANFILES = LIBOBJ

# target to make LIBOBJ:
LIBOBJ: $(libjunk_a_OBJECTS)
	rm -f $@ && d=`pwd` && for obj in $(libjunk_a_OBJECTS); do echo "$$d/$$obj" >> $@; done
