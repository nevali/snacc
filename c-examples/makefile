# c-examples/makefile
#
# $Header: /usr/app/odstb/CVS/snacc/c-examples/makefile,v 1.2 1995/07/24 20:38:56 rj Exp $
# $Log: makefile,v $
# Revision 1.2  1995/07/24 20:38:56  rj
# `cd && make' instead of `cd; make'.
#
# changed `_' to `-' in file names.
#

SUBDIRS		= test-lib simple any snmp

#-------------------------------------------------------------------------------

.PHONY:	implicit_default
implicit_default::
		$(MAKE) subdirs

subdirs::	$(SUBDIRS)
$(SUBDIRS)::
		cd $@ && $(MAKE) $(subtarget)

# the following hack is needed for older make versions (gmake doesn't need it):
init-depend::
		@for dir in $(SUBDIRS); do\
		  test -f $$dir/dependencies || touch $$dir/dependencies;\
		done

.DEFAULT::
		$(MAKE) subdirs subtarget=$@

distfiles::
		echo makefile
		for dir in $(SUBDIRS); do\
		  subfiles=`cd $$dir && $(MAKE) -s $@`;\
		  for file in $$subfiles; do\
		    echo "$$dir/$$file";\
		  done;\
		done

# dummy:
install::
