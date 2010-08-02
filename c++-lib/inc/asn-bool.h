// file: .../c++-lib/inc/asn-bool.h  - c++ version of ASN.1 integer
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-bool.h,v 1.8 1995/09/07 18:45:13 rj Exp $
// $Log: asn-bool.h,v $
// Revision 1.8  1995/09/07 18:45:13  rj
// use AsnBoolTypeDesc instead of AsnTypeDesc (no real difference, it is the same type).
//
// Revision 1.7  1995/07/24  17:53:54  rj
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// Revision 1.6  1995/02/18  19:17:19  rj
// add TRUE/FALSE for backwards compatibility.
//
// Revision 1.5  1995/02/18  12:41:31  rj
// a few more lines for the sake of backwards compatibility.
//
// Revision 1.4  1994/10/08  04:17:58  rj
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
// Revision 1.3  1994/08/31  23:32:13  rj
// use the bool built-in where applicable, and a replacement type otherwise.
//
// Revision 1.2  1994/08/28  10:00:45  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:27  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_bool_h_
#define _asn_bool_h_

#if GLASS
// for backwards compatibility:
#ifndef FALSE
enum { FALSE = false, TRUE = true };
#endif
#endif // GLASS

class AsnBool: public AsnType
{
protected:

// for backwards compatibility:
#if GLASS
#if BOOL_BUILTIN
  typedef bool			_bool;
#else
  enum
  {
    false = ::false,
    true = ::true
  };
#endif
#endif

  bool				value;

public:
				AsnBool (const bool val):
#if BOOL_BUILTIN
				  value (val)
#else
				  value (!!val)
#endif
				{}
				AsnBool()				{}

  AsnType			*Clone() const;

				operator bool() const			{ return value; }
  AsnBool			&operator = (bool newvalue)		{ value = newvalue; return *this; }

  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen			BEncContent (BUF_TYPE b);
  void				BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

  void				Print (ostream &) const;

#if META
  static const AsnBoolTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif // TCL
#endif // META
};

#endif // conditional include
