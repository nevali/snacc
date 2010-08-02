// file: .../c++-lib/inc/asn-config.h - decoder alloc routines and buffer routines and other configuration stuff.
//
// MS 92/06/18
// Copyright (C) 1992 Michael Sample and the University of British Columbia
//
// This library is free software; you can redistribute it and/or
// modify it provided that this copyright/license information is retained
// in original form.
//
// If you modify this file, you must clearly indicate your changes.
//
// This source code is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-config.h,v 1.7 1995/09/07 18:48:36 rj Exp $
// $Log: asn-config.h,v $
// Revision 1.7  1995/09/07 18:48:36  rj
// AsnIntType and AsnUIntType introduced to replace (unsigned) long int at a lot of places.
// they shall provide 32 bit integer types on all platforms.
//
// Revision 1.6  1995/07/25  20:19:00  rj
// changed `_' to `-' in file names.
//
// Revision 1.5  1995/02/13  14:47:46  rj
// settings for IEEE_REAL_FMT/IEEE_REAL_LIB moved from {c_lib,c++_lib}/inc/asn_config.h to acconfig.h.
//
// Revision 1.4  1994/10/08  04:17:59  rj
// code for meta structures added (provides information about the generated code itself).
//
// code for Tcl interface added (makes use of the above mentioned meta code).
//
// virtual inline functions (the destructor, the Clone() function, BEnc(), BDec() and Print()) moved from inc/*.h to src/*.C because g++ turns every one of them into a static non-inline function in every file where the .h file gets included.
//
// made Print() const (and some other, mainly comparison functions).
//
// several `unsigned long int' turned into `size_t'.
//
// Revision 1.3  1994/09/01  00:58:47  rj
// redundant code moved into ../../config.h.bot; semicolon removed from end of macro texts.
//
// Revision 1.2  1994/08/28  10:00:47  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:29  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_config_h_
#define _asn_config_h_

#include <ctype.h>  /* for isprint() in <<op on AsnOcts */
#include <iostream.h>
#include <memory.h>
#include <string.h>
#include <setjmp.h>
#include <math.h> /* to get ieee conversion functions & pow */

#include "snacc.h"

// used not only by AsnInt (asn-int.h), but by AsnNameDesc (meta.h) as well:
#if SIZEOF_INT == 4
#  define I		int
#else
#  if SIZEOF_LONG == 4
#    define I		long
#  else
#    if SIZEOF_SHORT == 4
#      define I		short
#    endif
#  endif
#endif
#ifdef I
  typedef I		AsnIntType;
  typedef unsigned I	AsnUIntType;
#  undef I
#else
#  error "can't find integer type which is 4 bytes in size"
#endif

/* used to test if optionals are present */
#define NOT_NULL( ptr)		((ptr) != NULL)


/*
 * Asn1Error (char *str)
 *  - configure error handler
 */
#define Asn1Error		cerr


/*
 * Asn1Warning (char *str)  - configure warning mechanism
 * (currently not called)
 */
#define Asn1Warning		cerr


/*
 * configure memory scheme used by decoder to allocate memory
 * for the decoded value.  The include file name cannot be
 * be null.
 */
#define Asn1New( class)		new class
#define Asn1Delete( ptr)	delete ptr
#define Asn1Alloc( size)	new char[size]
#define Asn1Free( ptr)		delete ptr

#include "asn-buf.h"
#define BUF_TYPE		AsnBuf &
#define ENV_TYPE		jmp_buf

/* return true if succeeded, false otherwise */
#define PDU_MEMBER_MACROS\
    int BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)\
    {\
	bytesEncoded = BEnc (b);\
	return !b.WriteError();\
    }\
\
    int BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)\
    {\
	jmp_buf env;\
	int val;\
\
	bytesDecoded = 0;\
	if ((val = setjmp (env)) == 0)\
	{\
	    BDec (b, bytesDecoded, env);\
	    return !b.ReadError();\
	}\
	else\
	    return false;\
    }


#endif /* conditional include */
