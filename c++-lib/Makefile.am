## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = 1.3 foreign

PHANTOM_DIRS = c++ @CXXTCLDIR@
SUBDIRS = $(PHANTOM_DIRS) inc
EXTRA_DIST = src README

# target to hook into the distribution:
dist-hook:
	cd $(distdir) && rm -rf $(PHANTOM_DIRS)
