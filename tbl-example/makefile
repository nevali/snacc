# file: .../tbl-example/makefile
#
# $Header: /usr/app/odstb/CVS/snacc/tbl-example/makefile,v 1.1 1997/02/15 19:33:26 rj Exp $
# $Log: makefile,v $
# Revision 1.1  1997/02/15 19:33:26  rj
# first check-in
#

#include ../../makehead

TOP		= /usr

ASN1_SRC_DIR	= $(TOP)/include/snacc/asn1

ASN1_C_LIB_DIR	= $(TOP)/lib
ASN1_C_INC_DIR	= $(TOP)/include/snacc/c
TTBL_ASN1_LIB	= $(ASN1_C_LIB_DIR)/libasn1ctbl.a

COMPILERDIR	= $(TOP)/bin
SNACC		= $(COMPILERDIR)/snacc
USEFUL_TYPES	= $(ASN1_SRC_DIR)/asn-useful.asn1
SNACCFLAGS	= -u $(USEFUL_TYPES)

TBLTOOLSDIR	= $(TOP)/bin
MKHDR		= $(TBLTOOLSDIR)/mkchdr

ASN1FILES	= $(ASN1_SRC_DIR)/p-rec.asn1
ASN1TTFILE	= p-rec.tt
ASN1TTHFILE	= p-rec.h

CFILES	= example.c
OFILES	= example.o

DISTFILES = \
	README		\
	makefile	\
	$(CFILES)	\
	p-rec.ber

CPPFLAGS	+= -g -I$(TOP) -I$(ASN1_C_INC_DIR) -DUSE_GEN_BUF
LIBS		+= -lm

#-------------------------------------------------------------------------------

all::		depend example

example:	$(OFILES) $(TTBL_ASN1_LIB)
		$(REASON)
		$(CC) $(CFLAGS) -o example $(OFILES) $(TTBL_ASN1_LIB) $(LIBS)

$(ASN1TTFILE):	$(ASN1FILES)
		$(REASON)
		$(SNACC) $(SNACCFLAGS) -T $@ $(ASN1FILES)

$(SNACC) $(MKHDR):
		cd $(@D) && $(MAKE) $(@F)

$(TTBL_ASN1_LIB):
		cd $(@D) && $(MAKE) tbl-lib

$(ASN1TTHFILE):	$(ASN1TTFILE)
		$(REASON)
		$(MKHDR) $? $@

check::		depend example $(ASN1TTFILE)

check::
		uudecode -o p-rec.ber p-rec.ber.uu
		./example p-rec.tt p-rec.ber
		cmp p-rec.ber p-rec.out.ber
		@echo "+++ the test was successful"

# dummy:
install::

clean::
		$(RM) example *.o *~ core .emacs* $(ASN1TTFILE) $(ASN1TTHFILE) p-rec.out.ber p-rec.ber

depend::
		$(MAKE) $(MKHDR)

depend::	$(ASN1TTHFILE)

#include ../maketail
