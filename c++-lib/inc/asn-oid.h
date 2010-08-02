// file: .../c++-lib/inc/asn-oid.h - ASN.1 OBJECT IDENTIFIER type
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-oid.h,v 1.6 1997/02/16 12:56:15 rj Exp $
// $Log: asn-oid.h,v $
// Revision 1.6  1997/02/16 12:56:15  rj
// construct in the order the members are defined
//
// Revision 1.5  1995/07/24  18:37:59  rj
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// _desc type corrected from AsnOctsTypeDesc to AsnOidTypeDesc.
//
// Revision 1.4  1995/02/18  19:25:16  rj
// remove const from arguments that are passed by value.
//
// Revision 1.3  1994/10/08  04:18:08  rj
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
// Revision 1.2  1994/08/28  10:00:54  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:40  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_oid_h_
#define _asn_oid_h_

class AsnOid: public AsnType
{
private:
  int				OidEquiv (const AsnOid &o) const;

protected:
  size_t			octetLen;
  char				*oid;

public:
				AsnOid():
				  octetLen (0),
				  oid (NULL)
				{}

				AsnOid (const char *encOid, size_t len)	{ Set (encOid, len); }
				AsnOid (const AsnOid &o)		{ Set (o); }
				AsnOid (unsigned long int a1, unsigned long int a2, long int a3 = -1, long int a4 = -1, long int a5 = -1, long int a6 = -1, long int a7 = -1, long int a8 = -1, long int a9 = -1, long int a10 = -1, long int a11 = -1)
									{ Set (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
#ifndef _IBM_ENC_
				~AsnOid();
#else
				~AsnOid()				{ mem_mgr_ptr->Put ((void*) oid); }     // Guido Grassel, 11.8.93
#endif /* _IBM_ENC_ */

  AsnType			*Clone() const;

  AsnOid			&operator = (const AsnOid &o)		{ ReSet (o); return *this; }

  size_t			Len() const				{ return octetLen; }
  const char			*Str() const				{ return oid; }
				operator char * ()			{ return oid; }
				operator const char * () const		{ return oid; }
  unsigned long int		NumArcs() const;

  bool				operator == (const AsnOid &o) const	{ return OidEquiv (o); }
  bool				operator != (const AsnOid &o) const	{ return !OidEquiv (o); }

  // Set methods overwrite oid and octetLen values
  void				Set (const char *encOid, size_t len);
  void				Set (const AsnOid &o);

  // first two arc numbers are mandatory.  rest are optional since negative arc nums are not allowed in the
  // encodings, use them to indicate the 'end of arc numbers' in the optional parameters
  void				Set (unsigned long int a1, unsigned long int a2, long int a3 = -1, long int a4 = -1, long int a5 = -1, long int a6 = -1, long int a7 = -1, long int a8 = -1, long int a9 = -1, long int a10 = -1, long int a11 = -1);


  // ReSet routines are like Set except the old oid value is freed
  void				ReSet (const char *encOid, size_t len);
  void				ReSet (const AsnOid &o);
  void				ReSet (unsigned long int a1, unsigned long int a2, long int a3 = -1, long int a4 = -1, long int a5 = -1, long int a6 = -1, long int a7 = -1, long int a8 = -1, long int a9 = -1, long int a10 = -1, long int a11 = -1);

  AsnLen			BEncContent (BUF_TYPE b);
  void				BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

  void				Print (ostream &os) const;

#if META
  static const AsnOidTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif /* TCL */
#endif /* META */
};

#endif /* conditional include */
