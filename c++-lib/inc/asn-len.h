// file: .../c++-lib/inc/asn-len.h - handle ASN.1 length encoding/decoding etc.
//
// MS 92/06/18
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/asn-len.h,v 1.6 1997/02/16 10:07:43 rj Exp $
// $Log: asn-len.h,v $
// Revision 1.6  1997/02/16 10:07:43  rj
// make the unsigned value unsigned :-)
//
// Revision 1.5  1995/07/25  20:19:01  rj
// changed `_' to `-' in file names.
//
// Revision 1.4  1994/10/08  04:18:04  rj
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
// Revision 1.3  1994/08/31  23:35:00  rj
// semicolon removed from end of macro text
//
// Revision 1.2  1994/08/28  10:00:50  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:36  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_len_h_
#define _asn_len_h_

typedef size_t		AsnLen;

#define INDEFINITE_LEN	~0UL // max unsigned value used for indef rep

#ifdef USE_INDEF_LEN

#define BEncEocIfNec(b)\
    BEncEoc (b)

#define BEncConsLen(b, len)\
    2 + BEncIndefLen (b) /* include len for EOC */

#else // default -- use definite length -- usually faster (for snacc encoders) and smaller encodings

#define BEncEocIfNec(b)  /* do nothing */

#define BEncConsLen(b, len)\
    BEncDefLen (b, len)

#endif

#define BEncIndefLen( b)\
    1;\
    b.PutByteRvs (0x80)

/*
 * use if you know the encoded length will be 0 >= len <= 127
 * Eg for booleans, nulls, any resonable integers and reals
 *
 * NOTE: this particular Encode Routine does NOT return the length
 * encoded (1).  The length counter must be explicity incremented
 */
#define BEncDefLenTo127( b, len)\
    b.PutByteRvs ((unsigned char) len)

#define BDEC_2ND_EOC_OCTET( b, bytesDecoded, env)\
{\
    if ((b.GetByte() != 0) || b.ReadError())\
	Asn1Warning << "Warning - second octet of EOC not zero" << endl;\
    (bytesDecoded)++;\
}

AsnLen BDecLen (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

AsnLen BEncDefLen ( BUF_TYPE b, AsnLen len);

AsnLen BEncEoc (BUF_TYPE b);

void  BDecEoc (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);

#endif /* conditional include */
