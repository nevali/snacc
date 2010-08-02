// file: .../c++-lib/inc/asn-int.h - c++ version of ASN.1 integer
//
// MS 92/06/15
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-int.h,v 1.5 1995/09/07 18:49:19 rj Exp $
// $Log: asn-int.h,v $
// Revision 1.5  1995/09/07 18:49:19  rj
// long int replaced by newly introduced AsnIntType at a lot of places.
// it shall provide a 32 bit integer type on all platforms.
//
// Revision 1.4  1995/07/24  17:53:56  rj
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:18:02  rj
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
// Revision 1.1  1994/08/28  09:20:35  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_int_h_
#define _asn_int_h_

class AsnInt: public AsnType
{
protected:
  AsnIntType			value;

public:
				AsnInt()				{}
				AsnInt (AsnIntType val):
				  value (val)
				{}

  AsnType			*Clone() const;

				operator AsnIntType() const		{ return value; }
  AsnInt			&operator = (AsnIntType newvalue)		{ value = newvalue; return *this; }

  void				Set (AsnIntType i)			{ value = i; }
  void				ReSet (AsnIntType i)			{ value = i; }

  AsnLen			BEncContent (BUF_TYPE b);
  void				BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

  void				Print (ostream &os) const;

#if META
  static const AsnIntTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif /* TCL */
#endif /* META */
};

#endif /* conditional include */
