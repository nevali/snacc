// file: .../c++-lib/src/asn-type.C  - Abstract class that all ASN.1 types are derived from
//               Design motivated by ANY type.
//
//               Runtime cost in speed and space for virtual fcns will
//               hopefully not be too bad
//
//               If your ASN.1 code does not use ANY or ANY DEFIND BY
//               types then you could  make the BEnc, BDec and Clone
//               non-virtual in the AsnType to improve performance.
//               (undef SUPPORT_ANY_TYPE)
//
//               NOTE: The virtual encode/decode/print etc fcns
//               could be purely virtual (= 0) creating an abstract class
//               but the ANY handling code needs to instantiate the AsnType
//               base class (via Cloning).   Also it allows for default
//               error reporting for ANY types that have not been
//               instantiated properly.
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
// MS 92
//
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/asn-type.C,v 1.4 1997/01/01 20:13:55 rj Exp $
// $Log: asn-type.C,v $
// Revision 1.4  1997/01/01 20:13:55  rj
// "virtual" removed from functions. (fix due to changed C++ language.)
//
// Revision 1.3  1995/07/24  20:35:21  rj
// _getref() gets an additional optional argument to faciliate the different member access semantics of TclGetVal() and TclSetVal().
//
// additional function TclUnsetVal() to delete OPTIONAL members and SEQUENCE OF and SET OF list elements.
// returns an error for all other types.
//
// #if TCL ... #endif wrapped into #if META ... #endif
//
// call constructor with additional pdu and create arguments.
//
// changed `_' to `-' in file names.
//
// Revision 1.2  1994/10/08  04:18:31  rj
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
// Revision 1.1  1994/09/13  14:18:45  rj
// inline functions moved from asn_type.h to asn_type.C.
// functions that are called upon error only don't need to be that fast.
//
// Revision 1.2  1994/08/28  10:00:57  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:44  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#include "asn-config.h"
#include "asn-len.h"
#include "asn-type.h"

AsnType::~AsnType()
{
}

#ifdef SUPPORT_ANY_TYPE

AsnType	 *AsnType::Clone() const
{
  return NULL;
}

void AsnType::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  Asn1Error << "ERROR - Attempt to decode an improperly formed ANY type (programming error)." << endl;
  longjmp (env, -80);
}

AsnLen AsnType::BEnc (BUF_TYPE b)
{
  Asn1Error << "ERROR - Attempt to encode an improperly formed ANY type (programming error)." << endl;
  return 0;
}

#endif

void AsnType::Print (ostream &os) const
{
  os << "ERROR - Attempt to print an improperly formed ANY type (programming error)." << endl;
}

#if META

const AsnTypeDesc AsnType::_desc (NULL, NULL, false, AsnTypeDesc::VOID, NULL);

const AsnTypeDesc *AsnType::_getdesc() const
{
  return &_desc;
}

AsnType	*AsnType::_getref (const char *membername, bool create)
{
  return NULL;
}

const char *AsnType::_typename() const
{
  return _desc.typenames[_getdesc()->type];
}

#if TCL

int AsnType::TclGetDesc (Tcl_DString *valstr) const
{
  return TCL_OK;
}

int AsnType::TclGetVal (Tcl_Interp *interp) const
{
  Tcl_AppendResult (interp, "can't get value from ", _typename(), NULL);
  return TCL_ERROR;
}

int AsnType::TclSetVal (Tcl_Interp *interp, const char *)
{
  Tcl_AppendResult (interp, "can't set value in ", _typename(), NULL);
  return TCL_ERROR;
}

int AsnType::TclUnsetVal (Tcl_Interp *interp, const char *)
{
  Tcl_AppendResult (interp, "can't unset member(s) in ", _typename(), NULL);
  return TCL_ERROR;
}

#endif /* TCL */
#endif /* META */
