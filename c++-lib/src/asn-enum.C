// file: .../c++-lib/src/asn-enum.C - methods for AsnEnum (ASN.1 ENUMERATED) class
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/asn-enum.C,v 1.5 1997/02/28 13:39:44 wan Exp $
// $Log: asn-enum.C,v $
// Revision 1.5  1997/02/28 13:39:44  wan
// Modifications collected for new version 1.3: Bug fixes, tk4.2.
//
// Revision 1.4  1995/08/17 15:19:52  rj
// AsnEnumTypeDesc gets its own TclGetVal and TclSetVal functions.
//
// Revision 1.3  1995/07/24  20:14:49  rj
// Clone() added, or else the _desc would be wrong (and the wrong BEnc etc... would get called) for Clone-d objects.
//
// call constructor with additional pdu and create arguments.
//
// changed `_' to `-' in file names.
//
// Revision 1.2  1994/10/08  05:26:37  rj
// comment leader fixed.
//
// Revision 1.1  1994/10/08  05:24:03  rj
// functions extracted from ../inc/asn_enum.h

#include "asn-config.h"
#include "asn-len.h"
#include "asn-tag.h"
#include "asn-type.h"
#include "asn-int.h"
#include "asn-enum.h"

AsnType *AsnEnum::Clone() const
{
  cerr << "AsnEnum::Clone() called" << endl;
  abort();
  return NULL;
}

AsnLen AsnEnum::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    BEncDefLenTo127 (b, l);
    l++;
    l += BEncTag1 (b, UNIV, PRIM, ENUM_TAG_CODE);
    return l;
}

void AsnEnum::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnLen elmtLen;
    if (BDecTag (b, bytesDecoded, env) != MAKE_TAG_ID (UNIV, PRIM, ENUM_TAG_CODE))
    {
	Asn1Error << "AsnEnum::BDec: ERROR tag on ENUMERATED is wrong." << endl;
	longjmp (env,-52);
    }

    elmtLen = BDecLen (b, bytesDecoded, env);
    BDecContent (b, MAKE_TAG_ID (UNIV, PRIM, ENUM_TAG_CODE), elmtLen, bytesDecoded, env);
}

#if META

const AsnEnumTypeDesc AsnEnum::_desc (NULL, NULL, false, AsnTypeDesc::ENUMERATED, NULL, NULL);

const AsnTypeDesc *AsnEnum::_getdesc() const
{
  return &_desc;
}

#if TCL

int AsnEnum::TclGetVal (Tcl_Interp *interp) const
{
  const AsnNameDesc *n = _getdesc()->getnames();
  if (n)
  {
    for (; n->name; n++)
      if (n->value == value)
      {
	Tcl_SetResult (interp, (char*)n->name, TCL_STATIC);
	return TCL_OK;
      }
  }
  char valstr[80];
  sprintf (valstr, "%d", value);
  Tcl_AppendResult (interp, "illegal numeric enumeration value ", valstr, " for type ", _getdesc()->getmodule()->name, ".", _getdesc()->getname(), NULL);
  Tcl_SetErrorCode (interp, "SNACC", "ILLENUM", NULL);
  return TCL_ERROR;
}

int AsnEnum::TclSetVal (Tcl_Interp *interp, const char *valstr)
{
  const AsnNameDesc *n = _getdesc()->getnames();
  if (n)
  {
    for (; n->name; n++)
      if (!strcmp (n->name, valstr))
      {
	value = n->value;
	return TCL_OK;
      }
  }
  Tcl_SetErrorCode (interp, "SNACC", "ILLENUM", NULL);
  Tcl_AppendResult (interp, "illegal symbolic enumeration value \"", valstr, "\" for type ", _getdesc()->getmodule()->name, ".", _getdesc()->getname(), NULL);
  return TCL_ERROR;
}

#endif /* TCL */
#endif /* META */
