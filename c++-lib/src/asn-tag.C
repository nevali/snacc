// file: .../c++-lib/src/asn-tag.C -  ASN.1 tag manipulation routines
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/asn-tag.C,v 1.6 1997/09/03 12:10:30 wan Exp $
// $Log: asn-tag.C,v $
// Revision 1.6  1997/09/03 12:10:30  wan
// Patch to tag decoding for tags > 2^14 (thanks to Enrico Badella)
//
// Revision 1.5  1997/02/16 20:26:06  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/24  20:33:17  rj
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:18:30  rj
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
// Revision 1.2  1994/08/28  10:01:20  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:21:09  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#include "asn-config.h"
#include "asn-len.h"
#include "asn-tag.h"

/*
 * Decode a BER Tag from the given buffer.  Error is
 * flagged if the tag is too long or if a read error occurs.
 */
AsnTag
BDecTag (BUF_TYPE  b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tagId;
    AsnTag tmpTagId;
    int i;

    tagId = ((AsnTag) b.GetByte()) << ((sizeof (AsnTag)-1) *8);
    bytesDecoded++;

    /* check if long tag format (ie code > 31) */
    if ((tagId & (((AsnTag) 0x1f) << ((sizeof (AsnTag)-1)*8))) == (((AsnTag)0x1f) << ((sizeof (AsnTag)-1)*8)))
    {
        i = 2;
        do
        {
            tmpTagId = (AsnTag) b.GetByte();
            tagId |= (tmpTagId << ((sizeof (AsnTag)-i)*8));
            bytesDecoded++;
            i++;
        }
        while ((tmpTagId & (AsnTag)0x80) && (i <= sizeof (AsnTag)));

        /*
         * check for too long a tag
         */
        if (i > (sizeof (AsnTag)+1))
        {
            Asn1Error << "BDecTag: ERROR - tag value overflow" << endl;
            longjmp (env, -21);
        }
    }

    if (b.ReadError())
    {
        Asn1Error << "BDecTag: ERROR - decoded past the end of data" << endl;
        longjmp (env, -22);
    }

    return tagId;

} /* BDecTag */
