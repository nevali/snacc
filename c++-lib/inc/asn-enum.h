// file: .../c++-lib/inc/asn-enum.h - c++ version of ASN.1 ENUMERATED
//
//              inherits from AsnInt but changes universal tag stuff
// MS 92/06/15
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-enum.h,v 1.5 1995/08/17 15:17:07 rj Exp $
// $Log: asn-enum.h,v $
// Revision 1.5  1995/08/17 15:17:07  rj
// AsnEnumTypeDesc gets its own TclGetVal and TclSetVal functions.
//
// Revision 1.4  1995/07/24  17:52:00  rj
// Clone() added, or else the _desc would be wrong (and the wrong BEnc etc... would get called for Clone-d objects).
//
// _desc changed from AsnIntTypeDesc to AsnEnumTypeDesc.
//
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:17:59  rj
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
// Revision 1.2  1994/08/28  10:00:48  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:31  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_enum_h_
#define _asn_enum_h_

class AsnEnum: public AsnInt
{
public:
#if !TCL
				AsnEnum():
				  AsnInt()
				{}
#endif
				AsnEnum (int i):
				  AsnInt (i)
				{}

  AsnType			*Clone() const;

  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

#if META
  static const AsnEnumTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif /* TCL */
#endif /* META */
};

#endif /* conditional include */
