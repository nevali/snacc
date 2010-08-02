// file: .../c++-lib/inc/asn-incl.h - includes all of the asn1 library files
//
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-incl.h,v 1.5 1997/02/16 20:25:37 rj Exp $
// $Log: asn-incl.h,v $
// Revision 1.5  1997/02/16 20:25:37  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/24  17:52:33  rj
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:18:01  rj
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
// Revision 1.2  1994/08/28  10:00:49  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:33  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifdef _IBM_ENC_
#define ChoiceUnion
#endif /* _IBM_ENC_ */

#include "asn-config.h"
#include "asn-buf.h"
#include "asn-len.h"
#include "asn-tag.h"
#include "asn-type.h"
#include "asn-int.h"
#include "asn-bool.h"
#include "asn-real.h"
#include "asn-oid.h"
#include "asn-octs.h"
#include "asn-bits.h"
#include "asn-enum.h"
#include "asn-null.h"
#include "asn-any.h"
#include "asn-useful.h"
#include "print.h"
