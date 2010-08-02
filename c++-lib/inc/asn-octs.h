// file: .../c++-lib/inc/asn-octs.h - ASN.1 OCTET STRING type
//
//  Mike Sample
//  92/07/02
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-octs.h,v 1.5 1997/02/16 20:25:40 rj Exp $
// $Log: asn-octs.h,v $
// Revision 1.5  1997/02/16 20:25:40  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/24  17:46:52  rj
// operator == and != return bool instead of int.
//
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:18:07  rj
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
// Revision 1.2  1994/08/28  10:00:53  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:39  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_octs_h_
#define _asn_octs_h_

#include <string.h>

class AsnOcts: public AsnType
{
private:
  int				OctsEquiv (const AsnOcts &o) const;

  void				FillBitStringStk (BUF_TYPE b, AsnLen elmtLen0, AsnLen& bytesDecoded, ENV_TYPE env);

  void				BDecConsOcts (BUF_TYPE b, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

protected:
  size_t			octetLen;
  char				*octs;

public:

  // constructor and Set alway copy strings so destructor can always delete
				AsnOcts():
				  octetLen (0),
				  octs (NULL)
				{}
				AsnOcts (const char *str)		{ Set (str); }
				AsnOcts (const char *str, const size_t len)
									{ Set (str, len); }
				AsnOcts (const AsnOcts &o)		{ Set (o); }
#ifndef _IBM_ENC_
				~AsnOcts();
#else
				~AsnOcts()				{ mem_mgr_ptr->Put ((void *)octs); }	// Guido Grassel, 11.8.93
#endif /* _IBM_ENC_ */

  AsnType			*Clone() const;

  AsnOcts			&operator = (const AsnOcts &o)		{ ReSet (o); return *this; }
  AsnOcts			&operator = (const char *str)		{ ReSet (str); return *this; }

  // these set the octs and octetLen values
  void				Set (const char *str, size_t len);
  void				Set (const AsnOcts &o);
  void				Set (const char *str);

  // these free the old octs value and
  // then reset the octs and octetLen values
  void				ReSet (const char *str, size_t len);
  void				ReSet (const AsnOcts &o);
  void				ReSet (const char *str);

  size_t			Len() const				{ return octetLen; }
				operator const char* () const		{ return octs; }
				operator char* ()			{ return octs; }

  bool				operator == (const AsnOcts &o) const	{ return OctsEquiv (o); }
  bool				operator != (const AsnOcts &o) const	{ return !OctsEquiv (o); }

  AsnLen			BEncContent (BUF_TYPE b);
  void				BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

  void				Print (ostream &os) const;

#if META
  static const AsnOctsTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif /* TCL */
#endif /* META */
};

#endif /* conditional include */
