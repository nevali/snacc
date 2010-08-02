// file: .../c++-lib/src/asn-null.C
//
// MS 92
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/asn-null.C,v 1.5 1995/08/17 15:38:19 rj Exp $
// $Log: asn-null.C,v $
// Revision 1.5  1995/08/17 15:38:19  rj
// set Tcl's errorCode variable
//
// Revision 1.4  1995/07/24  20:18:27  rj
// #if TCL ... #endif wrapped into #if META ... #endif
//
// call constructor with additional pdu and create arguments.
//
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:18:26  rj
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
// Revision 1.2  1994/08/28  10:01:15  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:21:04  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#include "asn-config.h"
#include "asn-len.h"
#include "asn-tag.h"
#include "asn-type.h"
#include "asn-null.h"

AsnType *AsnNull::Clone() const
{
  return new AsnNull;
}

void AsnNull::BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env)
{
    if (elmtLen != 0)
    {
        Asn1Error << "AsnNull::BDecContent: ERROR - NULL values len is non-zero" << endl;
        longjmp (env, -13);
    }
} /* AsnNull::BDecContent */

AsnLen AsnNull::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    BEncDefLenTo127 (b, l);
    l++;
    l += BEncTag1 (b, UNIV, PRIM, NULLTYPE_TAG_CODE);
    return l;
}

void AsnNull::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnLen elmtLen;
    if (BDecTag (b, bytesDecoded, env) != MAKE_TAG_ID (UNIV, PRIM, NULLTYPE_TAG_CODE))
    {
	Asn1Error << "AsnNull::BDec: ERROR tag on NULL is wrong." << endl;
	longjmp (env, -55);
    }

    elmtLen = BDecLen (b, bytesDecoded, env);
    BDecContent (b, MAKE_TAG_ID (UNIV, PRIM, NULLTYPE_TAG_CODE), elmtLen, bytesDecoded, env);
}

void AsnNull::Print (ostream &os) const
{
    os << "NULL";
}

#if META

const AsnNullTypeDesc AsnNull::_desc (NULL, NULL, false, AsnTypeDesc::NUL_, NULL);

const AsnTypeDesc *AsnNull::_getdesc() const
{
  return &_desc;
}

#if TCL

int AsnNull::TclGetVal (Tcl_Interp *interp) const
{
  return TCL_OK;
}

int AsnNull::TclSetVal (Tcl_Interp *interp, const char *valstr)
{
  if (*valstr)
  {
    Tcl_AppendResult (interp, "illegal non-null value `", valstr, "' for type ", _getdesc()->getmodule()->name, ".", _getdesc()->getname(), NULL);
    Tcl_SetErrorCode (interp, "SNACC", "ILLNULL", NULL);
    return TCL_ERROR;
  }

  return TCL_OK;
}

#endif /* TCL */
#endif /* META */
