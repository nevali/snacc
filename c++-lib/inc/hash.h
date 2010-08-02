// file: .../c++-lib/inc/hash.h - C++ hash tbl routines
//
// Based on hashing stuff from UBC Raven Code (Terry Coatta & Don Acton)
//
// MS 92
// Copyright (C) 1992 the University of British Columbia
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
// $Header: /usr/app/odstb/CVS/snacc/c++-lib/inc/hash.h,v 1.5 1997/02/28 13:39:42 wan Exp $
// $Log: hash.h,v $
// Revision 1.5  1997/02/28 13:39:42  wan
// Modifications collected for new version 1.3: Bug fixes, tk4.2.
//
// Revision 1.4  1997/02/16 20:25:51  rj
// check-in of a few cosmetic changes
//
// Revision 1.3  1994/10/08  04:18:12  rj
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
// Revision 1.2  1994/08/28  10:00:59  rj
// comment leader fixed.
//
// Revision 1.1  1994/08/28  09:20:46  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.

#ifndef _asn_hash_h_
#define _asn_hash_h_

#define TABLESIZE 256
#define INDEXMASK 0xFF
#define INDEXSHIFT 8

typedef void *Table[TABLESIZE];

typedef unsigned int Hash;

typedef struct HashSlot
{
  int    leaf;
  Hash   hash;
  void  *value;
  Table *table;
} HashSlot;

Hash MakeHash (const char *str, size_t len);

Table *InitHash();

int Insert (Table *table, void *element, Hash hash);

int CheckFor (Table *table, Hash hash);

int CheckForAndReturnValue (Table *table, Hash hash, void **value);


#endif /* conditional include */
