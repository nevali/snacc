## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.4 foreign
SUBDIRS = c-gen c++-gen idl-gen

noinst_LIBRARIES = libjunk.a
libjunk_a_SOURCES = cond.c cond.h str-util.c str-util.h tag-util.c tag-util.h
CORE_DIR = $(top_srcdir)/compiler/core
BACKEND_DIR = $(top_srcdir)/compiler/back-ends
ASN1_LIB_DIR = $(top_srcdir)/c-lib
ASN1_INC_DIR = $(ASN1_LIB_DIR)/inc
ASN1_BOOT_DIR = $(ASN1_LIB_DIR)/boot
INCLUDES = -DCOMPILER -DUSE_NIBBLE_MEMORY=0 -DUSE_EXP_BUF \
	-I$(ASN1_INC_DIR) -I$(ASN1_BOOT_DIR) -I$(BACKEND_DIR) -I$(CORE_DIR)
CLEANFILES = LIBOBJ

# target to make LIBOBJ:
GEN_LIBOBJ = c-gen/LIBOBJ c++-gen/LIBOBJ idl-gen/LIBOBJ
LIBOBJ: $(libjunk_a_OBJECTS) $(GEN_LIBOBJ)
	rm -f $@ && d=`pwd` && for obj in $(libjunk_a_OBJECTS); do echo "$$d/$$obj" >> $@; done
	for obj in $(GEN_LIBOBJ); do cat $$obj >> $@; done

# target to make remote things:
$(GEN_LIBOBJ): force
	cd `dirname $@` && $(MAKE) `basename $@`
force: ;

