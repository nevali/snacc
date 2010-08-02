// file: .../c++-lib/src/asn-any.C
//
// MS 92
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/src/asn-any.C,v 1.6 1997/02/28 13:39:43 wan Exp $
// $Log: asn-any.C,v $
// Revision 1.6  1997/02/28 13:39:43  wan
// Modifications collected for new version 1.3: Bug fixes, tk4.2.
//
// Revision 1.5  1997/02/16 20:26:01  rj
// check-in of a few cosmetic changes
//
// Revision 1.4  1995/07/24  20:12:48  rj
// changed `_' to `-' in file names.
//
// Revision 1.3  1994/10/08  04:18:20  rj
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
// Revision 1.2  1994/08/28  10:01:10  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:55  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#include "asn-config.h"
#include "asn-len.h"
#include "asn-tag.h"
#include "asn-type.h"
#include "asn-oid.h"
#include "asn-int.h"
#include "asn-any.h"


Table *AsnAny::oidHashTbl = NULL;
Table *AsnAny::intHashTbl = NULL;


// Define this ANY value's type to the one that the given id hashes
// to in the ANY table.
void
AsnAny::SetTypeByInt (AsnInt id)
{
    Hash hash;
    void *anyInfo;

    /* use int as hash string */
    AsnIntType idval = (AsnIntType) id;
    hash = MakeHash ((char*)&idval, sizeof (idval));
    if (CheckForAndReturnValue (intHashTbl, hash, &anyInfo))
        ai = (AnyInfo*) anyInfo;
    else
        ai = NULL; /* indicates failure */

} /* SetAnyTypeByInt */

// Define this ANY value's type to the one that the given id hashes
// to in the ANY table.
void AsnAny::SetTypeByOid (AsnOid &id)
{
    Hash hash;
    void *anyInfo;

    /* use encoded oid as hash string */
    hash = MakeHash (id.Str(), id.Len());
    if (CheckForAndReturnValue (oidHashTbl, hash, &anyInfo))
        ai = (AnyInfo*) anyInfo;
    else
        ai = NULL; /* indicates failure */

} /* SetAnyTypeByOid */



// Given an integer, intId, to hash on, the type and it's anyId
// are installed in the integer id hash tbl
void
AsnAny::InstallAnyByInt (AsnInt intId, int anyId, AsnType *type)
{
    AnyInfo *a;
    Hash h;

    a = new AnyInfo;
    //  Oid will be NULL and 0 len by default constructor
    a->anyId = anyId;
    a->intId = intId;
    a->typeToClone = type;

    if (AsnAny::intHashTbl == NULL)
        AsnAny::intHashTbl = InitHash();

    AsnIntType idval = (AsnIntType) intId;
    h = MakeHash ((char*)&idval, sizeof (idval));
    Insert (AsnAny::intHashTbl, a, h);

}  /* InstallAnyByInt */


// given an OBJECT IDENTIFIER, oid, to hash on, the type and it's anyId
// are installed in the OBJECT IDENTIFIER id hash tbl
void
AsnAny::InstallAnyByOid (AsnOid &oid, int anyId, AsnType *type)
{
    AnyInfo *a;
    Hash h;

    a =  new AnyInfo;
    a->anyId = anyId;
    a->oid = oid;  // copy given oid
    a->typeToClone = type;

    h = MakeHash (oid.Str(), oid.Len());

    if (AsnAny::oidHashTbl == NULL)
        AsnAny::oidHashTbl = InitHash();

    Insert (AsnAny::oidHashTbl, a, h);

}  /* InstallAnyByOid */


//
// if you haven't set up the value properly
// this will croak (since it's a programming error
// - ie, you didn't initialize the data structure properly
//
AsnLen
AsnAny::BEnc (BUF_TYPE b)
{
    return value->BEnc (b);
}



void
AsnAny::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    if (ai == NULL)
        longjmp (env, -81);

    value = ai->typeToClone->Clone();

    if (value == NULL)
        longjmp (env, -82);
    else
        value->BDec (b, bytesDecoded, env);
}


void AsnAny::Print (ostream &os) const
{
  os << value;
}
