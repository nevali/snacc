## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.3 foreign

PHANTOM_DIRS = Cebuf ebuf mbuf sbuf tbl
SUBDIRS = $(PHANTOM_DIRS) inc
EXTRA_DIST = src boot tbl.h.patch

# target to hook into the distribution:
dist-hook:
	cd $(distdir) && rm -rf $(PHANTOM_DIRS)
