// file: .../c++-lib/inc/asn-bits.h - ASN.1 BIT STRING type
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-bits.h,v 1.6 1997/02/16 20:25:33 rj Exp $
// $Log: asn-bits.h,v $
// Revision 1.6  1997/02/16 20:25:33  rj
// check-in of a few cosmetic changes
//
// Revision 1.5  1995/07/24  17:53:51  rj
// #if TCL ... #endif wrapped into #if META ... #endif
//
// changed `_' to `-' in file names.
//
// Revision 1.4  1995/02/18  19:26:18  rj
// remove const from arguments that are passed by value.
//
// Revision 1.3  1994/10/08  04:17:57  rj
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
// Revision 1.2  1994/08/28  10:00:44  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:25  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_bits_h_
#define _asn_bits_h_

extern char			numToHexCharTblG[];

#define TO_HEX( fourBits)	(numToHexCharTblG[(fourBits) & 0x0F])

class AsnBits: public AsnType
{
private:
  bool				BitsEquiv (const AsnBits &ab) const;
  void				BDecConsBits (BUF_TYPE b, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  void				FillBitStringStk (BUF_TYPE b, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env);

protected:
  size_t			bitLen;
  char				*bits;

public:

				AsnBits()				{ bits = NULL; bitLen = 0; }
				AsnBits (size_t numBits)		{ Set (numBits); }
				AsnBits (const char *bitOcts, size_t numBits)
									{ Set (bitOcts, numBits); }
				AsnBits (const AsnBits &b)		{ Set (b); }
#ifndef _IBM_ENC_
				~AsnBits();
#else
				~AsnBits()				{ mem_mgr_ptr->Put ((void *) bits); } // Guido Grassel, 11.8.93
#endif /* _IBM_ENC_ */

  AsnType			*Clone() const;

  AsnBits			&operator = (const AsnBits &b)		{ ReSet (b); return *this; }

  // overwrite existing bits and bitLen values
  void				Set (size_t numBits);
  void				Set (const char *bitOcts, size_t numBits);
  void				Set (const AsnBits &b);

  // free old bits value, the reset bits and bitLen values
  void				ReSet (size_t numBits);
  void				ReSet (const char *bitOcts, size_t numBits);
  void				ReSet (const AsnBits &b);

  bool				operator == (const AsnBits &ab) const	{ return BitsEquiv (ab); }
  bool				operator != (const AsnBits &ab) const	{ return !BitsEquiv (ab); }

  void				SetBit (size_t);
  void				ClrBit (size_t);
  bool				GetBit (size_t) const;

  size_t			BitLen() const				{ return bitLen; }

  AsnLen			BEncContent (BUF_TYPE b);
  void				BDecContent (BUF_TYPE b, AsnTag tagId, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen			BEnc (BUF_TYPE b);
  void				BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS

  void				Print (ostream &) const;

#if META
  static const AsnBitsTypeDesc	_desc;

  const AsnTypeDesc		*_getdesc() const;

#if TCL
  int				TclGetVal (Tcl_Interp *) const;
  int				TclSetVal (Tcl_Interp *, const char *val);
#endif /* TCL */
#endif /* META */
};

#endif /* conditional include */
