# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake 1.4 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = ../..
prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/snacc
pkglibdir = $(libdir)/snacc
pkgincludedir = $(includedir)/snacc

top_builddir = ../..

ACLOCAL = aclocal
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
host_alias = i386-unknown-freebsdelf3.2
host_triplet = i386-unknown-freebsdelf3.2
AS = @AS@
CC = gcc
CXX = c++
DLLTOOL = @DLLTOOL@
LD = /usr/libexec/elf/ld
LEX = flex
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LN_S = ln -s
LTLIBOBJS = 
MAKEINFO = makeinfo
NM = /usr/bin/nm -B
OBJDUMP = @OBJDUMP@
PACKAGE = snacc
RANLIB = ranlib
VERSION = 1.3
YACC = bison -y

AUTOMAKE_OPTIONS = 1.4 foreign

# This Makefile is never actually run - it exists to generate a
# template Makefile.in that configure modifies into Makefiles for the
# buffer-type build directories:

lib_LTLIBRARIES = libasn1cbuf.la
BUILT_SOURCES = asn-useful.c asn-useful.h tbl.h tbl.c
libasn1cbuf_la_SOURCES = asn-any.c asn-len.c asn-real.c print.c tbl-enc.c 	asn-bits.c asn-list.c asn-tag.c tbl-free.c 	asn-bool.c asn-null.c exp-buf.c str-stk.c tbl-gen.c 	asn-enum.c asn-octs.c hash.c tbl-dbg.c tbl-print.c 	asn-int.c asn-oid.c sbuf.c nibble-alloc.c tbl-dec.c tbl-util.c $(BUILT_SOURCES)

cpkgincludedir = $(pkgincludedir)/c
cpkginclude_HEADERS = asn-useful.h tbl.h
INCLUDES = -I$(top_srcdir)/c-lib/inc $(BUFFLAGS)

COMPILERDIR = $(top_srcdir)/compiler
SNACC = $(COMPILERDIR)/core/snacc
ASN1_SRC_DIR = $(top_srcdir)/asn1specs
USEFUL_TYPES = $(ASN1_SRC_DIR)/asn-useful.asn1
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = ../../config.h
CONFIG_CLEAN_FILES = 
LTLIBRARIES =  $(lib_LTLIBRARIES)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I../..
CPPFLAGS = 
LDFLAGS = 
LIBS = -lm 
X_CFLAGS =  -I/usr/X11R6/include
X_LIBS =  -L/usr/X11R6/lib
X_EXTRA_LIBS = 
X_PRE_LIBS =  -lSM -lICE
libasn1cbuf_la_LDFLAGS = 
libasn1cbuf_la_LIBADD = 
libasn1cbuf_la_OBJECTS =  asn-any.lo asn-len.lo asn-real.lo print.lo \
tbl-enc.lo asn-bits.lo asn-list.lo asn-tag.lo tbl-free.lo asn-bool.lo \
asn-null.lo exp-buf.lo str-stk.lo tbl-gen.lo asn-enum.lo asn-octs.lo \
hash.lo tbl-dbg.lo tbl-print.lo asn-int.lo asn-oid.lo sbuf.lo \
nibble-alloc.lo tbl-dec.lo tbl-util.lo asn-useful.lo tbl.lo
CFLAGS = -g -O2 -DFLEX_IN_USE
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
LTCOMPILE = $(LIBTOOL) --mode=compile $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(LIBTOOL) --mode=link $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
HEADERS =  $(cpkginclude_HEADERS)

DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
DEP_FILES =  .deps/asn-any.P .deps/asn-bits.P .deps/asn-bool.P \
.deps/asn-enum.P .deps/asn-int.P .deps/asn-len.P .deps/asn-list.P \
.deps/asn-null.P .deps/asn-octs.P .deps/asn-oid.P .deps/asn-real.P \
.deps/asn-tag.P .deps/asn-useful.P .deps/exp-buf.P .deps/hash.P \
.deps/nibble-alloc.P .deps/print.P .deps/sbuf.P .deps/str-stk.P \
.deps/tbl-dbg.P .deps/tbl-dec.P .deps/tbl-enc.P .deps/tbl-free.P \
.deps/tbl-gen.P .deps/tbl-print.P .deps/tbl-util.P .deps/tbl.P
SOURCES = $(libasn1cbuf_la_SOURCES)
OBJECTS = $(libasn1cbuf_la_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .lo .o .s
$(srcdir)/Makefile.in: Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --foreign c-lib/src/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status $(BUILT_SOURCES)
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-libLTLIBRARIES:

clean-libLTLIBRARIES:
	-test -z "$(lib_LTLIBRARIES)" || rm -f $(lib_LTLIBRARIES)

distclean-libLTLIBRARIES:

maintainer-clean-libLTLIBRARIES:

install-libLTLIBRARIES: $(lib_LTLIBRARIES)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libdir)
	@list='$(lib_LTLIBRARIES)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "$(LIBTOOL)  --mode=install $(INSTALL) $$p $(DESTDIR)$(libdir)/$$p"; \
	    $(LIBTOOL)  --mode=install $(INSTALL) $$p $(DESTDIR)$(libdir)/$$p; \
	  else :; fi; \
	done

uninstall-libLTLIBRARIES:
	@$(NORMAL_UNINSTALL)
	list='$(lib_LTLIBRARIES)'; for p in $$list; do \
	  $(LIBTOOL)  --mode=uninstall rm -f $(DESTDIR)$(libdir)/$$p; \
	done

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

.s.lo:
	$(LIBTOOL) --mode=compile $(COMPILE) -c $<

.S.lo:
	$(LIBTOOL) --mode=compile $(COMPILE) -c $<

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

distclean-libtool:

maintainer-clean-libtool:

libasn1cbuf.la: $(libasn1cbuf_la_OBJECTS) $(libasn1cbuf_la_DEPENDENCIES)
	$(LINK) -rpath $(libdir) $(libasn1cbuf_la_LDFLAGS) $(libasn1cbuf_la_OBJECTS) $(libasn1cbuf_la_LIBADD) $(LIBS)

install-cpkgincludeHEADERS: $(cpkginclude_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(cpkgincludedir)
	@list='$(cpkginclude_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(cpkgincludedir)/$$p"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(cpkgincludedir)/$$p; \
	done

uninstall-cpkgincludeHEADERS:
	@$(NORMAL_UNINSTALL)
	list='$(cpkginclude_HEADERS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(cpkgincludedir)/$$p; \
	done

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = c-lib/src

distdir: $(DISTFILES)
	here=`cd $(top_builddir) && pwd`; \
	top_distdir=`cd $(top_distdir) && pwd`; \
	distdir=`cd $(distdir) && pwd`; \
	cd $(top_srcdir) \
	  && $(AUTOMAKE) --include-deps --build-dir=$$here --srcdir-name=$(top_srcdir) --output-dir=$$top_distdir --foreign c-lib/src/Makefile
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
	$(MAKE) $(AM_MAKEFLAGS) top_distdir="$(top_distdir)" distdir="$(distdir)" dist-hook

DEPS_MAGIC := $(shell mkdir .deps > /dev/null 2>&1 || :)

-include $(DEP_FILES)

mostlyclean-depend:

clean-depend:

distclean-depend:
	-rm -rf .deps

maintainer-clean-depend:

%.o: %.c
	@echo '$(COMPILE) -c $<'; \
	$(COMPILE) -Wp,-MD,.deps/$(*F).pp -c $<
	@-cp .deps/$(*F).pp .deps/$(*F).P; \
	tr ' ' '\012' < .deps/$(*F).pp \
	  | sed -e 's/^\\$$//' -e '/^$$/ d' -e '/:$$/ d' -e 's/$$/ :/' \
	    >> .deps/$(*F).P; \
	rm .deps/$(*F).pp

%.lo: %.c
	@echo '$(LTCOMPILE) -c $<'; \
	$(LTCOMPILE) -Wp,-MD,.deps/$(*F).pp -c $<
	@-sed -e 's/^\([^:]*\)\.o[ 	]*:/\1.lo \1.o :/' \
	  < .deps/$(*F).pp > .deps/$(*F).P; \
	tr ' ' '\012' < .deps/$(*F).pp \
	  | sed -e 's/^\\$$//' -e '/^$$/ d' -e '/:$$/ d' -e 's/$$/ :/' \
	    >> .deps/$(*F).P; \
	rm -f .deps/$(*F).pp
info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am: install-libLTLIBRARIES
install-exec: install-exec-am

install-data-am: install-cpkgincludeHEADERS
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-libLTLIBRARIES uninstall-cpkgincludeHEADERS
uninstall: uninstall-am
all-am: Makefile $(LTLIBRARIES) $(HEADERS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(libdir) $(DESTDIR)$(cpkgincludedir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
	-test -z "$(BUILT_SOURCES)" || rm -f $(BUILT_SOURCES)
mostlyclean-am:  mostlyclean-libLTLIBRARIES mostlyclean-compile \
		mostlyclean-libtool mostlyclean-tags mostlyclean-depend \
		mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-libLTLIBRARIES clean-compile clean-libtool clean-tags \
		clean-depend clean-generic mostlyclean-am

clean: clean-am

distclean-am:  distclean-libLTLIBRARIES distclean-compile \
		distclean-libtool distclean-tags distclean-depend \
		distclean-generic clean-am
	-rm -f libtool

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-libLTLIBRARIES \
		maintainer-clean-compile maintainer-clean-libtool \
		maintainer-clean-tags maintainer-clean-depend \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-libLTLIBRARIES distclean-libLTLIBRARIES \
clean-libLTLIBRARIES maintainer-clean-libLTLIBRARIES \
uninstall-libLTLIBRARIES install-libLTLIBRARIES mostlyclean-compile \
distclean-compile clean-compile maintainer-clean-compile \
mostlyclean-libtool distclean-libtool clean-libtool \
maintainer-clean-libtool uninstall-cpkgincludeHEADERS \
install-cpkgincludeHEADERS tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir mostlyclean-depend \
distclean-depend clean-depend maintainer-clean-depend info-am info \
dvi-am dvi check check-am installcheck-am installcheck install-exec-am \
install-exec install-data-am install-data install-am install \
uninstall-am uninstall all-redirect all-am all installdirs \
mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


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
	patch < $(top_srcdir)/c-lib/tbl.h.patch
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

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
