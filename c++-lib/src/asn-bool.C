// file: .../c++-lib/src/asn-bool.C - methods for AsnBool (ASN.1 BOOLEAN) class
//
// MS 92/06/16
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/asn-bool.C,v 1.7 1997/02/28 13:39:44 wan Exp $
// $Log: asn-bool.C,v $
// Revision 1.7  1997/02/28 13:39:44  wan
// Modifications collected for new version 1.3: Bug fixes, tk4.2.
//
// Revision 1.6  1997/02/16 20:26:03  rj
// check-in of a few cosmetic changes
//
// Revision 1.5  1995/07/24  20:10:43  rj
// call constructor with additional pdu and create arguments.
//
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// Revision 1.4  1994/10/08  04:18:22  rj
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
// Revision 1.3  1994/08/31  23:30:48  rj
// use the bool built-in where applicable, and a replacement type otherwise.
//
// Revision 1.2  1994/08/28  10:01:11  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:58  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#include "asn-config.h"
#include "asn-len.h"
#include "asn-tag.h"
#include "asn-type.h"
#include "asn-bool.h"

AsnType *AsnBool::Clone() const
{
  return new AsnBool;
}

AsnLen AsnBool::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    BEncDefLenTo127 (b, l);
    l++;
    l += BEncTag1 (b, UNIV, PRIM, BOOLEAN_TAG_CODE);
    return l;
}

void AsnBool::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnLen elmtLen;
    if (BDecTag (b, bytesDecoded, env) != MAKE_TAG_ID (UNIV, PRIM, BOOLEAN_TAG_CODE))
    {
	Asn1Error << "AsnBool::BDec: ERROR tag on BOOLEAN wrong." << endl;
	longjmp (env, -51);
    }
    elmtLen = BDecLen (b, bytesDecoded, env);

    BDecContent (b, MAKE_TAG_ID (UNIV, PRIM, BOOLEAN_TAG_CODE), elmtLen, bytesDecoded, env);
}

// Decodes the content of a BOOLEAN and sets this object's value
// to the decoded value. Flags an error if the length is wrong
// or a read error occurs.
void AsnBool::BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env)
{
    if (elmtLen != 1)
    {
        Asn1Error << "AsnBool::BDecContent: ERROR - boolean value too long." << endl;
        longjmp (env, -5);
    }

    value = (b.GetByte() != 0);
    bytesDecoded++;

    if (b.ReadError())
    {
        Asn1Error << "AsnBool::BDecContent: ERROR - decoded past end of data " << endl;
        longjmp (env, -6);
    }
}

AsnLen AsnBool::BEncContent (BUF_TYPE b)
{
    b.PutByteRvs (value ? 0xFF : 0);
    return 1;
}

// print the BOOLEAN's value in ASN.1 value notation to the given ostream
void AsnBool::Print (ostream &os) const
{
  os << (value ? "TRUE" : "FALSE");
}

#if META

const AsnTypeDesc AsnBool::_desc (NULL, NULL, false, AsnTypeDesc::BOOLEAN, NULL);

const AsnTypeDesc *AsnBool::_getdesc() const
{
  return &_desc;
}

#if TCL

int AsnBool::TclGetVal (Tcl_Interp *interp) const
{
  Tcl_SetResult (interp, value ? "TRUE" : "FALSE", TCL_STATIC);
  return TCL_OK;
}

int AsnBool::TclSetVal (Tcl_Interp *interp, const char *valstr)
{
  int valval;

  if (Tcl_GetBoolean (interp, (char*) valstr, &valval) != TCL_OK)
    return TCL_ERROR;

  value = valval;

  return TCL_OK;
}

#endif /* TCL */
#endif /* META */
